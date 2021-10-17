#include "CRational.h"
using namespace std;

int CRational::GCD(int x, int y) {
        if (x % y == 0)
            return y;
        if (y % x == 0)
            return x;
        if (x > y)
            return GCD(x%y, y);
        return GCD(x, y%x);
    }
    int CRational::LCM(int x, int y) {
        return x * y / GCD(x, y);
    }
CRational::CRational(int u,int n, int d)
    {
        unit=u;
        numerator = n;
        if (d==0)
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
            exit(0);
        }
        else
            denominator = d;
    }
CRational CRational::Cheak()
    {
        if (numerator!=0) {
            if (numerator % denominator == 0) {
                unit += numerator / denominator;
                denominator = 1;
                numerator = 0;
            } else {
                if (numerator / denominator != 0) {
                    unit += (numerator / denominator);
                    numerator %= denominator;
                }
                if (GCD(numerator, denominator) != 1) {
                    int gcd=GCD(numerator, denominator);
                    numerator /= gcd;
                    denominator /= gcd;
                }
            }
        }
        else denominator=1;
        return {unit, numerator, denominator};
    }
CRational CRational::add(CRational number2)
    {
        CRational num(0,0,1);
        num.denominator=LCM(denominator, number2.denominator);
        numerator*=(num.denominator/denominator);
        number2.numerator*=(num.denominator/number2.denominator);
        num.numerator=numerator+number2.numerator;
        num.unit=unit+number2.unit;
        num.Cheak();
        numerator/=(num.denominator/denominator);
        return num;
    }
CRational CRational::multiplication(CRational number2)
    {
        CRational num(0,0,1);
        if (number2.unit) {
            number2.numerator += (number2.denominator * number2.unit);
            number2.unit=0;
        }
        if (unit) {
            numerator += (denominator * unit);
            unit=0;
        }
        num.numerator=numerator*number2.numerator;
        num.denominator=denominator*number2.denominator;
        num.Cheak();
        return num;
    }
void CRational::show() const
    {
        if (unit==0)
            cout <<numerator << "/" <<denominator<< "\n";
        else
        if (numerator==0)
            cout << unit << "\n";
        else
            cout << unit << " " << numerator << "/" << denominator<< "\n";
    }
void CRational::input()
    {
        cin >> unit;
        cin >> numerator;
        cin >> denominator;
        if (denominator==0)
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO!" << endl;
            exit(0);
        }
        Cheak();
    }