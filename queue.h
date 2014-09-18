/*
 * Copyright Alfred Sin, 2014.
 */
#ifndef AS_QUEUE_H
#define AS_QUEUE_H

class Queue {
public: 
	Queue();
	~Queue();
	void enqueue(int key);
	int dequeue();
	bool contains(int key);
	void printQueue();
	int size;

private:
	
	struct Node {
		int key;
		Node *next;
	};

	Node *head;
	Node *tail;
};

#endif