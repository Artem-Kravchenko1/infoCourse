#include <stdio.h>
void one_three(void);
void two(void);

int main() {
	char beep[32] = "ї";
	printf("Start:\n");
	one_three();
	printf("Finished!");
	printf("%c, %d", beep, beep);
	return 0;
}

void one_three(void) {
	printf("One\n");
	two();
	printf("Three\n");
}

void two(void) {
	printf("Two\n");
}