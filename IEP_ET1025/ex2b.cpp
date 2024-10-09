#include <iostream>
using namespace std ;
#define PI 3.142;
int main()
{
    double radius, length, volume ;
    cout<<"Enter radius:";
    cin>>radius;
    cout<<"Enter length:";
    cin>>length;
    volume = PI * radius * radius * length;
    cout<<"Volume ="<<volume<<endl;
    return 0 ;
}