CC = gcc 
CFLAGS = -std=c99 -Wall -Werror 

quizShow: quizShow.c questions.c
	$(CC) $(CFLAGS) quizShow.h quizShow.c questions.c -o quizShow

clean:
	rm quizShow
