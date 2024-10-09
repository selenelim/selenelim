#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main()
{
    int number, count=0 ;
    cout<<"Enter an integer :";
    cin>>number;
    while(count<=10)
    {
        cout<<number << " x "<<count<<" = "<<number*count<<"\n";
        count++;
    }
}