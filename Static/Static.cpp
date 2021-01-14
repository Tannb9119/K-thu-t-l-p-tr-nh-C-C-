#include <iostream>
#include <string>
using namespace std;
class HDBH
{
private:
	char *tenhang;
	double tienban;
	static int tshd;
	static double tstienban;

public:
	HDBH(char *tenhang1 = NULL, double tienban1 = 0.0)
	{
		tienban = tienban1;
		tenhang = tenhang1;
		++tshd;
		tstienban += tienban;
	}
	~HDBH()
	{
		cout << "HUy thoi" << endl;
		--tshd;
		tstienban -= tienban;
	}
	void sua();
	static void in()
	{
		cout << "\n Tong so hoa don:" << tshd;
		cout << "\n Tong so tien ban: " << tstienban;
	}
};
int HDBH::tshd = 0;
double HDBH::tstienban = 0.0;
void HDBH::sua()
{
	cout << "\n\n Tenhang:" << tenhang;
	cout << "\n Tien ban:" << tienban;
	tstienban -= tienban;
	cout << "\nSua tien ban thanh:";
	cin >> tienban;
	tstienban += tienban;
}
int main()
{
	HDBH h1((char *)"Xi mang", 2008);
	HDBH h2((char *)"Sat thep", 3008);
	HDBH h3((char *)"Xi mang", 4008);
	HDBH::in();
	h1.sua();
	HDBH::in();
	HDBH::in();
	cout << endl;
}
