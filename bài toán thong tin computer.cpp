#include <iostream>
#include <string>
using namespace std;
1

class produce{
		
	string address ; 	
	friend class machine;
	friend class computer; 
	public:
		string producer_name;
};
class machine{
	public:
		string label ;
		float cost;
		produce NSX;
		void input();
		void output();
};
void machine::input(){
	fflush(stdin);
	cout <<"Nhap ten nha san xuat:";
	getline(cin,NSX.producer_name);
	fflush(stdin);
	cout <<"Nhap dia chi nha san xuat:";
	getline(cin,NSX.address);
	cout << "Nhap nhan hieu san xuat:";
	getline(cin,label);
	cout << "Nhap gia thanh:";
	cin >> cost;
}
void machine::output(){
	cout<<"==========THONG TIN=========="<<endl;
	cout <<"Ten nha san xuat:"<<NSX.producer_name<<endl;
	cout <<"Dia chi nha san xuat:" <<NSX.address <<endl;
	cout << "Nhan hieu san xuat:"<<label<<endl;
	cout << "Gia thanh:"<<cost<<endl;
}
class computer: public machine{
	public:
		
		float speed;
		float dung_luong_ram;
		float dung_luong_HDD;
		void input();
		void output();
		friend void in_IBM();
		friend void sapxep();
		friend void xoa();
};
void computer :: input(){
	machine :: input();
	cout <<"Nhap toc do:";
	cin >> speed;
	cout <<"Nhap dung luong ram:";
	cin >> dung_luong_ram;
	cout <<"Nhap dung luong HDD:";
	cin >> dung_luong_HDD;
}
void computer::output(){
	machine :: output();
	cout <<"Nhap toc do:"<<speed<<endl;
	cout <<"Nhap dung luong ram:"<<dung_luong_ram<<endl;
	cout <<"Nhap dung luong HDD:"<<dung_luong_HDD<<endl;
}
void sapxep(int n,computer a[]){
	int tam;
	for(int i=0; i<n-1; i++){
		for(int j=i+1;j<n; j++){
			if(a[i].cost> a[j].cost){
				tam=a[i].cost;
				a[i].cost =  a[j].cost;
				a[j].cost = tam;
			}
		}
	}
}
//void in_IBM(int n, computer a[]){
//	for(int i=0; i<n; i++){
//		if (strcmp(a[i].NSX.producer_name,"IBM")==0){
//			a[i].output();
//		}
//	}
//}
int main(){
	computer a[100];
	int n;
	cout <<"Nhap gia tri n:";
	cin >> n;
	for(int i=0; i<n; i++){
		cout<<"SAN PHAM "<< i+1 <<endl;
		a[i].input();
	}
//	cout <<"MAY TINH HANG IBM"<<endl;
//		in_IBM(n,a);
	cout << "SAP XEP THEO GIA"<<endl;
		sapxep(n,a);
	for(int i=0; i<n; i++){
		a[i].output();
	}
	return 0;
}

