#include <iostream>

using namespace std;

void hanoi(int number, int begin , int end)
{
    if(number == 1)
        cout << begin << " to " << end << endl;
    
    else
    {
        int temp = 6-begin-end;
        hanoi(number-1, begin, temp);
        cout <<begin<< " to " <<end<< endl;
        hanoi(number-1, temp,end);
    }
}

int main() 
{
    int number;
    cout << "Input the number of layers of tower:" << endl;
    cin >>number;
    hanoi(number, 1, 3);
    return 0;
}