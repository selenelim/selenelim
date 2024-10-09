#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
    int i , zero_count=0 ;
    double data[5],max ;
    for (i=0 ; i<5 ; i++)
    {
        cout<<"Enter value for data ["<<i<<"]";
        cin>>data[i];
    }
    i=0;
    cout<<"Array elements are : ";
    while (i<5)
    {
        cout<<data[i]<<",";
        i++;
    }
    cout<<endl;
    max=data[0];
    for (i=1 ; i<5 ; i++)
    {
        if (data[i]>max)
        max=data[i];
    }
    cout<<"The highest element is "<<max<<"\n";
    for(i=0 ; i<5 ; i++)
    {
        if ( data[i]==0)
        {
            zero_count++;
        }
    }
    cout<<"The number of zeros is : "<<zero_count;
}