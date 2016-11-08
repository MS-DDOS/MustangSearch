/*
 * AvlTree.h
 *
 *  Created on: Nov 8, 2012
 *      Author: tyler
 */
#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <iostream>
#include "AvlNode.h"
#include "Dictionary.h"

template<typename Key, typename E>
class AvlTree : public Dictionary<Key, E> {
private:
    AvlNode<Key, E> * root;
    int numDocs;
    bool exist;

    void printTree(AvlNode<Key, E> * &t) {
        if (t != NULL) {
            printTree(t->left);
            std::cout << t->getVal();
            printTree(t->right);
        }
    }

    E findElm(const Key& k, AvlNode<Key, E> * t) {
        while (t != NULL) {
            if(k == t->getKey())
            	return t->getVal();
            else if(k < t->getKey())
                t = t->left;
            else
                t = t->right;
            exist = true;
        }
        std::cout << "Didn't find the node" << std::endl;
        	exist = false;
        E e;
        return e;
    }

    E elementAt(AvlNode<Key, E> * t) {
        return t == NULL ? NULL : t->getVal();
    }

    void rotateWithLeftChild(AvlNode<Key, E> * &t) //c1
    {
        AvlNode<Key, E> * t2 = t->left;
        t->left = t2->right;
        t2->right = t;
        t2->setHeight(max(height(t2->left), height(t2->right)) + 1);
        t->setHeight(max(height(t->left), t2->getHeight()) + 1);
    }

    void rotateWithRightChild(AvlNode<Key, E> * &t)//c4
    {
        AvlNode<Key, E> * t2 = t->right;
        t->right = t2->left;
        t2->left = t;
        t->setHeight(max(height(t->left), height(t->right)) + 1);
        t2->setHeight(max(height(t2->right), t->getHeight()) + 1);
    }

    void doubleWithRightChild(AvlNode<Key, E> * &t)//c3
    {
        rotateWithLeftChild(t->right);
        rotateWithRightChild(t);
    }

    void doubleWithLeftChild(AvlNode<Key, E> * &t) //c2
    {
        rotateWithRightChild(t->left);
        rotateWithLeftChild(t);
    }

    int max(int lhs, int rhs) {
        return lhs > rhs ? lhs : rhs;
    }

    int height(AvlNode<Key, E> * node) {
        if(node == NULL)
            return 0;
        return node->getHeight();
    }

    void insert(Key k, E val, AvlNode<Key, E> * &t) {
        if (t == NULL)
        {
        	t = new AvlNode<Key, E>(k, val, NULL, NULL);
        }
        else if (k < t->getKey()) {
            insert(k, val, t->left);
            if ((height(t->left) - height(t->right)) == 2) {
                if (k < t->left->getKey())
                    rotateWithLeftChild(t); //c1
                else
                    doubleWithLeftChild(t); //c2
            }
        }
        else if (t->getKey() < k) {
            insert(k, val, t->right);
            if ((height(t->right) - height(t->left)) == 2) {
                if (t->right->getKey() < k)
                    rotateWithRightChild(t); //c4
                else
                    doubleWithRightChild(t); // c3
            }
        }
        else
        	t->setHeight(max(height(t->left), height(t->right)) + 1);
    }

public:

    AvlTree() {
        root = NULL;
        numDocs = 0;
    }

    virtual ~AvlTree() {
    }

    void clear() {
    }

    void insert(const Key& k, const E& val) {
        insert(k,val, root);
        numDocs++;
    }

    E remove(const Key& k) {
    	E e;
    	return e;
    }

    E removeAny() {
    	E e;
    	return e;
    }

    E find(const Key& k){
        return findElm(k,root);
    }

    int size() {
        return numDocs;
    }

    void printTheTree() {
        printTree(root);
    };

    E getRoot()
    {
        return root->getVal();
    }

    bool doesExist(const Key& k){
    	findElm(k,root);
    	if(exist)
    		return true;
    	else
    	{
    		exist = true;
    		return false;
    	}
    }
};

#endif /* AVLTREE_H_ */
