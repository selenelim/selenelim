#include <iostream>
using namespace std;
int smallestInt(int num1 ,int num2 , int num3);
int main ()
{
    int num1 ,num2 , num3 ,smallest;
    cout<<"Enter the first number : ";
    cin>>num1;
    cout<<"Enter the second number : ";
    cin>>num2;
    cout<<"Enter the thrid number : ";
    cin>>num3;
    smallest = smallestInt(num1,num2,num3);
    cout<<"The smallest number is : "<<smallest;
    return 0;
}
int smallestInt (int num1 ,int num2 , int num3 )
{
    int local_smallest;
    if(num1<num2 && num1<num3)
    local_smallest=num1;
    else
    {
        if(num2<num1 && num2<num3)
        local_smallest=num2;
        else
        {
            local_smallest=num3;
        }
    }
    return local_smallest;
}