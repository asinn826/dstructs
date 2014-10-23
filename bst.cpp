#include <iostream>
#include <iomanip>  // provides std::setw()
#include "bst.h"

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
    COUT << "BSi Deleted." << ENDL;
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
  } else if (key < temp->key) {
    return find(key, from->left);
  } else if (key > temp->key) {
    return find(key, from->right);
  } else return temp;
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

bool BinarySearchTree::delete_node(Node * root, int key) {
	// CURRENTLY SEGFAULTING, WTF IS THIS SHIT FUCK
  // 3 cases: no children(leaf), 1 child, 2 children
	Node * to_delete = find(key, root);
	// need to find parent of node first
	Node * parent = find_parent(to_delete, key);
  // null node
  if (!to_delete) return false;
  // 0 child case, is a leaf
  if (!to_delete->left && !to_delete->right) {
		// node has a parent, so find if it's left or right, and delete accordingly
		if (parent) {
 		 	if (to_delete->key < parent->key) {
				parent->left = nullptr;
			} else {
				parent->right = nullptr;
			}
			delete to_delete;
			return true;
		} else {
			// node has no parent - it is root node. delete it, set root_ to null
			root_ = nullptr;
			delete root;
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
