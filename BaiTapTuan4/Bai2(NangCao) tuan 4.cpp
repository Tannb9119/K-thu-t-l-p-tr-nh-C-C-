#include<iostream>
#include<string.h>
using namespace std;

struct diemMH {
	float toan;
	float ly;
	float hoa;
	float tbc;
};

struct SinhVien {
	char hoTen[30];
	int mssv;
	char lop[10];
	int namSinh;
	struct diemMH diem;
};

int check(float a) {
	if (a != 0)
		return 1;
	return 0;
}

void nhapDiemMH(struct diemMH* diem) {
	cout << "Toan :";
	cin >> diem->toan;
	cout << "Ly :";
	cin >> diem->ly;
	cout << "Hoa :";
	cin >> diem->hoa;
	int count = check(diem->toan) + check(diem->ly) + check(diem->hoa);
	if (count)
		diem->tbc = (diem->toan + diem->ly + diem->hoa) / count;
	else
		diem->tbc = 0;
	cin.ignore();
}

struct SinhVien nhap() {
	struct SinhVien sinhVien;
	cout << "Nhap thong tin sinh vien\n";
	cout << "Ho ten:";
	cin.getline(sinhVien.hoTen, 30);
	cout << "Mssv:";
	cin >> sinhVien.mssv;
	cin.ignore();
	cout << "Lop:";
	cin.getline(sinhVien.lop, 10);
	cout << "Nam sinh:";
	cin >> sinhVien.namSinh;
	nhapDiemMH(&sinhVien.diem);
	return sinhVien;
}

char* timTen(char s[]) {
	char* k = new char, * p;
	p = strchr(s, ' ');
	while (p != NULL) {
		k = p + 1;
		p = strchr(k, ' ');
	}
	return k;
}

void hienThi(struct SinhVien sv) {
	printf("%-8d %-17s %-8s %-12d %-8.2f %-8.2f %-8.2f %-8.2f \n",
		sv.mssv, sv.hoTen, sv.lop, sv.namSinh, sv.diem.toan, sv.diem.ly, sv.diem.hoa, sv.diem.tbc);
}

void inLop(struct SinhVien dssv[], int slsv) {
	int a[100];// dung de duyet phan tu 
	int count = 0; //Dem so luong nhom sinh vien cung lop
	int b[100]; //so luong sinh vien nhom thu i 
	int count1; // Bien dem gan gia tri vao mang b[]
	struct SinhVien** cungLop = new SinhVien * [slsv];
	for (int i = 0; i < slsv; i++) {
		*(cungLop + i) = new SinhVien[10];
	}
	for (int i = 0; i < slsv; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < slsv; i++) {
		count1 = 0;
		if (a[i] != 0) {
			*(*(cungLop + count) + count1) = dssv[i];
			count1++;
			for (int j = i + 1; j < slsv; j++) {
				if (strcmp(dssv[i].lop, dssv[j].lop) == 0) {
					*(*(cungLop + count) + count1) = dssv[j];
					count1++;
					a[j] = 0;
				}
			}
			b[count++] = count1;
		}
	}
	int check1 = 0;
	for (int i = 0; i < count; i++) {
		if (b[i] != 1)
			check1 = 1;
		break;
	}
	if (check1) {
		for (int i = 0; i < count; i++) {
			if (b[i] != 1) {
				cout << "Cac sinh vien cung hoc lop " << (*(*(cungLop + i))).lop << "la: " << timTen((*(*(cungLop + i))).hoTen);
				for (int j = 1; j < b[i]; j++) {
					cout << ", " << timTen((*(*(cungLop + i) + j)).hoTen);
				}
				cout << endl;
			}
		}
	}
	else
		cout << "Khong co sinh vien nao hoc cung lop\n";
}

void inNamSinh(struct SinhVien dssv[], int slsv) {
	int a[100];
	int count = 0;
	int b[100];
	int count1;
	struct SinhVien** cungNS = new SinhVien * [slsv];
	for (int i = 0; i < slsv; i++) {
		*(cungNS + i) = new SinhVien[10];
	}
	for (int i = 0; i < slsv; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < slsv; i++) {
		count1 = 0;
		if (a[i] != 0) {
			*(*(cungNS + count) + count1) = dssv[i];
			count1++;
			for (int j = i + 1; j < slsv; j++) {
				if (dssv[i].namSinh == dssv[j].namSinh) {
					*(*(cungNS + count) + count1) = dssv[j];
					a[j] = 0;
					count1++;
				}
			}
			b[count++] = count1;
		}
	}
	int check1 = 0;
	for (int i = 0; i < count; i++) {
		if (b[i] != 1)
			check1 = 1;
		break;
	}
	if (check1) {
		for (int i = 0; i < count; i++) {
			if (b[i] != 1) {
				cout << "Cac sinh vien cung sinh nam " << (*(*(cungNS + i))).namSinh << "la: " << timTen((*(*(cungNS + i))).hoTen);
				for (int j = 1; j < b[i]; j++) {
					cout << ", " << timTen((*(*(cungNS + i) + j)).hoTen);
				}
				cout << endl;
			}
		}
	}
	else
		cout << "Khong co sinh vien nao cung nam sinh" << endl;
}

void inTenVaNamSinh(struct SinhVien dssv[], int slsv) {
	int a[100];
	int count = 0;
	int b[100];
	int count1;
	struct SinhVien** cungTenVaNS = new SinhVien * [slsv];
	for (int i = 0; i < slsv; i++) {
		*(cungTenVaNS + i) = new SinhVien[10];
	}
	for (int i = 0; i < slsv; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < slsv; i++) {
		count1 = 0;
		if (a[i] != 0) {
			*(*(cungTenVaNS + count) + count1) = dssv[i];
			count1++;
			for (int j = i + 1; j < slsv; j++) {
				if (dssv[i].namSinh == dssv[j].namSinh && strcmp(timTen(dssv[i].hoTen), timTen(dssv[j].hoTen)) == 0) {
					*(*(cungTenVaNS + count) + count1) = dssv[j];
					a[j] = 0;
					count1++;
				}
			}
			b[count++] = count1;
		}
	}
	int check1 = 0;
	for (int i = 0; i < count; i++) {
		if (b[i] != 1) {
			check1 = 1;
			break;
		}
	}
	if (check1) {
		for (int i = 0; i < count; i++) {
			if (b[i] != 1) {
				cout << "Cac sinh vien cung ten va sinh nam " << (*(*(cungTenVaNS + i))).namSinh << "la: " << timTen((*(*(cungTenVaNS + i))).hoTen);
				cout << endl;
			}
		}
	}
	else
		cout << "Khong co sinh vien nao cung ten va cung nam sinh\n";
}

int checkToan(float a, float b, float c) {
	if (a != 0 && b == 0 && c == 0)
		return 1;
	else
		return 0;
}

void inLopToan(struct SinhVien dssv[], int slsv) {
	int a[100];
	int count = 0;
	int b[100];
	int count1;
	struct SinhVien** cungLopToan = new SinhVien * [slsv];
	for (int i = 0; i < slsv; i++) {
		*(cungLopToan + i) = new SinhVien[10];
	}
	for (int i = 0; i < slsv; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < slsv; i++) {
		count1 = 0;
		if (a[i] != 0) {
			*(*(cungLopToan + count) + count1) = dssv[i];
			count1++;
			for (int j = i + 1; j < slsv; j++) {
				if (strcmp(dssv[i].lop, dssv[j].lop) == 0 && (checkToan(dssv[i].diem.toan, dssv[i].diem.ly, dssv[i].diem.hoa) == 1) && (checkToan(dssv[j].diem.toan, dssv[j].diem.ly, dssv[j].diem.hoa) == 1)) {
					*(*(cungLopToan + count) + count1) = dssv[j];
					a[j] = 0;
					count1++;
				}
			}
			b[count++] = count1;
		}
	}
	int check1 = 0;
	for (int i = 0; i < count; i++) {
		if (b[i] != 1) {
			check1 = 1;
			break;
		}
	}
	if (check1) {
		for (int i = 0; i < count; i++) {
			if (b[i] != 1) {
				cout << "Cac sinh vien cung lop " << (*(*(cungLopToan + i))).lop << " chi hoc toan la :" << timTen((*(*(cungLopToan + i))).hoTen);
				for (int j = 1; j < b[i]; j++) {
					cout << ", " << timTen((*(*(cungLopToan + i) + j)).hoTen);
				}
				cout << endl;
			}
		}
	}
	else
		cout << "Khong co sinh vien nao cung lop chi hoc mon toan" << endl;
}

int check3Mon(float a, float b, float c) {
	if ((check(a) + check(b) + check(c)) == 3)
		return 1;
	else
		return 0;
}

void inLop3Mon(struct SinhVien dssv[], int slsv) {
	int a[100];
	int count = 0;
	int b[100];
	int count1;
	struct SinhVien** cungLop3Mon = new SinhVien * [slsv];
	for (int i = 0; i < slsv; i++) {
		*(cungLop3Mon + i) = new SinhVien[10];
	}
	for (int i = 0; i < slsv; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < slsv; i++) {
		count1 = 0;
		if (a[i] != 0) {
			*(*(cungLop3Mon + count) + count1) = dssv[i];
			count1++;
			for (int j = i + 1; j < slsv; j++) {
				if (strcmp(dssv[i].lop, dssv[j].lop) == 0 && check3Mon(dssv[i].diem.toan, dssv[i].diem.ly, dssv[i].diem.hoa) == 1 && check3Mon(dssv[j].diem.toan, dssv[j].diem.ly, dssv[j].diem.hoa) == 1) {
					*(*(cungLop3Mon + count) + count1) = dssv[j];
					a[j] = 0;
					count1++;
				}
			}
			b[count++] = count1;
		}
	}
	int check1 = 0;
	for (int i = 0; i < count; i++) {
		if (b[i] != 1) {
			check1 = 1;
			break;
		}
	}
	if (check1) {
		for (int i = 0; i < count; i++) {
			if (b[i] != 1) {
				cout << "Cac sinh vien cung lop " << (*(*(cungLop3Mon + i))).lop << " hoc ca 3 mon la : " << timTen((*(*(cungLop3Mon + i))).hoTen);
				for (int j = 1; j < b[i]; j++) {
					printf(", %s", timTen((*(*(cungLop3Mon + i) + j)).hoTen));
				}
				printf("\n");
			}
		}
	}
	else
		cout << "Khong co sinh vien nao cung lop hoc ca 3 mon" << endl;
}

void sort(struct SinhVien dssv[], int slsv) {
	struct SinhVien tmp;
	for (int i = 0; i < slsv - 1; i++) {
		for (int j = i + 1; j < slsv; j++) {
			if (dssv[i].diem.tbc < dssv[j].diem.tbc) {
				tmp = dssv[i];
				dssv[i] = dssv[j];
				dssv[j] = tmp;
			}
		}
	}
}

void cungTBC(struct SinhVien dssv[], int slsv) {
	int a[100];
	int count = 0;
	int b[100];
	int count1;
	struct SinhVien** cungTBC = new SinhVien * [slsv];
	for (int i = 0; i < slsv; i++) {
		*(cungTBC + i) = new SinhVien[10];
	}
	for (int i = 0; i < slsv; i++) {
		a[i] = 1;
	}
	for (int i = 0; i < slsv; i++) {
		count1 = 0;
		if (a[i] != 0) {
			*(*(cungTBC + count) + count1) = dssv[i];
			count1++;
			for (int j = i + 1; j < slsv; j++) {
				if (dssv[i].diem.tbc == dssv[j].diem.tbc) {
					*(*(cungTBC + count) + count1) = dssv[j];
					count1++;
					a[j] = 0;
				}
			}
			b[count++] = count1;
		}
	}
	int check1 = 0;
	for (int i = 0; i < count; i++) {
		if (b[i] != 1) {
			check1 = 1;
			break;
		}
	}
	if (check1) {
		for (int i = 0; i < count; i++) {
			if (b[i] != 1) {
				cout << "So luong cac sinh vien co diem tbc =  " << (*(*(cungTBC + i))).diem.tbc << " la:" << b[i];
				cout << endl;
			}
		}
	}
	else
		cout << "Khong co sinh vien nao co cung diem TBC" << endl;
}

int main() {
	struct SinhVien dssv[100];
	int slsv, i;
	cout << "Nhap so luong sv:";
	cin >> slsv;
	cin.ignore();
	for (i = 0; i < slsv; i++) {
		dssv[i] = nhap();
	}
	printf("%-8s %s %s %-11s %-8s %-12s %-8s %-8s %-8s %-8s\n",
		"MSSV", "Ho", "va", "ten", "Lop", "Nam sinh", "Toan", "Ly", "Hoa", "TBC");
	for (i = 0; i < slsv; i++) {
		hienThi(dssv[i]);
	}
	inLop(dssv, slsv);
	inNamSinh(dssv, slsv);
	inTenVaNamSinh(dssv, slsv);
	inLopToan(dssv, slsv);
	inLop3Mon(dssv, slsv);
	sort(dssv, slsv);
	printf("DSSV sau khi sap xep la\n");
	printf("%-8s %s %s %-11s %-8s %-12s %-8s %-8s %-8s %-8s\n",
		"MSSV", "Ho", "va", "ten", "Lop", "Nam sinh", "Toan", "Ly", "Hoa", "TBC");
	for (i = 0; i < slsv; i++) {
		hienThi(dssv[i]);
	}
	cungTBC(dssv, slsv);
	return 0;
}

