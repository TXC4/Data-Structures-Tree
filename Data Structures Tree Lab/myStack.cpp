#include "myStack.h"
#include <iostream>

void myStack::push(Node* thisNode)
{
	stackNode* sNode = new stackNode;
	sNode->name = thisNode->name;
	sNode->phone = thisNode->phone;
	if (head == top)
	{
		head->next = sNode;
		sNode->previous = head;
	}
	else
	{
		top->next = sNode;
		sNode->previous = top;
	}
	top = sNode;
}

void myStack::pop()
{
	if (top != head)
	{
		top = top->previous;
		delete top->next; //return to storage
	}
	else
		std::cout << "Stack empty. Can't pop" << std::endl;
}

stackNode* myStack::getTop()
{
	return top;
}

bool myStack::isEmpty()
{
	if (top == head)
		return true;
	else
		return false;
}
