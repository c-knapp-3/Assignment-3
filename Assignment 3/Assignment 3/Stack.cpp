#include "Stack.h"

template<typename Item_Type>
Stack<Item_Type>::Stack() { }   

template<typename Item_Type>
void Stack<Item_Type>::push(const Item_Type& item) {
	container.push_back(item);
}

template<typename Item_Type>
Item_Type& Stack<Item_Type>::top() {
	return container.back();
}

template<typename Item_Type>
void Stack<Item_Type>::pop() {
	container.pop_back();
}

template<typename Item_Type>
bool Stack<Item_Type>::empty() const {
	return container.empty();
}

template<typename Item_Type>
size_t Stack<Item_Type>::size() const{
	return container.size();
}