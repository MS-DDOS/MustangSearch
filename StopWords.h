/* 
 * File:   StopWords.h
 * Author: carter
 *
 * Created on September 6, 2012, 1:30 PM
 * 
 * This is my StopWords class, its job is to hold all of the stop word for the book
 * The stop words are words to not included in the index
 * the words will be stored a char** and will include variables to record the array's size and capacity
 */

#ifndef STOPWORDS_H
#define	STOPWORDS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "HashTable.h"


using namespace std;


class StopWords {
public:
    StopWords();
    void readInStopWords(); //read data from file function
    string getStopWord(int); //returns the designated stop word
    int getSize();
    virtual ~StopWords();
private:
    Dictionary<int, string>* stopWords;
    int keyValue;


};

#endif	/* STOPWORDS_H */

