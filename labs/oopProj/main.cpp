// #include "header.cpp"
#include "methods.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
	string com;
	integral myInt;
	float result = 0;
	while (true)
	{
		cout << "Tell me what to do (var, data, count): ";
		cin >> com;
		
		if (com == "var") myInt.getVariant();
		else if (com == "data") myInt.getData();
		else if (com == "count") 
		{
			myInt.calculate();
			printf("Result is %f\n", myInt.lastResult);
		}
		else cout << "Wrong option\n";
	}
}