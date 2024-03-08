#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struct to store the return values of the search function
struct search_return{
    int iNumThreads;
    int threadSize;
    int processTime;
    int searchTime;
    int totalTime;
    int loveCount;
    int hateCount;
    string mostUsedWord;
};

// Function to count the number of occurrences of the words
vector<int> count_words(int iThread, string text, string word1, string word2);

// Function to sum the number of occurrences of the words
vector<int> somaThread(vector<vector<int>> count_vector, int iNumThreads);

// Function to read the text from a file
vector<string> read_text(string filename, int iNumThreads);

// Function to process multiple threads
search_return process_threads(int iNumThreads, string filename, string word1, string word2);