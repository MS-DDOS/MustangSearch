/*
 * AvlNode.h
 *
 *  Created on: Nov 8, 2012
 *      Author: tyler
 */

#ifndef AVLNODE_H_
#define AVLNODE_H_

template <typename Key, typename E>
class AvlTree;

template<typename Key, typename E> class AvlNode {
    friend class AvlTree<Key,E>;

public:

    AvlNode(Key k, E data, AvlNode<Key, E> * lst, AvlNode<Key, E> * rst, int h = 0) {
    	key_ = k;
        val = data;
        left = lst;
        right = rst;
        height = h;
    }

    int getHeight() {
        return height;
    }

    void setHeight(int h) {
        height = h;
    }

    E getVal() {
        return val;
    }

    Key getKey() {
    	return key_;
    }
    //AvlNode<E> * getLeft() {return left;}
    //AvlNode<E> * getRight() {return right;}
    //void setLeft(AvlNode<E> * lst) {left = lst;}
    //void setRight(AvlNode<E> * rst) {right = rst;}
    //virtual ~AvlNode();
private:
    Key key_;
    E val;
    AvlNode<Key, E> * left;
    AvlNode<Key, E> * right;
    int height;





};

#endif /* AVLNODE_H_ */
