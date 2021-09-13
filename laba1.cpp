#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char string1[20],string2[20], letter;
	int i, j=0, number,w=0, f;
	cout <<"Enter your string:\n";
	cin >> string1 ;
	i=strlen(string1);
	while(w<i)
	{  string2[w]='-';
		w++;
	}
	string2[w]='\0';
	while (j<i) {
		cout <<"Enter your letter:\n";
		cin >> letter;
		number=0;
		for(f=0;f<i;f++) {
			if (string1[f]==letter)
				{ number++;
				  string2[f]=letter;
		          j++;
				}
		}
			if (number==0)
				cout << "There isn't such letter in the word!\n";
			else cout << "There is such "<< number <<" letter in the word!\n";
			cout << string2 <<"\n";
	}
	cout << "Congratulations! You guessed the word.\n" ;
	return 0;
}