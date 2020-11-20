#include <iostream>
#include <string.h>
using namespace std;

void xoa(char *s, int k)
{
	int i;
	for (i = k; i < strlen(s) - 1; i++)
	{
		s[i] = s[i + 1];
	}
	s[strlen(s) - 1] = '\0';
}

char *Viet(char *s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[0] == ' ')
		{
			xoa(s, 0);
		}
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			xoa(s, i + 1);
			i--;
		}
		if (s[strlen(s) - 1] == ' ')
			xoa(s, strlen(s) - 1);
	}
	for (int i = 0; i < strlen(s); i++)
	{
		*s = toupper(*s);
		if (*(s + i) == ' ' && isalpha(*(s + i + 1)))
			*(s + i + 1) = toupper(*(s + i + 1));
	}
	return s;
}

int main()
{
	char a[] = "  nguyen    ba     tan    ";
	char *ptr = a;
	cout << Viet(ptr);
	system("pause");
	return 0;
}
