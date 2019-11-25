#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>

using namespace std;

int main()
{
	BinarySearchTree Tree;

	cout << "BEGIN C OPTION TASKS:" << endl << endl;
	Node* nodeList = NULL;
	nodeList = new Node[13];
	nodeList[0].name = "Moutafis";
	nodeList[0].phone = "295-1492";
	nodeList[1].name = "Ikerd";
	nodeList[1].phone = "291-1864";
	nodeList[2].name = "Gladwin";
	nodeList[2].phone = "295-1601";
	nodeList[3].name = "Robson";
	nodeList[3].phone = "293-6122";
	nodeList[4].name = "Dang";
	nodeList[4].phone = "295-1882";
	nodeList[5].name = "Bird";
	nodeList[5].phone = "291-7890";
	nodeList[6].name = "Harris";
	nodeList[6].phone = "294-8075";
	nodeList[7].name = "Ortiz";
	nodeList[7].phone = "584-3622";
	nodeList[8].name = "Avila";
	nodeList[8].phone = "294-1568";
	nodeList[9].name = "Quijada";
	nodeList[9].phone = "294-1568";
	nodeList[10].name = "Villatoro";
	nodeList[10].phone = "295-6622";
	Tree.insertBinarySearchTree(&nodeList[0]);
	Tree.insertBinarySearchTree(&nodeList[1]);
	Tree.insertBinarySearchTree(&nodeList[2]);
	Tree.insertBinarySearchTree(&nodeList[3]);
	Tree.insertBinarySearchTree(&nodeList[4]);
	Tree.insertBinarySearchTree(&nodeList[5]);
	Tree.insertBinarySearchTree(&nodeList[6]);
	Tree.insertBinarySearchTree(&nodeList[7]);

	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.findCustomerIterative("Ortiz"); 
	Tree.findCustomerRecursive(Tree.getRoot(), "Ortiz");
	Tree.findCustomerIterative("Penton");
	Tree.findCustomerRecursive(Tree.getRoot(), "Penton");
	Tree.inOrderTraversalIterative(Tree.findCustomerIterative("Ikerd"));

	Tree.insertBinarySearchTree(&nodeList[8]);
	Tree.insertBinarySearchTree(&nodeList[9]);
	Tree.insertBinarySearchTree(&nodeList[10]);

	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.preOrderTraversalIterative();
	Tree.postOrderTraversalIterative();

	cout << "______________________________________________________________________" << 
		endl <<
		"BEGIN B OPTION TASKS" << 
		endl << endl;

	//Tree.deleteNode("Robson");
	//Tree.deleteNode("Moutafis");
	//Tree.deleteNode("Ikerd");
	nodeList[11].name = "Poudel";
	nodeList[11].phone = "294-1666";
	nodeList[12].name = "Spell";
	nodeList[12].phone = "295-1882";
	Tree.insertBinarySearchTree(&nodeList[11]);
	Tree.insertBinarySearchTree(&nodeList[12]);
	Tree.inOrderTraversalIterative(Tree.getRoot());
	Tree.reverseInOrderTraverse();
	Tree.preOrderTraversalIterative();
	cin.get();
}
