#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    int x , y ,z ;
    cout<<"Enter value of x : ";
    cin>>x;
    cout<<"Enter value of y : ";
    cin>>y;
    cout<<"Enter value of z : ";
    cin>>z;
    if(z>y && y>x)
    {
        cout<<"Values are in ascending order";
    }
    else
    {
        cout<<"Values are not in ascending order";
    }
}