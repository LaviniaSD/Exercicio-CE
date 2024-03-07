#include <iostream>
#include <iomanip>
#include <regex>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
using namespace std;


// Function to count the number of occurrences of two words in a string ignoring punctuation
vector<int> count_words(int threadID,vector<vector<int>> count_vector ,string text, string word1, string word2){
    // Remove punctuation from the text
    text = regex_replace(text, regex("[^a-zA-Z\\s]"), "");
    // Convert the text to lowercase
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    // Count the number of occurrences of the words
    int count1 = 0;
    int count2 = 0;
    string word;
    stringstream ss(text);
    while(ss >> word){
        if(word == word1){
            count1++;
        }
        if(word == word2){
            count2++;
        }
    }
    return {count1, count2};
}


// Function to read the text from a file and divide it into blocks for each thread
vector<string> read_text(string filename, int iNumThreads){
    // Open the file
    ifstream file;
    file.open(filename);
    string line;
    // Calculate the number of lines in the file
    int num_lines = 0;
    while(getline(file, line)){
        num_lines++;
    }
    // Create the blocks of text for each thread based on the number of lines in the file
    vector<string> parts;
    int block_size = num_lines / iNumThreads;
    int start = 0;
    int end = block_size;
    int remainder = num_lines % iNumThreads;

    for(int i = 0; i < iNumThreads; i++){
        string part = "";
        if(i == iNumThreads - 1){
            end += remainder;
        }
        file.clear();
        file.seekg(0, ios::beg);
        for(int j = 0; j < num_lines; j++){
            getline(file, line);
            if(j >= start && j < end){
                part += line + "\n";
            }
        }
        parts.push_back(part);
        start = end;
        end += block_size;
    }
    file.close();
    return parts;
}


void process_threads(int iNumThreads, vector<string> text, string word1, string word2){

    // Create and launch multiple threads
    std::vector<std::thread> threads;

    // Vector of vectors to store the count of words for each thread
    vector<vector<int>> count_vector;

    // Start measuring time
    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < iNumThreads; ++i){
        threads.push_back(std::thread(count_words, i,count_vector, text[i], word1, word2));
    }

    for(auto& thread : threads){
        thread.join();
    }

    // End measuring time
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; // convert to seconds
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);

}



int main(){

    // Text to be processed by each thread
    string document = "shakespeare.txt";
    vector<string> parts;
    for (int i = 1; i <= 100; i++){
        // Process the text and divide it into blocks for each thread
        parts = read_text(document, i);
        process_threads(i, read_text(document, i), "love", "hate");
    }

    return 0;
}
