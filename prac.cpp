#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()
{
    int resistor1 , resistor2 ,total;
    char choice ;
    cout<<"Value of first resistor : ";
    cin>>resistor1;
    cout<<"Value of second resistor : ";
    cin>>resistor2;
    cout<<"PICK ONE : \n1.SERIES \n2.PARALLEL \nCHOICE ";
    cin>>choice;
    switch(choice)
    {
        case 1 : total = resistor1 + resistor2 ;
        break;
        case 2 : total = 1/(1/resistor1 +1/resistor2);
        break;
    }
    cout<<setprecision(4)<<total;
}