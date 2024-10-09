#include <iostream>
using namespace std;
void printsum(int sum);
int main()
{
    int num1,num2,sum;
    cout<<"Enter the first number :";
    cin>>num1;
    cout<<"ENter the second number : ";
    cin>>num2;
    sum=num1+num2;
    printsum(sum);
    return 0;
}
void printsum (int sum)
{
    cout<<"The sum is "<<sum;
    return;
}