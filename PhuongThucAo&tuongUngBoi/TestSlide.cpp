#include <iostream>
using namespace std;

class Person
{
    string name;
    int age;
    string gender;

public:
    Person(string, int, string);
    string get_name();
    void set_name(string);
    int get_age();
    void set_age(int);
    string get_gender();
    void set_gender(string);
    void display();
};

Person::Person(string _name, int _age, string _gender)
{
    name = _name;
    age = _age;
    gender = _gender;
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

class Student : public Person
{
    string lop;
    int id;

public:
    Student(string, int, string, string, int);
    void set_class(string c);
    string get_class();
    void set_id(int i);
    int get_id();
    void display();
};

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

class Lecture : public Person
{
    string faculty;
    int telnumber;

public:
    Lecture(string, int, string, string, int);
    void set_faculty(string f);
    string get_faculty();
    void set_telnumber(int tel);
    int get_telnumber();
    void display();
};
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
void Printout(Person *p)
{
    p->display();
}

int main()
{
    Person per("John", 21, "man");
    Student stu("Marry", 22, "woman", "Electronics1-K53", 20080001);
    Lecture lec("Michel", 22, "man", "Electronics Engineering", 123456789);
    cout << "Person:\t\t" << per.get_name() << "\t" << per.get_age() << "\t" << per.get_gender() << "\n\n";
    cout << "Student:\t" << stu.get_name() << "\t" << stu.get_age() << "\t" << stu.get_gender() << "\t" << stu.get_class() << "\t" << stu.get_id() << "\n\n";
    cout << "Lecture:\t" << lec.get_name() << "\t" << lec.get_age() << "\t" << lec.get_gender() << "\t" << lec.get_faculty() << "\t" << lec.get_telnumber() << "\n\n";
    per.display();
    stu.display();
    lec.display();
    Person *per2 = new Person("John", 21, "man");
    Student *stu2 = new Student("Marry", 22, "woman", "Electronics1-K53", 20080001);
    Lecture *lec2 = new Lecture("Michel", 22, "man", "Electronics Engineering", 123456789);
    Printout(per2);
    Printout(stu2);
    Printout(lec2);
    delete per2;
    delete stu2;
    delete lec2;
    Person *p, *q, *r;
    p = &per;
    q = &stu; //Con tro lop co so co the chua dia chi cua doi tuong lop dan xuat
    r = &lec;
    p->display();
    q->display();
    r->display();

    return 0;
}
