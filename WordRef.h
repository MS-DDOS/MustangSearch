/* 
 * File:   WordRef.h
 * Author: carter
 *
 * Created on November 14, 2012, 4:23 PM
 */

#ifndef WORDREF_H
#define	WORDREF_H
#include "Page.h"
#include "AvlTree.h"
#include <cstdlib>
#include <sstream>

class WordRef {
public:
    WordRef(string);
    WordRef(const WordRef& orig);
    virtual ~WordRef();
    void insertPage(int, Page * &);
    void insertPage(Page * &);
    Page * findPage(int);
    int calculateTF(string, Page *);
    int calculateDF();
    bool doesExist(Page *);
private:
    string word;
    AvlTree<double, Page *> * pages;
    

};



#endif	/* WORDREF_H */

