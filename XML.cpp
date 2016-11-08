/*
 * XML.cpp
 *
 *  Created on: Nov 17, 2012
 *      Author: tyler
 */

#include "XML.h"

XML::XML() {
	// TODO Auto-generated constructor stub
	wordRefs = new AvlTree<string, WordRef *>();
}

XML::~XML() {
	// TODO Auto-generated destructor stub
}

void XML::parsePage(const string& path)
{
	traverse_xml(load_file(path));
}

void XML::traverse_xml(const string& input_xml)
{
    vector<char> xml_copy(input_xml.begin(), input_xml.end());
    xml_copy.push_back('\0');

    xml_document<> doc;
    doc.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);

    xml_node<>* page = doc.first_node("mediawiki")->first_node("page");
    xml_node<>* element;

    while(page != NULL)
    {
    	element = page->first_node("title");
    	title = element->value();
    	 
    	//cout << id << endl;
    	author = element->next_sibling("revision")->first_node("contributor")->first_node("username")->value();
        //author = element->first_node("contributor")->first_node("username")->value();
    	element = page->first_node("revision");
    	date = element->first_node("timestamp")->value();
    	text = element->first_node("text")->value();

    	clearSpecialChars(title);
    	clearSpecialChars(author);
    	//clearSpecialCharsDate(date);
    	clearSpecialChars(text);

    	printPage();

    	//parseText();

    	page = page->next_sibling("page");
    }
}

void XML::parseText()
{
	string str;
	stringstream ss;
	ss << text;

	while(ss >> str)
	{
		Page * myPage = new Page(title,text,author, id, date);

		if(wordRefs->doesExist(str))
		{
			if(!wordRefs->find(str)->doesExist(myPage))
				wordRefs->find(str)->insertPage(myPage);
		}
		else
		{
			WordRef * myRef = new WordRef(str);
			wordRefs->insert(str,myRef);
			wordRefs->find(str)->insertPage(myPage);
		}
	}
}

string XML::load_file(const string& path)
{
    ostringstream contents;
    ifstream file(path.c_str());
    if ( !file.is_open() ) {
        // process error.
    	cerr << "ERROR => Unable to open file";
    }
    contents << file.rdbuf();
    return (contents.str());
}

void XML::printPage()
{
	cout << "Title: " << title << endl;
	cout << "ID: " << id << endl;
	cout << "Author: " << author << endl;
	cout << "TimeStamp: " << date << endl;
	cout << "Text: \n" << text << endl;
}

void XML::clearSpecialChars(string &text)
{
	char chars[]= ".,!()[]'<>:{}_|=+;-`~";
	        for (unsigned int i = 0; i < 21; ++i)
	        {
	            text.erase(std::remove(text.begin(),text.end(),chars[i]),text.end());
	        }
}

void XML::clearSpecialCharsDate(string &text)
{
	char chars[]= ".,!()[]'<>/{}_|=+;`~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	        for (unsigned int i = 0; i < 73; ++i)
	        {
	            text.erase(std::remove(text.begin(),text.end(),chars[i]),text.end());
	        }
}
