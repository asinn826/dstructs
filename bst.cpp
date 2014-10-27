#include <iostream>
#include <iomanip>  // provides std::setw()
#include "bst.h"
#include <stdio.h>

#define COUT std::cout
#define ENDL std::endl

BinarySearchTree::Node::Node(int key) :
  key(key),
  left(nullptr),
  right(nullptr)
  {}

BinarySearchTree::BinarySearchTree() :
  root_(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
  if(delete_tree(root_))
    COUT << "BST Deleted." << ENDL;
  else COUT << "something went wrong" << ENDL;
}

bool BinarySearchTree::delete_tree(Node * root) {
  if (root) {
    Node * temp_l = root_->left;
    Node * temp_r = root_->right;
    while(root) {
      delete root;
      delete_tree(temp_l);
      delete_tree(temp_r);
    }
    return true;
  } else return false;
}

BinarySearchTree::Node * BinarySearchTree::find(int key, Node * from) {
  Node * temp = from;
  if (!temp) {
    return temp;
  }
  if (key < temp->key) {
    return find(key, temp->left);
  }
  if (key > temp->key) {
    return find(key, temp->right);
  }
  return temp;
}

bool BinarySearchTree::insert(Node *& root, int key) {
  if (!root) {
    root = new Node(key);
    return true;
  } else if (key < root->key) {
    return insert(root->left, key);
  } else if (key > root->key) {
    return insert(root->right, key);
  }
  return false;
}

bool BinarySearchTree::contains(Node * root, int key) {
  return root->key == key || contains(root->left, key) || contains(root->right, key);
}

BinarySearchTree::Node * BinarySearchTree::find_parent(Node * root, int key) {
	if(!root || root->key == key) {
		return nullptr;
	}
	if (root->left->key == key || root->right->key == key) {
		return root;
	} else {
		if (key < root->key) {
			return find_parent(root->left, key);	
		} else {
			return find_parent(root->right, key);
		}
	}
}

BinarySearchTree::Node *& BinarySearchTree::predecessor() {
  Node *& pred = root_;
  pred = pred->left;
  while(pred->right) {
    pred = pred->right;
  }
  return pred;
}

BinarySearchTree::Node *& BinarySearchTree::successor() {
  Node *& suc = root_;
  suc = suc->right;
  while(suc->left) {
    suc = suc->left;
  }
  return suc;
}

bool BinarySearchTree::delete_node(Node * root, int key) {
	// CURRENTLY SEGFAULTING, WTF IS THIS SHIT FUCK
  // 3 cases: no children(leaf), 1 child, 2 children
	Node * to_delete = find(key, root);
	// null node
  if (!to_delete) return false;
  printf("rofl\n");
  // need to find parent of node first
  Node * parent = find_parent(to_delete, key);
  printf("Parent of 12: %d\n", parent->key);
  // 0 child case, is a leaf
  if (!to_delete->left && !to_delete->right) {
		// node has a parent, so find if it's left or right, and delete accordingly
		if (parent) {
 		 	if (parent->left == to_delete) {
				parent->left = nullptr;
			} else {
				parent->right = nullptr;
      }
		} else {
			// node has no parent - it is root node. delete it, set root_ to null
      root_ = nullptr;
		}
    delete to_delete;
    return true;
  }

  // 2 child case
  if (to_delete->left && to_delete->right) {
    Node *& pred = predecessor();
    to_delete->key = pred->key;
    to_delete = pred;
    pred = pred->left;
    delete to_delete;
    return true;
  }

  // one child cases: left and right
  // left child case
  if (to_delete->left) {
    if (parent) {
      parent->left = to_delete->left;
      delete to_delete;
      return true;
    } else {
      root_ = to_delete->left;
      delete to_delete;
      return true;
    }
  } else {
  // right child case
    if (parent) {
      parent->right = to_delete->right;
      delete to_delete;
      return true;
    } else {
      root_ = to_delete->right;
      delete to_delete;
      return true;
    }    
  }

  return false;
}

int BinarySearchTree::height(Node * root) {
  if (!root) return -1;
  int height_l = height(root->left);
  int height_r = height(root->right);
  return height_l > height_r ? height_l + 1 : height_r + 1;
}


void BinarySearchTree::print_tree(Node * root, int d = 0) {
  if(!root) return;
  print_tree(root->right, d+1);
  COUT << std::setw( 3 * d ) << ""; // output 3 * d spaces
  COUT << root->key << ENDL;
  print_tree(root->left, d+1);
}
