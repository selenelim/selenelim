#include <iostream>
#include<cmath>
#include <iomanip>
#define PI 3.142
using namespace std;

int main ()
{
    double Vo, Vs,rad_angle;
   cout << "Enter the voltage source:\n";
   cin >> Vs;
   cout << "Enter the angle input in rad_degrees:\n";
   cin >> rad_angle;
   if (0 <= rad_angle && rad_angle <= PI)
   {
       Vo = Vs * (sqrt(1 + ((sin(2 * rad_angle) - 2 * rad_angle) / (2 * PI))));
       cout << "Voltage output is " <<  fixed<<setprecision(5)<<Vo;
   }
   else
       cout << "Equation is not valid.";
   return 0;
}