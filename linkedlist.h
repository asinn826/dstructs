/*
 * Copyright Alfred Sin, 2014.
 */
#ifndef AS_LINKEDLIST_H
#define AS_LINKEDLIST_H

class LinkedList {
public: 
	LinkedList();
	~LinkedList();
	bool insert(int key);
	bool insertAfter(int target, int key);
	bool deleteHead();
	bool deleteTail();
	void remove(int target);
	bool contains(int key);
	void printList();
	int size;

private:

	struct Node {
		int key;
		Node *next;
		Node *prev;
	};

	
	Node *head;
	Node *tail;
};

#endif