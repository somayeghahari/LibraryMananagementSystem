/*
 * student.cpp
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#include "Student.h"


student::student( int i , std::string n) {
	id = i;
	name =  n;
	borrowedBooks = new queueLL<book>();
}

student::student( ) {
	id = 0;
	name =  " ";
	borrowedBooks = new queueLL<book>();
}

student::~student() {
	delete(borrowedBooks);
}

queueLL<book>* student::getBorrowedBooks() const {
	return borrowedBooks;
}

void student::addBorrowedBook(book * item){
	borrowedBooks->add(item);
}
void student::removeBorrowedBook() {
	borrowedBooks->remove();
}

void student::removeBorrowedBookAtindex(int index) {
	borrowedBooks->removeAtIndex(index);
}

//void student::setBorrowedBooks(const queueLL<book> *&borrowedBooks =
//		new queueLL<book>()) {
//	this->borrowedBooks = borrowedBooks;
//}

int student::getId() const {
	return id;
}

void student::setId(int id) {
	this->id = id;
}

const std::string& student::getName() const {
	return name;
}

void student::setName(const std::string &name) {
	this->name = name;
}

std::ostream& operator<< (std::ostream &out, const student &st){
	if(st.borrowedBooks->getSize()>0){
		return out <<"STUDENT id="<< st.id << " name=" <<st.name <<
				" {list of borrowed books:\n"<<*(st.borrowedBooks)<<"}\n";
	}
	else{
		return out <<"STUDENT id="<< st.id << " name=" <<st.name << " , student did not borrow a book\n ";
	}
}

bool operator<(const student & s1, const student & s2){
	if(s1.getId()<s2.getId())
		return true;
	else
		return false;
}

bool student::parseLine(std::string &line, BookHandler & books) {
	bool result = false;

    std::stringstream check1(line);
    std::string intermediate;

    if(std::getline(check1, intermediate, ',')){//id

		id =  std::stoi(intermediate);
			if(std::getline(check1, intermediate, ',')){//name
			name = intermediate;
			result = true;
			std::vector <std::string> tokens;
			while(getline(check1, intermediate, '*')){//borrowedbooks
				tokens.push_back(intermediate);
			}
			for(int i = 0; i < tokens.size(); i++){
				book * b = new book();
				b->parseLine(tokens[i]);
				book * fBook = books.findBook(*b);
				if(fBook== NULL){
					std::cout<<"BOOK ID NOT FOUND!\n";
				}
				borrowedBooks->add(fBook);
				delete(b);
			}
		}
    }
	return result;
}

void student::createLine(std::string &line) {

		line = std::to_string(id) + "," + name + "," ;
		for(int i=0;i<borrowedBooks->getSize();i++){
			std::string s;
			borrowedBooks->atIndex(i)->data->createLine(s);
			line.append(s);
			line.append("*");
		}
}
