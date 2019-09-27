#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char *argv[]){
	FILE *fp = fopen(argv[1], "r");
	int i, j, x;
	int tmp;
	int size = 0;
	int *arr;
	int *num;
	int number;
	int numbers = 0;

	//int size = sizeof(arr) / sizeof(arr[0]);

	if(fp == NULL){
		printf("Cannot open file");
		exit(1);
	}

		while((tmp = fgetc(fp)) != EOF){
			if(!isdigit(tmp)){
				//if(number != 1){
					size++;
				//}
			}
			//else{
			//	number = 0;
			//}
			//size = sizeof(arr) / sizeof([0]);
		}
		//arr[size];
		num[size];
		//num[size];
		fclose(fp);

		fp = fopen(argv[1], "r");

		fscanf(fp, "%d", &numbers);
		for(i = 0; i < size; i++){
			fscanf(fp, "%d", &num[i]);
		}
//		for(i=0; i <=size; i++){
//		printf("%d", num[i]);
//}
			for(i = 0; i < size; i++){
				for(j = i + 1; j < size; j++){
					if(num[i] > num[j]){
						x = num[i];
						num[i] = num[j];
						num[j] = x;
					}
				}
			}
		
		for(i = 0; i < size - 1; i++){
			printf("%d ", num[i]);
		}

	fclose(fp);
//	free(num);

	return 0;
}
