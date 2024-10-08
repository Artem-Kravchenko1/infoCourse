#include <stdio.h>
#include <math.h>

double matfunc10(double x);
double matfunc11(double x);

int main() {

	int var;

	do
	{
		printf("variant: ");
		scanf("%d", &var);
		if (var != 1 && var != 2) {
			printf("Wrong variant, choose between 1 and 2!\n");
		}
	} while (var != 1 && var != 2);


	float from, to, step;
	printf("from: ");
	scanf("%f", &from);
	printf("to: ");
	scanf("%f", &to);
	printf("step: ");
	scanf("%f", &step);
	// printf("from %f, to %f", from, step);
	printf("=============================================================\n");
	printf("|                  N|                  X|                  Y|\n");
	printf("=============================================================\n");
	int dig, digFrom, digNum;
	for (int i = 1;from <= to; from += step, i++) {
		if (var == 1) {
			dig = floor(log2(abs(i)) / 4) + 1;
			digFrom = floor(log10(abs(from))) + 1;
			if (from / floor(from) == 1) digFrom = floor(log2(abs(from)) / 4) - 2;
			digNum = floor(log10(abs(matfunc10(from)))) + 1;
			if (matfunc10(from) / floor(matfunc10(from)) == 1) digNum = floor(log2(abs(matfunc10(from))) / 4) - 2;
			printf("|");
			for (int j = 20 - dig; j > 1; j--) printf(" ");
			printf("%x|", i);
			for (int j = 17 - digFrom; j > 1; j--) printf(" ");
			if (from / floor(from) == 1) printf("%x|", (int)from);
			else printf("%.2f|", from);
			for (int j = 17 - digNum; j > 1; j--) printf(" ");
			if (matfunc10(from) / floor(matfunc10(from)) == 1) printf("%x|\n", (int)matfunc10(from));
			else printf("%.2f|\n", matfunc10(from));
			// printf("x = %.2f, y = %.2f\n",from , matfunc10(from));
		}
		else {
			dig = floor(log10(abs(i))) + 1;
			digFrom = floor(log10(abs(from))) + 1;
			digNum = floor(log10(abs(matfunc11(from)))) + 1;
			printf("|");
			for (int j = 20 - dig; j > 1; j--) printf(" ");
			printf("%d|", i);
			for (int j = 17 - digFrom; j > 1; j--) printf(" ");
			printf("%.2f|", from);
			for (int j = 17 - digNum; j > 1; j--) printf(" ");
			printf("%.2f|\n", matfunc11(from));
		}
		char b;
		b = getchar();
	}
	printf("=============================================================\n");
	char c;
	c = getchar();
	c = getchar();
	return 0;
}


double matfunc10(double x) {
	return (0.25 * (x - 25) * (x - 25) + (x + 25) * (x + 25) * (x + 25) / 100 + 1);
}

double matfunc11(double x) {
	// printf("\nis %f", 0.5*(x+250)*(x+250)*(x+250)-(x-125)*(x-125)+500);
	return (0.5 * (x + 250) * (x + 250) * (x + 250) - (x - 125) * (x - 125) + 500);
}