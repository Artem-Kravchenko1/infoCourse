#include <stdio.h>


int strlen(char s[]);
int main() {
	char beep[32] = "ї";
	printf("Start:\n");
	printf("Finished! %d", strlen("Hello"));
	printf("%c, %d", beep, beep);
	return 0;
}

int strlen(char *s) {
	char *k = s;
	char *p = k;

	while (*p != '\0')
		p++;
	return p - s;
}