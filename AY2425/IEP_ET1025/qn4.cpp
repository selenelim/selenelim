#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    double Vs , Vo , angle ;
    cout<<"Enter the value of Vs : ";
    cin>>Vs;
    cout<<"Enter the value of angle within the range of 0 to 3.142 : ";
    cin>>angle;
    Vo =Vs*sqrt(1+((sin(2*angle)-2*angle)/2*PI));
    cout<<Vo;
}