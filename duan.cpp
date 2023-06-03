#include <iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

class homestay_dp{
friend class homestay_tt;
int room_no;
char ten[30];
char diachi[50];
char sdt[10];
public:
void datphong();
void thongtin();
int check(int r) ;
void chinhsua();
void suathongtin(int r);
void xoathongtin(int r);
 
    
};

void homestay_dp::datphong()
{

  system("cls");
int r,flag;
ofstream fout("lv.dat",ios::app);


cout<<"\n ----------------------";
cout<<"\n co tong 3 phong";
cout<<"\n phong danh cho dai gia dinh:1";
cout<<"\n phong danh cho gia dinh nho:2";
cout<<"\n phong danh cho cap doi:3";
cout <<"\n nhap vao phong muon dat:- "<<endl;
cin>>r;

flag=check(r);

if(flag)
cout<<"\n phong da duoc dat roi";

else
{

room_no=r;
cout<<" \nten: ";
cin>>ten;
cout<<"\n dia chi: ";
cin>>diachi;
cout<<"\n sdt: ";
cin>>sdt;

fout.write((char*)this,sizeof(homestay_dp));
cout<<"\n dat phong thanh cong...!!!";

}

cout<<"\n bam enter de tiep tuc.....!!";

getch();
fout.close();

}
int homestay_dp::check(int r)
{

int flag=0;

ifstream fin("lv.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(homestay_dp));
if(room_no==r)
{

flag=1;
break;
}
}
fin.close();
return(flag);
}


void homestay_dp::thongtin()
{

  system("cls");

ifstream fin("lv.dat",ios::in);
int r,flag;

cout<<"\n nhap vao phong muon hien thi thong tin:- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(homestay_dp));
if(room_no==r)
{

  system("cls");
cout<<"\n chi tiet";
cout<<"\n ----------------";
cout<<"\n\n phong so: "<<room_no;
cout<<"\n ten: "<<ten;
cout<<"\n dia chi: "<<diachi;
cout<<"\n sdt: "<<sdt;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n khong tim thay hoac bo trong....!!";
cout<<"\n\n bam enter de tiep tuc....!!";

getch();
fin.close();
}

void homestay_dp::suathongtin(int r)
{

  system("cls");



cout<<"\n nhap so phong: " ;
cin>>r;
long pos,flag=0;

fstream file("lv.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(homestay_dp));

if(room_no==r)
{

cout<<"\n nhap thong tin moi";
cout<<"\n -----------------";
cout<<"\n ten: ";
cin>>ten;
cout<<" dia chi: ";
cin>>diachi;
cout<<" sdt: ";
cin>>sdt;
file.seekg(pos);

file.write((char*)this,sizeof(homestay_dp));
cout<<"\n da sua thong tin....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n khong tim thay hoac bo trong...!!";
file.close();}


class homestay_tt{
int sodem;
public:
void bill();
};
void homestay_tt::bill(){
        int n,k;
        cout<< "BANG GIA"<<endl;
        cout<<"phong 1 800k/1dem"<<endl;
        cout<<"phong 2 500k/1dem"<<endl;
        cout<<"phong 3 300k/1dem"<<endl;
        cout<<"nhap vao phong can thanh toan"<<endl;
        cin>>n;
        cout<<"nhap sodem"<<endl;
        cin>>sodem;
        if(n==1){
            cout<<"so tien can tra la "<<sodem*800<<"k";
        }
        if(n==2){
            cout<<"so tien can tra la "<<sodem*500<<"k";
        }
        if(n==3){
            cout<<"so tien can tra la "<<sodem*300<<"k";
        }
        cout<<"\nchon phuong thuc thanh toan"<<endl;
        cout<<"1.chuyen khoan"<<endl;
        cout<<"2.tien mat"<<endl;
        cout<<"lua chon cua ban la:"<<endl;
        cin>>k;
        if(k==1){
            cout<<"stk:0704586311--MBANK--TRAN LE LONG VU"<<endl;
            }
        if(k==2){
            cout<<"tra tai quay";
        }
    }

void main_menu(homestay_dp &dp,homestay_tt &tt)
{
int choice,r;
while(choice!=5)
{

  system("cls");
cout<<"*************************"<<endl;
cout<<"      * MAIN MENU *"<<endl;
cout<<"*************************"<<endl;
cout<<"1.Dat phong"<<endl;
cout<<"2.tra cuu thong tin khach hang"<<endl;
cout<<"3. sua thong tin"<<endl;
cout<<"4. thanh toan"<<endl;
cout<<"5.Exit"<<endl;
cout<<"lua chon cua ban: ";
cin>>choice;

switch(choice)
{

case 1:	dp.datphong();
break;

case 2: dp.thongtin();
break;

case 3: dp.suathongtin(r);
break;

case 4: tt.bill();
break;

case 5: break;

default:
{

cout<<"\n\n\t\t\tlua chon khong hop ly.....!!!";
cout<<"\n\t\t\t hay chon lai....!!";
getch();

}

}

}

}

int main(){
  homestay_dp dp;
  homestay_tt tt;
  
   main_menu(dp,tt);
   return 0;

}










