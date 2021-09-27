#include<iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int> IntVector;

int cheak()
{
    while(1)
    {
        float number;

        cout << "Enter an integer positive number less than 100:\n";
        cin >> number;
        
        if(cin.fail() || number < 0 || number >= 100 || floor(number)!=number) //cin.fail() определ€ет, соответствует ли введенное значение значению, определенному в переменной.
       // floor() возвращает наибольшее целое число
        {
            cin.clear(); //cin.clear() очищает флаг ошибки на cin
            cin.ignore(10000, '\n'); //ќн извлекает 10000 символов из буфера, но останавливаетс€, если встречает новую строку (\n)

            cout << "Input is incorrect.\n";
        }
        
        else 
            return (int)number;
    }
}
void Change( int x1, int x2)
{}

void Output(IntVector &v)
{for (int i=0;i<v.size();i++)
	cout <<v(i)<<" ";
cout << endl;
}

void QuickSort(int first, int last)
{}
int main()
{
	int N = cheak(),i;
	vector <int> massiv;
	cout << "Enter the number of items: ";
	cin >> N;
	for (i=0;i<N;i++)
		massiv.push_back(rand()%10);
	Output(massiv);

	return 0;
}