#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int isWord, words = 0, chars = 0, lines = 0, i, count = 1, l = 0, w = 0, c = 0;
	char current;

	for(i = 1; i < argc; i++){

		if(strcmp("-l", argv[i]) == 0){
			l++;
		}
		else if(strcmp("-w", argv[i]) == 0){
			w++;
		}
		else if(strcmp("-c", argv[i]) == 0){
			c++;
		}
		
		else if(strcmp("-l", argv[i]) != 0 && strcmp("-w", argv[i]) != 0 && strcmp("-c", argv[i]) != 0){
			fp = fopen(argv[i], "r");
			if(fp == NULL){
				printf("my_wc: cannot open file\n");
				exit(1);
			}
			while((fscanf(fp, "%c", &current)) != EOF) {
				chars++;
				if(current == '\n')
					lines++;
				if(!isspace(current)){ //&& current != '\n'
					if(isWord != 1){
						words++;
						isWord = 1;
					}
				}
				else
					isWord = 0;
			}

			
			fclose(fp);
		}
	}

	if(l<2 && w<2 && c<2){

		if(l == 1)
			printf("%d ", lines);

		if(w == 1)
			printf("%d ", words);

		if(c == 1)
			printf("%d ", chars);

		if(l == 0 && w == 0 && c == 0){
			printf("%d %d %d ", lines, words, chars);
		}
		printf("%s\n", argv[count]);
	}
	else{
		printf("my_wc: [option ...] [file ...]");
		exit(1);
	}
		

	return 0;
	
}

