#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A,B,C,y ;
    cout<<"Enter value of A:";
    cin>> A;
    cout<<"Enter value of B:";
    cin>> B;
    cout<<"Enter value of C:";
    cin>> C;
    y= A>=B && A==C;
    cout<< y <<endl ;

    return 0;

}