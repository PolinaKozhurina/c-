#include <iostream>
#include <fstream>  
#include <math.h>
using namespace std;

int main()
{
    const float PI = atan(1.0) * 4;
    float x, y, z, ax, bx, hx, ay, by, hy;
    int I;
    string title, zone, variables1, variables2, variables3 ;
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
    cout << "variables3 = ";
    cin >> variables3;
    ofstream outfile("data.dat");
    outfile << "TITLE=\""<< title <<"\"" << endl;
    outfile << "VARIABLES=\"" << variables1 << "\", \"" << variables2 << "\", \"" << variables3 << "\"" << endl;
    outfile << "ZONE T=\"" << zone <<"\", I="<<I<<", F=POINT" << endl;
    ax = 0;
    bx = 2*PI;
    hx = (bx - ax) / I;
    ay = 0;
    by = 2*PI;
    hy = (by - ay) / I;
    for (int j = 0; j < I; j++){
    for (int i = 0; i < I; i++) {
        z = sin(y)*sin(x);
        outfile << x << " "<<y <<" "<<z<< endl;
        x+=hx;
    }
        x = ax;
        y+= hy;
    }
    outfile.close();
}
