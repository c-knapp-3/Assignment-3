#include "Queue.h"

Queue::Queue() {                       // default constructor 
	front = nullptr;                   // assign nodes with null
	rear = nullptr;
	numElements = 0;                   // initial value is zero
}

void Queue::addElement(int d) {       // @param integer data
	qNode* temp = new qNode;          // makes new node
	temp->data = d;                   // sets new node data with param passed to function
	temp->nextPtr = nullptr;          // next pointer becomes new null
	if (front == nullptr) {           // if empty
		front = temp;                 // add new
		rear = temp;                  
		numElements++;
	}
	else {
		rear->nextPtr = temp;         // otherwise, add to end
		rear = temp;
		numElements++;
	}
}

int Queue::removeElement() {
	if (front == nullptr) {          // check if empty
		cout << "Sorry, the queue is empty.\n";  // if empty, display message to user
		return -1;
	}
	else {                           // remove from front
		qNode* delNode = front;
		qNode* tempData = new qNode;
		tempData->data = front->data;
		front = front->nextPtr;
		delete delNode;              // deallocate memory
		delNode = nullptr;
		numElements--;
		return tempData->data;
	}
}

int Queue::showFront() {
	if (front == nullptr) {          // check if empty
		cout << "Sorry, the queue is empty.\n";   // if empty, display message to user
		return -1;
	}
	else {
		return front->data;          // return element at front
	}
}

bool Queue::empty() {
	if (front == nullptr) {          
		return true;                // if empty, return true
	}
	return false;                   // otherwise, return false
}

int Queue::getNumElements() {       
	return numElements;
}

void Queue::print() {               // prints elements in the queue
	qNode* tempNode = front;
	while (tempNode != nullptr) {
		if (tempNode->nextPtr != nullptr) {
			cout << tempNode->data << ", ";
		}
		else {
			cout << tempNode->data << endl;
		}
		tempNode = tempNode->nextPtr;
	}
}
