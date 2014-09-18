#include <iostream>
#include "stack.h"
#define COUT std::cout
#define ENDL std::endl
// Note: when compiling, add "-std=c++11" or "-std=c++0x" if using nullptr instead of NULL

Stack::Stack() :
	size(0),
	top(nullptr)
	{}

Stack::~Stack() {
	Node *temp = top;
	while (temp) {
		delete temp;
		temp = temp->next;
	}
}

void Stack::push(int x) {
	Node *newNode = new Node();
	newNode->key = x;
	newNode->next = top;
	top = newNode;
	size++;
}

int Stack::pop() {
	int temp = top->key;
	top = top->next;
	size--;
	return temp;
}

void Stack::printStack() {
	Node *temp = top;
	while (temp) {
		COUT << "|" << temp->key << "|" << ENDL;
		// COUT << temp->key << ", ";
		// temp = temp->next;
		temp = temp->next;
	}
	COUT << "---" << ENDL;
}