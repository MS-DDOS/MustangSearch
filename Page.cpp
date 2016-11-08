/* 
 * File:   Page.cpp
 * Author: carter
 * 
 * Created on November 14, 2012, 4:15 PM
 */

#include "Page.h"

Page::Page(string title, string text, string author, string id, string date) {
    setTitle(title);
    setText(text);
    setAuthor(author);
    setId(id);
    setDate(date);
}

Page::Page(const Page& orig) {
}

Page::~Page() {
}

string Page::getAuthor()  {
    return author;
}

void Page::setAuthor(string author) {
    this->author = author;
}

//string Page::getDate()  {
//    return date;
//}
//
void Page::setDate(string date) {
    this->date = date;
}

string Page::getText()  {
    return text;
}

void Page::setText(string text) {
    this->text = text;
}

string Page::getTitle()  {
    return title;
}

void Page::setTitle(string title) {
    this->title = title;
}

string Page::getId()
{
	return id;
}

void Page::setId(string id)
{
	this->id = id;
}
