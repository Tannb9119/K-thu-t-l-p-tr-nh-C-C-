#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <class T>
class Node
{
public:
    T Value;
    Node *Next;
    Node(T v) : Value(v), Next(0) {}
};

template <class T>
class List
{
    Node<T> *head, *tail;
    int count;

public:
    List() : count(0) {}
    ~List()
    {
        delete head;
        delete tail;
        count = 0;
    } // Hàm hủy

    void RemoveAll()
    {
        while (count)
        {
            --count;
            Node<T> *p = head;
            head = p->Next;
            delete p;
        }
    }
    void Add(T v)
    {
        Node<T> *p = new Node<T>(v);
        if (count++ == 0)
        {
            head = p;
        }
        else
        {
            tail->Next = p;
        }
        tail = p;
    }
    Node<T> *First() const { return head; }
    int Count() const { return count; }
    T *ToArray()
    {
        T *arr = new T[count];
        Node<T> *p = head;
        for (int i = 0; i < count; i++, p = p->Next)
        {
            arr[i] = p->Value;
        }
        return arr;
    }
    void sort()
    {
        for (Node<T> *p1 = head; p1 != 0; p1 = p1->Next)
        {
            for (Node<T> *p2 = p1->Next; p2 != 0; p2 = p2->Next)
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
};

class Date
{
public:
    int Day, Month, Year;
    Date() { Day = Month = Year = 0; }
    Date(int a, int b, int c)
    {
        Year = a;
        Month = b;
        Day = c;
    } // Hàm khởi tạo thiết lập các giá trị năm, tháng, ngày
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
    } // toán tử luồng ra
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
        HoTen = (string)hoTen;
        Toan = toan;
        Ly = ly;
        Anh = anh;
    }
    double Tong() const
    {
        return (Toan * 2 + Ly + Anh);
    } // Tính tổng điểm
    double TB() const
    {
        return (Toan * 2 + Ly + Anh) / 4;
    }                                                       // Trung bình các điểm
    friend ostream &operator<<(ostream &, const ThiSinh &); // toán tử luồng ra
};

ostream &operator<<(ostream &os, const ThiSinh &ts1)
{
    os << left << setw(30) << ts1.HoTen;
    os << ts1.NgaySinh << "\t";
    os << left << setw(6) << ts1.Toan;
    os << left << setw(6) << ts1.Ly << left << setw(6) << ts1.Anh << left << setw(6) << ts1.Tong();
    os << setprecision(3) << ts1.TB() << endl;
}

class ListThiSinh : public List<ThiSinh *>
// danh sach các Node co value kieu ThiSinh
{
public:
    ListThiSinh(ThiSinh **arr)
    {
        int i = 0;
        while (arr[i])
        {
            this->Add(arr[i++]);
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
    for (int i = 0; i < soLuong; i++, p = p->Next)
    {
        cout << *p->Value << endl;
    }
    cacThiSinh.sort();
    cout << "List thi sinh sau khi sap xep:" << endl;
    Node<ThiSinh *> *p1 = cacThiSinh.First();
    for (int i = 0; i < soLuong; i++, p1 = p1->Next)
    {
        cout << *p1->Value << endl;
    }
}
