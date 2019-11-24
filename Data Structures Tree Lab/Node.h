#pragma once
#include <string>

struct Node
{
	std::string name;
	std::string phone;
	Node* left;
	Node* right;
	bool lTag;
	bool rTag;
};