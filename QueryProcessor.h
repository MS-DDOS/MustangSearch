/* 
 * File:   QueryProcessor.h
 * Author: carter
 *
 * Created on November 21, 2012, 10:06 PM
 */

#ifndef QUERYPROCESSOR_H
#define	QUERYPROCESSOR_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "StopWords.h"
using namespace std;

class QueryProcessor {
public:
    QueryProcessor();
    QueryProcessor(const QueryProcessor& orig);
    void parseQuery(string, StopWords);
    bool checkStopWords(string, StopWords);
    void printQuery();
    virtual ~QueryProcessor();
private:
    vector<string*> NOT;
    vector<string*> AND;
    vector<string*> OR;
    string singleWordEntry;
};

#endif	/* QUERYPROCESSOR_H */

