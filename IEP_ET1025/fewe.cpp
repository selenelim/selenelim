#include <iostream>
#include<cmath>
#include <iomanip>
double computeBMI(double height , double weight);
using namespace std;
int main()
{
    double local_BMI,height ,weight ;
    cout<<"Enter your weight in kg : ";
    cin>>weight;
    cout<<"Enter yout height in m : ";
    cin>>height;
    local_BMI=computeBMI( height ,  weight);
    cout<<local_BMI;

}
double computeBMI(double height , double weight)
{
    double compute_BMI;
    compute_BMI=weight / (height*height);
    return compute_BMI;

}