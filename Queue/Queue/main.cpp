#include "Queue.h"

int main() {
	Queue testQueue;
	int userInput;
	int userNewElement;
	while (true) {
		cout << "\nWhat would you like to do with the Queue?\n1) Add a new element at the rear.\n2) Remove the front element.\n3) Show the front element.\n4) Check if it is empty.\n5) Show the number of elements in it.\n6) Nothing, quit and show queue.\n";
		cin >> userInput;
		if (userInput == 6) {
			break;
		}
		switch (userInput) {
		case 1:
			cout << "Please enter element to add -> ";
			cin >> userNewElement;
			testQueue.addElement(userNewElement);
			break;
		case 2:
			cout << testQueue.removeElement() << endl;
			break;
		case 3:
			cout << testQueue.showFront() << endl;
			break;
		case 4:
			if (testQueue.empty() == 0) {
				cout << "The queue is not empty.\n";
			}
			else if (testQueue.empty() == 1) {
				cout << "The queue is empty.\n";
			}
			break;
		case 5:
			cout << "The total number of elements in the queue -> " << testQueue.getNumElements() << endl;
			break;
		default:
			cout << "Invalid input.\n";
		}
	}
	cout << "Thanks! Here is your queue:\n";
	testQueue.print();
}