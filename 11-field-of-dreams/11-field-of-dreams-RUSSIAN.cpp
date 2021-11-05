#include <iostream>
#include <cstring>
#include <io.h>
#include <fcntl.h>
#include <locale.h>

using namespace std;

int wstrlen(wchar_t* str) {
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
		k++;
	return k;
}
int Comp(wchar_t* str1, wchar_t* str2) {
	int k = 0, i = 0;
	if (wstrlen(str1) != wstrlen(str2))
		return 0;
	for (i; i < wstrlen(str1); i++)
		if (str1[i] == str2[i])
			k++;
	if (k == i)
		return 1;


}

int wmain()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin),_O_U16TEXT);
	_setmode(_fileno(stderr),_O_U16TEXT);
	wchar_t string1[20], string2[20], letter[20], pro[20];
	int i1, i2, j = 0, number, w = 0, f, k, h, p = 0, word = 0;
	wcout << L"Введите слово\n";
	wcin >> string1;
	i1 = wstrlen(string1);
	while (w < i1)
	{
		string2[w] = '-';
		w++;
	}
	string2[w] = '\0';
	while (j < i1) {
		wcout << L"Введите вашу букву\n";
		wcin >> letter;
		i2 = wstrlen(letter);
		if (i2 == 1) {
			k = 0;
			h = 0;
			while (h < p)
			{
				if (pro[h] == letter[0])
					k++;
				h++;
			}
			if (!k)
			{
				pro[p] = letter[0];
				p++;
				number = 0;
				for (f = 0; f < i1; f++) {
					if (string1[f] == letter[0])
					{
						number++;
						string2[f] = letter[0];
						j++;
					}
				}
				if (number == 0)
					wcout << L"Этой буквы нет в этом слове!\n";
				else wcout << L"В этом слове " << number << L" раз встречается эта буква!\n";
				wcout << string2 << "\n";
			}
			else
				wcout << L"Вы уже вводили эту букву.\n";
		}
		else
		{
			word++;
			break;
		}
	}
	if (word)
	{
		if (Comp(string1,letter))
			wcout << L"Поздравляю! Вы угадали слово.\n";
		else
			wcout << L"Вы проиграли :( \n";
	}
	else
		wcout << L"Поздравляю! Вы угадали слово.\n";
	return 0;
}
