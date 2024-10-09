#include <iostream>
using namespace std;
void moonweight(double weight);
int main()
{
    double weight ;
    cout<<"Enter your weight : ";
    cin>>weight;
    moonweight(weight);
    return 0 ;
}
void moonweight(double weight)
{
    weight=weight/6.0;
    cout<<"Your weight is "<<weight;
    return;

}