/*
 * BookHandler.h
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#ifndef BOOKHANDLER_H_
#define BOOKHANDLER_H_

#include "Book.h"
#include "QueueLL.h"
#include <fstream>

/**
 * Class handles the list of the books
 */
class BookHandler {
public:
	/**
	 * constructor function
	 */
	BookHandler();
	/**
	 * destructor function
	 */
	virtual ~BookHandler();
	/**
	 * function to add a book to the list of the books
	 * @param name: book name
	 * @param authName: author name of the book
	 */
	void addBook(std::string name, std::string authName);
	/**
	 * function to add a book to the list of the books
	 * @param temp: book object
	 */
	void addBook(book * temp);
	/**
	 * function to print the list of the books
	 */
	void print();
	/**
	 * function to find id of the book at location index of the books list
	 * @param index
	 * @return: pointer to the found book
	 */
	book * findBookId(int index) ;
	/**
	 * function to find book object among the books list
	 * @param temp book object
	 * @return: pointer to the found book
	 */
	book * findBook(book & temp) ;
	/**
	 * function to make a list of the borrowed books between all the books in the list
	 * @param result: string list of the borrowed books
	 * @param borrowedBooksSize: size of the string list of the borrowed books
	 */
	void borrowedBooksStrList(std::string * result, int & borrowedBooksSize);
	/**
	 * function to return size of the books list
	 * @return
	 */
	int getSize();
	/**
	 * function to print the list of the books to the file
	 */
	void printFile(std::ofstream& ouFile);


private:
	/**
	 * list of the books is kept in a queue
	 */
	queueLL<book> * booksList;

};

#endif /* BOOKHANDLER_H_ */
