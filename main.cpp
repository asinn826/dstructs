#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#define COUT std::cout
#define ENDL std::endl

int main() {
	// LINKEDLIST
	COUT << "================== LINKEDLIST ==================" << ENDL;
	LinkedList *myLL = new LinkedList();
	COUT << "     Current size: " << myLL->size << ENDL;
	COUT << "Inserting 0-9..." << ENDL;
	for (int i = 0; i < 10; i++) {
		myLL->insert(i);
	}
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	COUT << "Deleting head" << ENDL;
	myLL->deleteHead();
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	COUT << "Deleting tail" << ENDL;
	myLL->deleteTail();
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	if (myLL->contains(5)) COUT << "myLL contains 5!" << ENDL;
	if (!myLL->contains(20)) COUT << "myLL doesn't contain 20!" << ENDL;
	COUT << "     Current size: " << myLL->size << ENDL;
	COUT << "Insert 2 after 5" << ENDL;
	myLL->insertAfter(5, 2);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->remove(3);
	myLL->remove(4);
	myLL->remove(5);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->remove(1);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->remove(8);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->removeR(2);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->insert(50);
	myLL->insert(25);
	myLL->insert(12);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->removeR(25);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->removeR(12);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	myLL->removeR(6);
	myLL->printList();
	COUT << "     Current size: " << myLL->size << ENDL;
	delete myLL;

	// QUEUE
	COUT << "================== QUEUE ==================" << ENDL;
	Queue *myQ = new Queue();
	COUT << "     Current size: " << myQ->size << ENDL;
	COUT << "Enqueuing 10 random numbers at a solid rate of 1 number per second..." << ENDL;
	COUT << "The wait is needed for new rng seeds" << ENDL;
	for (int i = 0; i < 10; i++) {
		int random;
		srand(time(nullptr));
		random = rand() % 10 + 1;
		myQ->enqueue(random);
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}
	COUT << "     Current size: " << myQ->size << ENDL;
	COUT << "Current queue: " << ENDL;
	myQ->printQueue();
	COUT << "Enqueuing 10 numbers..." << ENDL;
	for (int i = 0; i < 10; i++) {
		myQ->enqueue(i);
	}
	COUT << "     Current size: " << myQ->size << ENDL;
	COUT << "Current queue: " << ENDL;
	myQ->printQueue();
	COUT << "Dequeueing..." << ENDL;
	myQ->dequeue();
	COUT << "Current queue: " << ENDL;
	myQ->printQueue();
	COUT << "     Current size: " << myQ->size << ENDL;
	COUT << "Dequeueing..." << ENDL;
	myQ->dequeue();
	COUT << "Current queue: " << ENDL;
	myQ->printQueue();
	COUT << "Dequeueing..." << ENDL;
	myQ->dequeue();
	COUT << "     Current size: " << myQ->size << ENDL;
	COUT << "Current queue: " << ENDL;
	myQ->printQueue();
	COUT << "Dequeueing 5 numbers..." << ENDL;
	for (int i = 0; i < 5; i++) {
		myQ->dequeue();
	}
	COUT << "Current queue: " << ENDL;
	myQ->printQueue();
	COUT << "     Current size: " << myQ->size << ENDL;
	delete myQ;

	// STACK
	COUT << "================== STACK ==================" << ENDL;
	Stack *myStack = new Stack();
	COUT << "     Current size: " << myStack->size << ENDL;
	COUT << "Pushing 1-10 onto stack..." << ENDL;
	for (int i = 1; i < 11; i++) {
		myStack->push(i);
	}
	COUT << "Current stack: " << ENDL;
	myStack->printStack();
	COUT << "     Current size: " << myStack->size << ENDL;
	COUT << "Popping 3 times..." << ENDL;
	for (int i = 0; i < 3; i++) {
		myStack->pop();
	}
	COUT << "Current stack: " << ENDL;
	myStack->printStack();
	COUT << "     Current size: " << myStack->size << ENDL;

	COUT << ENDL;
	COUT << "~~Goodbye!~~" << ENDL;


	return 0;
}