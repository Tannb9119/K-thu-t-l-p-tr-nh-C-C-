#include<stdio.h>
#include<string.h>

struct diemMH{
	float toan;
	float ly;
	float hoa;
	float tbc;
};

struct SinhVien{
	char hoTen[30];
	int mssv;
	char lop[10];
	int namSinh;
	struct diemMH diem; 
};

int check(float a){
	if(a)
		return 1;
	return 0;
}

void nhapDiemMH(struct diemMH *diem){
	printf("Toan :");
	scanf("%f", &diem->toan);
	printf("Ly :");
	scanf("%f",&diem->ly);
	printf("Hoa :");
	scanf("%f",&diem->hoa);
	int count = check(diem->toan)+check(diem->ly)+check(diem->hoa);
	if(count)
		diem->tbc = (diem->toan + diem->ly + diem->hoa)/count;
	else
		diem->tbc = 0;
	getchar();
}

struct SinhVien nhap(){
	struct SinhVien sinhVien;
	printf("Nhap thong tin sinh vien : \n");
	printf("Ho ten:");
	gets(sinhVien.hoTen);
	printf("Mssv:");
	scanf("%d",&sinhVien.mssv);
	getchar();
	printf("Lop:");
	gets(sinhVien.lop);
	printf("Nam sinh:");
	scanf("%d",&sinhVien.namSinh);
	nhapDiemMH(&sinhVien.diem);
	return sinhVien;
}

char *timTen(char s[]){
	char *k, *p;
	p = strchr(s,' ');
	while(p != NULL){
		k = p+1;
		p = strchr(k,' ');
	}
	return k;
}

void hienThi(struct SinhVien sv){
	printf("%-8d %-17s %-8s %-12d %-8.2f %-8.2f %-8.2f %-8.2f \n",
	sv.mssv, sv.hoTen, sv.lop, sv.namSinh,sv.diem.toan, sv.diem.ly, sv.diem.hoa, sv.diem.tbc);
}

void inLop(struct SinhVien dssv[], int slsv){
	int a[slsv];
	for(int i = 0; i < slsv; i++){
		a[i] = 1;
	}
	for(int i = 0; i < slsv; i++){
		if(a[i]){
			printf("\nCac sinh vien cung hoc lop %s la: %s",dssv[i].lop, timTen(dssv[i].hoTen));
			for(int j = i+1; j < slsv; j++){
				if(strcmp(dssv[i].lop, dssv[j].lop) == 0){
					printf(", %s",timTen(dssv[j].hoTen));
					a[j] = 0;
				}
			}
		}
	}
}

void inNamSinh(struct SinhVien dssv[], int slsv){
	int a[slsv];// dung de duyet phan tu 
	int count = 0; //Dem so luong nhom sinh vien co cung nam sinh
	int b[slsv]; //so luong sinh vien nhom thu i 
	int count1; // Bien dem gan gia tri vao mang b[]
	char Ten[slsv][slsv][10];
	for(int i = 0; i < slsv; i++){
		a[i] = 1;
	}
	for(int i = 0; i < slsv; i++){
		count1 = 0;
		if(a[i] != 0){
			strcpy(Ten[count][count1] , timTen(dssv[i].hoTen));
			count1++;
			for(int j = i+1; j < slsv; j++){
				if(dssv[i].namSinh == dssv[j].namSinh){
					strcpy(Ten[count][count1] , timTen(dssv[j].hoTen));
					a[j] = 0;
					count1++;
				}
			}
			b[count++] = count1;
		}
	}
	for(int i = 0; i < count; i++){
		if(b[i] != 1){
			printf("Cac sinh vien cung sinh nam %d la: %s", Ten[i][0]);
			for(int j = 1; j < b[i]; j++){
			printf(", %s", Ten[i][j]);
			}
		}
	}
}

int main(){
	struct SinhVien dssv[100];
	int slsv, i;
	printf("Nhap so luong sv:");
	scanf("%d",&slsv);
	getchar();
	for(i = 0; i < slsv; i++){
		dssv[i] = nhap();
	}
	printf("%-8s %s %s %-11s %-8s %-12s %-8s %-8s %-8s %-8s\n",
			"MSSV","Ho","va","ten","Lop","Nam sinh","Toan","Ly","Hoa","TBC");
	for(i = 0; i < slsv; i++){
		hienThi(dssv[i]);
	}
	inNamSinh(dssv, slsv);
	return 0;
}

