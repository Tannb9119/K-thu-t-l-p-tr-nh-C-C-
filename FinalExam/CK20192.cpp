#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <class T>
class Node
{
public:
    T Value;
    Node *next;
    Node(T v) : Value(v), next(0) {}
};

template <class T>
class List
{
private:
    Node<T> *head, *tail;
    int count;

public:
    List() : count(0) { head = 0, tail = 0; }
    ~List()
    {
        delete head;
        delete tail;
    }
    void RemoveAll()
    {
        while (count--)
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
        {
            head = newNode;
        }
        else
            tail->next = newNode;
        tail = newNode;
    }
    Node<T> *First() const
    {
        return head;
    }
    int Count() const
    {
        return count;
    }
    T *toArray()
    {
        T *arr = new T[count];
        int i = 0;
        Node<T> *p = head;
        while (p != 0)
        {
            arr[i++] = p->Value;
            p = p->next;
        }
        return arr;
    }
    void sort()
    {
        for (Node<T> *p1 = head; p1 != 0; p1 = p1->next)
        {
            for (Node<T> *p2 = p1->next; p2 != 0; p2 = p2->next)
            {
                if (p1->Value->Tong() < p2->Value->Tong())
                {
                    T tmp = p1->Value;
                    p1->Value = p2->Value;
                    p2->Value = tmp;
                }
            }
        }
    }
    double TongTB()
    {
        int dem = 0;
        Node<T> *p = head;
        for (int i = 0; i < count; i++, p = p->next)
            if (p->Value->TB() >= 8)
                dem++;
        return (double)dem * 100 / count;
    }
    void search(int n)
    {
        T *arr = this->toArray();
        for (int i = 0; i < count; i++)
        {
            if (arr[i]->TB() >= n)
            {
                cout << *arr[i] << endl;
            };
        }
    }
};

class Date
{
public:
    int Day, Month, Year;
    Date()
    {
        Day = Month = Year = 0;
    }
    Date(int a, int b, int c)
    {
        Year = a;
        Month = b;
        Day = c;
    }
    friend ostream &operator<<(ostream &os, const Date &d1)
    {
        if ((d1.Day < 10) && (d1.Month < 10))
            os << ""
               << "0" << d1.Day << ".0" << d1.Month << "." << d1.Year;
        else if (d1.Month < 10)
            os << "" << d1.Day << ".0" << d1.Month << "." << d1.Year;
        else if (d1.Day < 10)
            os << ""
               << "0" << d1.Day << "." << d1.Month << "." << d1.Year;
        else
            os << "" << d1.Day << "." << d1.Month << "." << d1.Year;
        return os;
    }
};

class ThiSinh
{
public:
    Date NgaySinh;
    string HoTen;
    double Toan, Ly, Anh; // Điểm các môn thi, điểm toán hệ số 2
public:
    ThiSinh() {}
    ThiSinh(const char *hoTen, const Date ns, double toan, double ly, double anh)
    {
        NgaySinh = ns;
        HoTen = hoTen;
        Toan = toan;
        Ly = ly;
        Anh = anh;
    }
    double Tong() const
    {
        return (this->Toan * 2 + this->Ly + this->Anh);
    } // Tính tổng điểm
    double TB() const
    {
        return (this->Toan * 2 + this->Ly + this->Anh) / 4;
    } // Trung bình các điểm
    friend ostream &operator<<(ostream &os, const ThiSinh &ts1)
    {
        os << left << setw(30) << ts1.HoTen;
        os << ts1.NgaySinh << "\t";
        os << left << setw(6) << ts1.Toan;
        os << left << setw(6) << ts1.Ly << left << setw(6) << ts1.Anh << left << setw(6) << ts1.Tong();
        os << setprecision(3) << ts1.TB() << endl;
    } // toán tử luồng ra
};

class ListThiSinh : public List<ThiSinh *>
{
public:
    ListThiSinh(ThiSinh **arr)
    {
        int i = 0;
        while (arr[i])
        {
            this->add(arr[i++]);
        }
    }
};

int main()
{
    ThiSinh *arr[] = {
        new ThiSinh("Nguyen Thanh Son", Date(2020, 1, 15), 8, 7, 8),
        new ThiSinh("Tran Hai Nam", Date(2020, 10, 6), 9, 8, 6),
        new ThiSinh("Vu Duy Anh", Date(2020, 7, 31), 7, 10, 9),
        new ThiSinh("Hoang Anh Tuan", Date(2020, 12, 22), 3, 5, 7),
        new ThiSinh("Pham Thanh Huyen", Date(2020, 8, 10), 8, 8, 8),
        new ThiSinh("Phung Ngoc Linh", Date(2020, 4, 5), 9, 9, 9),
        0};
    ListThiSinh cacThiSinh(arr);
    Node<ThiSinh *> *p = cacThiSinh.First();
    int soLuong = cacThiSinh.Count();
    for (int i = 0; i < soLuong; i++, p = p->next)
    {
        cout << *p->Value << endl;
    }
    cout << "sap xep tang dan theo tong diem" << endl;
    cout << "\n";
    cacThiSinh.sort();
    Node<ThiSinh *> *p1 = cacThiSinh.First();
    for (int i = 0; i < soLuong; i++, p1 = p1->next)
    {
        cout << *p1->Value << endl;
    }
    cout << "danh sach thi sinh co diem trung binh lon hon 8" << endl;
    cacThiSinh.search(8);
    cout << "Ty le thi sinh dat chuan" << endl;
    cout << cacThiSinh.TongTB() << "%" << endl;
    return 0;
}