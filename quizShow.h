#ifndef QUIZSHOW_H
#define QUIZSHOW_H

#include <stdbool.h>

struct Gameplay {
	int result; 
	int firstQuestion;  
}; 

struct Gameplay game = {0, 1}; 

void initialise_quiz(void); 
void question_prompt(void); 
void open_file_question(int);
void display_results(int);
void name_prompt(void); 
void correct_prompt(void); 
void incorrect_prompt(void); 
void retrieve_question(char* textfile); 
char* retrieve_answer(char* textfile); 
char* obtain_textfiles(void); 
char** randomize_questions(void); 
bool has_txt_extension(char const*); 

#endif
