#include <iostream>
#include <fstream>  
#include <math.h>
using namespace std;

int main()
{
    const float PI = atan(1.0) * 4;
    float x, y, a, b, h;
    int I;
    string title, zone, variables1, variables2;
    cout << "I = ";
    cin >> I;
    cout << "title = ";
    cin >> title;
    cout << "zone = ";
    cin >> zone;
    cout << "variables1 = ";
    cin >> variables1;
    cout << "variables2 = ";
    cin >> variables2;
    ofstream outfile("data.dat");
    outfile << "TITLE=\""<< title <<"\"" << endl;
    outfile << "VARIABLES=\"" << variables1 << "\", \"" << variables2 << "\"" << endl;
    outfile << "ZONE T=\"" << zone <<"\", I="<<I<<", F=POINT" << endl;
    a = -100;
    b = 100;
    h = (b - a) / I;
    
    for (int i = 0; i < I; i++) {
        y = x*sin(x);
        outfile << x << " "<<y << endl;
        x+=h;
    }
    outfile.close();
}
