#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
using namespace std;

struct qNode {
	int data;
	qNode* nextPtr;
};

class Queue {
private:
	qNode* front;
	qNode* rear;
	int numElements;
public:
	Queue();
	void addElement(int d);
	int removeElement();
	int showFront();
	bool empty();
	int getNumElements();
	void print();
};
#endif
