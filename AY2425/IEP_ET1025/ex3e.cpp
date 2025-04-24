#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double weight , result ;
    cout << "Enter weight in lbs:";
    cin >> weight;
    result= weight/2.2 ;
    cout<<"Your weight is :" <<fixed <<setprecision(2)<< result<<endl;
    return 0 ;
}