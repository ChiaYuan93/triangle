#include "TryCatch.h"
#include "CException.h"
#include "ErrorCode.h"
#include <stdio.h>
#include <string.h>

int getIntegerNumber(char *ptrNumberText)
{
  if(ptrNumberText == NULL)
    Throw(ERR_TEXT_IS_NULL);
  else if(ptrNumberText[0] == '\0')
    Throw(ERR_TEXT_IS_EMPTY);
  else 
  {
    int i;
    for(i = 0; i < strlen(ptrNumberText); i++)
    {
      if((ptrNumberText[i]) == '.')
        Throw(ERR_CANNOT_BE_FLOAT_NUMBER);
      if (!isdigit(ptrNumberText[i]))
        Throw(ERR_NOT_A_NUMBER);

    }
  }
  return atoi(ptrNumberText);
}

int getPositiveIntegerNumber(char *ptrNumberText)
{
  int number = getIntegerNumber(ptrNumberText);
  if(number < 0)
    Throw(ERR_NOT_A_POSITIVE_NUMBER);
  return number;
}
void printIntegerNumberError(int errorCode)
{
  switch(errorCode)
    {
      case ERR_TEXT_IS_NULL:
        printf("The text cannot be NULL\n");
        break;
      case ERR_TEXT_IS_EMPTY:
        printf("The text cannot be empty\n");
        break;  
      case ERR_NOT_A_NUMBER:
        printf("The text is not a number\n");
        break;
      case ERR_CANNOT_BE_FLOAT_NUMBER:
        printf("The text cannot be a floating number\n");
        break;
      case ERR_NOT_A_POSITIVE_NUMBER:
        printf("The text is not a positive number\n");
        break;
      default:
        printf("Unknown error caught! Error code is: %d\n", errorCode);
        break;
        
    }
    
}

void tryCatch()
{
  int number;
  CEXCEPTION_T error;
  
  Try
  {
    printf("Convert number\n");
    number = getPositiveIntegerNumber("34.a5");
    printf("the number  is %d\n", number);
    //Throw(34);
  }
  Catch(error)
  {
    printIntegerNumberError(error);
    printf("Error caught! Error code is : %d\n",  error);
  }

}