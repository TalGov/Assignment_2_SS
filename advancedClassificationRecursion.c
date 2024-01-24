#include "NumClass.h"

int isArmstrong(int num)
{
    int count_d = countDigits(num);
    int tempN = num;
    
    if (num < 0)
    {
        return 0;
    }
    num = num % 10 ;
    tempN = num/10 ;
    
    return ((factorial(num)+ isArmstrong(tempN)) == num);

}
int isPalindrome(int num)
{
    int count_d = countDigits(num);

    if (num < 0)
    {
        return 0;
    }

    if( num >= 0 && num <= 9 )
    {
        return 1;
    }
    
    int tempLast= num % 10 ; 
    int tempFirst= num / (power(num, count_d - 1));
   
    if(tempFirst != tempLast)
    {
        return 0;
    }
    
    num = num /10;
    num = num % (power(num, count_d - 2));
    
    return isPalindrome(num); 
}