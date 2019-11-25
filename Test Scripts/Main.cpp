#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int>s;

int main()
{
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	while(!s.empty())
	{
		int x = s.top();
		s.pop();
		cout << x << endl;
	}
	cin.get();
}