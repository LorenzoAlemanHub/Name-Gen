#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <time.h>

using namespace std;
char letter;
string name = "";
int select, nameLen, nameAmt, which;
vector<int> cons;
vector<int> vowels = { 97,101,105,111,117 };

void print(vector<int> x)
{
	for (int k = 0; k <= x.size() - 1; k++)
	{
		letter = x[k];
		cout << letter << endl;
	}
};

char randomVowel()
{
	select = rand() % 4;
	letter = vowels[select];
	return letter;
};

char randomConsonant()
{
	select = rand() % 20;
	letter = cons[select];
	return letter;
};

// if true, vowel. if false, consonant.
bool decider(string s)
{
	char last = s[s.length() - 1];
	int lascii = last;
	bool prev = false;
	
	for (int r = 0; r <= vowels.size() - 1; r++)
	{
		if (lascii == vowels[r])
		{
			prev = true;
		}
	}

	return prev;
}

int main()
{
	srand(time(0));
	bool flag = false;
	for (int i = 98; i <= 122; i++)
	{
		for (int d = 0; d <= vowels.size() - 1; d++)
		{
			if (i == vowels[d])
			{
				flag = true;
			}
		}
		if (flag == false)
		{
			cons.push_back(i);
		}
		flag = false;
	}

	cout << "How many names? ";
	cin >> nameAmt;
	cout << "Enter name length: ";
	cin >> nameLen;
	char add;

	for (int l = 0; l <= nameAmt - 1; l++)
	{
		which = rand() % 2;
		if (which == 0)
		{
			add = randomConsonant();
			name += add;
		}
		if (which != 0)
		{
			add = randomVowel();
			name += add;
		}
		for (int itr = 0; itr <= nameLen - 2; itr++)
		{
			if (decider(name) == true)
			{
				add = randomConsonant();
				name += add;
			}
			else if (decider(name) == false)
			{
				add = randomVowel();
				name += add;
			}
		}
		cout << "Name: " << name << endl;
		name = "";
	}
	system("PAUSE");
	return 0;
}