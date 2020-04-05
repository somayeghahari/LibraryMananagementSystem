//============================================================================
// Name        : LibraryMananagementSystem.cpp
// Author      : SomayeGhahari
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "StudentHandler.h"
#include "BookHandler.h"
#include <fstream>
using namespace std;

StudentHandler students;
BookHandler books;
ifstream inFileStudent;
ifstream inFileBook;
ofstream ouFileStudent;
ofstream ouFileBook;
string fileNameStudents;
string fileNameBooks;

/**
 * Generic funcion to swap two items in a list
 * @tparam T
 * @tparam T
 * @param a : first items
 * @param b : second item
 */
template <typename T>
void swap(T* a, T* b)
{
    T t = *a;
    *a = *b;
    *b = t;
}
/**
 * Generic function to partition the list of items around a pivot
 * @tparam T
 * @tparam T
 * @param arrList: list of items
 * @param start: start index
 * @param end: end index
 * @return: index of the pivot
 */
template <typename T>
int partition(T * arrList,int start,int end)
{
	   T pivot = arrList[end]; // pivot
	    int i = (start - 1); // Index of smaller element

	    for (int j = start; j <= end - 1; j++)
	    {
	        // If current element is smaller than the pivot
	        if (arrList[j] < pivot)
	        {
	            i++; // increment index of smaller element
	            swap(&arrList[i], &arrList[j]);
	        }
	    }
	    swap(&arrList[i + 1], &arrList[end]);
	    return (i + 1);
 }
/**
 * Generic recursive function to sort list of items
 *  based on the QUICK SORT method
 * @tparam T
 * @tparam T
 * @param arrList: list of items
 * @param start: start index
 * @param end: end index
 */
template <typename T>
 void Quicksort(T * arrList, int start, int end)
 {
    if(start<end)
    {
         int index=partition(arrList, start, end);
             Quicksort(arrList, start, index - 1);
             Quicksort(arrList, index + 1, end);
    }
}
/**
 * function to read students' list at the beginning from the students's file
 * @param fileNameStudents: name of student's file
 */
void readStudentsFromFile(){
	if(fileNameStudents!=""){
		inFileStudent.open(fileNameStudents);
		if(inFileStudent.fail()){
			cout<<"\nSTUDENT FILE DOES NOT EXIST\n\n";
//			goodbye();
//			return 0;
		}
		else{
			while(!inFileStudent.eof())
			{
				string tStr;
				student * stdnt = new student();
				getline(inFileStudent, tStr);
				if(tStr.size()>1 && tStr.at(0)!='#'){
	//				cout << tStr ;
					stdnt->parseLine(tStr, books);
					students.addStudent(stdnt);
				}

			}
		}
		inFileStudent.close();
	}
}
/**
 * function to read books' list at the beginning from  the book's file
 * @param fileNameBooks: name of book's file
 */
void readBooksFromFile(){
	if(fileNameBooks!=""){
		inFileBook.open(fileNameBooks);
		if(inFileBook.fail()){
			cout<<"\nBOOK FILE DOES NOT EXIST\n\n";
//			goodbye();
//			return 0;
		}
		else{
			while(!inFileBook.eof())
			{
				string tStr;
				book * bk = new book();
				getline(inFileBook, tStr);
				if(tStr.size()>1 && tStr.at(0)!='#'){
	//				cout << tStr ;
					bk->addBOOK_COUNT();
					bk->parseLine(tStr);
					books.addBook(bk);
				}

			}
		}
		inFileBook.close();
	}
}
/**
 * function to write students' list to the student's file
 * @param fileName: name of the student's file
 */
void writeStudentsToFile(){

	remove( fileNameStudents.c_str() );
	ouFileStudent.open(fileNameStudents, std::fstream::in | std::fstream::out | std::fstream::app);
	students.printFile( ouFileStudent);
	ouFileStudent.close();
}
/**
 * function to write books' list to the book's file
 * @param fileName: name of the book's file
 */
void writeBooksToFile(){

	remove( fileNameBooks.c_str() );
	ouFileBook.open(fileNameBooks, std::fstream::in | std::fstream::out | std::fstream::app);
	books.printFile( ouFileBook);
	ouFileBook.close();
}

/**
 * function to print intro message
 */
void intro(){
	//system("clear");
	cout<<"******* THE LIBRARY MANAGEMENT SYSTEM ******* ";
    cout<<"\n\n******* AUTHOR : YOUR NAME ******* \n";
}
/**
 * function to print goodbye message
 */
void goodbye(){
	//system("clear");
	cout<<"******* THANKS FOR USING THE LIBRARY MANAGEMENT SYSTEM ******* ";
    cout<<"\n\n******* AUTHOR : YOUR NAME ******* \n";
}
/**
 * function to print initial menu
 */
void menu1(){
	cout<<"\n1. ADMINISTRATOR";
	cout<<"\n2. STUDENT";
	cout<<"\n9. EXIT";
	cout<<"\n\nENTER YOUR CHOISE: ";
}
/**
 * function to handle and show administrator's menu
 */
void menuAdmin(){
	int choise = 0;
	int id=0;
	std::string name;
	std::string authName;

	do{
		cout<<"\n1. ADD STUDENT";
		cout<<"\n2. PRINT STUDENTS LIST";
		cout<<"\n3. ADD BOOK";
		cout<<"\n4. PRINT BOOKS LIST";
		cout<<"\n5. PRINT BORROWED BOOKS (SORT BASED ON DUE DATE)";
		cout<<"\n9. RETURN TO PREVIOUS MENU";
		cout<<"\n\nENTER YOUR CHOISE: ";
		cin >> choise;
		switch(choise){
		case 1:
		{
			cout<<"ENTER STUDENT ID:";
			cin>>id;
			while(cin.fail()) {
				std::cout << "ID IS NOT VALID\n";
				std::cin.clear();
				std::cin.ignore(256,'\n');
				cout<<"RE-ENTER STUDENT ID:";
				cin>>id;
			}
			while ( students.findStudentId(id) ){
				std::cout << "ANOTHER STUDENT HAS SAME ID, \n";
				cout<<"RE-ENTER STUDENT ID:";
				cin>>id;
			}
			cout<<"ENTER STUDENT NAME:";
			cin>>name;
			student * stdnt = new student(id, name);
			students.addStudent(stdnt);
//			string temp;
//			stdnt->createLine(temp);
//			ouFileStudent<<temp;
			break;
		}
		case 2:
		{
			students.print();
			break;
		}
		case 3:
		{
			cout<<"ENTER BOOK NAME:";
			cin>>name;
			cout<<"ENTER AUTHOR NAME:";
			cin>>authName;
			books.addBook( name, authName);
			break;
		}
		case 4:
		{
			books.print();
			break;
		}
		case 5:
		{
			string  borrowedBooks[books.getSize()];
			int borrowedBooksSize = 0;
			books.borrowedBooksStrList(borrowedBooks,borrowedBooksSize);
			if(borrowedBooksSize==0){
				cout<<"NO BOOK IS BORROWED\n";
			}
			else{
				Quicksort(borrowedBooks, 0, borrowedBooksSize-1);
				for(int j = 0;j<borrowedBooksSize;j++){
					std::cout<<borrowedBooks[j].substr(11);
				}
			}
			break;
		}
		case 9:
			break;
		default:
			cout<<"Unknown input";
			break;
		}
	}while(choise!=9);
	writeBooksToFile();
	writeStudentsToFile();
}
/**
 * function to handle and show student's meni
 */
void menuStudent(){
	int choise = 0;
	student * currentStudent = NULL;
	int id=0;
	std::string name;
	std::string authName;
	book * fBook =NULL;

	do{
		cout<<"ENTER YOUR ID:";
		cin >>id;
		while(cin.fail()) {
			std::cout << "ID IS NOT VALID\n";
			std::cin.clear();
			std::cin.ignore(256,'\n');
			cout<<"RE-ENTER SYUDENT ID:";
			cin>>id;
		}
		currentStudent = students.findStudentId(id);
		if(currentStudent== NULL){
			cout<<"STUDENT ID NOT FOUND!\n";
		}
	}while(currentStudent== NULL);

	do{
		cout<<"\n1. BORROW A BOOK";
		cout<<"\n2. RETURN A BOOK";
		cout<<"\n3. PRINT BORROWED BOOKS";
		cout<<"\n5. PRINT BOOKS LIST";
		cout<<"\n9. RETURN TO PREVIOUS MENU";
		cout<<"\n\nENTER YOUR CHOISE: ";
		cin >> choise;
		switch(choise){
		case 1:
		{
			fBook =NULL;
			do{
				cout<<"ENTER BOOK ID TO BORROW:";
				cin>>id;
				while(cin.fail()) {
					std::cout << "ID IS NOT VALID\n";
					std::cin.clear();
					std::cin.ignore(256,'\n');
					cout<<"RE-ENTER BOOK ID:";
					cin>>id;
				}
				fBook = books.findBookId(id);
				if(fBook== NULL){
					cout<<"BOOK ID NOT FOUND!\n";
				}
			}while(fBook== NULL);
			int *stdId = new int(currentStudent->getId());
			if(fBook->borrowBook(stdId)){
				currentStudent->addBorrowedBook(fBook);
				cout<<"STUDENT "<<currentStudent->getId()<<" BORROWS BOOK "<<id<<"\n";
			}
			break;
		}
		case 2:
		{
			fBook =NULL;
			do{
				cout<<"ENTER BOOK ID TO RETURN:";
				cin>>id;
				while(cin.fail()) {
					std::cout << "ID IS NOT VALID\n";
					std::cin.clear();
					std::cin.ignore(256,'\n');
					cout<<"RE-ENTER BOOK ID:";
					cin>>id;
				}
				fBook = books.findBookId(id);
				if(fBook== NULL){
					cout<<"BOOK ID NOT FOUND IN BOOK LIST!";
				}
			}while(fBook== NULL);
			int xBookId = currentStudent->getBorrowedBooks()->find(*fBook);
			if(xBookId!=-1){
				int sid = fBook->returnBook();
				if(sid > -1){
					currentStudent->removeBorrowedBookAtindex(xBookId);
				}
				if(sid > 0 ){
					student * tempStudent = students.findStudentId(sid);

					tempStudent->addBorrowedBook(fBook);
					cout<<"STUDENT "<<tempStudent->getId()<<" BORROWS BOOK "<<id<<"\n";
				}
			}
			break;
		}
		case 3:
		{
			cout<<*(currentStudent->getBorrowedBooks());
			break;
		}
		case 5:
		{
			books.print();
			break;
		}
		case 9:
			break;
		default:
			cout<<"Unknown input";
			break;
		}

	}while(choise!=9);
	writeBooksToFile();
	writeStudentsToFile();
}
/**
 * main function that handles whole program
 * @return
 */
int main(int argc, char* argv[]) {
	intro();

	int choise = 0;
//	string fileNameStudents;
//	string fileNameBooks;

	if(argc == 3){
		fileNameStudents = argv[1];
		fileNameBooks = argv[2];
	}
	else{
		fileNameStudents = "student.txt";
		fileNameBooks = "book.txt";
	}

	readBooksFromFile();
	readStudentsFromFile();

	do{
		menu1();
		cin >> choise;
		while(cin.fail()) {
			std::cout << "YOUR COISE IS NOT VALID\n";
			std::cin.clear();
			std::cin.ignore(256,'\n');
			cout<<"RE-ENTER YOUR CHOISE:";
			cin>>choise;
		}
		switch(choise){
		case 1:
			menuAdmin();
			break;
		case 2:
			menuStudent();
			break;
		case 9 :
			 goodbye();
			 break;

		}
	}while(choise!=9);
	writeBooksToFile();
	writeStudentsToFile();
	return 0;
}
