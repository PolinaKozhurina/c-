#include <iostream>
#include <new>
using namespace std;

class Basic
{
public:
    int* p;
    int number;
    
    Basic()
    {
        number = 0;
    }
    virtual void push(int item)
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
    ~Basic()
    {
        if (number > 0)
            delete[] p;
    }
    virtual void print()
    {
        for (int i = 0; i < number; i++){
            cout << p[i];
            if(i<number-1)
            cout<<",";}
        cout<< endl;
    }
};

class Stack: public Basic
{
public:
    int pop()
    {
        if (number == 0)
            return 0;
        number--;
        cout<<"The item was removed:"<<  p[number] << endl;
        return p[number];
    }
};

class Queue: public Basic
{
public:
    int pop()
    {
        if (number == 0)
            return 0;
        int item;
        item = p[0];
        try {
            int* temp;
            temp = new int[number - 1];
            number--;
            for (int i = 0; i < number; i++)
                temp[i] = p[i + 1];
            if (number > 0)
                delete[] p;
            p = temp;
            cout<<"The item was removed:"<< item<< endl;
            return item;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
};

int main(){
    Queue first;
    first.push(1);
    first.push(2);
    first.push(3);
    first.push(4);
    first.pop();
    first.print();
    Stack second;
    second.push(1);
    second.push(2);
    second.push(3);
    second.push(4);
    second.pop();
    second.print();
    return 0;
}