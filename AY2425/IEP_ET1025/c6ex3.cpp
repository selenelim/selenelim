#include <iostream>
using namespace std;
void displaySum(int sum);
int main()
{
    int num1,num2,sum;
    cout<<"Enter a number : ";
    cin>>num1;
    cout<<"Enter a second number : ";
    cin>>num2 ;
    sum=num1+num2;
    displaySum(sum);
    return 0;
}
void displaySum(int sum)
{
    cout<<"The sum is :"<<sum;
    return;
}