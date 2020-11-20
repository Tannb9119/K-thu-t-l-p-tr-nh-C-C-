#include <iostream>
#include <stdlib.h>
using namespace std;

char *Dec2Bin(int a)
{
	string s;
	if (a == 0)
		s = '0';
	while (a != 0)
	{
		s = (char)(a % 2 + '0') + s;
		a /= 2;
	}
	char *bin = new char[s.length()];
	int i = 0;
	for (i = 0; i < s.length(); i++)
	{
		bin[i] = s[i];
	}
	bin[i] = '\0';
	return bin;
}

int main()
{
	cout << Dec2Bin(13);
	return 0;
}
