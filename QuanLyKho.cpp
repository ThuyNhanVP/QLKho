#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
// cloneeeeeeee
using namespace std;

int dem = 0;
struct MatHang {
	int mahang;
	string ten;
	string loai;
	int soLuong;
	long int giaTri;

	void Nhap() {

		cout << "Nhap ma hang: ";
		cin >> mahang;
		cin.ignore();

		cout << "Nhap ten mat hang: ";
		getline(cin, ten);

		cout << "Nhap loai mat hang: ";
		getline(cin, loai);


		cout << "Nhap so luong mat hang: ";
		cin >> soLuong;

		cout << "Nhap gia tri mat hang: ";
		cin >> giaTri;

		cout << endl;
	}
};

void TieuDe() {
	cout << "         ------------------DANH SACH KHO HANG------------------           " << endl;
	cout << "                       ***********o0o***********                          " << endl;

	cout << left << setw(10) << "Ma Hang"
		<< setw(20) << "Ten"
		<< setw(20) << "Loai"
		<< setw(14) << "So Luong"
		<< setw(13) << "Gia Tri (VND)" << endl;


	cout << setfill('-') << setw(70) << "-" << endl;
}

void Xuat(MatHang* mh, int i) {
	cout << setfill(' ');

	cout << left << setw(10) << mh[i].mahang
		<< setw(20) << mh[i].ten
		<< setw(20) << mh[i].loai
		<< setw(14) << mh[i].soLuong
		<< setw(13) << mh[i].giaTri << endl;
}

void XuatThongTin(string filename, MatHang*& mh) {
	mh = new MatHang[100];
	ifstream inFile;
	inFile.open(filename);
	if (inFile.is_open()) {
		cout << "Mo file thanh cong \n";
		string tam;
		getline(inFile, tam);
		int i = 0;
		TieuDe();
		while (!inFile.eof()) {
			string temp;
			getline(inFile, temp, ',');
			mh[i].mahang = stoi(temp);
			getline(inFile, mh[i].ten, ',');
			getline(inFile, mh[i].loai, ',');
			getline(inFile, temp, ',');
			mh[i].soLuong = stoi(temp);
			getline(inFile, temp);
			mh[i].giaTri = stol(temp);
			Xuat(mh, i);
			i++;
		}
		inFile.close();
	}
	else
		cout << "Khong mo duoc file\n";
}

void LuuThongTin(string filename, MatHang*& mh) {
	ofstream outFile;
	outFile.open(filename, std::ios::out);
	if (outFile.is_open()) {
		std::cout << "Mo file de ghi thanh cong \n";
		int i = 15;
		for (int j = 0; j < i; j++) {
			outFile << mh[j].mahang << ",";
			outFile << mh[j].ten << ",";
			outFile << mh[j].loai << ",";
			outFile << mh[j].soLuong << ",";
			outFile << mh[j].giaTri << "\n";
		}
		outFile.close();
	}
	else {
		std::cout << "Khong mo duoc file de ghi\n";
	}
}


void NhapSL(int& n) {
	do
	{
		cout << "Nhap so luong hang hoa: ";
		cin >> n;
		if (n < 0) {
			cout << "Vui long nhap lai: " << endl;
		}
	} while (n < 0);
}
void NhapHang(MatHang* mh, int n) {
	int kt = 0;
	for (int i = 0; i < n; ++i) {

		do
		{
			kt = 0;
			cout << "Nhap thong tin mat hang thu " << i + 1 << ": " << endl;
			mh[i].Nhap();
			for (int j = 0; j < i; ++j) {
				if (mh[j].mahang == mh[i].mahang) {
					cout << "Moi ban nhap lai " << endl;
					kt++;
				}
			}
		} while (kt != 0);
	}

}
void Them(MatHang* mh, int& n) {
	int kt;
	int cong;
	cout << "Nhap so luong mat hang can them: ";
	cin >> cong;
	n += cong;
	do
	{
		kt = 0;
		for (int i = 0; i < cong; i++) {
			cout << "Nhap thong tin mat hang them thu " << i + 1 << ": " << endl;
			mh[n - i - 1].Nhap();
		}
		for (int i = 0; i < cong; i++) {
			for (int j = 0; j < n - 2; j++) {
				if (mh[j].mahang == mh[n - i - 1].mahang) {
					cout << "Moi ban nhap lai do ma hang hoa khong duoc trung nhau: " << mh[n - i - 1].mahang << endl;
					kt++;
				}
			}
		}
	} while (kt != 0);

}
void Xoa(MatHang* mh, int& n) {
	int macanxoa;
	int kt = 0;
	cout << "Nhap ma hang can xoa: ";
	cin >> macanxoa;
	for (int i = 0; i < n; i++) {
		if (mh[i].mahang == macanxoa) {
			kt++;
			for (int j = i; j < n; j++) {
				mh[j] = mh[j + 1];
			}
		}
	}
	if (kt == 0) {
		cout << "Ma hang ban nhap ko ton tai" << endl;
	}
	else n--;
}
void Chinhsua(MatHang* mh, int n) {
	int macs;

	int kt = 0;
	cout << "Nhap ma hang can chinh sua: ";
	cin >> macs;

	int thongtin, chuyendoi;
	string doi;

	for (int i = 0; i < n; i++) {
		if (mh[i].mahang == macs) {
			kt++;
			TieuDe();
			Xuat(mh, i);
			cout << "Chon thong tin muon chinh sua (VD: Ten = 2; Loai = 3; Soluong = 4; Giatri = 5):  ";
			cin >> thongtin;
			cout << "Gia tri thay doi thanh: ";
			cin >> doi;

			switch (thongtin)
			{
			case 2:
				mh[i].ten = doi;
				break;
			case 3:
				mh[i].loai = doi;
				break;
			case 4:
				chuyendoi = stoi(doi);
				mh[i].soLuong = chuyendoi;
				break;
			case 5:
				chuyendoi = stoi(doi);
				mh[i].giaTri = chuyendoi;
				break;
			default: cout << "Thong tin ban muon chinh sua khong chinh xac";
				break;
			}

		}
	}
	if (kt == 0) {
		cout << "Ma hang ban nhap ko ton tai" << endl;
	}

}
void Hienthi(MatHang* mh, int n) {
	string loaihang;
	int kt = 0;
	long int tongtien = 0;
	cout << "Nhap loai hang can hien thi: ";
	cin.ignore();
	getline(cin, loaihang);
	TieuDe();
	for (int i = 0; i < n; i++) {
		if (mh[i].loai == loaihang) {
			kt++;
			Xuat(mh, i);
			tongtien += mh[i].soLuong * mh[i].giaTri;
		}
	}
	cout << "Tong gia tri mat hang co trong kho: " << tongtien;
	if (kt == 0) {
		cout << "Loai ban nhap ko ton tai" << endl;
	}

}
void Sapxepmhh(MatHang* mh, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mh[i].mahang > mh[j].mahang) {
				swap(mh[i], mh[j]);
			}
		}
	}
}
void Sapxepslg(MatHang* mh, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mh[i].soLuong < mh[j].soLuong) {
				swap(mh[i], mh[j]);
			}
		}
	}
}
void Sapxepgtr(MatHang* mh, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (mh[i].giaTri < mh[j].giaTri) {
				swap(mh[i], mh[j]);
			}
		}
	}
}
void XuatHang(MatHang* mh, int n) {
	long int tongtien = 0;
	TieuDe();
	for (int i = 0; i < n; i++) {
		Xuat(mh, i);
		tongtien += mh[i].soLuong * mh[i].giaTri;
	}
	cout << "Tong gia tri mat hang co trong kho: " << tongtien;
}
void Menu() {
	cout << endl;
	cout << "          +----------------------------------------------------+  " << endl;
	cout << "          | Menu                                               |  " << endl;
	cout << "          | 1. Nhap hang vao kho                               |  " << endl;
	cout << "          | 2. Hien thi toan bo mat hang dang co trong kho     |  " << endl;
	cout << "          | 3. Them hang vao kho                               |  " << endl;
	cout << "          | 4. Chinh sua thong tin                             |  " << endl;
	cout << "          | 5. Xoa mot mat hang trong kho bang ma hang         |  " << endl;
	cout << "          | 6. Hien thi cac loai mat hang chi dinh             |  " << endl;
	cout << "          | 7. Sap xep cac hang hoa theo ma hang hoa           |  " << endl;
	cout << "          | 8. Sap xep cac hang hoa theo so luong co trong kho |  " << endl;
	cout << "          | 9. Sap xep cac hang hoa theo gia tri               |  " << endl;
	cout << "          | 10. Luu file *                                     |  " << endl;
	cout << "          | 0. Thoat                                           |  " << endl;
	cout << "          +----------------------------------------------------+  " << endl;
	cout << "Moi ban nhap lua chon: ";
}

void Menu1() {
	cout << endl;
	cout << "          +----------------------------------------------------+  " << endl;
	cout << "          | Menu                                               |  " << endl;
	cout << "          | 1. Tiep tuc file co san                            |  " << endl;
	cout << "          | 2. Lam bang moi                                    |  " << endl;
	cout << "          | 0. Thoat                                           |  " << endl;
	cout << "          +----------------------------------------------------+  " << endl;
	cout << "Moi ban nhap lua chon: ";
}



int main() {
	MatHang* mh;
	mh = new MatHang[99999];

	string nguon;

	int luachon0;
	Menu1();
	cin >> luachon0;

	int n = 15;
	int luachon;

	do
	{
		switch (luachon0)
		{
		case 1:
			cout << "Moi ban nhap duong dan vao file : ";
			cin >> nguon;
			system("cls");
			XuatThongTin(nguon, mh);


			do
			{
				Menu();
				cin >> luachon;
				system("cls");
				switch (luachon)
				{
				case 1:
					NhapSL(n);
					NhapHang(mh, n);
					break;
				case 2:
					XuatHang(mh, n);
					break;
				case 3:
					Them(mh, n);
					break;
				case 4:
					Chinhsua(mh, n);
					break;
				case 5:
					Xoa(mh, n);
					break;
				case 6:
					Hienthi(mh, n);
					break;
				case 7:
					Sapxepmhh(mh, n);
					XuatHang(mh, n);
					break;
				case 8:
					Sapxepslg(mh, n);
					XuatHang(mh, n);
					break;
				case 9:
					Sapxepgtr(mh, n);
					XuatHang(mh, n);
					break;
				case 10:
					LuuThongTin(nguon, mh);
					break;
				case 0:
					char xacnhan;
					cout << "Ban co thuc su muon thoat chuong trinh khong? (Y/N): ";
					cin >> xacnhan;
					if (xacnhan == 'Y' || xacnhan == 'y') {
						cout << "Thoat chuong trinh";
						exit(0);
					}
					else {
						cout << "Tiep tuc chuong trinh";
						Menu1();
						cin >> luachon0;
						system("cls");
					}
					break;
				default:
					cout << "Lua chon khong hop le vui long chon lai ";
					break;
				}
			} while (luachon0 != 0);
			break;


		case 2:
			do
			{
				Menu();
				cin >> luachon;
				system("cls");
				switch (luachon)
				{
				case 1:
					NhapSL(n);
					NhapHang(mh, n);
					break;
				case 2:
					XuatHang(mh, n);
					break;
				case 3:
					Them(mh, n);
					break;
				case 4:
					Chinhsua(mh, n);
					break;
				case 5:
					Xoa(mh, n);
					break;
				case 6:
					Hienthi(mh, n);
					break;
				case 7:
					Sapxepmhh(mh, n);
					XuatHang(mh, n);
					break;
				case 8:
					Sapxepslg(mh, n);
					XuatHang(mh, n);
					break;
				case 9:
					Sapxepgtr(mh, n);
					XuatHang(mh, n);
					break;
				case 0:
					char xacnhan;
					cout << "Ban co thuc su muon thoat chuong trinh khong? (Y/N): ";
					cin >> xacnhan;
					if (xacnhan == 'Y' || xacnhan == 'y') {
						cout << "Thoat chuong trinh";
						exit(0);
					}
					else {
						cout << "Tiep tuc chuong tinh";
						Menu();
						cin >> luachon;
						system("cls");
					}
					break;
				default:
					cout << "Lua chon khong hop le vui long chon lai ";
					break;
				}
			} while (luachon != 0);
			break;

		case 0:
			char xacnhan0;
			cout << "Ban co thuc su muon thoat chuong trinh khong? (Y/N): ";
			cin >> xacnhan0;
			if (xacnhan0 == 'Y' || xacnhan0 == 'y') {
				cout << "Thoat chuong trinh";
				exit(0);
			}
			else {
				cout << "Tiep tuc chuong tinh";
				Menu1();
				cin >> luachon0;
				system("cls");
			}
			break;
		default:
			cout << "Lua chon khong hop le vui long chon lai ";
			break;
		}
	} while (luachon0 != 0);


	/*	int n = 5;
		int luachon;
		do
		{
			Menu();
			cin >> luachon;
			system("cls");
			switch (luachon)
			{
			case 1:
				NhapSL(n);
				NhapHang(mh, n);
				break;
			case 2:
				XuatHang(mh, n);
				break;
			case 3:
				Them(mh, n);
				break;
			case 4:
				Chinhsua(mh, n);
				break;
			case 5:
				Xoa(mh, n);
				break;
			case 6:
				Hienthi(mh, n);
				break;
			case 7:
				Sapxepmhh(mh, n);
				XuatHang(mh, n);
				break;
			case 8:
				Sapxepslg(mh, n);
				XuatHang(mh, n);
				break;
			case 9:
				Sapxepgtr(mh, n);
				XuatHang(mh, n);
				break;
			case 0:
				char xacnhan;
				cout << "Ban co thuc su muon thoat chuong trinh khong? (Y/N): ";
				cin >> xacnhan;
				if (xacnhan == 'Y' || xacnhan == 'y') {
					cout << "Thoat chuong trinh";
				}
				else {
					cout << "Tiep tuc chuong tinh";
					Menu();
					cin >> luachon;
					system("cls");
				}
				break;
			default:
				cout << "Lua chon khong hop le vui long chon lai ";
				break;
			}
		} while (luachon != 0);
		*/
	return 0;
}