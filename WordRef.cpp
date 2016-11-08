/* 
 * File:   WordRef.cpp
 * Author: carter
 * 
 * Created on November 14, 2012, 4:23 PM
 */

#include "WordRef.h"

WordRef::WordRef(string word_) {
	word = word_;
	pages = new AvlTree<double,Page *>(); //here the key will be the term frequency in that said document.
}

WordRef::WordRef(const WordRef& orig) {
}

WordRef::~WordRef() {
}

void WordRef::insertPage(int key, Page * &t)
{
	pages->insert(key, t); //no sorting neccisary as avl tree keeps node in order.
}

void WordRef::insertPage(Page * &t)
{
	double key;
	key = calculateTF(word, t);
	pages->insert(key, t); //no sorting neccisary as avl tree keeps node in order.
}

Page * WordRef::findPage(int key)
{
	return pages->find(key);
}

int WordRef::calculateDF()
{
	return pages->size();
}

int WordRef::calculateTF(string word_, Page * page_)
{
	int freq = 0;
	string str;

	stringstream ss;
	ss << page_->getText(); // >> ss;

		while(ss >> str)
			{
				if(str == word_)
					freq++;
			}

		return freq;
}
