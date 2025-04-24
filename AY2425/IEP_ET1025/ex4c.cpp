#include <iostream>
#include<cmath>
using namespace std;

int main()
{  int t;
    cout<<"Enter temperature in degree celcius:";
    cin>> t;
    if (t<=0)
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
}