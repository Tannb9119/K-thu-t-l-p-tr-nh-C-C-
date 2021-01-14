#include <iostream>
#include <string>
using namespace std;

class person
{
private:
    int id;
    string name;
    string gender;

public:
    person(int _id = 0, string _name = "Unkown", string _gender = "unknown")
    {
        id = _id;
        name = _name;
        gender = _gender;
    }
    person(const person &per)
    {
        id = per.id;
        name = per.name;
        gender = per.gender;
    }
    ~person() { id = 0, name = "unknown", gender = "unknown"; }
    void input()
    {
        cout << "Nhap ma dinh danh:";
        cin >> id;
        fflush(stdin);
        cout << "Nhap ho ten:";
        getline(cin, name);
        cout << "Nhap gioi tinh:";
        getline(cin, gender);
    }
    void display()
    {
        cout << "ID:\t" << id << endl;
        cout << "Name:\t" << name << endl;
        cout << "Gender:\t" << gender << endl;
    }
    int getID() { return id; }
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
    void input()
    {
        person::input();
        cout << "Nhap stuID:";
        cin >> stuID;
        fflush(stdin);
        cout << "Nhap clas:";
        getline(cin, clas);
    }
};

template <class T>
class Node
{
public:
    T value;
    Node<T> *next;

public:
    Node(T v) : value(v), next(NULL) {}
};

template <class T>
class List
{
private:
    Node<T> *head, *tail;
    int count;

public:
    List() : count(0), head(NULL), tail(NULL) {}
    ~List() { count = 0, delete head, delete tail; }
    void removeAll()
    {
        while (head != NULL)
        {
            Node<T> *p = head;
            head = p->next;
            delete p;
        }
    }
    void add(T v)
    {
        Node<T> *newNode = new Node<T>(v);
        if (count++ == 0)
            head = newNode;
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
    }
    Node<T> *First() { return head; }
    T *toArray()
    {
        T *arr = new T[count];
        Node<T> *p = head;
        int i = 0;
        while (p != NULL)
        {
            arr[i++] = p->value;
            p = p->next;
        }
        return arr;
    }
    void remove(int pos)
    {
        Node<T> *p = head;
        if (pos <= 1)
        {
            head = p->next;
            delete p;
        }
        else
        {
            if (pos > count)
                pos = count;
            int check = 1;
            while (check++ != pos - 1)
            {
                p = p->next;
            }
            Node<T> *p1 = p->next;
            p->next = p1->next;
            if (pos == count)
                tail = p;
            delete p1;
        }
        count--;
    }
    void display()
    {
        T *arr = this->toArray();
        for (int i = 0; i < count; i++)
        {
            cout << "Thong tin nguoi thu: " << i + 1 << endl;
            arr[i].display();
            cout << endl;
        }
    }
    void sort()
    {
        for (Node<T> *p = head; p != NULL; p = p->next)
        {
            for (Node<T> *p1 = p->next; p1 != NULL; p1 = p1->next)
            {
                if (p->value.getID() > p1->value.getID())
                {
                    T tmp = p->value;
                    p->value = p1->value;
                    p1->value = tmp;
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