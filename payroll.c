#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	double total_payment;
	char *first_name;
	char *last_name;

	first_name = argv[1];
	last_name = argv[2];
	int hours_worked = atoi(argv[3]);
	double hourly_rate = atof(argv[4]);

	if(argc = 4) {
		total_payment = hours_worked * hourly_rate;
		printf("%s, %s: %.2lf", last_name, first_name, total_payment);
	}
	else {
		printf("You must enter four arguments.\n");
	}
	return 0;
}
