#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	int i;
	FILE *fp;
	
	char *line = NULL;
	size_t len = 0;	
	
		if(argc == 1){
			printf("my_grep: searchterm [file ...]\n");
			exit(1);
		}

		if(argc == 2){
			while(getline(&line, &len, stdin) != -1){
				if(strcmp("", argv[1]) == 0) {printf("%s", line);}
				else {
					if((strstr(line, argv[1])) != NULL){
						printf("%s", line);
					}
				}
			}
			return 0;
		}

	for(i = 1; i < argc; i++){ //Traversing through command line arguments
		
		if(i > 1){
			fp = fopen(argv[i], "r");

			if(fp == NULL){
				printf("my_grep: cannot open file\n");
				exit(1);
			}
			if((fp = fopen(argv[i], "r")) == NULL) { //printf("my_grep: cannot open file\n");
				exit(1);
			}
			if(fp){
				while(getline(&line, &len, fp) != -1){
					if(strcmp("", argv[1]) == 0) {printf("%s", line);}
					if((strstr(line, argv[1])) != NULL){
						printf("%s", line);
					}
				}
			}
			else{
				if(getline(&line, &len, stdin) == -1){
					if((strstr(line, argv[1])) != NULL){
						printf("%s", line);
					}
				}
			}
			if(fp){
				fclose(fp);
			}
		}
	}
	return 0;
}
