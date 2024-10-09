#include <iostream>
using namespace std;
void printsum(int sum);
int main()
{
    int num[5]={9,0,-5,6,7};
    num [0]=20;
    num [4]=num[0]+num[2];
    cout<<num[4];
}