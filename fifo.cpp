#include <iostream>
#include <new>
using namespace std;

class Queue
{
private:
    int* p;
    int number;

public:
    Queue()
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
            return item;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
    ~Queue()
    {
        if (number > 0)
            delete[] p;
    }
    void print()
    {
        cout << "Object: " << endl;
        for (int i = 0; i < number; i++){
            cout << p[i];
            if(i<number-1)
            cout<<",";}
        cout<< endl;
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
    return 0;
}
