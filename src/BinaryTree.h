/*
 * BinaryTree.h
 *
 *  Created on: Mar 26, 2020
 *      Author: somayeghahari
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "QueueLL.h"

/**
 * Generic class Node is the node of the binary tree
 * @tparam Type
 */
template<class Type>
class Node {
public:
	/**
	 * constructor function
	 * @param data
	 */
	Node(Type * data){
		this->data = data;
		left = right = 0;
	}
	/**
	 * constructor function
	 */
	Node(){
		this->data = 0;
		left = right = 0;
	}
	/**
	 * data of Node
	 */
	Type * data;
	/**
	 * left pointer of Node
	 */
	Node * left;
	/**
	 * right pointer of Node
	 */
	Node * right;
};

/**
 * Generic class BinaryTree defines the binary tree
 * @tparam Type
 */
template<class Type>
class BinaryTree {
public:
	/**
	 * constructor function
	 */
	BinaryTree(){
		root = 0;
	}
	/**
	 * destructor function deletes the nodes in the tree and
	 * destroys the tree
	 */
	virtual ~BinaryTree(){
		destroy(root);
	}
	/**
	 * function to insert a new node to the binary tree
	 * @param data: generic data of new node
	 */
	void insertNode(Type * data) {
		Node <Type> * temp = new Node<Type>(data);

		if(root == 0){
			root = temp;
			return;
		}
		else {
			queueLL<Node <Type>> * queue = new queueLL<Node <Type>>();
			//Add root to the queue
			queue->add(root);

			while(true) {
				Node<Type> * n = queue->remove();
				if(n!=0){
					if(n->left != 0 && n->right != 0) {
						queue->add(n->left);
						queue->add(n->right);
					}
					else {
						if(n->left == 0) {
						 n->left = temp;
						 queue->add(n->left);
						}
						//If node has left child but no right child, make newNode as right child
						else {
						 n->right = temp;
						 queue->add(n->right);
						}
						break;
					}
					//delete(n);
				}
			}
			delete(queue);
		}
	}
	/**
	 * function to return root of the binary tree
	 * @return  root of the binary tree
	 */
	const Node<Type>* getRoot() const {
		return root;
	}

private:
	/**
	 * function to destroy the binary tree
	 * @param tmp
	 */
	void destroy(Node<Type> * tmp){
		if (tmp != NULL)	{
			destroy(tmp->left);
			tmp->left = NULL;
			destroy(tmp->right);
			tmp->right = NULL;
			delete tmp;
		}
	}

	/**
	 * root of the the binary tree
	 */
	Node<Type> * root;

};

#endif /* BINARYSEARCHTREE_H_ */
