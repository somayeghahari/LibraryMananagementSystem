/*
 * student.h
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "QueueLL.h"
#include "BookHandler.h"
#include "Book.h"
#include <bits/stdc++.h>
#include <vector>

/**
 * Class book shows all the functions and members of a student
 */
class student {
public:
	/**
	 * constructor function
	 */
	student(int i , std::string n);
	/**
	 * constructor function
	 */
	student();
	/**
	 * destructor function
	 */
	virtual ~student();
	/**
	 * function returns queue of the borrowed books
	 * @return queue of the borrowed books
	 */
	queueLL<book>* getBorrowedBooks() const;
	/**
	 * function returns student id
	 * @return student id
	 */
	int getId() const;
	/**
	 * function sets student id
	 * @param student id
	 */
	void setId(int id);
	/**
	 * function returns student name
	 * @return student name
	 */
	const std::string& getName() const;
	/**
	 * function sets student name
	 * @param student name
	 */
	void setName(const std::string &name);
	/**
	 * function adds a book to the queue of the borrowed books
	 * @param item: pointer to the book
	 */
	void addBorrowedBook(book * item);
	/**
	 * function removes the first book of the borrowed queue
	 */
	void removeBorrowedBook();
	/**
	 * function removes the book at location index of the borrowed queue
	 */
	void removeBorrowedBookAtindex(int index);
	/**
	 * function overloads operator <<
	 * @param out: output stream
	 * @param st: student object
	 * @return
	 */
    friend std::ostream& operator<< (std::ostream &out, const student &st);
	/**
	 * function overloads operator !=
	 * @param out: output stream
	 * @param st: student object
	 * @return
	 */
    friend bool operator!=(const student & s1, const student & s2);
    /**
	 * function to parse line from file
	 * @param line: line that is read from file
	 * @return true, if parse is successful
	 */
	bool parseLine( std::string& line, BookHandler & books);
	/**
	 * function to create line for file
	 * @param line: line that is supposed to write to file
	 */
	void createLine( std::string& line);

private:
    /**
     * student id
     */
	int id;
	/**
	 * student name
	 */
	std::string name;
	/**
	 * queue of borrowed books
	 */
	queueLL<book> *borrowedBooks;
};

#endif /* STUDENT_H_ */
