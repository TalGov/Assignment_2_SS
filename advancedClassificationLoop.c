#include "NumClass.h"

int isArmstrong(int num)
{
    int count_d = countDigits(num);

    if (num < 0)
    {
        return 0;
    }

    int sum = 0;
    int tempN = num;
    
    for(int i = 0; tempN != 0 ; i++)
    {
        sum = sum + power(tempN % 10, count_d);
        tempN = tempN / 10 ; 
    }    

    if(sum == num)
    {
        return 1;
    }
    return 0;
   
}
int isPalindrome(int num)
{
    int count_d = countDigits(num);
    int arr[12] = {0};
    int tempN = num;

    if(num < 0)
    {
        return 0;
    }
    
    for(int i=0; i < count_d ; i++)
    {
        arr[i] = tempN % 10;
        tempN = tempN / 10;
    }
    for(int i=0 ; i <= count_d /2 ; i++)
    {
        int j= count_d-1-i ;  
        if( (arr[i] - arr[j]) != 0)
        {
            return 0;
        }
    }
    return 1;
}

int countDigits(int num)
{
    int count = 0;
    int tempN = num;

    for(int i = 0; tempN != 0 ; i++)
    {
        tempN = tempN/10 ;
        count++ ;
    }
    return count;
}

int power(int x , int _power)
{
    int res = 1;

    for(int i=1; i<= _power; i++)
    {
        res = res * x ; 
    }
    return res;
}