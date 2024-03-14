#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired (){
    printf("The length of your text is less than specified, please update your text\n");
}

void equalThanRequired (){
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired (){
    printf("Your text is too long, please reduce the text\n");
}

int checkLenghtRequirement(char* text){
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else if (length <= MAX_LENGTH)  // Added condition for maximum length
        return 2;
    else
        return 3; //when length exceeds MAX_LENGTH
}

int main() {
    int length, lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLenghtRequirement(text);

    void (*functions[3])() = {lessThanRequired, equalThanRequired, moreThanRequired};
    lengthOfText = (MIN_LENGTH * (selectOption == 0)) + (MIN_LENGTH * (selectOption == 2));

    functions[selectOption]();

    printf("\nThe Length is updated to %d", lengthOfText);

    return 0;
}