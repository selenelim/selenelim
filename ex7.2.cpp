#include <iostream>
using namespace std;
void printsum(int sum);
int main()
{
    int marks [5][3];
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"Enter marks for the student"<<i+1;
            cout<<",subject"<<j+1<<":";
            cin>>marks[i][j];
        }
    }
    cout<<"\n\t\t\tSubject 1\tSubject 2\tSubject 3"<<endl;
    for (i=0;i<5;i++)
    {
        cout<<"Marks for student "<<i+1;
        cout<<"\t";
        for(j=0;j<3;j++)
        {
            cout<<" "<<marks[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
    return 0;

}
