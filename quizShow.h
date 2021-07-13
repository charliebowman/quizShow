#ifndef QUIZSHOW_H
#define QUIZSHOW_H

void initialise_quiz(void); 
void question_prompt(void); 
void open_file_question(int);
void display_results(int);
void name_prompt(void); 
void retrieve_question(void); 
char* retrieve_answer(void); 
char* obtain_textfiles(void); 
char* randomize_questions(void); 
bool has_txt_extension(char const*); 

#endif
