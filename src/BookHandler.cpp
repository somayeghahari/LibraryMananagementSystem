/*
 * BookHandler.cpp
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#include "BookHandler.h"

BookHandler::BookHandler() {
	booksList = new queueLL<book>();
}

BookHandler::~BookHandler() {
	delete(booksList);
}

void BookHandler::addBook(std::string name, std::string authName) {
	book * temp = new book(name, authName);
	booksList->add(temp);
}
void BookHandler::addBook(book * temp) {
	booksList->add(temp);
}

void BookHandler::print() {
	if(booksList->getSize() == 0){
		std::cout<<"No student is added to the tree";
	}
	else {
		std::cout<<*booksList;
	}
}
void BookHandler::printFile(std::ofstream& ouFile) {
	book ** list = booksList->nodeList();
	for(int i=0; i<booksList->getSize(); i++){
		std::string str;
		list[i]->createLine(str);
		ouFile<<str<<"\n";
	}
}
book * BookHandler::findBookId(int index) {
	book ** list = booksList->nodeList();
	for(int i=0; i<booksList->getSize(); i++){
		if(list[i]->getId()==index){
			return list[i];
		}
	}
	return NULL;
}
book * BookHandler::findBook(book & temp) {
	book ** list = booksList->nodeList();
	for(int i=0; i<booksList->getSize(); i++){
		if(!(*list[i]!=temp)){
			return list[i];
		}
	}
	return NULL;
}

//void BookHandler::borrowedBooksQueue(queueLL<book> * result) {
//	book ** list = booksList->nodeList();
//	for(int i=0; i<booksList->getSize(); i++){
//		if(list[i]->isBorrowed()){
//			result->add(list[i]);
//		}
//	}
//}

void BookHandler::borrowedBooksStrList(std::string * result, int & borrowedBooksSize) {
	book ** list = booksList->nodeList();
	int c=0;
	for(int i=0; i<booksList->getSize(); i++){
		if(list[i]->isBorrowed()){
			std::string temp ;
			list[i]->toString(temp);
			result[c++]=temp;
		}
	}
	borrowedBooksSize = c;
}

int BookHandler::getSize() {
	return booksList->getSize();
}

