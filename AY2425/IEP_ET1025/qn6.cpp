#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    int a , b , c ;
    cout<<"Enter length of side 1 : ";
    cin>>a;
    cout<<"Enter length of side 2 : ";
    cin>>b;
    cout<<"Enter length of side 3 : ";
    cin>>c;
    if (a==b && b==c)
    {
        cout<<"The triangle is a equilateral triangle";
    }
    else if (a==b || b==c || c==a)
    {
        cout<<"The triangle is an isoceles triangle";
    }
    else
    {
        cout<<"The triangle is an scalene triangle ";
    }
}