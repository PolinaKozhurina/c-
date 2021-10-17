#ifndef CRATIONAL
#define CRATIONAL

class CRational
{
public:
    int GCD(int x, int y);
    int LCM(int x, int y);
    int unit,numerator,denominator;
    CRational(int u,int n, int d);
    CRational Cheak();
    CRational add(CRational number2);
    CRational multiplication(CRational number2);
    void show() const;
    void input();
};

#endif
