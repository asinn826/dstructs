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
	bool remove(int target);
	bool removeR(int target);
	bool contains(int key);
	void printList();
	int size;

private:
	struct Node {
		int key;
		Node *next;
		Node *prev;
	};
	bool removeR_h(int target, Node * currentNode);
	
	Node *head;
	Node *tail;
};

#endif