#include <iostream>
#include<cmath>
using namespace std;

int main()
{
int age;
cout << "\nPlease enter your age : ";
cin >> age;
while ( (age <= 0) || (age > 100) )
{
    cout << "\nInvalid age.\n";
    cout << "\nPlease Re-enter age : ";
    cin >> age;
}

}