#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

Node * BinarySearchTree::insertBinarySearchTree(Node * newNode)
{
	newNode->lTag = false;
	newNode->rTag = false;
	if (root == root->left && root == root->right)
	{
		newNode->left = root;
		root->left = newNode;
		newNode->lTag = root->lTag;
		root->lTag = true;
		newNode->right = root;
		//test
		newNode->rTag = false;
		return nullptr;
	}
	else
	{
		Node* temp = root->left;
		while(true)
		{
			if (newNode->name < temp->name)
			{
				if (temp->lTag == false)
				{
					//insert left child
					newNode->left = temp->left;
					temp->left = newNode;
					newNode->lTag = temp->lTag;
					temp->lTag = true;
					newNode->right = temp;
					return nullptr;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if (temp->rTag == false)
				{
					//insert right child
					newNode->right = temp->right;
					temp->right = newNode;
					newNode->rTag = temp->rTag;
					temp->rTag = true;
					newNode->left = temp;
					return nullptr;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}

Node * BinarySearchTree::findCustomerIterative(string searchName)
{
	return nullptr;
}

Node * BinarySearchTree::findCustomerRecursive(string searchName)
{
	return nullptr;
}

Node * BinarySearchTree::inOrderSuccessor(Node * searchNode)
{
	return nullptr;
}

string BinarySearchTree::getCustomerName(Node * searchNode)
{
	return std::string();
}

string BinarySearchTree::getCustomerPhone(Node * searchNode)
{
	return std::string();
}

Node* findInorderSuc(Node* temp)
{
	if (temp->rTag == false)
		return temp->right;
	temp = temp->right;
	while (temp->lTag != false)
		temp = temp->left;
	return temp;
}

void BinarySearchTree::inOrderTraversalIterative()
{
	Node* temp = root->left;
	while (temp->lTag == true)
	{
		temp = temp->left;
	}
	while (temp != root)
	{
		cout << temp->name << ", " << temp->phone << endl;
		temp = findInorderSuc(temp);
	}
}

void BinarySearchTree::preOrderTraversalIterative()
{
}

void BinarySearchTree::postOrderTraversalIterative()
{
}
