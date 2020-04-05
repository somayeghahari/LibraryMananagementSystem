/*
 * queueLL.h
 *
 *  Created on: Mar 26, 2020
 *      Author: somayeghahari
 */

#ifndef QUEUELL_H_
#define QUEUELL_H_

#include <iostream>

/**
 * Generic class queueLLNode is the node of the queue class
 * @tparam Type
 */
template<class Type>
class queueLLNode {
public:
	/**
	 * constructor function
	 * @param data
	 */
    queueLLNode(Type * data) {
        this->data = data;
        this->next = 0;
    }
    /**
     * function to set data and next pointer of the node
     * @param data: data of the node with generic type
     * @param next: pointer to the next node
     */
    void setNode(Type * data, queueLLNode* next ) {
        this->data = data;
        this->next = next;
    }
    /**
     * data of the node
     */
    Type* data;
    /**
     * pointer to the next node
     */
    queueLLNode* next;
};
/**
 * Generic class queueLL is the queue data structure which is implemented
 * based on the linked list datastructure
 * @tparam Type
 */
template<class Type>
class queueLL {
private:
	/**
	 * pointer to the first node of the queue
	 */
	queueLLNode<Type> * front;
	/**
	 * pointer to the last node of the queue
	 */
	queueLLNode<Type> * rear;
	/**
	 * size of the queue
	 */
    size_t size;

public:
    /**
	 * constructor function
	 */
	queueLL(){
		front = rear = 0;
		size = 0;
	}
	/**
	 * destructore function deletes the nodes in the queue and destroy the
	 * queuee
	 */
	virtual ~queueLL(){
	    queueLLNode<Type> *temp;

		while(front!=0)
		{
			temp=front;
			front=front->next;
			delete temp;
			size--;
		}
		rear=0;
		size=0;
	}
	/**
	 * function adds a new node to rear of the queue
	 * @param value: data of the node
	 */
	void add(Type * value) {

		// Create a new LL node
		queueLLNode<Type>* temp = new queueLLNode<Type>(value);

		if (rear == 0) { 	// If queue is empty,
			front = rear = temp;
			size++;
		}
		else{	// Add the new node at the end of queue
			rear->next = temp;
			rear = temp;
			size++;
		}
	}
	/**
	 * function removes and returns the data of the first node of the queue
	 * @return pointer to the data of the first node of the queue
	 */
	Type * remove() {
		Type * returnNode = 0;
		// If queue is empty, return false.
		if (front == 0) {
	        std::cout<<"Queue is empty.";
		}
		else{
			queueLLNode<Type>* temp = front;
			front = front->next;
			//queue gets empty
			if (front == 0)
				rear = 0;
			returnNode = temp->data;
			size--;
			delete (temp);
			temp = 0;
		}
		return returnNode;
	}
	/**
	 * function removes and returns the data of the node at location index of the queue
	 * @return pointer to the data of the node which is located at location index of the queue
	 */
	Type* removeAtIndex(int index)
	{
		Type * returnNode = 0;
		queueLLNode<Type>* temp = front;
		queueLLNode<Type>* prev = front;


	    int count = 0;
	    while (temp != 0)
	    {
	        if (count == index){
	        	if(temp!=front)
	        		prev->next = temp->next;
	        	else{
	        		front=rear = 0;
	        	}
				returnNode = temp->data;
				size--;
				delete (temp);
				temp = 0;
				return returnNode;
	        }
	        count++;
	    	prev=temp;
	        temp = temp->next;
	    }
	    std::cout<<"Node at index:"<<index<<" does not exist\n";

	    return 0;
	}
	/**
	 * function returns the node at location index of the queue
	 * @return pointer to the node which is located at location index of the queue
	 */
	queueLLNode<Type>* atIndex(int index)
	{

		queueLLNode<Type>* temp = front;


	    int count = 0;
	    while (temp != 0)
	    {
	        if (count == index)
	            return(temp);
	        count++;
	        temp = temp->next;
	    }
	    std::cout<<"Node at index:"<<index<<" does not exist\n";

	    return 0;
	}
	/**
	 * function overloads operator <<
	 * @param out: output stream
	 * @param b: queue object
	 * @return
	 */
	friend std::ostream& operator<<(std::ostream &out,  const queueLL &b) {

	    if(b.front==0){
	    	out<<"Queue is empty.";
	    }
	    else{
	    	queueLLNode<Type> *temp=b.front;
	    	while(temp){
				out<< *temp->data <<" \n";
				temp = temp->next;
			}
	    }
//	    os<<std::endl;
	    return out;
	}
//	queueLLNode<Type>& operator[](std::size_t idx) {
//		return *atIndex(idx);
//	}
	/**
	 * function return size of the queue
	 * @return size of the queue
	 */
	size_t getSize() const {
		return size;
	}
	/**
	 * function returns list of the nodes
	 * @return list of the nodes
	 */
	Type** nodeList(){
		Type ** list = new  Type*[size];
		int i=0;
		queueLLNode<Type> *temp=front;
		while(temp){
			list[i++] = temp->data ;
			temp = temp->next;
		}
		return list;
	}
	/**
	 * functions finds the index of the node with specififc data
	 * @param data: data of the node
	 * @return: index of the node
	 */
	int find(Type data){
		int i=-1;
		if(front){
			i=0;
			queueLLNode<Type> *temp=front;
			while(temp && *(temp->data)!=data){
				temp = temp->next;
				i++;
			}
			if(temp==NULL){
				i = -1;
			}
			else if(*temp->data!=data){
				i = -1;
			}
		}
		return i;
	}
};


#endif /* QUEUELL_H_ */
