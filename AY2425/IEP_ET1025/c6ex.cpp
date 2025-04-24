#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

char grade;
int totalA=0, totalB=0,totalC=0;
void readandTotalGrades(void);
void displayTotals(void);


int main()
{
    readandTotalGrades();
    displayTotals();
    return 0 ;
}
void readandTotalGrades(void)
{
    for(int i = 0 ; i<10 ; i++)
    {
        cout<<"Enter the grade for students "<<i+1<<"(A,B or C):";
        cin>>grade;

        switch(grade)
        {
            case 'A':
            case 'a':
                totalA++;
                break;
            case 'B':
            case 'b':
                totalB++;
                break;
            case 'C':
            case 'c':
                totalC++;
                break;
            default:
                cout<<"Invalid grade entered.Please enter A , B or C";
                i--;
                break;
                return ;


        }

    }
}
void displayTotals(void)
{
    cout<<"Total number of As : "<< totalA;
    cout<<"Total number of Bs : "<<totalB;
    cout<<"Total number of Cs : "<<totalC;
    return ;

}