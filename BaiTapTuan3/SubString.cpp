#include <iostream>

#include <string.h>

using namespace std;

char *SubString(char *s, int index, int length)
{

    char *str = new char[length];

    int count = 0;

    for (int i = index; i < index + length; i++)
    {

        *(str + count++) = *(s + i);
    }

    return str;
}

int main()
{

    char *s = "Nguyen Ba Tan";

    int index = 7, length = 5;

    cout << SubString(s, index, length);

    return 0;
}