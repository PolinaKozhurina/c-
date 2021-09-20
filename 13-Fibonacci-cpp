#include<iostream>
#include <math.h>

using namespace std;

int cheak()
{
    while(1)
    {
        float number;

        cout << "Enter an integer positive number less than 100:\n";
        cin >> number;
        
        if(cin.fail() || number < 0 || number >= 100 || floor(number)!=number) //cin.fail() определяет, соответствует ли введенное значение значению, определенному в переменной.
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

int Fibonacci(int number)
{
    if (number == 0)
        return 0;
    
    else if (number == 1)
        return 1;

    else 
        return Fibonacci(number-2) + Fibonacci(number-1);
}

int main()
{
    int i, number = cheak();
    cout << "There are Fibonacci numbers: ";

    for(i = 0; i < number; i++)
        {
            cout << Fibonacci(i) << " ";
        }

    cout << endl;
    return 0;
}
