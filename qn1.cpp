#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    double f , c;
    cout<<"Enter temperature in Celcius : ";
    cin>>c;
    f= (c * (9/5))+32;
    cout<<"Temperature is "<< setprecision(3)<<f<<" degrees farenheit";
}