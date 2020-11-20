#include <iostream>
#include <string.h>

using namespace std;

int indexOf(char *s, char c)
{

    for (int i = 0; i < strlen(s); i++)
    {

        if (c == *(s + i))

            return i;
    }

    return -1;
}

int main()
{

    char *s = "Nguyen Ba Tan";

    char c = 'T';

    if (indexOf(s, c) != -1)

        cout << "Ky tu " << c << " nam o vi tri thu " << indexOf(s, c) << " trong sau s";

    else

        cout << "Khong tim thay ky tu " << c << " trong sau s";

    return 0;
}