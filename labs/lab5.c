#include <stdio.h>
#include <math.h>
FILE *in, *out, *outb;

double matfunc10(double x);
double matfunc11(double x);

int main() {

	int var;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	outb = fopen("outputb.txt", "wb");
	do
	{
		fscanf(in, "%d", &var);
		if (var != 1 && var != 2) {
			printf("Wrong variant, choose between 1 and 2!\n");
			return 0;
		}
	} while (var != 1 && var != 2);


	float from, to, step;
	fscanf(in, "%f", &from);
	fscanf(in, "%f", &to);
	fscanf(in, "%f", &step);
	fprintf(outb, "%d\n", (int)(abs((from-to)/step)));

	fprintf(out, "=============================================================\n");
	fprintf(out, "|                  N|                  X|                  Y|\n");
	fprintf(out, "=============================================================\n");
	for (int i = 1;from <= to; from += step, i++) {
		if (var == 1) {
			fprintf(out, "|%19d|", i);
			fprintf(out, "%19.2f|", from);
			fprintf(out, "%19.2f|\n", matfunc10(from));
			fprintf(outb, "%f %lf\n", from, matfunc10(from));

		}
		else {
			fprintf(out, "|");
			fprintf(out, "%19d|", i);
			fprintf(out, "%19.2f|", from);
			fprintf(out, "%19.2f|\n", matfunc11(from));
			fprintf(outb, "%f %lf\n", from, matfunc10(from));
		}
	}
	fprintf(out, "=============================================================\n");
	char group[5]; 
	char fname[20];
	char lname[10];
	fscanf(in, "%s", group);
	fprintf(out, "%s\n", group);
	fscanf(in, "%s", fname);
	fscanf(in, "%s", lname);
	fprintf(out, "%s %s", fname, lname);
	
	return 0;
}


double matfunc10(double x) {
	return (0.25 * (x - 25) * (x - 25) + (x + 25) * (x + 25) * (x + 25) / 100 + 1);
}

double matfunc11(double x) {
	return (0.5 * (x + 250) * (x + 250) * (x + 250) - (x - 125) * (x - 125) + 500);
}