#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class integral {
	public:
		void calculate();
		void getData();
		void getVariant();
		int variant = 0;
		double from, to, intervals = 0;
};


void integral::getData() {
	while (true)
	{	
		string resp;
		cout << "Start point: ";
		if (!(cin >> from)) continue;
		cout << "End point: ";
		if (!(cin >> to)) continue;
		cout << "Amount of intervals: ";
		if (!(cin >> intervals)) continue;
		if (from <= to && intervals > 0) break;
		cout << "Wrong data\n";
	}
	
};

void integral::calculate() {

};

void integral::getVariant() {
	while (true) {
		string resp;
		cout << "Your calculating variant (1-4): ";
		cin >> resp;
		variant = resp[0] - '0';
		if (resp.length() == 1 && variant >= 1 && variant <= 4) break;
		cout << "Wrong option!\n";
	}
};

int main() {
	string com;
	integral myInt;
	while (true)
	{
		cout << "Tell me what to do (var, data, count): ";
		cin >> com;
		
		if (com == "var") myInt.getVariant();
		else if (com == "data") myInt.getData();
		else if (com == "count") myInt.calculate();
		else cout << "Wrong option\n";
	}
	
}