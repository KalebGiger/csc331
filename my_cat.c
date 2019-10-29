#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_CHARS 255

int main(int argc, char *argv[]){
	FILE *fp;
	char c;
	int i;

	for(i = 1; i < argc; i++){
		fp = fopen(argv[i], "r");   //Open file for read.

  		if (fp == NULL)
  		{
    			printf("my_cat: cannot open file\n");          
    			exit(1);
  		}
		
		while((c=fgetc(fp)) != EOF){
         		putchar(c);
    		}
    		fclose(fp);
 	}
	return 0;
}

