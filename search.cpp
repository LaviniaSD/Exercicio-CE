#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


void read_text(string filename){
    fstream books;
    books.open(filename,ios::in); //open a file to perform read operation using file object
    if (books.is_open()){ //checking whether the file is open
      string content;
      while(getline(books, content)){ //read data from file object and put it into string.
         cout << content << "\n"; //print the data of the string
      
      break;}
      books.close(); //close the file object.
    }   
}






int main(){


    string document = "shakespeare.txt";
    time_t start, end;
    time(&start);
    read_text(document);
    time(&end); 

    // Calculating total time taken by the program. 
    double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    cout << " sec " << endl;


    

    return 0;
}