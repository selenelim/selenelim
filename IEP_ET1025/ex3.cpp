#include <iostream>
using namespace std;
int main()
{
    int total_mins , hours , mins;
    cout<<"Enter time in minutes:";
    cin >> total_mins;
    hours=total_mins/60 ;
    mins = (total_mins % 60);
    cout <<hours << "h" << mins << "mins" << endl;
    return 0;
}