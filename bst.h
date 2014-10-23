/*
 * Copyright Alfred Sin, 2014.
 */
#ifndef AS_BINARY_SEARCH_TREE_H
#define AS_BINARY_SEARCH_TREE_H

class BinarySearchTree {
public: 
	struct Node {
    Node(int key);
		int key;
		Node * left;
		Node * right;
	};

	BinarySearchTree();
	~BinarySearchTree();
  bool delete_tree(Node * root);
  Node * find(int key, Node * from);
	bool insert(Node *& root, int key);
	bool contains(Node * root, int key);
	Node * find_parent(Node * root, int key);
	bool delete_node(Node * root, int key);
  int height(Node * root);
  int num_leaves(Node * root);
  int depth(Node * root, Node * depthTo);
	Node *& predecessor();
	Node *& successor();
	void in_order();
	void pre_order();
	void post_order();
	void print_tree(Node * root, int d);
	void bst_sort();

  struct Node * root_;

private:
  

};

#endif
