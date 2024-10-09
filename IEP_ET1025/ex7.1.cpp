#include <iostream>
using namespace std;
void printsum(int sum);
int main()
{
    int d[]={1,2,3,4,5};
    char code [6]={'W','@','a','7'};
    code[2]='x';
    code[0]=d[1]+code[2];
    cout<<code[0];
}