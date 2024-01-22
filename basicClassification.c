#include <NumClass.h>

int isStrong(int num)
{
    int* digits_num = decomposeDigits(num);
    int sum = 0;

    for(int j= 0 ; j <= sizeof(digits_num) ; j++)
    {
        sum = sum + factorial(digits_num[j]);
    }    

    if(sum == num)
    {
        return 1;
    }
    return 0;
}

int isPrime(int num)
{
    for(int i=2; i*i < num; i++)
    {
         if ( num % i == 0 )
         {
            return 0;
         } 
    }
    return 1;
   
}

int* decomposeDigits(int num)
{
    int digits [12] = {0};
    int tempN = num; 
  
    for(int i = 0; tempN != 0 ; i++)
    {
        digits[i] = tempN % 10 ;
        tempN = tempN/10 ;
    }
    return digits;
}
int factorial (int num)
{
    if(num == 1)
    {
        return 1;
    }
    return (num * factorial(num-1));
}