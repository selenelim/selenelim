#include <iostream>
using namespace std;
double average(double num1,double num2 ,double num3);
int main ()
{
    double num1 , num2 , num3 , avg;
    cout<<"Emter first number :";
    cin>>num1;
    cout<<"Enter second number : ";
    cin>>num2;
    cout<<"Enter third number : ";
    cin>>num3;
    avg=average(num1,num2,num3);
    cout<<"The average is "<<avg;
    return 0;
}
double average ( double num1 , double num2 , double num3)
{
    double local_avg;
    local_avg=(num1+num2+num3)/3;
    return local_avg;
}