#include<iostream>
#include <vector>
#include <iterator>
#include <math.h>
#include <random>

using namespace std;
typedef vector<int> IntVector;

int cheak()
{
    while(1)
    {
        float number;

        cout << "Enter the number of items: ";
        cin >> number;
        
        if(cin.fail() || number <= 1 || number >= 100 || floor(number)!=number)
        {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Input is incorrect.\n";
        }
        
        else 
            return (int)number;
    }
}
void Change1( int x, int y, IntVector &massiv)
{
    int helper;/*- вспомогательная переменная */
    helper=massiv[x];
    massiv[x]=massiv[y];
    massiv[y]=helper;
}
void Change2( int x, int y, IntVector &massiv)
{
    massiv[x]=massiv[x] + massiv[y]-(massiv[y] = massiv[x]); 
}
void Change3( int x, int y, IntVector &massiv)
{
    massiv[x]^=massiv[y]^=massiv[x]^=massiv[y];
}

void Output(IntVector &v, int N)
{
    for (auto const &element: v)
        cout <<element<<" ";
cout << endl;
}

void QuickSort(int first, int last, IntVector &massiv)
    {
    int average,left,right; /* опорное значение, левый и правый счетчики*/
    left=first; right=last;
    average=massiv[(left+right)/2]; /*определение опорного значения*/
    while (left<=right) {
        while (massiv[left]<average)
            left++;
         while (massiv[right]>average)
			right--;
        if (left<=right) {
            if (left!=right)
    	        {Output(massiv, massiv.size());
                Change3(left, right, massiv);} /*перестановка двух элементов, можно любую функцию change подставить)*/
            left++;
            right--;
        }
    } /*Рекурсивная сортировка:*/
 if (first<right) QuickSort(first, right, massiv); /*- левого участка, */
 if (left<last) QuickSort(left, last, massiv); /*- правого участка.*/
 } 
int main()
{
    random_device rd; 
    mt19937 mersenne(rd());
	int N = cheak();
	vector <int> massiv;
	for (int i=0,sign;i<N;i++)
		{massiv.push_back(mersenne()%100);
		sign = rand()%3; //я просто так захотела))
		if (sign > 1)
		massiv.at(i)*= -1;
		}
	//massiv.reserve(N);
	QuickSort(0,N-1,massiv);
	cout <<"Sorted list:\n";
	Output(massiv, N);
	return 0;
}
