#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
    char string[] = "Wizard";
    int number1, number2, sum;
    char operator;
    int  finalStatement = 0;
    int  num = atoi (argv[2]);
    if (strcmp(argv[1], string) == 0)
    {
	    

    // FOr loop to have the calulator run six times at max
    for(int i =0; i<6; i++){
    // Promps a user enter a math opperation
    printf("Enter an opperation of whole numbers only: ");
    scanf("%d%c%d" , &number1, &operator, &number2);
    //Switch staements based off the opperation entered by the user
    switch(operator)
    {
        case '+': //For any case with addition
            sum = number1 + number2;
            printf("%s says the sum of %d and %d is %d\n", string, number1, number2, sum);
            //if staemnt to see if any number entered is the magic number
            if (number1 == num || number2 == num)
            {
                   printf("\nWizard says you got the magic number: %d  ................WHOOOOOOOOOOO!!!!\n", num);
            }
	    break;
        case '-': //For any case with subtraction
            sum = number1 - number2;
            printf("%s says the sum of %d and %d is  %d\n", string, number1, number2, sum);
            //if staemnt to see if any number entered is the magic number
            if (number1 == num || number2 == num)
            {
                   printf("\nWizard says you got the magic number: %d  ................WHOOOOOOOOOOO!!!!\n", num);
            }
	    break;
        case '*': //For any case with mutplication
            sum = number1 * number2;
            printf("%s says the sum of %d and %d is %d\n", string, number1, number2, sum);
            //if staemnt to see if any number entered is the magic number
            if (number1 == num || number2 == num)
            {
                   printf("\nWizard says you got the magic number: %d  ................WHOOOOOOOOOOO!!!!\n", num);
            }
	    break;
        case '/': // For any case with divsion
            sum = number1 / number2;
            printf("%s says the sum of %d and %d is %d\n", string, number1, number2, sum);
            //if staemnt to see if any number entered is the magic number
	        if (number1 == num || number2 == num)
            {
                   printf("\nWizard says you got the magic number: %d  ................WHOOOOOOOOOOO!!!!\n", num);
            }
            break;
            break;
        case '%': //For any case finding the remainder 
            sum = number1 % number2;
            printf("%s says the sum of %d and %d is %d\n", string, number1, number2, sum);
            //if staemnt to see if any number entered is the magic number
	        if (number1 == num || number2 == num)
            { 
                   printf("\nWizard says you got the magic number: %d  ................WHOOOOOOOOOOO!!!!\n", num);
            }
            break;
        default: //Default case if the user enters something wrong 
            printf("%s says you cannot do that I can only do +, -, *, /, and %.\n", string);
	    finalStatement += 1;
            break;
    }
    }
}
//if statement to see if there any errros and if there is any it primts the magic number 
if (finalStatement > 0) 
{
    printf("%s says the magic number is: %d \n", string, num);
}
    printf("The magic number is %d\n", num);
}