#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node *next;
    Node(T v) : value(v), next(0){};
};

template <class T>
class List
{
    Node<T> *head, *tail;
    int count;

public:
    List() : count(0) { head = 0, tail = 0; }
    ~List()
    {
        delete head;
        delete tail;
    }                //Ham huy
    void RemoveAll() // Ham xoa danh sach
    {
        while (count)
        {
            --count;
            Node<T> *p = this->head;
            this->head = p->next;
        }
    }
    void add(T v) // ham bo sung mot node v vao ds
    {
        Node<T> *newNode = new Node<T>(v);
        if (count++ == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node<T> *First() const // Ham lay ra node dau tien
    {
        return head;
    }
    int Count() const // Ham tinh tong so node trong list
    {
        return count;
    }
    T *ToArray() // Ham duyet cac node de lay ra thuoc tinh value trong list
    {
        T *arr = new T[count];
        Node<T> *p = head;
        for (int i = 0; i < count; i++, p = p->next)
        {
            arr[i] = p->value;
        }
        return arr;
    }
    void remove(int pos)
    {
        Node<T> *p = head;
        int k = 1;
        if (pos <= 1) // kiem tra xem node muon xoa co phai node dau tien ko
        {
            Node<T> *tmp = head;
            head = tmp->next;
            delete tmp;
        }
        else
        {
            if (pos > count)
                pos = count;
            while (k++ != pos - 1) // tra ve node truoc node can xoa
            {
                p = p->next;
            }
            Node<T> *tmp = p->next;
            p->next = tmp->next;
            if (pos == count)
                tail = p;
            delete tmp;
        }
        count--;
    }
    void display()
    {
        T *arr = this->ToArray();
        for (int i = 0; i < count; i++)
        {
            cout << "Thong tin nguoi thu: " << i + 1 << endl;
            arr[i].display();
        }
    }
    void sort()
    {
        for (Node<T> *p1 = head; p1 != 0; p1 = p1->next)
        {
            for (Node<T> *p2 = p1->next; p2 != 0; p2 = p2->next)
            {
                if (p1->value.getID() > p2->value.getID())
                {
                    T tmp = p1->value;
                    p1->value = p2->value;
                    p2->value = tmp;
                }
            }
        }
    }
    void modify(int pos)
    {
        Node<T> *p = head;
        int k = 1;
        if (pos < 1)
            pos = 1;
        else if (pos > count)
            pos = count;
        while (k++ != pos)
            p = p->next;
        p->value.input();
    }
};

//Dinh nghio lop co so
class person
{
private:
    int id;
    string name;
    string gender;

public:
    person(int _id = 0, string _name = "unknown", string _gender = "unknown")
    {
        id = _id;
        name = _name;
        gender = _gender;
    }
    person(const person &per1)
    {
        id = per1.id;
        name = per1.name;
        gender = per1.gender;
    }
    ~person(){};
    void input()
    {
        cout << "Nhap ma dinh danh:";
        cin >> this->id;
        cout << "Nhap ho ten: ";
        cin.ignore(1);
        getline(cin, this->name);
        cout << "Nhap gioi tinh: ";
        getline(cin, this->gender);
    }
    void display()
    {
        cout << "Person:\n";
        cout << "ID:\t" << id << endl;
        cout << "Name:\t" << name << endl;
        cout << "Gender:\t" << gender << endl;
    }
    int getID()
    {
        return id;
    }
};

class student : public person
{
private:
    int stuID;
    string clas;

public:
    student(int _id = 0, string _name = "unknown", string _gender = "unknown", int _stuID = 0, string _clas = "unknown") : person(_id, _name, _gender)
    {
        stuID = _stuID;
        clas = _clas;
    }
    void display()
    {
        person::display();
        cout << "student ID:\t" << stuID << endl;
        cout << "Class:\t" << clas << endl;
    }
    void input()
    {
        person::input();
        cout << "   + Nhap stuID: ";
        cin >> this->stuID;
        cin.ignore(1);
        cout << "   + Nhap ten lop: ";
        getline(cin, this->clas);
    }
};

int main()
{
    List<student> lofstuds;
    student std1(1, "le thi mai", "female", 22, "ET4");
    student std2(2, "le thi hoa", "female", 23, "ET4");
    student std3(3, "Pham thanh long", "male", 24, "ET4");
    lofstuds.add(std3);
    lofstuds.add(std2);
    lofstuds.add(std1);
    lofstuds.sort();
    cout << "=======================List hien tai:=========================" << endl;
    lofstuds.display();
    cout << "Nhap thong tin sua doi:" << endl;
    lofstuds.modify(2); // chinh sua value o node thu 2
    cout << "======================List sau khi sua doi:===================" << endl;
    lofstuds.display();
    cout << "======================List sau khi xoa:=======================" << endl;
    lofstuds.remove(3); // xoa node thu 3
    lofstuds.display();
    cout << endl;
    return 0;
}