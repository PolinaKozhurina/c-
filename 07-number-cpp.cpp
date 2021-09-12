#include <iostream>
using namespace std;
int main()
{
    int n, a=1, b=100, answer=0, i=0;
    cout<<"Think of a number N from 1 to 100, and I'll guess!\n";
    do
    {
        i++;
        n=(a+b)/2;
        cout<<"Is N greater than "<< n <<"(1 yes, 2 no, 3 equals)?\n";
        cin>>answer;
        if (answer==1) a=n;
        if (answer==2) b=n;
        if (answer==3)
        {
            cout<<"You have in mind the number "<<n<<"! And I'm great! Number of attempts:"<< i <<"\n";
            break;
        }
    }
    while (n/2>0);
    return 0;
}