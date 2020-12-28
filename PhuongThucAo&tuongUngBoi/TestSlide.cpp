#include <iostream>
#include "student.h"
#include "lecture.h"
#include "person.h"
using namespace std;

int main()
{
    Person per("John", 21, "man");
    Student stu("Marry", 22, "woman", "Electronics1-K53", 20080001);
    Lecture lec("Michel", 22, "man", "Electronics Engineering", 123456789);
    cout << "Person:\t" << per.get_name() << "\t" << per.get_age() << "\t" << per.get_gender() << "\n\n";
    cout << "Student:\t" << stu.get_name() << "\t" << stu.get_age() << "\t" << stu.get_gender() << "\t" << stu.get_class() << "\t" << stu.get_id() << "\n\n";
    cout << "Lecture:\t" << lec.get_name() << "\t" << lec.get_age() << "\t" << lec.get_gender() << "\t" << lec.get_faculty() << "\t" << lec.get_telnumber() << "\n\n";
    per.display();
    stu.display();
    lec.display();
    return 0;
}
