/*
 * StudentHandler.cpp
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#include "StudentHandler.h"

StudentHandler::StudentHandler() {
	studentTree = new BinaryTree<student>();
}

StudentHandler::~StudentHandler() {
	delete(studentTree);
}

void StudentHandler::addStudent(int id, std::string name) {
	student * temp = new student(id, name);
	studentTree->insertNode(temp);
}

void StudentHandler::addStudent(student * temp) {
	studentTree->insertNode(temp);
}

student* StudentHandler::find(const Node<student> * node,int id){
    if (node == NULL)
        return NULL;

    if (node->data->getId() == id)
        return node->data;

    student * resultL = find(node->left, id);
    if(resultL != NULL) return resultL;

    return find(node->right, id);
}

student* StudentHandler::findStudentId(int id) {

	if(studentTree->getRoot() == 0){
//		std::cout<<"No student is added to the tree";
		return NULL;
	}
	else {
		return find(studentTree->getRoot(), id);
	}
}

void StudentHandler::inorder(const Node<student> * tmp){
		if(tmp->left!= 0)
			inorder(tmp->left);
		std::cout<<*(tmp->data) << "\n";
		if(tmp->right!= 0)
			inorder(tmp->right);
	}
void StudentHandler::print() {
	if(studentTree->getRoot() == 0){
		std::cout<<"No student is added to the tree";
	}
	else {
		 inorder(studentTree->getRoot());
	}
}

void StudentHandler::inorderFile(const Node<student> * tmp, std::ofstream& ouFileStudent){
		if(tmp->left!= 0)
			inorderFile(tmp->left, ouFileStudent);
		std::string str;
		tmp->data->createLine(str);
		ouFileStudent<<str<<"\n";
		if(tmp->right!= 0)
			inorderFile(tmp->right, ouFileStudent);
	}
void StudentHandler::printFile(std::ofstream& ouFileStudent) {
	if(studentTree->getRoot() == 0){
		std::cout<<"No student is added to the tree";
	}
	else {
		inorderFile(studentTree->getRoot(),ouFileStudent);
	}
}
