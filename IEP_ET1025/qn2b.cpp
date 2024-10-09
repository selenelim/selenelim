#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    int grade ;
    cout<<"Enter your grade : ";
    cin>> grade;
    if(grade>=60 && grade<=100)
    {
        cout<<"Grade is between 60 and 100 !";
    }
    else
    {
        cout<<"Invalid !!";
    }
}