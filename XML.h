/*
 * XML.h
 *
 *  Created on: Nov 17, 2012
 *      Author: tyler
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "./rapidxml/rapidxml.hpp"
#include "./rapidxml/rapidxml_print.hpp"
#include "Page.h"
#include "WordRef.h"
#include "AvlTree.h"

#ifndef XML_H_
#define XML_H_

using namespace std;
using namespace rapidxml;

class XML {
public:
	XML();
	virtual ~XML();
	void parsePage(const string&);
	void traverse_xml(const string&);
	string load_file(const string&);
	void printPage();
	void storePage();

	string getPath();
	string getTitle();
	string getAuthor();
	string getDate();
	string getText();
	void setPath(string);
	void setTitle(string);
	void setAuthor(string);
	void setDate(string);
	void setText(string);
	void clearSpecialChars(string&);
	void clearSpecialCharsDate(string&);
	void parseText();
private:
	string title;
	string author;
	string date;
	string text;
	string id;
	AvlTree<string, WordRef *> * wordRefs;
};

#endif /* XML_H_ */
