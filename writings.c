/**************************
 *
 * writings.c
 * author: CLB
 *
 **************************/

#include <stdio.h>

int main(int argc, char** argv) {

	FILE* fp = fopen("writing.txt", "w"); 
	char newline[40]; 
	int count = 0;

	while ((fgets(newline, sizeof(newline), fp)) != NULL) {
		count++; 

		if (count == 1) {
		       fputs(newline, "You did good kid!");
		}	       
	
	}
	fprintf(fp, "that is groovy my guy"); 
	fclose(fp); 

}	
