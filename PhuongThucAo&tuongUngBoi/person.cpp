#include "person.h"
Person::Person(string _name, int _age, string _gender)
{
    name = _name;
    age = _age;
    sex = _gender;
}
string Person::get_name() { return name; }
void Person::set_name(string _name) { name = _name; }
int Person::get_age() { return age; }
void Person::set_age(int _age) { age = _age; }
string Person::get_gender() { return gender; }
void Person::set_gender(string _gender) { gender = _gender; }
void Person::display()
{
    cout << "Person :\n";
    cout << "Name :\t" << name << endl;
    cout << "Age :\t" << age << endl;
    cout << "Gender :\t" << gender << endl;
}
