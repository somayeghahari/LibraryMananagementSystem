/*
 * StudentHandler.h
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#ifndef STUDENTHANDLER_H_
#define STUDENTHANDLER_H_
#include "BinaryTree.h"
#include "Student.h"
#include <fstream>


/**
 * Class handles the list of the students
 */
class StudentHandler {
public:
	/**
	 * constructor function
	 */
	StudentHandler();
	/**
	 * destructor function
	 */
	virtual ~StudentHandler();
	/**
	 * function to add a student to the list of the students
	 * @param id: student id
	 * @param name: student name
	 */
	void addStudent(int id, std::string name);
	/**
	 * function to add a student to the list of the students
	 * @param temp: student object
	 */
	void addStudent(student * temp);

	/**
	 * function to find id of the student at location index of the books list
	 * @param index
	 * @return: pointer to the found student
	 */
	student* findStudentId(int index);
	/**
	 * function to print the list of the students
	 */
	void print();
	/**
	 * function to print the list of the students to the file
	 */
	void printFile(std::ofstream& ouFileStudent);

private:
	/**
	 * list of the students is kept in a queue
	 */
	BinaryTree<student> *studentTree;
	/**
	 * function to find node
	 * @param node
	 * @param id
	 * @return
	 */
	student* find(const Node<student> * node,int id);
	/**
	 * function to traverse binary tree of the list of the students inorder
	 * @param tmp
	 */
	void inorder(const Node<student> * tmp);
	/**
	 * function to traverse binary tree of the list of the students inorder
	 * and write in file
	 * @param tmp
	 */
	void inorderFile(const Node<student> * tmp, std::ofstream& ouFileStudent);


};

#endif /* STUDENTHANDLER_H_ */
