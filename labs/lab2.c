#include <stdio.h>
#include <math.h>


double integratedFunc(double x) {
	return x*x*sin(x);
}

double countIntegralBasic(int var, double a, double b, int amount) {
	// printf("a %lf, b %lf\n", a, b);
	printf("\nCalculating var: %d", var);
	double cut = (b-a)/((double) amount);
	double h1, h2, h3;
	double sum = 0;
	// printf("cut %lf\n", cut);
	h1 = integratedFunc(a);
	h2 = integratedFunc(a + cut);
	h3 = (h1 + h2)/2;
	// printf("sum %lf, h1 %lf, h2 %lf, h3 %lf\n", sum, h1, h2, h3);

	for (int i = 0; i < amount; i++) {
		if (var == 1) sum += h1*cut;
		else if (var == 2) sum += h2*cut;
		else if (var == 3) sum += h3*cut;
		else {
			// printf("Sth went wrong!\n");
			return 0;
		}
		h1 = h2;
		h2 = integratedFunc(a+cut*(i+2));
		h3 = (h1 + h2)/2;
		// printf("sum %f, h1 %f, h2 %f, h3 %f\n", sum, h1, h2, h3);
	}
	return sum;
}

double countIntegralAdvanced(double a, double b, int amount) {
	printf("Calculating var: 4\n");
	double sum = 0;
	double cut = (b-a)/((double) amount);
	// printf("cut %f\n", cut);
	double f1, f2, f3;
	f1 = integratedFunc(a);
	f2 = integratedFunc(a + cut);
	f3 = integratedFunc(a + cut*2);
	// printf("f1 %f, f2 %f, f3 %f\n", f1, f2, f3);
	sum += cut/3*(f1 + 4*f2+ f3);
	// printf("sum %f\n", sum);
	for (int i = 0; i < (amount/2)-1; i++) {
		f1 = f3;
		f2 = integratedFunc(a + cut*(i*2+3));
		f3 = integratedFunc(a + cut*(i*2+4));
		sum += cut/3*(f1 + 4*f2+ f3);
		// printf("f1 %f, f2 %f, f3 %f\n", f1, f2, f3);
		// printf("sum %f\n", sum);
	}
	return sum;
}


int main() {

	char var = 0;
	double a, b = 0;
	int intervals = 0;
	double res;





	do {
		printf("Please, write only what you are asked for\n");
		printf("choose the variant of calculation (1-4): ");
		scanf("%d", &var);
	}
	while (var < 1 || var > 4);

	do {
		printf("Please, write only what you are asked for\n");
		printf("choose 1st edge (a): ");
		scanf("%lf", &a);
		printf("choose 2nd edge (b): ");
		scanf("%lf", &b);
		printf("choose the amount of intervals (2n for 4th method of calc): ");
		scanf("%d", &intervals);
	} while (intervals <= 0 || (var == 4 && intervals % 2 == 1));
	
	// printf("a %f, b %f\n", a, b);
	if (var != 4) res = countIntegralBasic(var, a, b, intervals);
	else res = countIntegralAdvanced(a, b, intervals);
	// printf("kinda %0.13lf", res);
};