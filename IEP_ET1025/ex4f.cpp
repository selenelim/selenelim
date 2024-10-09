#include <iostream>
#include<cmath>
using namespace std;

int main ()
{
    char grade ;
    cout<<"Enter your grade:";
    cin>>grade;
    switch(grade)
    {
    case 'A':case 'a': cout<<"Excellent";
    break;
    case 'B':case 'b': cout<<"Good";
    break;
    case 'C':case 'c': cout<<"Satisfactory";
    break;
    case 'D' :case 'd': cout<<"Poor";
    break;
    case 'F':case 'f': cout<<"FAIL";
    break;

    default:cout<<"INVALID";
    break;

    }
}