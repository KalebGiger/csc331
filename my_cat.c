#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_CHARS 255

int main(int argc, char *argv[]){
	FILE *fp;
	char file_name[MAX_FILE_NAME_CHARS], c;
	int i;

	for(i = 1; i < argc; i++){
		fp = fopen(argv[i], "r");   //Open file for read.

  		if (fp == NULL)
  		{
    			//printf("my_cat: cannot open file\n");    //Program prints error message 			and closes if file is not found            
    			exit(0);
  		}
		
		while((c=fgetc(fp)) != EOF){
         		putchar(c);
    		}
    		fclose(fp);
 	}
	return 0;
}
	//} 

//	if (fp == NULL) 
    //	{ 
    //    	printf("my_cat: cannot open file\n"); 
  //      	exit(1); 
    	
//	}
	//c = fgetc(fp); 
    	//while (c != EOF) 
    	//{ 
        //	for(i = 0; i < argc; i++){
			
	//	}
	//	printf ("%c", c); 
    //    	c = fgetc(fp); 
  //  	}  
//}
