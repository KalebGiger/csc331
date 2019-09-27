#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[]){
	FILE *fp;
	int num, sum, size;
	int *arr;

	size = 10;
	arr = malloc(sizeof(int) * size);

	fp = fopen(argv[1], "r");

	if(fp == NULL){
		printf("Cannot open file");
		exit(1);
	}
	else{

		for(int i = 0; i < size; i++){
			fscanf(fp, "%d", &num);
			sum += num;
		}

		printf("%d", sum);
		fclose(fp);
	}
}
