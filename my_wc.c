#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int words = 0, chars = 0, lines = 0, i, count = 1, l = 0, w = 0, c = 0;
	char prev, current;

	for(i = 1; i < argc; i++){

		if(strcmp("-l", argv[i]) == 0){
			count++;
			l++;
		}
		else if(strcmp("-w", argv[i]) == 0){
			count++;
			w++;
		}
		else if(strcmp("-c", argv[i]) == 0){
			count++;
			c++;
		}
		
		else{
			fp = fopen(argv[i], "r");
			if(fp == NULL){
				printf("my_wc: cannot open file\n");
				exit(1);
			}
			while((fscanf(fp, "%c", &current)) != EOF) {
				chars++;
				if(current == '\n')
					lines++;
				if (isspace(current)) 
					words++;
				prev = current;
			}
			fclose(fp);
		}
	}
	if (argc == 1) {
    		printf("my_wc: [option ...] [file ...]\n");   
   		exit(1);
  	}
		
	if(l == 1)
		printf("%d ", lines);
	if(w == 1)
		printf("%d ", words);
	if(c == 1)
		printf("%d ", chars);
	if(l == 1 || w == 1 || c == 1)
		printf("%s\n", argv[count]);
	else{
		printf("my_wc: [option ...] [file ...]\n"); 
		exit(1);
	}
		

	return 0;
	
}

