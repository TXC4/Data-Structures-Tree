#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
	BinarySearchTree Tree;

	cout << "BEGIN C OPTION TASKS:" << endl << endl;
	
	Tree.insertBinarySearchTree("Moutafis","295-1492");
	Tree.insertBinarySearchTree("Ikerd","291-1864");
	Tree.insertBinarySearchTree("Gladwin", "295-1601");
	Tree.insertBinarySearchTree("Robson", "293-6122");
	Tree.insertBinarySearchTree("Dang", "295-1882");
	Tree.insertBinarySearchTree("Bird", "291-7890");
	Tree.insertBinarySearchTree("Harris", "294-8075");
	Tree.insertBinarySearchTree("Ortiz", "584-3622");
	

	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.findCustomerIterative("Ortiz"); 
	Tree.findCustomerRecursive(Tree.getRoot()->left, "Ortiz");
	Tree.findCustomerIterative("Penton");
	Tree.findCustomerRecursive(Tree.getRoot()->left, "Penton");
	Tree.inOrderTraversalIterative(Tree.findCustomerIterative("Ikerd"));
	
	Tree.insertBinarySearchTree("Avila", "294-1568");
	Tree.insertBinarySearchTree("Quijada", "294-1568");
	Tree.insertBinarySearchTree("Villatoro", "295-6622");
	
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

	Tree.insertBinarySearchTree("Poudel", "294-1666");
	Tree.insertBinarySearchTree("Spell","295-1882");
	
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
