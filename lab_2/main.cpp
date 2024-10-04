#include <iostream>
using namespace std;

int main()
{
    cout<<"enter a number: ";
    short a;
    cin>>a;
    if (a>0 && a<40)
    {
        cout<< "V= "<<a*a*a;
    }
    else
    {
        cout<<"number does not satisfy the rule";
    }
    return 0;
}