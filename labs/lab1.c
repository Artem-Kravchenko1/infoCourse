#include <stdio.h>
#include <stdlib.h>

#define Name "Artem"
#define LastName "Kravchenko"
#define GroupName "RE-41"
#define Faculty "RTF"
#define University "Igor Sikorsky Kyiv Polytechnic Institute"

int main()
{
	unsigned int semestr;
	float admissionScore;
	int grade1;
	int grade2;
	int grade3;
	double averageGrade;
	unsigned int age;

	printf("%s %s Enter following data.\n", Name, LastName);

	printf("Enter semestr: ");
	scanf("%u", &semestr);

	printf("Enter your admission score: ");
	scanf("%f", &admissionScore);

	printf("Enter grade #1: ");
	scanf("%d", &grade1);

	printf("Enter grade #2: ");
	scanf("%d", &grade2);

	printf("Enter grade #3: ");
	scanf("%d", &grade3);

	printf("Enter your age: ");
	scanf("%u", &age);

	averageGrade = (double)(grade1 + grade2 + grade3) / 3;

	system("cls");
	printf("%s\n", University);
	printf("%s\n", Faculty);
	printf("%s\n", GroupName);
	printf("---------------------------\n");
	printf("student: %s %s\n", Name, LastName );
	printf("age: %u\n", age);
	printf("semestr: %u\n", semestr);
	printf("---------------------------\n");
	printf("admission score: %.2f\n", admissionScore);
	printf("\naverage grade = %.3lf\n", averageGrade);
	printf("\n");



	return 0;
}