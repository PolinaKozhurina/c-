#include<iostream>
#include <math.h>

using namespace std;

int cheak()
{
    while(1)
    {
        float number;

        cout << "Enter an integer positive number less than 100000:\n";
        cin >> number;
        
        if(cin.fail() || number < 0 || number >= 100000 || floor(number)!=number) //cin.fail() определяет, соответствует ли введенное значение значению, определенному в переменной.
       // floor() возвращает наибольшее целое число
        {
            cin.clear(); //cin.clear() очищает флаг ошибки на cin
            cin.ignore(10000, '\n'); //Он извлекает 10000 символов из буфера, но останавливается, если встречает новую строку (\n)

            cout << "Input is incorrect.\n";
        }
        
        else 
            return (int)number;
    }
}

int factorialis(int number)
{
    int i,fact=1;
    if (number == 0)
        return 1;
    
    else for(i=2;i<=number;i++)
    fact=fact*i;
    return fact;

}

int main()
{
    int number = cheak();
    cout << "The factorialis:\n";
    cout << factorialis(number);
    cout << endl;
    return 0;
}
