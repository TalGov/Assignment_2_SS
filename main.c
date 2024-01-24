#include "NumClass.h"
#include <stdio.h>

void main()
{
    int number1;
    int number2;
    int minNum;
    int maxNum;

    printf("\n Please enter the first number:");
    scanf("%d", $number1);
    while (number1 < 0)
    {
        printf("\n Error! Please enter the first number again:");
        scanf("%d", $number1);
    }
    
    printf("\n Please enter the second number:");
    scanf("%d", $number2);
    while (number2 < 0)
    {
        printf("\n Error! Please enter the second number again:");
        scanf("%d", $number2);
    }
    
    if(number1 < number2)
    {
        minNum = number1;
        maxNum = number2;
    }
    else
    {
        minNum = number2;
        maxNum = number1;
    }

    printf("\nThe Armstrong numbers are: ");
    for(int i = minNum; i<= maxNum; i++)
    {
       printf("%d ", isArmstrong(i));
    }
    printf("\nThe Palindromes are: ");
    for(int i = minNum; i<= maxNum; i++)
    {
       printf("%d ", isPalindrome(i));
    }
    printf("The Prime numbers are: ");
    for(int i = minNum; i<= maxNum; i++)
    {
        printf("%d ", isPrime(i));
    }
    printf("\nThe Strong numbers are: ");
    for(int i = minNum; i<= maxNum; i++)
    {
       printf("%d ", isStrong(i));
    }

}