#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matriceMinMax(int **X, int n);
void transportedMatrice(int **B, int n, int m);
void printMatrice(int **X, int n, int m);
int** multiplyMatrices(int **A, int **B, int n, int m);
int sortRow(int *row, int n, int start);
int sortMatrice(int **A, int n, int start);
void printSum(int **A, int **B, int n, int m);
void swap(int *a, int *b);

int main() {
	int n, m;

	printf("\nYour n: ");
	scanf("%d", &n);
	printf("Your m: ");
	scanf("%d", &m);
	int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        A[i] = (int*)malloc(n * sizeof(int));

	int** B = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        B[i] = (int*)malloc(m * sizeof(int));
	
	int** C = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
        C[i] = (int*)malloc(m * sizeof(int));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = (i == j)? 1 : 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
			B[i][j] = i + j;

	int choice, c;
	int a = 1;
	int b = 2;
	swap(&a, &b);
	printf("a: %d, b: %d", a, b);
	while (true) {

		printf("\nA: \n");
		printMatrice(A, n, n);
		printf("B: \n");
		printMatrice(B, n, m);

		printf("Choose the command:\n1 - show min and max of A\n2 - show transported B\n3 - show multiplied C\n4 - sort a row\n5 - sort A matrice\n6 - sum of rows and columns\n");
		scanf("%d", &choice);
		printf("Choice: %d\n", choice);
		// printf("sth");
		switch (choice)
		{
			case 1:
				matriceMinMax(A, n);
				break;

			case 2:
				printf("\n");
				transportedMatrice(B, n, m);
				break;
			
			case 3:
				C = multiplyMatrices(A, B, n, m);
				break;
			
			case 4:
				printf("Select the row: ");
				int rowNum;
				scanf("%d", rowNum);
				printf("Sorted row %d:\n", rowNum);
				sortRow(A[rowNum], n, 0);
				printMatrice(A, n, n);
				break;

			case 5:
				printf("Sorted matrice A:\n");
				sortMatrice(A, n, 0);
				printMatrice(A, n, n);
				break;

			case 6:
				printSum(A, B, n, m);
				
			default:
				break;
		}
		c = getchar();
		c = getchar();
	}
}

void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void swap2(int *a, int *b) {

}

void printMatrice(int **X, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			printf("%3d ", X[i][k]);
			// printf("i: %d, j: %d\n", i, k);
		}
		printf("\n");
	}
	printf("\n");
}

void matriceMinMax(int **X, int n) {
	int max = X[1][0];
	int min = X[1][0];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if (X[i][j] > max) max = X[i][j];
			else if (X[i][j] < min) min = X[i][j];
		}
	}
	printf("Max value is: %d\n", max);
	printf("Min value is: %d\n", min);
}

void transportedMatrice(int **B, int n, int m) {
	int** C = (int**)malloc(m * sizeof(int*));
	// printf("sth");
    for (int i = 0; i < m; i++)
        C[i] = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			// printf("%d, %d\n", i, k);
			C[i][k] = B[k][i];
		}
	}
	printf("Transported B: \n");
	printMatrice(C, m, n);
}

int** multiplyMatrices(int **A, int **B, int n, int m) {
	int** C = (int**)malloc(n * sizeof(int*));
	int sum;
	// printf("sth");
    for (int i = 0; i < n; i++)
        C[i] = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			// printf("%d, %d\n", i, k);
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += A[i][j]*B[j][k];
			}
			C[i][k] = sum;
		}
	}
	printf("Multiplied: \n");
	printMatrice(C, n, m);
	return C;
}

int sortRow(int *row, int n, int start) {
	if (start == n) return 0;
	int min = row[start];
	int temp;
	for (int i = start; i < n; i++) {
		if (row[i] < min) {
			min = row[i];
			row[i] = row[start];
			row[start] = min;
		}
	}
	return sortRow(row, n, start+1);
}

int sortMatrice(int **A, int n, int start) {

	if (start == n*n) return 0;
	int min = A[start/n][start%n];
	int temp;
	for (int i = start; i < n*n; i++) {
		if (A[i/n][i%n] < min) {
			min = A[i/n][i%n];
			A[i/n][i%n] = A[start/n][start%n];
			A[start/n][start%n] = min;
		}
	}
	return sortMatrice(A, n, start+1);
}

void printSum(int **A, int **B, int n, int m) {
	int sum;
	printf("Matrice A rows sums:\n");
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += A[i][j];
		}
		printf("Row %d: %d\n", (i+1), sum);
	}
	printf("\nMatrice B columns sums:\n");
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += B[j][i];
		}
		printf("Column %d: %d\n", (i+1), sum);
	}
	printf("\n");
}
