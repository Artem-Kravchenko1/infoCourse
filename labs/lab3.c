#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double matfunc10(double x);
int compareSigns(double a, double b);
int checkTheDifs(double a, double b, int n);
int checkTheDif(double smallA, double smallB);
int findDerSign(double x);
int findRoots(double a, double b, int n);
double rootByChords(double a, double b);

double doubleMatFunc10 (double x) {
	return matfunc10(x);
}

int main() {
	double a, b, delta;
	unsigned int n;
	char inputVar;
	unsigned int rootsAmount = 0;

	while (true)
	{
		printf("Put the 1st point: ");
		scanf("%lf", &a);
		printf("Put the 2nd point: ");
		scanf("%lf", &b);
		printf("What do you wanna input - delta or n(d/n)?\n");
		scanf("%s", &inputVar);
		if (inputVar == 'd') {
			printf("Your delta: ");
			scanf("%lf", &delta);
			n = abs(b-a)/delta;
		} else if (inputVar == 'n') {
			printf("Your amount n is: ");
			scanf("%d", &n);
			delta = abs(b-a)/(float)n;
		} else continue;

		if (!checkTheDifs(a, b, n) && inputVar == 'd') {
			printf("Give smaller delta!\n");
			continue;
		} else if (!checkTheDifs(a, b, n) && inputVar == 'n') {
			printf("Put bigger amount!\n");
			continue;
		}

		
		rootsAmount = findRoots(a, b, n);
		printf("\n\nComplete amount of roots is %d\n--------------------\n\n", rootsAmount);
	}
}


double matfunc10(double x) {
	// return (0.25 * (x - 25) * (x - 25) + (x + 25) * (x + 25) * (x + 25) / 100 + 1);
	return x*x*sin(x);
}

int compareSigns(double a, double b) {
	if (a == 0 || b == 0) return 0;
	else if ((a>0 && b>0) || (a<0 && b<0)) return 1;
	else return -1;
}

int findDerSign(double x) {
	double smallDif = 1e-6;
	if (matfunc10(x+smallDif) - matfunc10(x)>0) return 1;
	else return -1;
}

int checkTheDif(double smallA, double smallB) {
	double smallDif = 1e-6;
	int derSign = findDerSign(smallA);
	int i = 1;

	for (; smallA < smallB; smallA += smallDif) {
		// if (i == 1000 || i == 10000 || i == 100000 || i == 1000000 || i == 10000000) printf("%d\n", i);
		if (findDerSign(smallA + smallDif) != derSign) {
			// printf("SmallA: %lf\n", smallA);
			return 0;
		}
		i++;
	}
	
	return 1;
}

int checkTheDifs(double a, double b, int n) {
	
	double dif = abs(b-a)/(float) n;
	int isGood;
	for (; a < b; a += dif) {
		if (compareSigns(matfunc10(a), matfunc10(a+dif)) >= 0) continue;
		isGood = checkTheDif(a, a + dif);
		if (!isGood) return 0;
	}
	return 1;
}

double rootByChords(double pointA, double pointB) {
	double root = pointB;
	for (int i = 0; i < 1e+6; i++) {
		root = root - matfunc10(root)/(matfunc10(root) - matfunc10(pointA))*(root-pointA);
	}
	return root;
}

int findRoots(double a, double b, int n) {
	double dif = abs(b-a)/(float) n;
	int rootsAmount = 0;
	double root;
	for ( ;a < b; a += dif) {
		// printf("\na: %lf\n", a);
		// printf("b: %lf\n", b);
		if (a == -2 || a == 1) printf("in compareSigns: %d", compareSigns(matfunc10(a), matfunc10(a+dif)));
		if (compareSigns(matfunc10(a), matfunc10(a+dif)) == 0) {
			if (matfunc10(a+dif) == 0) {
				rootsAmount++;
				root = a+dif;
				printf("1Root #%d: %lf\n", rootsAmount, root);
			} 
		}
		else if (compareSigns(matfunc10(a), matfunc10(a+dif)) == -1) {
			// printf("\na: %lf\n", a);
			rootsAmount++;
			root = rootByChords(a, a + dif);
			printf("2Root #%d: %lf\n", rootsAmount, root);
		}
	}
	return rootsAmount;
}