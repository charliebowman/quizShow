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
#include <stdbool.h>

int main(int argc, char** argv) {
  
	char** questions = randomize_questions(); 
	initialise_quiz();
	name_prompt();
		
	char finished;	
	char answers[10]; 

	while (1) {
		for (int count = 0; count < 10; count++) {
			printf("\n\n\n");
			retrieve_question(questions[count]);
			question_prompt();
			if (game.firstQuestion) {
			 	scanf("%c", &answers[count]);
				game.firstQuestion = 0; 
			} else {
				scanf(" %c", &answers[count]); 
			}
			char* answer = retrieve_answer(questions[count]);
		  	if (answers[count] == answer[0]) {
				correct_prompt();
				game.result += 1;  
			} else { 
				incorrect_prompt();  
			}
		}

		display_results(game.result);
		game.result = 0;

		scanf(" %c", &finished);  
		if (finished == 'y') {
			system("clear");
			continue;  
		}	

		if (finished == 'n') {
			break; 
		}	
	}
}

