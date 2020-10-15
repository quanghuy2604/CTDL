#include <iostream>
#include<cstring>
#include <conio.h>
#include <windows.h>
using namespace std;

class sach
{
private:
    string maSach, tenSach,tacGia, NXB;
    int giaBan, namPH, soTrang;
    string ngayNK;
    int tinhTrang;
public:
    /*sach()
    {
        this->maSach = "";
        this->tenSach = "";
        this->tacGia = "";
        this->NXB = "";
        this->giaBan = 0;
        this->namPH = 0;
        this->soTrang = 0;
        this->ngayNK = "";
        this->tinhTrang = 0;
    }
    ~sach()
    {
        this->maSach = "";
        this->tenSach = "";
        this->tacGia = "";
        this->NXB = "";
        this->giaBan = 0;
        this->namPH = 0;
        this->soTrang = 0;
        this->ngayNK = "";
        this->tinhTrang = 0;
    }*/


    void them()
    {
        cout << "Ma sach : " << endl;
        cin >> this->maSach;
        cout << "Ten sach : " << endl;
        cin >> this->tenSach;
        cout << "Tac gia : " << endl;
        cin >> this->tacGia;
        cout << "Nha xuat ban : " << endl;
        cin >> this->NXB;
        cout << "Gia sach : " << endl;
        cin >> this->giaBan;
        cout << "Tinh trang : " << endl;
        cin >> this->tinhTrang;
        cout << "Nam phat hanh : " << endl;
        cin >> this->namPH;
        cout << "So trang : " << endl;
        cin >> this->soTrang;
        cout << "Ngay nhap kho : " << endl;
        cin >> this->ngayNK;
    }

    void xoa()
    {
        
    }
    void sua()
    {

    }
    void xuat()
    {
        cout << "Ma sach : "<<this->maSach << endl;
        cout << "Ten sach : "<<this->tenSach << endl;
        cout << "Tac gia : "<<this->tacGia << endl;
        cout << "Nha xuat ban : "<<this->NXB << endl;
        cout << "Gia sach : "<<this->giaBan << endl;
        cout << "Tinh trang : "<<this->tinhTrang << endl;
        cout << "Nam phat hanh : "<<this->namPH << endl;
        cout << "So trang : "<<this->soTrang << endl;
        cout << "Ngay nhap kho : "<<this->ngayNK << endl;

    }
};
class banDoc {
private:
    string ma, hoTen, ngayTG;
public:
    banDoc()
    {
        this->ma="";
        this->hoTen = "";
        this->ngayTG = "";
    }
    ~banDoc()
    {
        this->ma = "";
        this->hoTen = "";
        this->ngayTG = "";
    }
    void setBD()
    {

    }

    void getBD()
    {

    }
};

class phieuMuon {
private:
    string soPhieu, maBD, maSach, ngayMuon, ngayTra, tinhTrang;
    int stt;
public:
    phieuMuon()
    {
        this->soPhieu = "";
        this->maBD = "";
        this->maSach = "";
        this->ngayMuon = "";
        this->ngayTra = ngayMuon;
        this->tinhTrang = "";

    }
    ~phieuMuon()
    {
        this->soPhieu = "";
        this->maBD = "";
        this->maSach = "";
        this->ngayMuon = "";
        this->ngayTra = "";
        this->tinhTrang = "";
    }
    void setBD()
    {

    }

    void getBD()
    {

    }
};
string inputPassword(size_t length_max)
{
    string strRet;
    char ch = 0;
    bool bShow = false;
    do
    {
        ch = _getch();
        if ((strRet.size() < length_max) &&
            (isalpha(ch) || isalnum(ch)))
        {
            cout << (bShow ? ch : '*');
            strRet.push_back(ch);
        }
        else
        {
            if (0x1B == ch)
            {
                bShow = !bShow;
                cout << string(strRet.size(), '\b');

                if (bShow)
                    cout << strRet;
                else
                    cout << string(strRet.size(), '*');

            }
            if ('\b' == ch && !strRet.empty())
            {
                cout << "\b \b";
                strRet.resize(strRet.size() - 1);
            }
        }

    } while ('\r' != ch);
    cout << endl;
    return strRet;
}
bool dangNhap() {
    tryagain: 
    string username, pass;
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 14);
    cout << "************************************"<<endl;
    cout << "*        DANG NHAP HE THONG        *" << endl;
    cout << "************************************" << endl;
    cout << "User : "; cin >> username;
    cout << "Password :"; pass=inputPassword(20);
    if (username == "user" && pass=="123456789") {
        cout << "Dang nhap thanh cong"<<endl;
        
        return true;
    }
    else {
        system("cls");
        cout << "Sai ten dang nhap hoac mat khau"<<endl;
        goto tryagain;

    }

}
void menu()
{
    //system("cls");
    cout << "1. Quan ly sach"<<endl;
    cout << "2. Qan ly phieu muon"<<endl;
}


int main()
{
    sach s;
    if (dangNhap()){
        menu();
        s.them();
        s.xuat();
    }
}