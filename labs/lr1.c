#include <stdio.h>
#include <string.h>
#include <math.h>
//RE-41 KRAVCHENKO ARTEM

// int func2(int x);
double loopSum(int var, double x, int b);
double myFunc(double x);

int main() {
	int var;
	char choice[2];
	char p1[2] = "p1";
	char p2[2] = "p2";
	float arr[5][3];
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 3; j++) {
			arr[i][j] = i*2;
			printf("%f ", arr[i][j]);
		}
		
	int x;
	int b;

	do {
		printf("Your choice (p1 or p2): ");
		scanf("%s", choice);
		// printf("%d, %c, %c", strlen(choice), choice[0], choice[1]);

		if (strcmp(choice, "p1") == 0) {
			printf("Var: ");
			do {
				scanf("%d", &var);
			} while (var != 1 && var != 2);

			printf("b: ");
			scanf("%d", &b);
			printf("Your x: ");
			scanf("%d", &x);
			double res1;
			res1 = loopSum(var, x, b);
			printf("Your res - %f\n", res1);
		}

		else if (strcmp(choice, "p2") == 0)
		{
			printf("Your x: ");
			scanf("%d", &x);

			int res2 = loopSum(2, x, 0);
			printf("Your res - %d", res2);
		}
	} while (1);
	
	

}

double myFunc(double x) {
	return 0.25*(x-25)*(x-25) + (x+25)*(x+25)*(x+25)/(double)100 + 1;
}

double loopSum(int var, double x, int b) {
	double sum = 0;
	double arg;
	for (int i = 0; i<50; i++) {
		arg = pow(-1, i)/(2*i+1);
		if (b != 0 && i == b) break; 
		if (var == 2) {
			sum += myFunc(x);
		} else 
			sum += myFunc(arg);
		// if (var == 1 && i % 5 == 0) printf("Sum: %lf\n", sum);
	}
	return sum;
}

// int func2(int x) {
// 	return 0;
// }