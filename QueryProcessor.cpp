/* 
 * File:   QueryProcessor.cpp
 * Author: carter
 * 
 * Created on November 21, 2012, 10:06 PM
 */

#include "QueryProcessor.h"

QueryProcessor::QueryProcessor() {
}

QueryProcessor::QueryProcessor(const QueryProcessor& orig) {
}

QueryProcessor::~QueryProcessor() {
}

void QueryProcessor::parseQuery(string query, StopWords stopList) {
    stringstream parseQuery(query);
    string buffer;
    parseQuery >> buffer;
    if (buffer == "AND") {
        while (buffer != "NOT" ) {
            parseQuery >> buffer;
            if (checkStopWords(buffer, stopList)) {
                string *strptr = new string(buffer);
                AND.push_back(strptr);
            }
            
        }
        if (parseQuery.good()) {
            parseQuery >> buffer;
            while (parseQuery.good()) {
                if (checkStopWords(buffer, stopList)) {
                    string *strptr = new string(buffer);
                    NOT.push_back(strptr);

                }
                parseQuery >> buffer;
            }
        }
    } else if (buffer == "OR") {
        while (buffer != "NOT" && parseQuery.good()) {
            parseQuery >> buffer;
            if (checkStopWords(buffer, stopList)) {
                string *strptr = new string(buffer);
                OR.push_back(strptr);

            }
            
        }
        parseQuery >> buffer;
        while (parseQuery) {
            if (checkStopWords(buffer, stopList)) {
                string *strptr = new string(buffer);
                NOT.push_back(strptr);

            }
            parseQuery >> buffer;
        }
    } else {
        singleWordEntry = buffer;
    }
}

void QueryProcessor::printQuery() {
    cout << "AND:" << endl;
    for (int x = 0; x < AND.size(); x++)
        cout << *AND[x] << endl;
    cout << "OR:" << endl;
    for (int x = 0; x < OR.size(); x++)
        cout << *OR[x] << endl;
    cout << "NOT:" << endl;
    for (int x = 0; x < NOT.size(); x++)
        cout << *NOT[x] << endl;

}

bool QueryProcessor::checkStopWords(string word, StopWords stopList) {
    string word2;
    for (int x = 0; x < stopList.getSize(); x++) {
        cout << word << endl;
        word2 = stopList.getStopWord(x);
        cout << word2;
        if (word == word2)
            return false;
        //        if (word == stopList.getStopWord(x))
        //            return false;
        //        else if (x == 666)
        // return true;
    }
    return true;
}