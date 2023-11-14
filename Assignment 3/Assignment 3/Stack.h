#ifndef STACK_H_
#define STACK_H_
#include <vector>

template<typename Item_Type>
class Stack {
private: 
	std::vector<Item_Type> container;      // container to hold stack

public:
	Stack();    //  constructor creates an initially empty stack
	void push(const Item_Type& item);   // pushes item to top of stack; @param item to be added
	Item_Type& top();  // returns a reference to item at top of stack w/ out removing it
	void pop();       // remove item at the top of the stack
	bool empty() const;   // returns true if stack is empty, otherwise returns false
	size_t size() const;  // returns number of items in the stack
};
#endif

