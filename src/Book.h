/*
 * book.h
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <ctime>
#include "QueueLL.h"
#include <cstring>
#include <time.h>
#include <bits/stdc++.h>
#include <vector>

static int BOOK_COUNT=0;
const int BORROW_TIME = 2;

/**
 * Class book shows all the functions and members of a book
 */
class book {
public:
	/**
	 * constructor function
	 */
	book();
	/**
	 * constructor function
	 * @param name: book name
	 * @param authName: author name
	 */
	book(std::string name, std::string authName);
	/**
	 * destructor function
	 */
	virtual ~book();
	/**
	 * function returns the name of the author
	 * @return the name of the author
	 */
	const std::string& getAuthorName() const;
	/**
	 * function sets the name of the author
	 * @param authorName: the name of the author
	 */
	void setAuthorName(const std::string &authorName);
	/**
	 * function shows if the books is borrowed or not
	 * @return true, if the book is borrowed. false, if the book is not borrowed
	 */
	bool isBorrowed() const;
	/**
	 * function sets borrowed
	 * @param borrowed: shows if book is borrowed or not
	 */
	void setBorrowed(bool borrowed);
	/**
	 * function returns the due time
	 * @return the due time
	 */
	const tm getDueTime() const;
	/**
	 * function sets the due time
	 */
	void setDueTime();
	/**
	 * function returns the book id
	 * @return the book id
	 */
	int getId() const;
	/**
	 * function returns the book name
	 * @return the book name
	 */
	const std::string& getName() const;
	/**
	 * function sets the book name
	 * @param name:the book name
	 */
	void setName(const std::string &name);
	/**
	 * function converts the book object to string
	 * @param out: the output string
	 */
	void toString (std::string & out);
	/**
	 * function overloads operator <<
	 * @param out: output stream
	 * @param b: book object
	 * @return
	 */
    friend std::ostream& operator<< (std::ostream &out, const book &b);
    /**
     * function overloads operator != (not equal)
     * @param b1: first book object
     * @param b2: second book object
     * @return
     */
    friend bool operator!=(const book & b1, const book & b2);
    /**
     * overload operator <
     * @param b1 first book object
     * @param b2 first book object
     * @return true, if due time b1 is smaller than due time b2
     */
    friend bool operator<( book & b1,  book & b2);

	/**
	 * function to borrow book
	 * @param studentId id of student
	 * @return true, if book is borrowed to studentId.
	 * false, if book is not borrowed and studentIf is added to waitingStudentId
	 */
	bool borrowBook(int * studentId);
	/**
	 * function to return book
	 * @return  0 		 if book is returned.
	 *		   -1 		 if book can not be returned
	 *		   studentid if book is returned and borrowed by first student in waiting list
	 */
	int returnBook();
	/**
	 * function returns id of the student that borrowed the book student
	 * @return id of the student
	 */
	int getBorrowedByStudent() const;
	/**
	 * function to parse line from file
	 * @param line: line that is read from file
	 * @return true, if parse is successful
	 */
	bool parseLine( std::string& line);
	/**
	 * function to create line for file
	 * @param line: line that is supposed to write to file
	 */
	void createLine( std::string& line);

private:
	/**
	 * id of the book
	 */
	int id;
	/**
	 * name of the book
	 */
	std::string name;
	/**
	 * author name of the book
	 */
	std::string authorName;
	/**
	 * if book is borrowed or not
	 */
	bool borrowed;
	/**
	 * student id that borrowed the book
	 */
	int borrowedByStudent;
	/**
	 * due time of returning the book
	 */
	tm due_time ;
	/**
	 * waiting list of students' id who want to borrow the book
	 */
	queueLL<int> * waitingStudentId;

};

#endif /* BOOK_H_ */
