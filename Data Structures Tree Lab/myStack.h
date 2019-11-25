#pragma once
#include "Node.h"
#include <string>

struct stackNode
{
	stackNode* next;
	stackNode* previous;
	std::string name;
	std::string phone;
};

class myStack
{
private:
	stackNode* head = new stackNode;
	stackNode* top;
public:
	myStack()
	{
		top = head;
	}
	void push(Node*);
	void pop();
	stackNode* getTop();
	bool isEmpty();
};