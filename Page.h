/* 
 * File:   Page.h
 * Author: carter
 *
 * Created on November 14, 2012, 4:15 PM
 */

#ifndef PAGE_H
#define	PAGE_H
#include "TimeStamp.h"
#include <cstdlib>
using namespace std;

class Page {
public:
    
    Page(string, string, string, string, string);
    Page(const Page& orig);
    virtual ~Page();
    void setTitle(string);
    void setText(string);
    void setAuthor(string);
    void setDate(string);
    void setId(string);
    string getTitle();
    string getText();
    string getAuthor();
    string getDate();
    string getId();
private:
    string title;
    string text;
    string author;
    string date;
    string id;
};

#endif	/* PAGE_H */

