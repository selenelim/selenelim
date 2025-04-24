//NAME:Lim Sook Leng Selene
//ADM NO : 2404479
//CLASS : DCPE/FT/1A/01
#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main()
{
    double age,weight;
    double result ;
    cout<<"Enter your age : ";
    cin>>age;
    if (age>=21)
    {
        cout<<"Enter your weight : ";
        cin>>weight;
        result=((-age)/40)+sqrt((pow(1+(weight*weight),3)/(3*age)));
        cout<<"Your computed result is : "<<result;
    }
    else
    {
        cout<<"Your age must be 21 or older .";
    }
}