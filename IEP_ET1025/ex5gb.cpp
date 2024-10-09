#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main()
{
    int number, count=0 ;
    cout<<"Enter an integer :";
    cin>>number;
    while(number!=10)
    {
        count=0;
        while(count<=10)
        {
            cout<<number<<" x "<<count<<" = "<<number*count<<"\n";
            count++;

        }
        cout<<"Enter another integer :";
        cin>>number;
    }
}