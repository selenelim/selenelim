#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    double a=5.0, b=10.0 ,c;
    char operation ;
    cout<<"Enter the operation [+, -, * or /]:)";
    cin >> operation ;
    switch (operation)
    {
    case '+':c=a+b;
        break;
    case '-':c=a-b;
        break;
    case '*':c=a*b;
        break;
    case '/':c=a/b;
        break;
    default: cout<<"INVALID";
        break;
    }
    cout << a << operation << b << "=" << c;

}
