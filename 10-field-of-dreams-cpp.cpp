#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char string1[20],string2[20], letter[20], pro[20];
	int i1, i2, j=0, number,w=0, f,k,h,p=0, word=0;
	cout <<"Enter your string:\n";
	cin >> string1 ;
	i1=strlen(string1);
	while(w<i1)
	{  string2[w]='-';
		w++;
	}
	string2[w]='\0';
	while (j<i1) {
		cout <<"Enter your letter:\n";
		cin >> letter;
		i2=strlen(letter);
		if (i2==1) {
		k=0;
		h=0;
		while (h<p)
		{
		    if (pro[h]==letter[0])
		    k++;
		    h++;
		}
		if (!k)
		{pro[p]=letter[0];
		p++;
		number=0;
		for(f=0;f<i1;f++) {
			if (string1[f]==letter[0])
				{ number++;
				  string2[f]=letter[0];
		          j++;
				}
		    }
			if (number==0)
				cout << "There isn't such letter in the word!\n";
			else cout << "There is such "<< number <<" letter in the word!\n";
			cout << string2 <<"\n";
		}
		else 
		cout << "You have already entered this letter.\n" ;
		}
		else 
		{ word++;
		    break;}
	}
	if (word)
	{if (strcmp(string1,letter)==0)
	    cout << "Congratulations! You guessed the word.\n" ;
	   else 
	   cout << "You are loser :( \n" ;
	}
	else
	cout << "Congratulations! You guessed the word.\n" ;
	return 0;
}