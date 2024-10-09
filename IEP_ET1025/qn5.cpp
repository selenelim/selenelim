#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
 
    char character;
    cout << "Enter a character: ";
    cin >> character;

    if (character >= 'A' && character <= 'Z') {
        cout << character << " is an uppercase letter." << endl;
    } else if (character >= 'a' && character <= 'z') {
        cout << character << " is a lowercase letter." << endl;
    } else {
        cout << character << " is not a letter." << endl;
    }

    return 0;
}

