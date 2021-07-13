/*****************
 * 
 * quizShow.c
 * author: CLB
 *
 *****************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "quizShow.h"

struct Gameplay {
  	int result; 
	int round; 
};	

struct Gameplay game = {0, 1}; 

void display_question(int q) {

	char answers[10]; 	

	if (q == 0) {
		open_file_question(q); 
		question_prompt();
	    if (game.round == 1) { 	
			scanf("%c", &answers[q]);
		}
		if (game.round == 0) {
			scanf(" %c", &answers[q]); 
		}	
		if (answers[q] == 'B' || answers[q] == 'b') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2);
		       	game.result += 1;
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
			 	
	}

	if (q == 1) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'D' || answers[q] == 'd') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}

	
	if (q == 2) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'C' || answers[q] == 'c') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}


	if (q == 3) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'C' || answers[q] == 'c') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}


	if (q == 4) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'A' || answers[q] == 'a') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}


	if (q == 5) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'A' || answers[q] == 'a') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}
	
	if (q == 6) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'A' || answers[q] == 'a') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}
	

	
	if (q == 7) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'D' || answers[q] == 'd') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1;
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}


	if (q == 8) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'A' || answers[q] == 'a') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}


	if (q == 9) {
		open_file_question(q); 
		question_prompt(); 
		scanf(" %c", &answers[q]); 
		if (answers[q] == 'B' || answers[q] == 'b') {
			printf("\nCongratulations you got it correct !\n\n");
			sleep(2); 
			game.result += 1; 
		} else {
			printf("\nThat is incorrect !\n\n"); 
			sleep(2); 
		}
		system("clear"); //unix/linux
	}


}
 
int main(int argc, char** argv) {
  
	char finished; 

	initialise_quiz();
	name_prompt(); 

	while (1) {
		for (int count = 0; count < 10; count++) {
			printf("\n\n\n"); 
			display_question(count);  
		}

		display_results(game.result);
		game.result = 0;

		scanf(" %c", &finished);  
		if (finished == 'y') {
			system("clear");
		       	game.round = 0; 	
			continue;  
		}	

		if (finished == 'n') {
			break; 
		}	
	}
}

