#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
    double BMI, weight , height;
    cout<<"Enter your weight in kg : ";
    cin>>weight;
    cout<<"Enter yout height in m : ";
    cin>>height;
    BMI=weight/(height * height);
    cout<<BMI;
}

