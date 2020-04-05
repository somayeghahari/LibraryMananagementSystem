/*
 * book.cpp
 *
 *  Created on: Mar 27, 2020
 *      Author: somayeghahari
 */

#include "Book.h"


book::book() {
	id = -1;
	name = " ";
	authorName = " ";
	borrowed = false;
	time_t now = time( NULL);
	due_time = *localtime( &now);
	waitingStudentId = new queueLL<int>();
	borrowedByStudent = -1;
}

book::book(std::string name, std::string authName) {
	id = ++BOOK_COUNT;
	this->name = name;
	this->authorName = authName;
	borrowed = false;
	time_t now = time( NULL);
	due_time = *localtime( &now);
	waitingStudentId = new queueLL<int>();
	borrowedByStudent = -1;
}


book::~book() {

}

const std::string& book::getAuthorName() const {
	return authorName;
}

void book::setAuthorName(const std::string &authorName) {
	this->authorName = authorName;
}


bool book::isBorrowed() const {
	return borrowed;
}

void book::setBorrowed(bool borrowed) {
	this->borrowed = borrowed;
}

const tm book::getDueTime() const {
	return due_time;
}

void book::setDueTime() {

     time_t now = time( NULL);

     due_time = *localtime( &now);

	 due_time.tm_hour += BORROW_TIME;
}

int book::getId() const {
	return id;
}

const std::string& book::getName() const {
	return name;
}

void book::setName(const std::string &name) {
	this->name = name;
}

int book::returnBook() {
	int returnValue = -1;

	if(borrowed == true){
		borrowedByStudent = -1;
		borrowed = false;
		if((waitingStudentId->getSize()) >0){
			int * studentId = waitingStudentId->remove();
			std::cout<<"BOOK IS RETUNED AND IS BORROWED BY FIRST STUDENT "
					<<*studentId<<" IN WAITING LIST\n";
			borrowBook(studentId);
			returnValue = *studentId;
		}
		else{
			std::cout<<"BOOK IS RETUNED\n";
			returnValue = 0;
		}
	}
	else{
		std::cout<<"BOOK IS NOT BORROWED AND CAN NOT BE RETURNED\n";
		returnValue = -1;
	}
	return  returnValue;
}
bool book::borrowBook(int * studentId) {
	bool returnValue = false;
	if( borrowed == true && borrowedByStudent == *studentId){
		std::cout<<"STUDENT "<<*studentId<<" ALREADY BORROWED THE BOOK\n";
	}
	else if( borrowed == true && waitingStudentId->find(*studentId) > -1  ){
			std::cout<<"STUDENT "<<*studentId<<" ALREADY IS IN WAITING LIST\n";
		}
	else if(borrowed == true){
		waitingStudentId->add(studentId);
		std::cout<<"STUDENT "<<*studentId<<" ADDED TO WAITING LIST\n";
	}
	else{
		borrowed = true;
		borrowedByStudent = *studentId;
		setDueTime();
		returnValue = true;
	}
	return  returnValue;
}
void book::toString (std::string & out){
	 std::string tmp= borrowed?"borrowed ":"not borrowed ";
	 time_t t = mktime(&due_time);
//	 std::string tmp2 = ctime(&t);
	 std::string tmp2 = std::to_string(t);
	 out = tmp2 +" id="+std::to_string(id) + " name="+
			name+ " author_name="+authorName+ " "+ tmp+"\n";
}

 std::ostream& operator<< (std::ostream &out, const book &b){
	 std::string tmp= b.borrowed?"borrowed ":"not borrowed ";
	 if(b.waitingStudentId->getSize()>0)
		 return out <<"BOOK id="<< b.id << " name=" << b.name << " author="
				 << b.authorName << " "<<tmp << " due date="
				 << b.due_time.tm_year<<"-"<< b.due_time.tm_mon<<"-"
				 << b.due_time.tm_mday<<" "<< b.due_time.tm_hour<<":"
				 << b.due_time.tm_min<< ":"<< b.due_time.tm_sec
				 <<" waiting students' id="<< *(b.waitingStudentId)<<"\n";
	 else{
		 if( b.borrowed)
			 return out <<"BOOK id="<< b.id << " name=" << b.name << " author="
					 << b.authorName << " "<< tmp << " due date="
					 << b.due_time.tm_year<<"-"<< b.due_time.tm_mon<<"-"
					 << b.due_time.tm_mday<<" "<< b.due_time.tm_hour<<":"
					 << b.due_time.tm_min<< ":"<< b.due_time.tm_sec <<"\n";
		 else
			 return out <<"BOOK id="<< b.id << " name=" << b.name << " author="
			 					 << b.authorName << " "<< tmp<<"\n";
	 }
}


bool operator!=(const book & b1, const book & b2){
	if(b1.id!=b2.id || b1.name!=b2.name || b1.authorName!=b2.authorName)
		return true;
	else
		return false;
}

bool operator<( book & b1,  book & b2){
	time_t t1 = mktime(&(b1.due_time));
	time_t t2 = mktime(&(b2.due_time));
	double diffSecs = difftime(t1, t2);
	if(diffSecs<0 )
		return true;
	else
		return false;
}




int book::getBorrowedByStudent() const {
	return borrowedByStudent;
}

bool book::parseLine(std::string &line) {

	bool result = false;

    std::stringstream check1(line);
    std::string intermediate;

    if(std::getline(check1, intermediate, ',')){//id
		id =  std::stoi(intermediate);
			if(std::getline(check1, intermediate, ',')){//name
				name = intermediate;
				if(std::getline(check1, intermediate, ',')){//author name
					authorName = intermediate;
					result = true;
					if(std::getline(check1, intermediate, ',')){//borrowed by student
						borrowed = true;
						borrowedByStudent =  std::stoi(intermediate);
						if(std::getline(check1, intermediate, '/')){//year
							due_time.tm_year =  std::stoi(intermediate);
							if(std::getline(check1, intermediate, '/')){//month
								due_time.tm_mon =  std::stoi(intermediate);
								if(std::getline(check1, intermediate, '-')){//day
									due_time.tm_mday =  std::stoi(intermediate);
									if(std::getline(check1, intermediate, ':')){//hour
										due_time.tm_hour =  std::stoi(intermediate);
										if(std::getline(check1, intermediate, ':')){//min
											due_time.tm_mon =  std::stoi(intermediate);
											if(std::getline(check1, intermediate, ',')){//sec
												due_time.tm_sec=  std::stoi(intermediate);
												if(std::getline(check1, intermediate, ',')){//waiting student id
													int * n = new int( std::stoi(intermediate) );
													waitingStudentId->add(n);

													std::vector <int> tokens;
													while(getline(check1, intermediate, ',')){
														tokens.push_back(std::stoi(intermediate));
													}
													for(int i = 0; i < tokens.size(); i++){
														int *temp = new int( tokens[i] );
														waitingStudentId->add(temp);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}

			}
    }
/*	char  cLine[line.size()+1];
	bool result = false;
	strcpy(cLine, line.c_str());
	char * tokenPtr = NULL;
	//get id
	tokenPtr = strtok (cLine,",");
	if (tokenPtr != NULL){
		id = atoi(tokenPtr);
		//get name
		tokenPtr = strtok (NULL, ",");
		if (tokenPtr != NULL){
			name = tokenPtr;
			//get author
			tokenPtr = strtok (NULL, ",");
			if (tokenPtr != NULL){
				authorName = tokenPtr;
				result = true;
				//borrowedByStudent
				tokenPtr = strtok (NULL, ",");
					if (tokenPtr != NULL){
						borrowed = true;
						borrowedByStudent = atoi(tokenPtr);
						//year
						tokenPtr = strtok (NULL, ",");
						if (tokenPtr != NULL){
							due_time.tm_year = atoi(tokenPtr);
							//month
							tokenPtr = strtok (NULL, "/");
							if (tokenPtr != NULL){
								due_time.tm_mon = atoi(tokenPtr);
								//day
								tokenPtr = strtok (NULL, "/");
								if (tokenPtr != NULL){
									due_time.tm_mday = atoi(tokenPtr);
									//hour
									tokenPtr = strtok (NULL, "-");
									if (tokenPtr != NULL){
										due_time.tm_hour = atoi(tokenPtr);
										//min
										tokenPtr = strtok (NULL, ":");
										if (tokenPtr != NULL){
											due_time.tm_min = atoi(tokenPtr);
											//sec
											tokenPtr = strtok (NULL, ":");
											if (tokenPtr != NULL){
												due_time.tm_sec = atoi(tokenPtr);
												//waiting student id
												tokenPtr = strtok (NULL, ",");
												if (tokenPtr != NULL){
													int i = atoi(tokenPtr);
													waitingStudentId->add(&i);
													tokenPtr = strtok (NULL, " ");
													while (tokenPtr != NULL){
														int i = atoi(tokenPtr);
														waitingStudentId->add(&i);
														tokenPtr = strtok (NULL, " ");
													}

												}//waiting student id
											}//sec
										}//min
									}//hour
								}//day
							}//month
						}//year
					}//borrowedByStudent
					else{
						borrowed = false;
						time_t now = time( NULL);
						due_time = *localtime( &now);
						borrowedByStudent = -1;
					}
			}//author
		}//name
	}//id
	*/
	return result;
}

void book::createLine(std::string &line) {
	if(borrowed == true){
		line = std::to_string(id) + "," + name + "," + authorName + "," +
				std::to_string(borrowedByStudent) + "," +
				std::to_string(due_time.tm_year) + "/" + std::to_string(due_time.tm_mon) + "/" +
				std::to_string(due_time.tm_mday) + "-" +
				std::to_string(due_time.tm_hour) + ":" + std::to_string(due_time.tm_min) + ":" +
				std::to_string(due_time.tm_sec) ;
		if(waitingStudentId->getSize()>0)
			line.append( ",");
		for( int i=0; i < waitingStudentId->getSize(); i++){
			line.append(std::to_string(*waitingStudentId->atIndex(i)->data));
			line.append(",");
		}
	}
	else{
//		line = std::to_string(id) + "," + name + "," + authorName + "," ;
		line = std::to_string(id) + "," + name + "," + authorName  ;
	}
}

void book::addBOOK_COUNT(){
	++BOOK_COUNT;
}
