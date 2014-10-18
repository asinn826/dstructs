#include "./linkedlist.h"
#include <iostream>
#define COUT std::cout
#define ENDL std::endl
// Note: when compiling, add "-std=c++11" 
// or "-std=c++0x" if using nullptr instead of NULL

LinkedList::LinkedList() :
	size(0),
	head(nullptr),
	tail(nullptr)
	{  }

LinkedList::~LinkedList() {
	while (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	COUT << "Object was deleted" << ENDL;
}

bool LinkedList::insert(int key) {
	Node *next = new Node();
	next->key = key;
	next->prev = nullptr;
	next->next = nullptr;
	if (size == 0) {
		head = next;
		tail = next;
		tail->next = nullptr;
		size++;
		return true;
	} else if (size > 0) {
		next->prev = tail;
		tail->next = next;
		tail = tail->next;
		tail->next = nullptr;
		size++;
		return true;
	}
	return false;
}

bool LinkedList::insertAfter(int target, int key) {
	Node *theNode = new Node();
	theNode->key = key;
	theNode->prev = nullptr;
	theNode->next = nullptr;
	if (size > 0) {
		Node *temp = head;
		while (temp->next) {
			if (temp->key == target) {
				theNode->next = temp->next;
				temp->next->prev = theNode;
				temp->next = theNode;
				theNode->prev = temp;
				size++;
				return true;
			}
			temp = temp->next;
		}
	}
	return false;
}

bool LinkedList::deleteHead() {
	Node *temp = head;
	head->next->prev = nullptr;
	head = head->next;
	delete temp;
	size--;
	return true;
}

bool LinkedList::deleteTail() {
	Node *temp = tail;
	tail->prev->next = nullptr;
	tail = tail->prev;
	delete temp;
	size--;
	return true;
}

void LinkedList::remove(int target) {
	Node *temp = head;
	if (!temp) return; // empty list
	while (temp) {
		if (!temp->next && !temp->prev && temp->key == target) {
      // one element list
			delete temp;
			head = tail = nullptr;
      size--;
		} else if (head->key == target && temp->key == target) {
      // head of linked list
      head = temp->next;
      head->prev = nullptr;
      delete temp;
      size--;
    } else if (tail->key == target && temp->key == target) {
      // tail of linked list
      tail = temp->prev;
      tail->next = nullptr;
      delete temp;
      size--;
    } else if (temp->key == target) {
      // middle of linked list
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      delete temp;
      size--;
		}
    temp = temp->next;
	}
}

bool LinkedList::contains(int key) {
	Node *currentNode = head;
	while (currentNode->next) {
		if (currentNode->key == key) {
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

void LinkedList::printList() {
	Node *curr = head;
	while (curr) {
		COUT << curr->key << "<-->";
		curr = curr->next;
	}
	COUT << "nullptr" << ENDL;
}
