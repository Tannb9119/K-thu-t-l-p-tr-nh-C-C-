#include <iostream>
#include <stdlib.h>
using namespace std;

// Cho các lớp sau:

// Lớp mô tả một điểm ảnh
// cho bởi 3 byte màu Red, Green và Blue
// mỗi byte có giá trị từ 0 đến 255
#define BYTE unsigned char
class Pixel
{
public:
    BYTE R, G, B;

public:
    Pixel();
    Pixel(BYTE r, BYTE g, BYTE b);
    Pixel(int value);      // R - byte 0, G - byte 1, B - byte 2
    int GrayScale() const; // lấy mức xám: (2R + 3G + B) / 8

    friend Pixel operator+(const Pixel &left, const Pixel &right);
    friend ostream &operator<<(ostream &left, const Pixel &right);
};

Pixel::Pixel()
{
    R = G = B = 0;
}

Pixel::Pixel(BYTE r, BYTE g, BYTE b) : R(r), G(g), B(b) {}

Pixel::Pixel(int value)
{
    B = value % 256;
    value /= 256;
    G = value % 256;
    R = value / 256;
}
int Pixel::GrayScale() const
{
    return (2 * R + 3 * G + B) / 8;
}

Pixel operator+(const Pixel &left, const Pixel &right)
{
    return Pixel(left.R + right.R, left.G + right.G, left.B + right.B);
}
ostream &operator<<(ostream &left, const Pixel &right)
{
    left << "(" << (int)right.R << ", " << (int)right.G << ", " << (int)right.B << ")";
}
// Lớp mô tả một ảnh
// có chiều rộng, chiều cao
// và mảng 2 chiều các điểm ảnh
class Bitmap
{
    int width, height;
    Pixel **data;
    void freeData();
    void createData(int w, int h);

public:
    ~Bitmap() { freeData(); }
    Bitmap();
    Bitmap(int width, int height);
    Bitmap(const Bitmap &bmp);

    int getWidth() const;
    int getHeight() const;

    // Lấy ảnh con từ điểm(x, y) có kích thước w x h
    Bitmap Crop(int x, int y, int w, int h);

    // Lấy tần suất các mức xám trong ảnh
    int *Histogram();

    Pixel &operator()(int x, int y);
    Bitmap &operator=(const Bitmap &bmp);
};

Bitmap::Bitmap() : width(0), height(0), data(0) {}

Bitmap::Bitmap(int width, int height)
{
    createData(width, height);
}

Bitmap::Bitmap(const Bitmap &bmp)
{
    freeData();
    Bitmap(bmp.width, bmp.height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = bmp.data[i][j];
        }
    }
}

int Bitmap::getWidth() const { return width; }

int Bitmap::getHeight() const { return height; }

Bitmap Bitmap::Crop(int x, int y, int w, int h)
{
    Bitmap crop(w, h);
    int ww = (x + w) <= width ? (x + w) : width;
    int hh = (y + h) <= height ? (y + h) : height;
    for (int i = y; i < hh; i++)
    {
        for (int j = x; j < ww; j++)
        {
            crop.data[i][j] = this->data[i][j];
        }
    }
    return crop;
}

int *Bitmap::Histogram()
{
    int *bmp = new int[256];
    for (int i = 0; i < 256; i++)
        bmp[i] = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bmp[data[i][j].GrayScale()] += 1;
        }
    }
    return bmp;
}

Pixel &Bitmap::operator()(int x, int y) { return data[x][y]; }

Bitmap &Bitmap::operator=(const Bitmap &bmp)
{
    if (this->width != bmp.width || this->height != bmp.height)
    {
        freeData();
        createData(bmp.width, bmp.height);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                data[i][j] = bmp.data[i][j];
            }
        }
    }
    return *this;
}

void Bitmap::freeData()
{
    if (data == 0)
        return;
    for (int i = 0; i < height; i++)
        delete[] data[i];
    delete[] data;
}

void Bitmap::createData(int w, int h)
{
    width = w;
    height = h;
    data = new Pixel *[height];
    for (int i = 0; i < height; i++)
        data[i] = new Pixel[width];
}

int main()
{
    Pixel p(0, 60, 120);
    cout << p + Pixel(10, 10, 10) << endl;
    // cho kết quả trên màn hình: (10, 70, 130)

    Bitmap A;
    Bitmap B(100, 100);

    for (int y = 0; y < B.getHeight(); y++)
    {
        for (int x = 0; x < B.getWidth(); x++)
            B(x, y) = Pixel(rand());
    }
    A = B;

    int *hist = A.Histogram();
    for (int i = 0; i < 256; i++)
        cout << hist[i] << endl;
    delete[] hist;
    Bitmap C(B.Crop(20, 20, 40, 60));
    cout << C(0, 0);
    return 0;
}
