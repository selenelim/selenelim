#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    char input='y';
    double voltage , current ;
    while(input=='y')
    {
        cout<<"Enter the voltage and current:";
        cin>>voltage>>current ;
        cout<<"The resistance is "<< voltage/current <<'\n';
        cout<<"Do you wish to continue? [y/n]";
        cin>>input;

    }
}