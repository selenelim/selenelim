#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;
//selene lim , P2404479 , DCPE/FT/1A/01

int main()
{
    
    int choice ;
    double A , B , height , volume , area ;
    cout<< "Enter value of A : ";
    cin>>A;
    cout<<"Enter value of B : ";
    cin>>B;
    cout<<"Enter value of height : ";
    cin>>height;
    cout<<"Enter 1 to calculate area otherwise it will be volume : ";
    cin>>choice;
    if(choice != 1)
    {
        volume=(PI/3)*height*((A*A)+(B*B)+(A*B));
        cout<<"Your volume is :"<<setprecision(7)<<volume ;
    }
    else
    {
        area=PI*(A+B)*(sqrt((A-B)*(A-B)+height*height));
        cout<<"Your area is : "<<setprecision(6)<<area;
    }

}