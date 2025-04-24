#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int count ;
    double number , sum , average ;
    
    count=0;
    sum=0;
    average = 0;

    cout<<"Enter Number ( 0 to terminate) :";
    cin>>number ;
    while (number!=0)
    {
        sum = sum +number;
        count=count+1;
        
        cout<<"\nEnter Number :";
        cin>>number;

    }
    if (count !=0)
    average = sum/count;
    cout<<"Your average is "<<average<<"\n";
    cout<<"Your sum is "<<sum<<"\n";
    cout<<"Your count is "<<count;
    
}