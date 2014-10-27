#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include "bst.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <stdio.h>
#define COUT std::cout
#define ENDL std::endl
#define CIN std::cin
#define USAGE "usage: a test-number, where test number is: \n1=linkedlist, \n2=queue, \n3=stack, \n4=bst, \n100=run all\nor a test-number <args> where <args> is a series of int arguments"

// LINKEDLIST
void run_linked_list() {
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
}

// QUEUE
void run_queue() {
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
}
	

// STACK
void run_stack() {
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
}

// BST
void run_bst() {
	COUT << "================== BST ==================" << ENDL;
	BinarySearchTree * myBST = new BinarySearchTree();
	myBST->insert(myBST->root_, 12);
	myBST->insert(myBST->root_,5);
	myBST->insert(myBST->root_,16);
	myBST->insert(myBST->root_,3);
	myBST->insert(myBST->root_,14);
	myBST->print_tree(myBST->root_, 0);
	if (myBST->contains(myBST->root_, 5)) COUT << "Contains 5!" << ENDL;
	COUT << ENDL;
	BinarySearchTree * pretty = new BinarySearchTree();
	pretty->insert(pretty->root_, 50);
	pretty->insert(pretty->root_, 25);
	pretty->insert(pretty->root_, 75);
	pretty->insert(pretty->root_, 12);
	pretty->insert(pretty->root_, 35);
	pretty->insert(pretty->root_, 60);
	pretty->insert(pretty->root_, 85);
	pretty->print_tree(pretty->root_, 0);
	pretty->delete_node(pretty->root_, 12);
	pretty->print_tree(pretty->root_, 0);

	COUT << "Parent of 12: " << pretty->find_parent(pretty->root_, 12)->key << ENDL;
	COUT << "Height of tree: " << pretty->height(pretty->root_) << ENDL;
}

int main(int argc, char* argv[]) {
	int n;
	int arr[1000];

	if (argc < 2) {
		printf("What would you like to test?\n1: LinkedList\n2: Queue\n3: Stack\n4: BST\n100: All\n");
		CIN >> n;
	} else if (argc >= 3) {
		int count = 2;
		for (int i = 0; i < argc - 2; i++) {
			arr[i] = strtol(argv[count++], nullptr, 10);
		}
		n = strtol(argv[1], nullptr, 10);
	}	else {
		n = strtol(argv[1], nullptr, 10);
		arr[0] = 0;
	}

	COUT << "~~Hello!~~" << ENDL;

	switch(n) {
		case 1:
			if (arr[0]) {
				LinkedList *myLL = new LinkedList();
				for(int i = 0; i < argc - 2; i++) {
					myLL->insert(arr[i]);
				}
				myLL->printList();
				break;
			}
			run_linked_list();
			break;
		case 2:
			if (arr[0]) {
				Queue *myQ = new Queue();
				for (int i = 0; i < argc - 2; i++) {
					myQ->enqueue(arr[i]);
				}
				myQ->printQueue();
				break;
			}
			run_queue();
			break;
		case 3:
			if (arr[0]) {
				Stack *myStack = new Stack();
				for (int i = 0; i < argc - 2; i++) {
					myStack->push(arr[i]);
				}
				myStack->printStack();
				break;
			}
			run_stack();
			break;
		case 4:
			if (arr[0]) {
				BinarySearchTree *myBST = new BinarySearchTree();
				for (int i = 0; i < argc - 2; i++) {
					myBST->insert(myBST->root_, arr[i]);
				}
				myBST->print_tree(myBST->root_, 0);
				break;
			}
			run_bst();
			break;
		case 100:
			run_linked_list();
			run_queue();
			run_stack();
			run_bst();
			break;
		default:
			printf("%s\n", USAGE);
	}


	COUT << "~~Goodbye!~~" << ENDL;



	return 0;
}
