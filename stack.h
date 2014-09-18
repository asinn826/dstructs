/*
 * Copyright Alfred Sin, 2014
 */
#ifndef AS_STACK_H
#define AS_STACK_H

class Stack {
public:
	Stack();
	~Stack();
	void push(int x);
	int pop();
	void printStack();
	int size;
private:

	struct Node {
		int key;
		Node *next;
	};

	Node *top;

};

#endif