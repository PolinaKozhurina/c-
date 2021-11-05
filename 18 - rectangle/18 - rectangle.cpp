#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle {
private:
    string sxL, sxR, syD, syU;
    double xL, xR, yD, yU;

public:
    Rectangle(double a, double b, double c, double d) : xR(a), xL(b), yD(c), yU(d) {	}
    void Input() {
        ifstream inf("date.txt");
        if (!inf)
        {
            cerr << "Uh oh, date.txt could not be opened for reading!" << endl;
            exit(1);
        }
        getline(inf, sxL);
        xL=stod(sxL);
        getline(inf, syD);
        yD = stod(syD);
        getline(inf, sxR);
        xR = stod(sxR);
        getline(inf, syU);
        yU = stod(syU);
    }
    void Result() {
        cout << "You entered the following coordinates of the rectangle:" << endl;
        cout << " A:" << "(" << xL << "," << yD << ")" << endl;
        cout << " B:" << "(" << xR << "," << yD << ")" << endl;
        cout << " C:" << "(" << xR << "," << yU << ")" << endl;
        cout << " D:" << "(" << xL << "," << yU << ")" << endl;
    }
    void Crossing(Rectangle rec2) {
        double x_min = xL, x_max = xR, y_min = yD, y_max = yU;
        double A[4] = { xR,xL,rec2.xL,rec2.xR }, B[4] = { yD,yU,rec2.yD,rec2.yU };
        double S, S_min;
        for (int i = 0; i < 4; i++)
        {
            if (x_max < A[i])
            {
                x_max = A[i];
            }
            if (y_max < B[i])
            {
                y_max = B[i];
            }
            if (x_min > A[i])
            {
                x_min = A[i];
            }
            if (y_min > B[i])
            {
                y_min = B[i];
            }
        }
        S_min = ((x_max - x_min) * (y_max - y_min));
        S = ((xR - xL) + (rec2.xR - rec2.xL)) * ((yU - yD) + (rec2.yU - rec2.yD));
        if (S_min <S)
            cout << "They don't intersect";
        else cout << "They intersect";
    }
};
int main(void)
{
    Rectangle r1(1, 2, 3, 4), r2(2, 3, 4, 5);
    r1.Input();
    r1.Result();
    r2.Result();
    r1.Crossing(r2);
}
