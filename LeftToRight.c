/*
 * NAME: Alana Ruth
 *
 * Carries out a strict left-to-right evaluation of an arithmetic expression
 * consisting of integer constants and the operators +, -, *, and /.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * deleteSpaces(char*);

int main (void){

  //Array of characters to hold the user's entered expression
  char userExpression[200];
  //Array of characters to hold the algebraic expression without spaces
  char algExpression[200];


  //Prompt user for an expression and read in the expression char by char
  printf("Please enter an expression: "); fflush(stdout);
  fgets(userExpression, 200, stdin);

  //Deletes all spaces from userExpression and assigns the new array to algExpression
  strncpy(algExpression, deleteSpaces(userExpression), 200);

  //Declare an int to hold your answer and assign answer to the first inputted char
  int i = 0;
  int answer = algExpression[i] - '0';

  i++;
  //While loop to iterate for each char in the expression array
  while (algExpression[i] != '\n'){
    switch (algExpression[i]) {
    case '-':
      answer -= (algExpression[i+1] - '0');
      break;
    case '+':
      answer += (algExpression[i+1] - '0');
      break;
    case '*':
      answer *= (algExpression[i+1] - '0');
      break;
    case '/':
      answer /= (algExpression[i+1] - '0');
      break;
    default:
      break;
    }
    i++;
  }

  //Print the answer
  printf("Strict left-to-right value: %d\n", answer); fflush(stdout);
  return 0;
}


char * deleteSpaces(char *expression){
  char *output = expression; //points to expression
  char *temp = expression;   //points to expression

  //while the expression is not null
  while (*expression != '\0'){
    if (*expression != ' ')
      *temp++ = *expression;
    expression++;
  }

  *temp = '\0';

  //returns array without spaces
  return output;
}

