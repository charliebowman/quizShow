/*********************
 *
 * questions.c
 * author: CLB
 *
 *********************/ 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>

#define TOTALFILES 100
#define FILELENGTH 20
#define QUESTIONSTOTAL 10

void initialise_quiz(void) { 
	system("clear"); // unix based system 
	sleep(1); 
	printf("\n\n\nWelcome to \"CHARLIE'S QUESTIONNAIRE\" !\n\n");
	fflush(stdout); 
	sleep(2); 
   	printf("Answer as many questions as you can correctly\n\n");
	fflush(stdout); 
    sleep(4); 	
	system("clear"); 
}

void question_prompt(void) {
	printf("\nType a, b, c or d followed by enter: "); 
}

void correct_prompt(void) {
	printf("\nCongratulations you got it correct !\n\n"); 
	sleep(2); 
	system("clear"); 
}

void incorrect_prompt(void) {
	printf("\nThat is incorrect !\n\n"); 
	sleep(2); 
	system("clear"); 
}

void name_prompt(void) {
	
	int newPlayer = 1; 
	char input[15];
	char firstName[15];
    char lastName[15];
	char playerFile[40]; 
	FILE* player;	

	printf("\nWhat is your first name? \n");
   	fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", firstName); 
	fflush(stdout); 
	sleep(1); 
	printf("\nWhat is your last name? \n");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%s", lastName);
	
	playerFile[0] = '\0'; 
	strcpy(playerFile, firstName); 
    strcat(playerFile, lastName); 

	if (access(playerFile, F_OK) == 0) {
		newPlayer = 0; 
	} else {
		player = fopen(playerFile, "w"); 
		fprintf(player, "%s %s", firstName, lastName); 
		fclose(player);
	}

	fflush(stdout); 
	sleep(1); 
	if (newPlayer) {
		printf("\nEnjoy the quiz %s :) !", firstName);
	} else {
		printf("\nWelcome back %s!", firstName); 
	}
	fflush(stdout);  
	sleep(3); 
	system("clear"); // unix/linux	
}

void display_results(int result) {
	system("clear"); 
	printf("\n\n\nYou got %d/10 correct answers!\n\n", result);
    fflush(stdout);
    sleep(1); 
	printf("Do you want to try again?\n");
	fflush(stdout); 
	sleep(1); 
    printf("\nPress y for yes OR n for no followed by enter: "); 	
}

void open_file_question(int textNumber) {

	char textlist[10][15] = {
		"question1.txt", 
		"question2.txt", 
		"question3.txt",
		"question4.txt", 
		"question5.txt", 
		"question6.txt",
		"question7.txt", 
		"question8.txt",
		"question9.txt", 
		"question10.txt"
	};

	FILE* questionFiles = fopen(textlist[textNumber], "r"); 
	char buffer[256]; 

	if (questionFiles) {
		while(fgets(buffer, sizeof(buffer), questionFiles)) {
			fputs(buffer, stdout); 
		}
		fclose(questionFiles); 
	} else {
		fprintf(stderr, "Could not open that question."); 
		perror(0); 
		errno = 0;
	}	
} 

void retrieve_question(char* textfile) {
	FILE* question = fopen(textfile, "r"); 
	char buffer[256]; 
	size_t count = 0; 
	
	if (question) {
		while (1) {
			char* c = 0; 
			while ((c = fgets(buffer, sizeof(buffer), question)) != 0) {
				if (buffer[0] == '\n') {
					count++; 
				}
				printf("%s", buffer); 
				break;
			}
			if (count == 2)
				break; 
		}	
		fclose(question);
	} else {
		fprintf(stderr, "Could not open that question."); 
		perror(0); 
		errno = 0; 
	}
}

char* retrieve_answer(char* textfile) {
	FILE* answer = fopen(textfile, "r"); 
	char* buffer; 
	int len = strlen(textfile); 

	buffer = malloc(sizeof(char)  * (len + 1)); 
	if (fseek(answer, -2, SEEK_END) != 0) {
		perror("Failed to read"); 
		fclose(answer); 
		exit(0); 
	}
	fgets(buffer, sizeof(buffer), answer); 
	return buffer;  
}

bool has_txt_extension(char const* name) {
	size_t len = strlen(name); 
	return len > 4 && strcmp(name + len - 4, ".txt") == 0; 
}

size_t textfile_amount(void) {
	DIR* dir = opendir("."); 
	size_t len = 0; 
	struct dirent* entity; 
	entity = readdir(dir); 
	while (entity != 0) {
		if (has_txt_extension(entity->d_name)) {
			len++; 
		}
		entity = readdir(dir); 
	}
	closedir(dir); 
	return len; 
}

char** obtain_textfiles(void) {
	DIR* dir = opendir(".");
	size_t count = 0; 
	char** textfiles = malloc(sizeof(char*) * TOTALFILES);

	for (size_t i = 0; i < TOTALFILES; i++) {
		textfiles[i] = malloc(sizeof(char) * FILELENGTH);
	} 

	struct dirent* entity; 
	entity = readdir(dir); 
	while(entity != 0) {
		if (has_txt_extension(entity->d_name)) {
			textfiles[count] = entity->d_name;
			count++; 
		}
		entity = readdir(dir); 
	}

	closedir(dir); 
	return textfiles; 
}

char** randomize_questions(void) {
	int i, j, k; 
	size_t totalTextfiles = textfile_amount(); 
	char temp[FILELENGTH]; 

	char** questions = obtain_textfiles();
	srand(time(NULL)); 

	for (i = 0; i < totalTextfiles; i++) {
		j = rand() % totalTextfiles; 
		k = rand() % totalTextfiles; 
		if (j != k) {
			strcpy(temp, questions[j]); 
			strcpy(questions[j], questions[k]); 
			strcpy(questions[k], temp); 
		}
	}
	return questions;
} 		

