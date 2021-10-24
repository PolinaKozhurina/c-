#include <iostream>
#include <new>
using namespace std;

class Stack
{
private:
    int* p;
    int number;
public:
    Stack()
    {
        number = 0;
    }
    void push(int item)
    {
        int* temp; // объявить доp указатель
        temp = p;
        try {
            p = new int[number + 1];
            for (int i = 0; i < number; i++)
                p[i] = temp[i];
            p[number] = item;
            number++;
            if (number > 1) // освободождаем выделенную память
                delete[] temp;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl; // вывести сообщение об ошибке
            p = temp;
        }
    }

    int pop()
    {
        if (number == 0)
            return 0;
        number--;
        return p[number];
    }

    ~Stack()
    {
        if (number > 0)
            delete[] p;
    }
    void print(const char* objName)
    {
        cout << "Object: " << objName << endl;
        for (int i = 0; i < number; i++)
            cout << p[i] << "\t";
        cout<< endl;
    }
};