#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    double t;
    cout<<"Enter temperature in degree celcius:";
    cin>> t;
    if (t<=100)
{
    cout<< "Ice";
}
else
{
    if (t>=100)
    {
        cout<<"steam";
    }
    else
    {
        cout<<"water";
    }
}