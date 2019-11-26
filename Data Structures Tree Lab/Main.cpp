#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
	BinarySearchTree Tree;

	cout << "BEGIN C OPTION TASKS:" << endl << endl;

	Tree.readIn("Book1.csv");

	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.findCustomerIterative("Ortiz"); 
	Tree.findCustomerRecursive(Tree.getRoot()->left, "Ortiz");
	Tree.findCustomerIterative("Penton");
	Tree.findCustomerRecursive(Tree.getRoot()->left, "Penton");
	Tree.inOrderTraversalIterative(Tree.findCustomerIterative("Ikerd"));
	
	Tree.readIn("Book2.csv");
	
	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.preOrderTraversalIterative();
	Tree.postOrderTraversalIterative();

	cout << "______________________________________________________________________" << 
		endl <<
		"BEGIN B OPTION TASKS" << 
		endl << endl;

	Tree.deleteNode("Robson");
	Tree.deleteNode("Moutafis");
	Tree.deleteNode("Ikerd");

	Tree.readIn("Book3.csv");
	
	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.reverseInOrderTraverse();
	Tree.preOrderTraversalIterative(); 

	cout << "______________________________________________________________________" <<
		endl <<
		"BEGIN A OPTION TASKS" <<
		endl << endl;

	Tree.postOrderTraversalIterative();
	cout << endl << "POST ORDER RECURSIVE" << endl;
	Tree.postOrderTraversalRecursive(Tree.getRoot()->left);

	cin.get();
}
