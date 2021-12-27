#include<iostream>
#include <vector>
#include <math.h> 
#include <string>

using namespace std;

int GCD(int x, int y) {
    if (x==0){
       cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO" << endl;
       exit(0);
    }
    if (x % y == 0)
        return y;
    if (y % x == 0)
        return x;
    if (x > y)
        return GCD(x%y, y);
    return GCD(x, y%x);
}
int LCM(int x, int y)
{
    return x*y / GCD(x, y);
}
class CRational
{
public:
    int unit,numerator,denominator;
    CRational(int u,int n, int d)
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
    int cheak_input()
    {
    while(1)
    {
        float num;
        cin >> num;
        
        if(cin.fail() || num < -1000 || num >= 1000 || floor(num)!=num) //cin.fail() определяет, соответствует ли введенное значение значению, определенному в переменной.
       // floor() возвращает наибольшее целое число
        {
            cin.clear(); //cin.clear() очищает флаг ошибки на cin
            cin.ignore(1000, '\n'); //Он извлекает 10000 символов из буфера, но останавливается, если встречает новую строку (\n)
            cout << "Input is incorrect.\n";
        }
        
        else 
            return (int)num;
    }
        
    }
    CRational Cheak()
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
    CRational add(CRational number2)
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
    CRational multiplication(CRational number2)
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
    void show() const
    {
        if (unit==0)
            cout <<numerator << "/" <<denominator<< "\n";
        else
            if (numerator==0)
                cout << unit << "\n";
            else
                cout << unit << " " << numerator << "/" << denominator<< "\n";
    }
    void input()
    {
        unit = cheak_input();
        numerator = cheak_input();
        denominator = cheak_input();
        cin.ignore(1000,'\n');
        if (denominator==0)
        {
            cout << "ERROR: ATTEMPTING TO DIVIDE BY ZERO!" << endl;
            exit(0);
        }
        Cheak();
    }
};
int main() {
    CRational number1={0,0,1}, number2={0,0,1};
    cout << "Enter a fraction in the format: integer and fraction,that you want add numerator denominator\n***If the fraction is mixed, the whole fraction is 0.***\nFraction 1:";
    number1.input();
    cout << "Fraction 2:";
    number2.input();
    cout << "Sum of fractions:\n";
    (number1.add(number2)).show();
    cout << "Multiplication of fractions:\n";
    (number1.multiplication(number2)).show();
    return 0;
}

