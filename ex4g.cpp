#include <iostream>
#include<cmath>
using namespace std;

int main ()
{
    double R1,R2,TOTAL;
    int choice;
    cout<<"Enter the value of first resistor:";
    cin>>R1;
    cout<<"Enter the value of second resistor:";
    cin>>R2;
    cout<<"1.Series Connection\n2.Parallel Connection\nEnter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1: TOTAL = R1 + R2;
    break;
    case 2 : TOTAL=1/(1/R1+1/R2);
    break;
    }
    cout<<"Total resistance is"<< TOTAL<<" OHMS";
}