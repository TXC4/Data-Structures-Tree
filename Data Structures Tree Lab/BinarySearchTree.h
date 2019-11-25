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
	Node* getRoot();
	Node* insertBinarySearchTree(Node* newNode);
	Node* findCustomerIterative(std::string searchName);
	Node* findCustomerRecursive(Node* thisRoot, std::string searchName);
	Node* findInorderPre(Node* searchNode);
	std::string getCustomerName(Node* searchNode);
	std::string getCustomerPhone(Node* searchNode);
	void inOrderTraversalIterative(Node* thisRoot);
	void preOrderTraversalIterative();
	void postOrderTraversalIterative();

	void deleteNode(std::string searchName);
	void reverseInOrderTraverse();
private:
	Node* root;
};