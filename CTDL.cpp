#include <iostream>
#include<string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include<iomanip>


using namespace std;
//DSLK
/*template <typename T>
struct node {
    T data;
    node<T>* next;
};

template <class T>
node<T>* GetNode(T x);

template <class T>
class List
{
    node<T>* head;
    node<T>* tail;
public:
    List();
    node getNode(T x)
    {
        node p;
        if (p != NULL)
        {
            p->data = x;
            p->next = NULL;
        }
        return p;
    }
    void create_list() {
       node head =NULL, tail = NULL;
    };
    void AddTail(node& head, node& tail , T val) {
        node r = getNode(val);
        if (head == NULL)
            head = tail = r;
        else
        {
            tail->next = r;
            tail = r;
        }
    };
    void RemoveNode(node& head, node& tail, string id) {
        node* ps = new node();
        ps = head;
        while (ps->next != NULL ) {
            if (ps.data) {
                ps->next = ps->next->next;
                break;
            }
            ps = ps->next;
            it++;
        }
    }
    };
    void RemoveList();
    node<T>* FindNode(T val);
};
*/

//cac class

class sach
{
private:
    string maSach, tenSach,tacGia, NXB;
    string giaBan, namPH, soTrang;
    string ngayNK;
    string tinhTrang;
public:
    sach()
    {
        this->maSach = "";
        this->tenSach = "";
        this->tacGia = "";
        this->NXB = "";
        this->giaBan = "";
        this->namPH = "";
        this->soTrang = "";
        this->ngayNK = "";
        this->tinhTrang = "";
    }
    ~sach()
    {
        this->maSach = "";
        this->tenSach = "";
        this->tacGia = "";
        this->NXB = "";
        this->giaBan = "";
        this->namPH = "";
        this->soTrang = "";
        this->ngayNK = "";
        this->tinhTrang = "";
    }


    void them(sach &s)
    {
        
        cout << "Ma sach : " << endl;
        getline(cin, s.maSach);
        getline(cin, s.maSach);
        cout << "Ten sach : " << endl;
        getline(cin, s.tenSach);
        cout << "Tac gia : " << endl;
        getline(cin, s.tacGia);
        cout << "Gia sach : " << endl;
        getline(cin, s.giaBan);
        cout << "Nha xuat ban : " << endl;
        getline(cin, s.NXB);
        cout << "Tinh trang : " << endl;
        getline(cin, s.tinhTrang);
        cout << "Nam phat hanh : " << endl;
        getline(cin, s.namPH);
        cout << "So trang : " << endl;
        getline(cin, s.soTrang);
        cout << "Ngay nhap kho : " << endl;
        getline(cin, s.ngayNK);

       
    }
    void update_sach(sach arr[1000],int n)
    {
        ofstream file_s("../Sach.txt");
        for (int i = 0; i < n; i++) {
            file_s << arr[i].maSach << "," << arr[i].tenSach << "," << arr[i].tacGia << "," << arr[i].giaBan << "," << arr[i].NXB << "," << arr[i].tinhTrang << "," << arr[i].namPH << "," << arr[i].soTrang << "," << arr[i].ngayNK << endl;
        }
        file_s.close();
    }
    void xoa(sach arr[1000], int &n)
    {
        string id_xoa;
        cout << "Nhap id sach can xoa"<<endl;
        cin >> id_xoa;
        bool flag=false;
        for (int index = 0; index <n ; index++) {
            if (arr[index].maSach == id_xoa) {
                arr[index].maSach = "null";
                flag = true;
            }
        }
        if (!flag) {
            cout << "Ma sach khong ton tai";
        }
    }
    void sua()
    {

    }
    void xuattitle()
    {
        int w = 15;
        cout << setw(90) << "Danh sach sach trong thu vien" << endl<<endl;
        cout << "*******************************************************************************************************************************************************"<<endl;
        cout << setw(w) <<"Ma sach"  << setw(w) <<"Ten sach" << setw(w) <<"Gia sach" << setw(w) << "Tac gia" << setw(w) << "NXB" << setw(w) << "Tinh trang" << setw(20) << "Nam phat hanh" << setw(20) << "So trang" << setw(20) << "Ngay nhap kho" << setw(w) << endl;
    }
    void xuat()
    {
        int w = 15;
        if (this->maSach != "null") {
            cout << setw(w) << this->maSach;
            cout << setw(w) << this->tenSach;
            cout << setw(w) << this->giaBan;
            cout << setw(w) << this->tacGia;
            cout << setw(w) << this->NXB;
            cout << setw(w) << this->tinhTrang;
            cout << setw(20) << this->namPH;
            cout << setw(20) << this->soTrang;
            cout << setw(20) << this->ngayNK;
            cout << endl;
        }
    }
    void getlist(sach arr[1000],int &sl)
    {
        fstream f;
        int i = 0;
        sl = 0;
        f.open("../Sach.txt", ios::in);
        string line, sach_item;
        int  item = 0;
        while (!f.eof())
        {
            getline(f, line);
            sach_item = line;
            if (sach_item != "") {
                for (int index = 0; index <= sach_item.size() - 1; index++) {
                    if (sach_item[index] != ',') {
                        if (item == 0) {
                            arr[sl].maSach.push_back(sach_item[index]);
                        }
                        else if (item == 1) {
                            arr[sl].tenSach.push_back(sach_item[index]);
                        }
                        else if (item == 2) {
                            arr[sl].giaBan.push_back(sach_item[index]);
                        }
                        else if (item == 3) {
                            arr[sl].tacGia.push_back(sach_item[index]);
                        }
                        else if (item == 4) {
                            arr[sl].NXB.push_back(sach_item[index]);
                        }
                        else if (item == 5) {
                            arr[sl].tinhTrang.push_back(sach_item[index]);
                        }
                        else if (item == 6) {
                            arr[sl].namPH.push_back(sach_item[index]);
                        }
                        else if (item == 7) {
                            arr[sl].soTrang.push_back(sach_item[index]);
                        }
                        else if (item == 8) {
                            arr[sl].ngayNK.push_back(sach_item[index]);
                        }

                    }
                    else
                    {
                        item++;
                    }

                }
                item = 0;
                sl++;
            }

        }
        
        f.close();
        
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
    string stt;
public:
    phieuMuon()
    {
        this->soPhieu = "123";
        this->maBD = "321";
        this->maSach = "112";
        this->ngayMuon = "26/03/20";
        this->ngayTra = ngayMuon;
        this->tinhTrang = "0";

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
    void title_phieumuon()
    {
        int w = 22;
        cout << setw(77) << "Danh sach phieu muon" << endl << endl;
        cout << "***********************************************************************************************************************************" << endl;
        cout << setw(w) << "So phieu" << setw(w) << "Ma ban doc" << setw(w) << "Ma sach" << setw(w) << "Ngay muon" << setw(w) << "Ngay tra" << setw(w) << "Tinh trang" << endl;
    }
    void xuat()
    {
        int w = 22;
        if (this->soPhieu != "null") {
            cout << setw(w) << this->soPhieu;
            cout << setw(w) << this->maBD;
            cout << setw(w) << this->maSach;
            cout << setw(w) << this->ngayMuon;
            cout << setw(w) << this->ngayTra;
            cout << setw(w) << this->tinhTrang;

            cout << endl;
        }
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
    int sl = 0;
tryagain: 

    fstream f;
    f.open("../Admin.txt", ios::in);
    string datalogin;
    string line;
    string username, pass, login;
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, 14);
    cout << "************************************"<<endl;
    cout << "*        DANG NHAP HE THONG        *" << endl;
    cout << "************************************" << endl;
    cout << "====================================="<<endl;
    cout << setw(10) << "User : "; cin >> username;
    cout << setw(10) << "Password :"; pass=inputPassword(20);
    login = username +","+ pass;
    
    while (!f.eof())
    {
        getline(f, line);
        datalogin = line;

        if (datalogin==login) {
            system("cls");
            cout << "Dang nhap thanh cong" << endl;
            f.close();
            return true;
        }
    }
    if (sl >= 2) {
        exit(0);
    }
    system("cls");
    sl++;
    cout << "Sai ten dang nhap hoac mat khau , bạn còn "<<3-sl<< " lan nhap sai." << endl;
    goto tryagain;
    

}
void menu()
{
    int tab,tab_sach,tab_phieu,n=0;
    sach list[1000],s, iteminput;
    phieuMuon l;
    //system("cls");
    s.getlist(list, n);
menu:
    cout << "1. Quan ly sach"<<endl;
    cout << "2. Quan ly phieu muon"<<endl;
    cout << "Chon tac vu: "<<endl;
    cin >> tab;
    if (tab == 1)
    {
        cout << "1. Xem danh sach Sach" << endl;
        cout << "2.Them sach moi" << endl;
        cout << "3.Xoa sach" << endl;
        cout << "Chon tac vu: " << endl;
        cin >> tab_sach;
        if (tab_sach == 1) {
           //xem danh sach sach
            s.xuattitle();
            
            for (int i = 0; i < n; i++) {
                list[i].xuat();
            }



            goto menu;

        }
        else if (tab_sach == 2) {
            //them sach
            iteminput.them(iteminput);
            list[n] = iteminput;
            n++;
            iteminput.update_sach(list, n);

            goto menu;
        }
        else if (tab_sach == 3) {
            //Xoa sach
            s.xoa(list, n);
            iteminput.update_sach(list, n);
            goto menu;
        }
    }
    else if (tab==2)
    {
        cout << "1. Xem danh sach phieu muon" << endl;
        cout << "2.Them phieu muon moi" << endl;
        cout << "3.Tra sach" << endl;
        cout << "Chon tac vu: " << endl;
        cin >> tab_sach;
        if (tab_sach == 1) {
            //xem danh sach sach
            l.title_phieumuon();

            for (int i = 0; i < n; i++) {
                l.xuat();
            }



            goto menu;

        }
        else if (tab_sach == 2) {
            //them sach
            iteminput.them(iteminput);
            list[n] = iteminput;
            n++;
            iteminput.update_sach(list, n);

            goto menu;
        }
        else if (tab_sach == 3) {
            //Xoa sach
            s.xoa(list, n);
            iteminput.update_sach(list, n);
            goto menu;
        }

        goto menu;
    }

}


int main()
{   
    
    sach s;
    if (dangNhap()){
        menu();
        
    }


}
