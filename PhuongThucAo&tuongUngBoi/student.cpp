#include "student.h"
Student::Student(string _n, int _a, string _g, string _l, int _id)
    : Person(_n, _a, _g)
{
    lop = _l;
    id = _id;
}
void Student::set_class(string c) { lop = c; }
string Student::get_class() { return lop; }
void Student::set_id(int i) { id = i; }
int Student::get_id() { return id; }
void Student::display()
{
    Person::display();
    cout << "class:\t" << lop << endl;
    cout << "ID:\t" << id << endl;
}
