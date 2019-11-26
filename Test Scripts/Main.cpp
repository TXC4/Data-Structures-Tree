#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


struct thing
{
	string n;
	string p;
};
int main()
{
	ifstream in;
	in.open("Book1.csv");
	string name;
	string phone;
	while(getline(in, name, ',') && getline(in, phone, '\n'))
		cout << "*" << name << "*" << phone << "*" <<  endl;
	in.close();
	cin.get();
}