#include <iostream>
#include <fstream>  
#include <math.h>
#define PI 4*atan(1.0)
using namespace std;
float f(float x);

int main()
{
    float x, y, z, ax, bx, hx, ay, by, hy;
    int I, J;
    string title, zone, variables1, variables2, variables3 ;
    cout << "I = ";
    cin >> I;
    cout << "J = ";
    cin >> J;
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
    outfile << "ZONE T=\"" << zone <<"\", I="<<I<<", J="<<J<<", F=POINT" << endl;
    ax = -2*PI;
    bx = 2*PI;
    hx = (bx - ax) / I;
    ay = -2*PI;
    by = 2*PI;
    hy = (by - ay) / J;
    for (int j = 0; j < J; j++){
    for (int i = 0; i < I; i++) {
        z = f(y)*f(x);
        outfile << x << " "<<y <<" "<<z<< endl;
        x+=hx;
    }
        x = ax;
        y+= hy;
    }
    outfile.close();
}
float f(float x){
    float f;
    f = 1.0/sqrtf(2.0*PI)*exp(-x*x/2);
    return f;

}


