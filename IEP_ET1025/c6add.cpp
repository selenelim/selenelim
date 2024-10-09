#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;
int num1 , num2 , sum ;
void getnumbers(void);
void computesum(void);
void printsum(void);

int main()
{
    getnumbers();
    computesum();
    printsum();
    return 0;
}
void getnumbers(void)
{
    cout<<"Enter the First Number :";
    cin>>num1;
    cout<<"Enter the Second Number :";
    cin>>num2;
    return;
}
void computesum(void)
{
    sum= num1 + num2;
    return;
}
void printsum(void)
{
    cout<<"The sum is :"<<sum;
    return;
}