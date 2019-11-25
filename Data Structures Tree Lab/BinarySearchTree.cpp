#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include "myStack.h" //for postorder iterative

using namespace std;

Node * BinarySearchTree::getRoot(){ return root; }

//Node * BinarySearchTree::insertBinarySearchTree(Node * newNode)
Node* BinarySearchTree::insertBinarySearchTree(string name, string phone)
{
	Node* newNode = new Node;
	newNode->name = name;
	newNode->phone = phone;
	newNode->lTag = false;
	newNode->rTag = false;

	if (root == root->left && root == root->right)
	{
		newNode->left = root;
		root->left = newNode;
		newNode->lTag = root->lTag;
		root->lTag = true;
		newNode->right = root;
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
				if (temp->lTag == false)//ins left
				{
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
				if (temp->rTag == false)//ins right
				{
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

Node * BinarySearchTree::findParent(std::string searchName)
{
	Node* temp = root->left;
	if (searchName == temp->name)
	{
		cout << "Find Parent:  Orphan" << endl;
		return nullptr;
	}
	while (temp->lTag == true || temp->rTag == true)
	{
		if (searchName == temp->left->name || searchName == temp->right->name)
			return temp;
		if (searchName < temp->name)
			temp = temp->left;
		else if (searchName > temp->name)
			temp = temp->right;
	}
	cout << "Find Parent:  No child found" << endl;
	return nullptr;
}

Node * BinarySearchTree::findCustomerIterative(string searchName)
{
	Node* temp = root->left;
	while (temp->lTag == true || temp->rTag == true)
	{
		if (searchName < temp->name)
		{
			temp = temp->left;
		}
		else if (searchName > temp->name)
		{
			temp = temp->right;
		}
		if (searchName == temp->name)
		{
			cout << "Iterative Search Found:  " << temp->name << ", " << temp->phone << endl;
			return temp;
		}
	}
	cout << "Iterative Search: " << searchName << " not found in tree" << endl;
	return nullptr;
}

Node * BinarySearchTree::findCustomerRecursive(Node* thisRoot, string searchName)
{
	thisRoot = thisRoot;
	if (thisRoot->lTag == false && thisRoot->rTag == false &&
		searchName != thisRoot->name)
	{
		cout << "Recursive Search could not find " << searchName << endl;
		return nullptr;
	}
	if (searchName > thisRoot->name)
		findCustomerRecursive(thisRoot->right, searchName);
	if (searchName < thisRoot->name)
		findCustomerRecursive(thisRoot->left, searchName);
	if (searchName == thisRoot->name)
	{
		cout << "Recursive Search found:  " << thisRoot->name << ", " << thisRoot->phone << endl;
		return thisRoot;
	}
}

Node* BinarySearchTree::findInorderPre(Node* searchNode)
{
	if (searchNode->lTag == false)
		return searchNode->left;
	searchNode = searchNode->left;
	while (searchNode->rTag != false)
		searchNode = searchNode->right;
	return searchNode;
}

string BinarySearchTree::getCustomerName(Node* searchNode)
{
	return std::string();
}

string BinarySearchTree::getCustomerPhone(Node* searchNode)
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

void BinarySearchTree::inOrderTraversalIterative(Node* thisRoot)
{
	string startPoint = thisRoot->name;
	if (startPoint == "")
		startPoint = "Root";
	cout << "INORDER TRAVERSAL ITERATIVE from " << startPoint << endl;
	
	Node* temp = thisRoot;
	if (thisRoot == root)
	{
		temp = thisRoot->left;
	}
	while (temp->lTag == true)
	{
		temp = temp->left;
	}
	while (temp != root)
	{
		cout << temp->name << ", " << temp->phone << endl;
		temp = findInorderSuc(temp);
	}
	cout << endl;
}

void BinarySearchTree::preOrderTraversalIterative()
{
	cout << "PREORDER TRAVERSAL ITERATIVE" << endl;
	Node* temp = root->left;
	cout << temp->name << ", " << temp->phone << endl;
	while (temp != root)
	{
		if (temp->lTag == true)
		{
			temp = temp->left;
			cout << temp->name << ", " << temp->phone << endl;
		}
		else if (temp->rTag == true)
		{
			temp = temp->right;
			cout << temp->name << ", " << temp->phone << endl;
		}
		else if (temp->rTag == false)
		{
			while (temp->rTag == false)
			{
				temp = temp->right;
			}
			temp = temp->right;
			if (temp != root)
				cout << temp->name << ", " << temp->phone << endl;
			else
				cout << endl;
		}
	}
}

void BinarySearchTree::postOrderTraversalIterative()
{
	cout << "POST ORDER TRAVERSAL" << endl;
	if (root->left == root)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	Node* temp = root->left;
	myStack s;
	s.push(temp);
	while (temp->left != root)
	{
		if (temp->rTag == true)
			temp = temp->right;
		else
		{
			while (temp->lTag != true)
				temp = temp->left;
			temp = temp->left;
		}
		s.push(temp);
	}
	while (!s.isEmpty())
	{
		cout << s.getTop()->name << ", " << s.getTop()->phone << endl;
		s.pop();
	}
}

void BinarySearchTree::postOrderTraversalRecursive(Node* thisRoot)
{
	thisRoot = thisRoot;
	if (thisRoot->lTag == true)
		postOrderTraversalRecursive(thisRoot->left);
	if (thisRoot->rTag == true)
		postOrderTraversalRecursive(thisRoot->right);
	cout << thisRoot->name << endl;
}

void BinarySearchTree::deleteNode(std::string searchName)
{
	Node* toDelete = findCustomerIterative(searchName);
	Node* returnMeToStorage = toDelete;
	Node* parent = findParent(searchName);
	Node* temp = toDelete;
	Node* grandChild;
	
	if (toDelete->rTag && toDelete->lTag)//2 children
	{
		parent = toDelete;
		temp = toDelete->left;
		while (temp->rTag == true)
		{
			parent = temp;
			temp = temp->right;
		}
		toDelete->name = temp->name;
		toDelete->phone = temp->phone;
		cout << "Deleted " << searchName << endl;
		//delete returnMeToStorage;
		//return;
	}
	if (temp->lTag == true || temp->rTag == true) //1 child
	{
		if (temp->lTag == true)
			grandChild = temp->left;
		else
			grandChild = temp->right;
		if (parent == nullptr)
		{
			root->left = temp;
		}
		else if (temp == parent->left)
			parent->left = grandChild;
		else
			parent->right = grandChild;
		if (temp->lTag == true)
			findInorderPre(temp)->right = findInorderSuc(temp);
		else
		{
			if (temp->rTag == true)
				findInorderSuc(temp)->left = findInorderPre(temp);
		}
		cout << "Deleted " << temp->name << endl;
		//delete temp;
		//return;
	}
	else if (temp->rTag == false && temp->lTag == false) //no children
	{
		if (parent == nullptr)
		{
			root->left = root;
			root->lTag = false;
		}
		else if (temp == parent->left)
		{
			parent->lTag = false;
			parent->left = temp->left;
		}
		else
		{
			parent->rTag = false;
			parent->right = temp->right;
		}
		cout << "Deleted " << temp->name << endl;
		//delete temp;
		//return;
	}
}

void BinarySearchTree::reverseInOrderTraverse()
{
	cout << "REVERSE INORDER TRAVERSAL ITERATIVE" << endl;

	Node* temp = root->left;
	while (temp->rTag == true)
	{
		temp = temp->right;
	}
	while (temp != root)
	{
		cout << temp->name << ", " << temp->phone << endl;
		temp = findInorderPre(temp); 
	}
	cout << endl;
}
