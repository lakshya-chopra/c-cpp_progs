#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

char * words[] = {"Hi!","When","will","you","get","a","job"}; 
int wordCount = 7;
//a pointer array of char *, i.e. one which stores pointers to char * element.

void printSentence(char **words){

	int i = 0;
	while(i<wordCount){
		printf("%s ",*words);
		words++;
		i++;
	}
	return;

}

int main(){

	while(true){

		printf("Here's the string, right now:\n");
		printSentence(words);

		char inp;
		printf("\nWould you like to any more word? (y/n):\n");
		scanf(" %c",&inp); //I have added a space before

		if (inp == 'y' || inp == 'Y'){

			char word[50];
			printf("Enter the next word: \n");
			scanf("%s",word); //https://stackoverflow.com/a/34078801
			words[wordCount++] = strdup(word);

		}
		else{
			break;
		}


	}
	return 0;
}