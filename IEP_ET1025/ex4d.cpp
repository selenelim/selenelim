#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int number;
    cout<<"Enter number between 1 and 4:";
    cin>>number;
    switch (number)
    {
    case 1:cout<<"ONE\n";
        break;
    case 2:cout<<"TWO\n";
        break;
    case 3:cout<<"THREE\n";
        break;
    case 4: cout<<"FOUR\n";
        break;
    default:cout<<"OUT OF RANGE\n";
        break;
    }
}