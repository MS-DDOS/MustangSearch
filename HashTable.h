/* 
 * File:   HashTable.h
 * Author: Tyler Springer & Carter Dewey
 *
 * Created on November 12, 2012, 4:18 PM
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H
#include <cstdlib>
using namespace std;
// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#include "Dictionary.h"
#include "AvlTree.h"

// Dictionary implemented with a hash table

template <typename Key, typename E>
class hashdict : public Dictionary<Key, E> {
private:
    AvlTree<Key, E>* HT; // The hash table
    int M; // Size of HT
    int currcnt; // The current number of elements in HT
    Key EMPTYKEY; // User-supplied key value for an empty slot

    int p(Key K, int i) const // Probe using linear probing
    {
        return i;
    }

    int h(int x) const {
        return x % M;
    } // Poor hash function

    int h(char* x) const { // Hash function for character keys
        int i, sum;
        for (sum = 0, i = 0; x[i] != '\0'; i++)
        	sum += (int) x[i];
        return sum % M;
    }

    int h(string x) const { // Hash function for string keys
            int i, sum;
            for (sum = 0, i = 0; i < x.size(); i++)
            	sum += (int) x.at(i);
            return sum % M;
        }

    void hashInsert(const Key&, const E&);
    void hashInsertCollide(const Key&, const E&);
    E hashSearch(const Key&) const;
    E hashSearchCollide(const Key&) const;

public:

    hashdict(int sz, Key k) { // "k" defines an empty slot
        M = sz;
        EMPTYKEY = k;
        currcnt = 0;
        HT = new AvlTree<Key, E>[sz]; // Make HT of size sz
        for (int i = 0; i < M; i++)
            HT[i].insert(-1,""); // Initialize HT
    }

    ~hashdict() {
        delete HT;
    }

    // Find some record with key value "K"

    E find(const Key& k) {
        return hashSearchCollide(k);
    }

    int size() {
        return currcnt;
    } // Number stored in table

    // Insert element "it" with Key "k" into the dictionary.

    void insert(const Key& k, const E& it) {
        hashInsertCollide(k, it);
        currcnt++;
    }
    // I took this code out of the book, it doesn't add anything

    // remove not implemented

    E remove(const Key& K) {
        return NULL;
    }

    E removeAny() { // Remove the first element
        /*
    	int i;
        for (i = 0; i < M; i++)
            if (HT[i]->getKey() != EMPTYKEY) {
                (HT[i]).setKey(EMPTYKEY);
                currcnt--;
                break;
            }
        return (HT[i]).value();
        */
    }

    void clear() { // Clear the dictionary
    	/*
        for (int i = 0; i < M; i++) (HT[i]).setKey(EMPTYKEY);
        currcnt = 0;
        */
    }
};


// Insert e into hash table HT

//template <typename Key, typename E>
//void hashdict<Key, E>::hashInsert(const Key& k, const E& e) {
//    int home; // Home position for e
//    int pos = home = h(k); // Init probe sequence
//    for (int i = 1; EMPTYKEY != (HT[pos]).key(); i++) {
//        pos = (home + p(k, i)) % M; // probe
//    }
//    KVpair<Key, E> temp(k, e);
//
//    HT[pos] = temp; 
//}

template <typename Key, typename E>
void hashdict<Key, E>::hashInsertCollide(const Key& k, const E& e) {
    int pos = h(k); // Init probe sequence
    HT[pos].insert(k,e);
}


template <typename Key, typename E>
E hashdict<Key, E>::hashSearchCollide(const Key& k) const {
    int home; // Home position for k
    int pos = h(k); // Initial position is home slot
    return HT[pos].find(k);
}

// Search for the record with Key K
template <typename Key, typename E>
E hashdict<Key, E>::hashSearch(const Key& k) const {
    int home; // Home position for k
    int pos = home = h(k); // Initial position is home slot
    for (int i = 1; (k != (HT[pos]).key()) &&
            (EMPTYKEY != (HT[pos]).key()); i++)
        pos = (home + p(k, i)) % M; // Next on probe sequence
    if (k == (HT[pos]).key()) // Found it
        return (HT[pos]).value();
    else return NULL; // k not in hash table
}
#endif	/* HASHTABLE_H */

