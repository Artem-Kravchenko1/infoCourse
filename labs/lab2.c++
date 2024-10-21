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
		double from, to, intervals;
		double lastResult = 0;
	private:
		double countIntegralBasic();
		double integratedFunc(double x);
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

double integral::integratedFunc(double x) {
	return sqrt(4 + 5*sin(M_PI*x/2)*sin(M_PI*x/2));
}

double integral::countIntegralBasic() {
	printf("Calculating var: %d\n", variant);
	double cut = (to-from)/((double) intervals);
	double h1, h2, h3;
	double sum = 0;
	printf("cut %lf\n", intervals);
	h1 = integratedFunc(from);
	h2 = integratedFunc(from + cut);
	h3 = (h1 + h2)/2;

	for (int i = 0; i < intervals; i++) {
		// printf("sum %lf, h1 %lf, h2 %lf, h3 %lf\n", sum, h1, h2, h3);
		if (variant == 1) sum += h1*cut;
		else if (variant == 2) sum += h2*cut;
		else if (variant == 3) sum += h3*cut;
		else {
			printf("Sth went wrong!\n");
			return 0;
		}
		h1 = h2;
		h2 = integratedFunc(from+cut*(i+2));
		h3 = (h1 + h2)/2;
		// printf("sum %f, h1 %f, h2 %f, h3 %f\n", sum, h1, h2, h3);
	}
	return sum;
};

void integral::calculate() {
	lastResult = countIntegralBasic();
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