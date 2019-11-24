#pragma once
#include "Node.h"
#include <string>

class BinarySearchTree
{
public:
	BinarySearchTree()
	{
		root = new Node;
		root->lTag = false;
		root->rTag = true;
		root->left = root;
		root->right = root;
		root->name = "";
		root->phone = "";
	}
	Node* insertBinarySearchTree(Node* newNode);
	Node* findCustomerIterative(std::string searchName);
	Node* findCustomerRecursive(std::string searchName);
	Node* inOrderSuccessor(Node* searchNode);
	std::string getCustomerName(Node* searchNode);
	std::string getCustomerPhone(Node* searchNode);
	void inOrderTraversalIterative();
	void preOrderTraversalIterative();
	void postOrderTraversalIterative();
private:
	Node* root;
};