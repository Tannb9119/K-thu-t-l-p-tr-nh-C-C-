#include <iostream>
#include <string.h>
using namespace std;

enum Sex
{
    man,
    woman,
    bi_sexualism
};
int curentyear() { return 2020; }
struct Person
{
    char *name;
    int yob; //năm sinh
    Sex sex;
};

void my_malloc(struct Person &per, int n)
{
    per.name = new char[n];
}

void my_free(struct Person &per)
{
    delete[] per.name;
}

void set_person(struct Person &per, char *name, int yob, Sex sex)
{
    strcpy(per.name, name);
    per.yob = yob;
    per.sex = sex;
}

char *getName(Person per)
{
    return per.name;
}

int main()
{
    struct Person per;
    my_malloc(per, 30);
    int yob = 2001;
    char s[] = "Nguyen Ba Tan";
    Sex sex = man;
    set_person(per, s, yob, sex);
    char *s1 = getName(per);
    return 0;
}