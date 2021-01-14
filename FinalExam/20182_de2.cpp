#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

// Cho các lớp sau:

// Lớp mô tả một kích thước trên mặt phẳng
class Size
{
public:
    double Width, Height;

public:
    Size();
    Size(double width, double height);
};

Size::Size() : Width(0), Height(0) {}

Size::Size(double width, double height) : Width(width), Height(height) {}

// Lớp mô tả một điểm trên mặt phẳng
class Point
{
public:
    double X, Y;

public:
    Point();
    Point(double x, double y);

    friend Point operator+(const Point &left, const Size &size);

    friend double operator-(const Point &left, const Point &right);

    friend ostream &operator<<(ostream &left, const Point &right);
    // Tinh dien tich tam giac theo tich vo huong
    friend double calculateAreaTriangle(Point A, Point B, Point C)
    {
        return (0.5 * abs((C.X - A.X) * (B.Y - A.Y) - (B.X - A.X) * (C.Y - A.Y)));
    };
};

Point::Point() : X(0), Y(0) {}

Point::Point(double x, double y) : X(x), Y(y) {}

Point operator+(const Point &left, const Size &size)
{
    Point res;
    res.X = left.X + size.Width;
    res.Y = left.Y + size.Height;
    return res;
}

double operator-(const Point &left, const Point &right)
{
    Point res;
    res.X = left.X - right.X;
    res.Y = left.Y - right.Y;
    return sqrt(pow(res.X, 2) + pow(res.Y, 2));
}

ostream &operator<<(ostream &left, const Point &right)
{
    left << "(" << right.X << ", " << right.Y << ")";
    return left;
}

// Lớp mô tả một vùng khép kín
// là tập các điểm có tính chất
// 3 điểm bất kỳ không tạo thành đường thẳng
class Area
{
    int nPoint;
    Point *data;

public:
    ~Area()
    {
        if (data)
            delete[] data;
    }
    Area();
    Area(int n);

    Point &operator[](int index);
    Area &operator=(const Point *pts); // Copy từ dãy các điểm
    Area &operator+=(const Point &pt); // Thêm một điểm vào cuối danh sách
    double operator()();               // Lấy diện tích của vùng bao bởi các điểm
    friend ostream &operator<<(ostream &left, const Area &right);
};

Area::Area() : nPoint(0), data(NULL) {}
Area::Area(int n) : nPoint(n) { data = new Point[n]; }

Point &Area::operator[](int index)
{
    return data[index];
}

Area &Area::operator=(const Point *pts)
{
    for (int i = 0; i < nPoint; i++)
    {
        data[i] = pts[i];
    }
    return *this;
} // Copy từ dãy các điểm

Area &Area::operator+=(const Point &pt)
{
    Point *p = new Point[nPoint];
    for (int i = 0; i < nPoint; i++)
        p[i] = data[i];
    delete[] data;
    data = new Point[nPoint + 1];
    for (int i = 0; i < nPoint; i++)
        data[i] = p[i];
    data[nPoint] = pt;
    nPoint++;
    return *this;
} // Thêm một điểm vào cuối danh sách

void swap(Point &a, Point &b)
{
    Point tmp = a;
    a = b;
    b = tmp;
}

double Area::operator()()
{
    // sap xep theo thu tu tang dan cua x
    for (int i = 0; i < nPoint - 1; i++)
    {
        for (int j = i + 1; j < nPoint; j++)
        {
            if (data[i].X > data[j].X)
                swap(data[i], data[j]);
        }
    }
    int up = 0;
    for (int i = 0; i < nPoint; i++)
    {
        if (data[i].Y > data[nPoint - 1].Y) // dem cac diem nam tren diem xa nhat
            up++;
    }
    int flag = (data[0].Y > data[nPoint - 1].Y) ? up : up + 1;
    if (flag != nPoint - 1)
        swap(data[flag], data[nPoint - 1]); // Hoan doi diem xa nhat voi diem[flag]
    int i_up = 1;
    //-xap sep diem theo vong tron
    //+xep tren
    for (int i = 1; i < nPoint; i++)
    {
        if (data[i].Y > data[flag].Y)
        {
            if (i != i_up)
                swap(data[i], data[i_up]);
            i_up++;
        }
    }
    // +xep duoi
    for (int i = flag + 1; i < nPoint - 1; i++)
    {
        for (int j = i + 1; j < nPoint; j++)
            if (data[i].X < data[j].X)
                swap(data[i], data[j]);
    }
    double area = 0;
    for (int i = 1; i < nPoint - 1; i++)
        area += calculateAreaTriangle(data[0], data[i], data[i + 1]);
    return area;
} // Lấy diện tích của vùng bao bởi các điểm

ostream &operator<<(ostream &left, const Area &right)
{
    left << "{";
    for (int i = 0; i < right.nPoint; i++)
    {
        left << right.data[i];
        if (i != right.nPoint - 1)
            left << ", ";
    }
    left << "}";
    return left;
}

int main()
{
    Point O; // Điểm tại gốc tọa độ
    Point src[] = {O, Point(40, 0), Point(40, 20), Point(35, 25)};

    Area area(4);
    area = src;
    area += (area[3] + Size(-30, 0)); // Thêm một điểm (5, 25)
    area += Point(25, -5);
    cout << "Khoang cach giua " << area[1] << " va " << area[2]
         << " la " << area[1] - area[2] << endl;
    cout << "Vung: " << area << endl
         << "Co dien tich: " << area() << endl;

    return 0;
}
