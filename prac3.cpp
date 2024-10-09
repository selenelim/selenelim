#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    char operation ;
    double no1 , no2 , total;
    cout<<"Enter the first number : ";
    cin>>no1;
    cout<<"Enter the second number : ";
    cin>>no2;
    cout<<"Enter the operation [ + , - , x , / ] : ";
    cin>>operation;
    switch (operation)
    {
        case '+':
        total = no1 + no2;
        cout<<total;
        break;
        case '-':
        total = no1 - no2;
        cout<<total;
        break;
        case 'x':
        total = no1 * no2;
        cout<<total;
        break;
        case '/':
        total = no1 / no2;
        cout<<total;
        break;
        default:
        cout<<"Invalid operation ";
        break;
    }
}