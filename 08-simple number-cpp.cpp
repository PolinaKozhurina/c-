#include <iostream>
using namespace std;

int main()
{
    int n,a,i;
    cout<<"Enter number:\n";
    cin>>n;
    for (i=2,a=1;i<n;i++)
        if (!(n%i))
            a=0;
    if (a)
        cout<<"The number "<<n<<" is simple\n";
    else
        cout<<"The number "<<n<<" is not simple\n";
    system("pause");
    return 0;
}
