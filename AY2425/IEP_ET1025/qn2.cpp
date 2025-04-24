#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    int number , result1 , result2 ;
    cout<<"Enter the number : ";
    cin>> number;
    result1 =number % 2;
    result2 = number %3;
    if (result1 == 0 && result2 == 0)
    {
        cout<<"Number is divisible by both 2 and 3";
    }
    else
    {
        cout<<"Number is not divisible by both 2 and 3";
    }
}