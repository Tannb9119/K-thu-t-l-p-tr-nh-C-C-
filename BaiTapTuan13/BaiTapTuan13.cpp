#include <iostream>
#include <string>
#include <vector>
using namespace std;

class person
{
private:
    int id;
    string name;
    string gender;
    person *next;

public:
    person(int _id = 0, string _name = "unknown", string _gender = "unknown", person *_next = NULL)
    {
        id = _id;
        name = _name;
        gender = _gender;
        next = _next;
    }
    person(const person &per1)
    {
        id = per1.id;
        name = per1.name;
        gender = per1.gender;
        next = per1.next;
    }
    person &operator=(const person &per2)
    {
        id = per2.id;
        name = per2.name;
        gender = per2.gender;
        next = per2.next;
        return *this;
    }
    ~person()
    {
        next = NULL;
    }
    void input_pers(int &_id, string &_name, string &_gender)
    {
        cout << "Nhap ma dinh danh:";
        cin >> _id;
        cout << "Nhap ho ten:";
        cin.ignore(1);
        getline(cin, _name);
        cout << "Nhap gioi tinh:";
        getline(cin, _gender);
        this->id = _id;
        this->name = _name;
        this->gender = _gender;
    }
    void swap(person &per2)
    {
        person tmp = *this;
        *this = per2;
        per2 = tmp;
    }
    void display()
    {
        cout << "Person:\n";
        cout << "ID:\t" << id << endl;
        cout << "Name:\t" << name << endl;
        cout << "Gender:\t" << gender << endl;
    }
    string getName()
    {
        return name;
    }
    friend class listofperson;
};

class listofperson
{
private:
    person *firstpers;

public:
    void lofpers_Init(listofperson *lofpers)
    {
        lofpers->firstpers = 0;
    }
    void add_pers(listofperson *lofpers, person &per2)
    {
        person *newpers = new person(per2);
        newpers->next = lofpers->firstpers;
        lofpers->firstpers = newpers;
    }
    void add_pers_Final_Input(listofperson *lofpers)
    {
        int id;
        string name;
        string gender;
        person persIn;
        persIn.input_pers(id, name, gender);
        person *newpers = new person(persIn);
        person *node = lofpers->firstpers;
        while (node->next != 0)
        {
            node = node->next;
        }
        newpers->next = node->next;
        node->next = newpers;
    }
    int lofPerson_Length(listofperson *lofpers)
    {
        int dem = 0;
        person *node = lofpers->firstpers;
        while (node != 0)
        {
            dem++;
            node = node->next;
        }
        return dem;
    }
    void lofpers_Display(listofperson *lofpers)
    {
        person *node = lofpers->firstpers;
        int i = lofPerson_Length(lofpers);
        cout << "Do dai cua listofperson: " << i;
        if (node == 0)
            cout << "listofperson rong\n";
        else
        {
            while (node != 0)
            {
                cout << "\nNguoi thu: " << i << "\n";
                cout << "\nId:\t\t" << node->id;
                cout << "\nName:\t\t" << node->name;
                cout << "\nGender:\t\t" << node->gender << endl;
                node = node->next;
                i--;
            }
        }
    }
    person *lofperson_Search(listofperson *lofpers, string name)
    {
        person *node = lofpers->firstpers;
        while (node != 0)
        {
            if (node->name == name)
                return node;
            else
                node = node->next;
        }
    }
    void lofpers_RemoveAfter(person *node)
    {
        person *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
    void sortlistofpersonPerson(listofperson *lofpers)
    {
        for (person *node1 = lofpers->firstpers; node1 != 0; node1 = node1->next)
        {
            for (person *node2 = node1->next; node2 != 0; node2 = node2->next)
            {
                if (node1->id > node2->id)
                {
                    int tmp = node1->id;
                    node1->id = node2->id;
                    node2->id = tmp;
                }
            }
        }
    }
};

class student : public person
{
private:
    int stuID;
    string clas;

public:
    student(int _id = 0, string _name = "unknown", string _gender = "unknown", person *_next = NULL, int _stuID = 0, string _clas = "unknown") : person(_id, _name, _gender, _next)
    {
        stuID = _stuID;
    }
    student(const student &stu1) : person(stu1)
    {
        stuID = stu1.stuID;
        clas = stu1.clas;
    }
    student &operator=(const student &stu2)
    {
        person::operator=(stu2);
        stuID = stu2.stuID;
        clas = stu2.clas;
        return (*this);
    }
    void input_stud(int &id, string &name, string &gender, int &stuID, string &clas)
    {
        person::input_pers(id, name, gender);
        cout << "   + Nhap stuID: ";
        cin >> stuID;
        cin.ignore(1);
        cout << "   + Nhap ten lop: ";
        getline(cin, clas);
        this->stuID = stuID;
        this->clas = clas;
    }
    void display()
    {
        person::display();
        cout << "student ID:\t" << stuID << endl;
        cout << "Class:\t" << clas << endl;
    }
    friend class listOfStudent;
};

class listOfStudent
{
private:
    vector<student> lofstuds;

public:
    //them hoc sinh vao list
    void add_stud(student &stud)
    {
        lofstuds.push_back(stud);
    }
    //xoa hoc sinh
    void lofstuds_Remove()
    {
        int pos;
        cout << "Nhap vi tri cua sv muon xoa:";
        cin >> pos;
        vector<student>::iterator it = lofstuds.begin();
        lofstuds.erase(it + pos);
    }
    //Chinh xua thong tin sinh vien
    void lofStuds_Set()
    {
        int pos;
        cout << "Nhap vi tri cua sv muon sua:";
        cin >> pos;
        int id, studID;
        string name, gender, clas;
        lofstuds[pos].input_stud(id, name, gender, studID, clas);
    }
    void lofstuds_sort()
    {
        for (int i = 0; i < lofstuds.size(); i++)
        {
            for (int j = i + 1; j < lofstuds.size(); j++)
            {
                if (lofstuds[i].stuID > lofstuds[j].stuID)
                {
                    student tmp = lofstuds[i];
                    lofstuds[i] = lofstuds[j];
                    lofstuds[j] = tmp;
                }
            }
        }
    }
    void lofstuds_display()
    {
        if (lofstuds.size() == 0)
            cout << "List student rong" << endl;
        else
        {
            for (int i = 0; i < lofstuds.size(); i++)
            {
                lofstuds[i].display();
                cout << endl;
            }
        }
    }
};

int main()
{
    // person per1(01, "nguyen van a", "male");
    // person per2 = per1;
    // cout << "thong tin nguoi 2: " << endl;
    // per2.display();
    // person per3(02, "nguyen van b", "male");
    // per3.swap(per2);
    // per2.display();
    // listofperson lofpers;
    // lofpers.lofpers_Init(&lofpers);
    // lofpers.add_pers(&lofpers, per1);
    // lofpers.add_pers(&lofpers, per2);
    // lofpers.add_pers(&lofpers, per3);
    // lofpers.sortlistofpersonPerson(&lofpers);
    // cout << "\nNoi dung listofperson la: " << endl;
    // lofpers.lofpers_Display(&lofpers);
    student std1(1, "le thi mai", "female", NULL, 22, "ET4");
    student std2(2, "le thi hoa", "female", NULL, 23, "ET4");
    student std3(3, "Pham thanh long", "male", NULL, 24, "ET4");
    listOfStudent lofstuds;
    lofstuds.add_stud(std1);
    lofstuds.add_stud(std2);
    lofstuds.add_stud(std3);
    lofstuds.lofstuds_sort();
    cout << "\nNoi dung lisofstuds da sap xep la: " << endl;
    lofstuds.lofstuds_display();
    lofstuds.lofStuds_Set();
    lofstuds.lofstuds_sort();
    cout << "\nNoi dung lisofstuds sau khi chinh sua la:" << endl;
    lofstuds.lofstuds_display();
    lofstuds.lofstuds_Remove();
    cout << "Noi dung cua lisofstuds sau lenh xoa: " << endl;
    lofstuds.lofstuds_display();
    return 0;
}