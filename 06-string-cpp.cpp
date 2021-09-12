#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char first_string[20], second_string[20];
    int i;
    cout << "Enter your string: \n";
    cin >> first_string ;
    for(i = 0; i <= strlen(first_string)-1; i++)
        second_string[i] = first_string[i];

    cout << "Your string: \n" << second_string << "\n";

    return 0;
}
