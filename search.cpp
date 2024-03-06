#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


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
    return parts;
}


void print_vector(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout<< "Thread " << i << endl;
        cout << v[i] << endl;
    }
}





int main(){


    string document = "shakespeare.txt";
    string document = "testando.txt";

    time_t start, end;
    time(&start);
    print_vector(read_text(document, 4));
    time(&end); 

    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    cout << " sec " << endl;

    


    

    return 0;
}