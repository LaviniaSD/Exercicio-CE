#include <fstream>
#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
#include <thread>
#include <vector>
#include "search.h"
using namespace std;


// Function to count the number of occurrences of two words in a string ignoring punctuation
void count_words(int threadID, vector<vector<int>> count_vector, string text, string word1, string word2) {
    // Remove punctuation from the text
    text = regex_replace(text, regex("[^a-zA-Z\\s]"), "");
    // Convert the text to lowercase
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    // Count the number of occurrences of the words
    int count1 = 0;
    int count2 = 0;
    string word;
    // Create a stringstream to read the text word by word
    stringstream ss(text);
    while(ss >> word){
        if(word == word1){
            count1++;
        }
        if(word == word2){
            count2++;
        }
    }
    
    // Update the vector with the count of words for the thread
    count_vector[threadID-1] = {count1, count2};
}

// Function to sum the counts of words from each thread
vector<int> somaThread(vector<vector<int>> vec, int numThreads){
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < numThreads; i++){
        sum1 += vec[i][0];
        sum2 += vec[i][1];
    }
    return {sum1, sum2};
}

// Function to read the text from a file and divide it into blocks for each thread
vector<string> read_text(string filename, int iNumThreads){
    // Open the file
    ifstream file;
    file.open(filename);
    string line;
    // Set each line to a thread until all lines are used
    vector<string> parts;
    for(int i = 0; i < iNumThreads; i++){
        parts.push_back("");
    }
    int actual_thread = 0;
    while(getline(file, line)){
        if(actual_thread < iNumThreads){
            parts[actual_thread] += line + "\n";
            actual_thread++;
        }
        else{
            actual_thread = 0;
            parts[actual_thread] += line + "\n";
        }
    }
    file.close();
    return parts;
}

// Function to process multiple threads
search_return process_threads(int iNumThreads, string filename, string word1, string word2){

    auto start = chrono::high_resolution_clock::now();

    // Create a struct to store the return values
    struct search_return search_return;
    search_return.iNumThreads = iNumThreads;

    // Text processing
    auto start_text_processing = chrono::high_resolution_clock::now();
    vector<string> parts = read_text(filename, iNumThreads);
    auto end_text_processing = chrono::high_resolution_clock::now();

    // Update the struct with the size of the text blocks
    search_return.threadSize = parts[0].size();

    // Create and launch multiple threads
    std::vector<std::thread> threads;

    // Vector of vectors to store the count of words for each thread
    vector<vector<int>> count_vector;

    // Start measuring time
    auto start_search = chrono::high_resolution_clock::now();

    for(int i = 1; i <= iNumThreads; ++i){
        count_vector.push_back({0, 0});
        threads.push_back(std::thread(count_words, i, count_vector, parts[i-1], word1, word2));
    }

    // End measuring time

    for(auto& thread : threads){
        thread.join();
    }

    auto end_search = chrono::high_resolution_clock::now();


    // Calculate the number of occurrences of the words
    vector<int> vectorSoma = somaThread(count_vector, iNumThreads);


    // Store the return values in the struct
    search_return.loveCount = vectorSoma[0];
    search_return.hateCount = vectorSoma[1];

    // Set the most used word
    if(vectorSoma[0] > vectorSoma[1]){
        search_return.mostUsedWord = word1;
    }
    else{
        search_return.mostUsedWord = word2;
    }

    // End measuring time
    auto end = chrono::high_resolution_clock::now();

    // Calculating time taken by the program for different tasks and storing it in the struct
    search_return.processTime = chrono::duration_cast<chrono::milliseconds>(end_text_processing - start_text_processing).count();
    search_return.searchTime = chrono::duration_cast<chrono::milliseconds>(end_search - start_search).count();
    search_return.totalTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    return search_return;
}

int main(){
    // Text to be processed by each thread
    string document = "shakespeare.txt";

    // Create a struct to store the return values
    struct search_return search_return;

    // Create a vector to store the time taken by the program for different number of threads
    vector<vector<int>> time_vector;

    // Process the program for different number of threads
    for (int i = 1; i <= 100; i++){
        cout << "Number of threads: " << i << endl;
        search_return = process_threads(i, document, "love", "hate");
        cout << "Process time: " << search_return.processTime << " ms" << endl;
        cout << "Search time: " << search_return.searchTime << " ms" << endl;
        cout << "Total time: " << search_return.totalTime << endl;
        cout << "Love count: " << search_return.loveCount << endl;
        cout << "Hate count: " << search_return.hateCount << endl;
        cout << "Most used word: " << search_return.mostUsedWord << endl;
        time_vector.push_back({i, search_return.searchTime});
        cout<<endl;
    }

    // Save the time vector to a csv file
    ofstream file;
    file.open("time.csv");
    file << "A,B" << endl;
    for(int i = 0; i < time_vector.size(); i++){
        file << time_vector[i][0] << "," << time_vector[i][1] << endl;
    }
    file.close();


    return 0;
}
