#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main()
{
    double v , r , i ;
    int choice ;
    cout<<"SELECT YOUR CHOICE: \n 1.Voltage Calculation \n 2.Current Calculation \n 3.Resistance Calculation\n CHOICE ";
    cin>>choice;
    switch(choice)
    {
        case 1 : cout<<"Enter Resistance : ";cin>>r;cout<<"Enter Current : ";cin>>i;v=r*i;
        break;
        case 2 : cout<<"Enter Resistance : ";cin>>r;cout<<"Enter Voltage : ";cin>>v;i=v/r;
        break;
        case 3 : cout<<"Enter Voltage : ";cin>>v;cout<<"Enter Current : ";cin>>i;r=v/i;
        break;
    }
    cout<<"Voltage :"<<setprecision(3)<<v<<" volts"<<'\n';
    cout<<"Resistance :"<<setprecision(3)<<r<<" ohms"<<'\n';
    cout<<"Current : "<<setprecision(3)<<i<<" amperes"<<'\n';
}
