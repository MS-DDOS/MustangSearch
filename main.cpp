/* 
 * File:   main.cpp
 * Author: carter
 *
 * Created on November 11, 2012, 7:46 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Page.h"
#include "HashTable.h"
#include "TimeStamp.h"
#include "AvlTree.h"
#include "XML.h"
//#include "english_stem.h"
#include "StopWords.h"
//#include "QueryProcessor.h"
#include "WordRef.h"
//#include "porter2_stemmer.h"


using namespace std;


int main(int argc, char** argv) {
/*
	string unstemmed = "Fucked";
    string stemmed = Porter2Stemmer::stem(unstemmed);
    cout << unstemmed << endl;
    cout << stemmed << endl;
*/

//This code block will demonstrate the stemmer
    
//    std::wstring word;
//    stemming::english_stem<> StemEnglish;
//    /*if you are using std::string (ANSI strings) then convert it to a temporary
//    wchar_t buffer, assign that to a std::wstring, and then stem that.*/
//    std::string ANSIWord("DocUmeNtation");
//    wchar_t* UnicodeTextBuffer = new wchar_t[ANSIWord.length()+1];
//    std::wmemset(UnicodeTextBuffer, 0, ANSIWord.length()+1);
//    std::mbstowcs(UnicodeTextBuffer, ANSIWord.c_str(), ANSIWord.length());
//    word = UnicodeTextBuffer;
//    StemEnglish(word);
//    //now the variable "word" should equal "document"
//    std::wcout << L"\nDemonstrating the stemming of an ANSI string:\n";
//    std::wcout << L"(English) Original text:  " << ANSIWord.c_str() << std::endl;
//    std::wcout << L"(English) Stemmed text:   " << word.c_str() << std::endl;


//This code block will demonstrate the XML parser

	XML * parser = new XML();
	parser->parsePage("WikiDumpSample.xml");


//This code block will demonstrate an AVL Tree
	

//    AvlTree<int, string>* tree = new AvlTree<int, string>;
//    tree->insert(1,"one");
//    tree->insert(10,"ten");
//    tree->insert(4,"four");
//    tree->insert(40,"fourty");
//
//    cout << tree->size() << endl;
//    cout << tree->find(10) << endl;
//    cout << tree->find(40) << endl; //find an element
//    cout << tree->find(1) << endl;
//    cout << tree->find(4) << endl;


//This code block will demonstrate a Hash Table


//    Dictionary<int, string>* dict = new hashdict<int, string>(1,-1);
//    dict->insert(1, "hello");
//    dict->insert(10, "world");
//    dict->insert(40, "yay");
//    dict->insert(4, "margaret");

//    cout << dict->size() << endl;
//    cout << dict->find(10) << endl;
//    cout << dict->find(1) << endl;
//    cout << dict->find(4) << endl;
//    cout << dict->find(40) << endl;


	//This code block will demonstrate the wordRef class

		//Page * apage = new Page("Title","This is some text . But what is text but another form of text","Author","Date");
		//WordRef * word = new WordRef("text");
		//word->insertPage(apage);

		//Page * temp = word->findPage(11);
		//cout << temp->getText();


    //This block of code will insert all of the stopwords and print them out to screen
    
	/*
    StopWords stopList;
    stopList.readInStopWords();
    for (int x = 0; x < stopList.getSize(); x++){
        cout << stopList.getStopWord(x) << endl;
    }


	//This block of code will demonstrate the query processor
    

    string myString = "OR ipad marker NOT texas";
    QueryProcessor qp;
    qp.parseQuery(myString, stopList);
    qp.printQuery();
	*/
    
}

