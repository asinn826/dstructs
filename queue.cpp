#include "queue.h"
#include <iostream>
#define COUT std::cout
#define ENDL std::endl
// Note: when compiling, add "-std=c++11" or "-std=c++0x" if using nullptr instead of NULL

Queue::Queue() :
	size(0),
	head(nullptr),
	tail(nullptr) 
	{}

Queue::~Queue() {
	while (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	COUT << "Object was deleted" << ENDL;
}

void Queue::enqueue(int key) {
	Node *newNode = new Node();
	if (size == 0) {		
		head = newNode;
		tail = newNode;
		size++;
	} else if (size > 0) {
		newNode->key = key;
		tail->next = newNode;
		tail = newNode;
		size++;
	}
}
	
int Queue::dequeue() {
	Node *temp = head;
	head = head->next;
	size--;
	return temp->key;
}
	
bool Queue::contains(int key) {
	while (head) {
		if (head->key == key) return true;
	}
	return false;
}
	
void Queue::printQueue() {
	Node *temp = head;
	while (temp) {
		COUT << temp->key << "-->";
		temp = temp->next;
	}
	COUT << "nullptr" << ENDL;
}