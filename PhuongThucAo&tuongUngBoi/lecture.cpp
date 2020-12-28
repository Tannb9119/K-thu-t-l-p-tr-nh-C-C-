#include "lecture.h"
Lecture::Lecture(string _n, int _a, string _g, string _f, int _t)
    : Person(_n, _a, _g)
{
    faculty = _f;
    telnumber = _t;
}
void Lecture::set_faculty(string f) { faculty = f; }
string Lecture::get_faculty() { return faculty; }
void Lecture::set_telnumber(int tel) { telnumber = tel; }
int Lecture::get_telnumber() { return telnumber; }
void Lecture::display()
{
    Person::display();
    cout << "Faculty:\t" << faculty << endl;
    cout << "Telephone Number:\t" << telnumber << endl;
}
