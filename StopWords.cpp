/* 
 * File:   StopWords.cpp
 * Author: carter
 * 
 * Created on September 6, 2012, 1:30 PM
 * 
 * This file will hold the inplimentation for StopWords, include code to read in data, to maintain data and access the data
 */

#include "StopWords.h"


using namespace std;

StopWords::StopWords() {
    stopWords = new hashdict<int, string>(667,-1);
    keyValue = 0;
}
//This function will read in the stop words from the designated file
//and store them into a char** array

void StopWords::readInStopWords() {
    string buffer;
    ifstream inStopWords("stopwords.txt", ios::in);

    if (!inStopWords) //checks to make sure the file is open //checks to make sure the user chose a valid file and that the file could be opened
    {
        cerr << "File could not be opened" << endl; //if the file is not open displays error message
        exit(1);
    }

    while(!inStopWords.eof()){
        inStopWords >> buffer;
        stopWords->insert(keyValue,buffer);
        keyValue++;
    }
}


//returns a single stop word at the designated integer position passed in the array

string StopWords::getStopWord(int key) {
    return stopWords->find(key);
}

int StopWords::getSize(){
    return keyValue;
}


StopWords::~StopWords() {
}

