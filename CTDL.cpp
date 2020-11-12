#include <iostream>
#include<string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include<iomanip>
#include <ctime>
#include <chrono> 


using namespace std;

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
        s.tinhTrang = "0";
        cout << "Nam phat hanh : " << endl;
        getline(cin, s.namPH);
        cout << "So trang : " << endl;
        getline(cin, s.soTrang);
        cout << "Ngay nhap kho : " << endl;
        getline(cin, s.ngayNK);

       
    }
    void update_sach(sach arr[1000],int n)
    {
        bool flag = true;
        ofstream file_s("../Sach.txt");
        for (int i = 0; i < n-1; i++) {
            if (arr[i].maSach!="null" )
            file_s << arr[i].maSach << "," << arr[i].tenSach << "," << arr[i].tacGia << "," << arr[i].giaBan << "," << arr[i].NXB << "," << arr[i].tinhTrang << "," << arr[i].namPH << "," << arr[i].soTrang << "," << arr[i].ngayNK << endl;

            if (arr[i].maSach == arr[n - 1].maSach)
                flag = false;
        }
        file_s.close();
        if (flag) {
            file_s << arr[n-1].maSach << "," << arr[n - 1].tenSach << "," << arr[n - 1].tacGia << "," << arr[n - 1].giaBan << "," << arr[n - 1].NXB << "," << arr[n - 1].tinhTrang << "," << arr[n - 1].namPH << "," << arr[n - 1].soTrang << "," << arr[n - 1].ngayNK << endl;
        }
        else {
            cout << setw(20) << "Ma sach bi trung, khong them sach vao dc ." << endl;
        }
    }
    void xoa(sach arr[1000], int &n)
    {
        string id_xoa;
        cout << setw(20) << "Nhap id sach can xoa"<<endl;
        cin >> id_xoa;
        bool flag=false;
        for (int index = 0; index <n ; index++) {
            if (arr[index].maSach == id_xoa && arr[index].tinhTrang=="0") {
                arr[index].maSach = "null";
                flag = true;
            }
        }
        if (!flag) {
            cout << setw(20) << "Ma sach khong ton tai hoac sach dang duoc muon.";
        }
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
    int TimSach(sach arr[1000], int sl, string id) {
        for (int index = 0; index < sl; index++) {
            if (arr[index].maSach == id) {
                if (arr[index].tinhTrang == "0")
                    //sach  muon đuoc
                    return 2;
                else
                    //sach ko muon dc
                    return 1;
            }
        }
        //khong tim thay ma sach
        return 0;
    }
    void ttsach(sach arr[1000], int sl, string id,string cd) {
        for (int index = 0; index < sl; index++) {
            if (arr[index].maSach == id) {
                    //doi tinh trang sach
                arr[index].tinhTrang = cd;

            }
        }
    }

    
};
class banDoc {
private:
    string ma, hoTen,sdt, diachi ,ngayTG;
public:
    banDoc()
    {
        this->ma="";
        this->hoTen = "";
        this->ngayTG = "";
        this->sdt = "";
        this->diachi = "";
    }
    ~banDoc()
    {
        this->ma = "";
        this->hoTen = "";
        this->ngayTG = "";
        this->sdt = "";
        this->diachi = "";
    }
    void them(banDoc &bd, int id)
    {
        string maid = to_string(id);
        bd.ma = maid;
        cout << "Ho va ten: " << endl;
        getline(cin, bd.hoTen);
        getline(cin, bd.hoTen);
        cout << "SDT: " << endl;
        getline(cin, bd.sdt);
        cout << "Dia chi : " << endl;
        getline(cin, bd.diachi);
        cout << "Ngay tham gia : " << endl;
        getline(cin, bd.ngayTG);
    }

    void xuattitle_bd()
    {
        int w = 25;
        cout << setw(90) << "Danh sach ban doc" << endl << endl;
        cout << "*******************************************************************************************************************************************************" << endl;
        cout << setw(w) << "Ma ban doc" << setw(w) << "Ho va ten" << setw(w) << "So dien thoai" << setw(w) << "Dia chi" << setw(w) << "Ngay tham gia"<< endl;
    }
    void xuat_bd()
    {
        int w = 25;
        if (this->ma != "null")
        {
            cout << setw(w) << this->ma;
            cout << setw(w) << this->hoTen;
            cout << setw(w) << this->sdt;
            cout << setw(w) << this->diachi;
            cout << setw(w) << this->ngayTG;
            cout << endl;
        }
    }
    void update_bd(banDoc arr[1000], int n)
    {
        ofstream file_s("../BD.txt");
        for (int i = 0; i < n; i++) {
            if (arr[i].ma != "null")
            file_s << arr[i].ma << "," << arr[i].hoTen << "," << arr[i].sdt << "," << arr[i].diachi << "," << arr[i].ngayTG << endl;
        }
        file_s.close();
    }
    void getlist(banDoc arr[1000], int& sl)
    {
        fstream f;
        int i = 0;
        sl = 0;
        f.open("../BD.txt", ios::in);
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
                            arr[sl].ma.push_back(sach_item[index]);
                        }
                        else if (item == 1) {
                            arr[sl].hoTen.push_back(sach_item[index]);
                        }
                        else if (item == 2) {
                            arr[sl].sdt.push_back(sach_item[index]);
                        }
                        else if (item == 3) {
                            arr[sl].diachi.push_back(sach_item[index]);
                        }
                        else if (item == 4) {
                            arr[sl].ngayTG.push_back(sach_item[index]);
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
    
    bool timBD(banDoc arr[1000], int n,string id) {
        for (int index = 0; index < n; index++) {
            if (arr[index].ma == id) {
                return true;
            }
        }
        return false;
    }

};

class phieuMuon {
private:
    string soPhieu, maBD, maSach, ngayMuon, ngayTra, tinhTrang;
    string stt;
public:
    phieuMuon()
    {
        this->soPhieu = "";
        this->maBD = "";
        this->maSach = "";
        this->ngayMuon = "";
        this->ngayTra = "";
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
    void title_phieumuon()
    {
        int w = 25;
        cout << setw(77) << "Danh sach phieu muon" << endl << endl;
        cout << "***********************************************************************************************************************************" << endl;
        cout << setw(w) << "So phieu" << setw(w) << "Ma ban doc" << setw(w) << "Ma sach" << setw(w) << "Ngay muon" << setw(w) << "Ngay tra" << setw(w) << "Tinh trang" << endl;
    }
    void xuat()
    {
        int w = 25;
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
    void getlist_pm(phieuMuon arr[1000], int& sl)
    {
        fstream f;
        int i = 0;
        sl = 0;
        f.open("../PhieuMuon.txt", ios::in);
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
                            arr[sl].soPhieu.push_back(sach_item[index]);
                        }
                        else if (item == 1) {
                            arr[sl].maBD.push_back(sach_item[index]);
                        }
                        else if (item == 2) {
                            arr[sl].maSach.push_back(sach_item[index]);
                        }
                        else if (item == 3) {
                            arr[sl].ngayMuon.push_back(sach_item[index]);
                        }
                        else if (item == 4) {
                            arr[sl].ngayTra.push_back(sach_item[index]);
                        }
                        else if (item == 5) {
                            arr[sl].tinhTrang.push_back(sach_item[index]);
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

    void muonsach(phieuMuon arr[1000], int& sl, string mabd, string masach)
    {
        time_t baygio = time(0);
        tm* ltm = localtime(&baygio);
        string nam = to_string(1900 + ltm->tm_year);
        string thang = to_string(1 + ltm->tm_mon);
        string ngay = to_string(ltm->tm_mday);
        string ngaytra = to_string(ltm->tm_mday +7);

        arr[sl].soPhieu = to_string(sl+1);
        arr[sl].maBD = mabd;
        arr[sl].maSach = masach;
        arr[sl].ngayMuon = ngay+"/"+thang+"/"+nam;
        arr[sl].ngayTra = ngaytra + "/" + thang + "/" + nam;
        arr[sl].tinhTrang = "1";
        sl++;
         
    }
    string trasach(phieuMuon arr[1000], int sl, string sp) {
        for (int index = 0; index < sl; index++) {
            if (arr[index].soPhieu == sp) {
                if (arr[index].tinhTrang == "1") {
                    arr[index].tinhTrang = "0";
                    //tra sach thanh cong
                    return arr[index].maSach;
               }
                else {
                    //phieu muon da dc tra
                    return "1";
                }
            }
        }
        //ko tim thay phieu muon
        return "0";
    }
    void update_pm(phieuMuon arr[1000], int n)
    {
        ofstream file_s("../PhieuMuon.txt");
        for (int i = 0; i < n; i++) {
                file_s << arr[i].soPhieu << "," << arr[i].maSach << "," << arr[i].maBD << "," << arr[i].ngayMuon << "," << arr[i].ngayTra << "," << arr[i].tinhTrang << endl;
        }
        file_s.close();
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
    cout << setw(30) << "************************************"<<endl;
    cout << setw(30) << "*        DANG NHAP HE THONG        *" << endl;
    cout << setw(30) << "************************************" << endl;
    cout << setw(30) << "====================================="<<endl;
    cout << setw(20) << "User : "; cin >> username;
    cout << setw(20) << "Password :"; pass=inputPassword(20);
    login = username +","+ pass;
    
    while (!f.eof())
    {
        getline(f, line);
        datalogin = line;

        if (datalogin==login) {
            system("cls");
            cout << setw(20) << "Ban da dang nhap thanh cong, enter de tiep tuc." << endl;
            _getch();
            f.close();
            return true;
        }
    }
    if (sl >= 2) {
        exit(0);
    }
    system("cls");
    sl++;
    cout << setw(20) << "Sai ten dang nhap hoac mat khau , ban con "<<3-sl<< " lan nhap sai." << endl;
    goto tryagain;
    

}
void menu()
{
    int tab,tab_sach,tab_phieu,tab_bd,n_s=0,n_pm=0,n_bd=0;
    sach list_s[1000],s, iteminput;
    phieuMuon l,pm, list_pm[1000], pm_input;
    banDoc list_bd[1000],bandoc_input,bd ;
    //system("cls");
    s.getlist(list_s, n_s);
    l.getlist_pm(list_pm, n_pm);
    bd.getlist(list_bd, n_bd);
menu:
    system("cls");
    cout<<setw(20) << "MENU" << endl;
    cout << "*************************************" << endl;

    cout<<"1. Quan ly sach"<<endl;
    cout<<"2. Quan ly phieu muon"<<endl;
    cout<<"3. Quan ly ban doc" << endl;
    cout << "0. Thoat chuong trinh" << endl;

    cout<<setw(20) << "Chon tac vu: ";
    cin >> tab;

    if (tab == 1)
    {
    lb_sach:
        system("cls");
        cout << setw(20) << "SACH" << endl;
        cout << "*************************************" << endl;
        cout << "1. Xem danh sach Sach" << endl;
        cout  << "2.Them sach moi" << endl;
        cout  << "3.Xoa sach" << endl;
        cout << "0.Tro lai menu" << endl;

        cout << setw(20) << "Chon tac vu: ";
        cin >> tab_sach;
        if (tab_sach == 1) {
           //xem danh sach sach
            s.xuattitle();
            
            for (int i = 0; i < n_s; i++) {
                list_s[i].xuat();
            }
            _getch();
            goto lb_sach;
        }
        else if (tab_sach == 2) {
            //them sach
            iteminput.them(iteminput);
            list_s[n_s] = iteminput;
            n_s++;
            
            iteminput.update_sach(list_s, n_s);
            _getch();
            goto lb_sach;
        }
        else if (tab_sach == 3) {
            //Xoa sach
            s.xoa(list_s, n_s);
            iteminput.update_sach(list_s, n_s);
            _getch();
            goto lb_sach;
        }
        else if (tab_sach==0) {
            goto menu;
        }
        cout << endl;
        goto lb_sach;
    }
    else if (tab==2)
    {
    lb_pm:
        system("cls");
        cout << setw(20) << "MUON/ TRA SACH" << endl;
        cout << "*************************************" << endl;
        cout << "1. Xem danh sach phieu muon" << endl;
        cout << "2.Muon sach" << endl;
        cout <<  "3.Tra sach" << endl;
        cout <<"0.Tro lai menu" << endl;
        cout << setw(20) << "Chon tac vu: ";
        cin >> tab_phieu;
        if (tab_phieu == 1) {
            //xem danh sach sach
            l.title_phieumuon();

            for (int i = 0; i < n_pm; i++) {
                list_pm[i].xuat();
            }

            cout << endl;
            _getch();
            goto lb_pm;

        }
        else if (tab_phieu == 2) {
            //Muon sach
            string id_bd, id_sach;
            int err;
            cout <<endl << setw(20) << "Nhap ma ban doc : ";
            cin >> id_bd;
            cout << endl << setw(20) << "Nhap ma sach muon :";
            cin >> id_sach;
            err=s.TimSach(list_s, n_s, id_sach);
            if (err == 0) {
                cout << endl << setw(20) << "Khong tim thay sach muon muon.";
            }
            else if (err == 1) {
                cout << endl << setw(20) << "Sach da duoc muon.";
            }
            else {
                bool flag;
                flag=bd.timBD(list_bd, n_bd, id_bd);
                if (flag) {
                    l.muonsach(list_pm, n_pm, id_bd, id_sach);
                    l.update_pm(list_pm, n_pm);
                    s.ttsach(list_s,n_s, id_sach,"1");
                    s.update_sach(list_s, n_s);
                    cout << endl << setw(20)<<"Muon sach thanh cong.";
                }
                else {
                    cout << endl << setw(20) << "Khong tim thay ma ban doc.";
                }
            }
            cout << endl;

            goto lb_pm;
        }
        else if (tab_phieu == 3) {
            //Tra sach
            string sp;
            string err;
            cout << "Nhap so phieu muon tra: ";
            cin >> sp;
            //tra ve id sach
            err=l.trasach(list_pm, n_pm, sp);
            if (err == "0") {
                cout << endl << setw(20) << "Khong tim thay phieu muon.";
            }
            else if (err == "1") {
                cout <<endl << setw(20) << "Phieu muon da dc tra.";
            }
            else{
                cout << endl << setw(20) << "Tra sach thanh cong";
                s.ttsach(list_s, n_s,err, "0");
                s.update_sach(list_s, n_s);

            }
            l.update_pm(list_pm, n_pm);
            cout << endl;
            _getch();
            goto lb_pm;
        }
        else if (tab_phieu==0) {
            goto menu;
        }
        cout << setw(20) <<"Tac vu duoc chon khong ton tai" << endl;
        goto lb_pm;
    }
    else if (tab == 3) {
    lb_bd:
        system("cls");
        cout << setw(20) << "BAN DOC" << endl;
        cout << "*************************************" << endl;
        cout << "1. Xem danh sach ban doc" << endl;
        cout << "2. Them ban doc" << endl;
        cout << "0.Tro lai menu" << endl;
        cout << setw(20) << "Chon tac vu: " ;
        cin >> tab_bd;
        if (tab_bd == 1) {
            //xem danh sach ban doc
            bd.xuattitle_bd();

            for (int i = 0; i < n_bd; i++) {
                list_bd[i].xuat_bd();
            }
            _getch();
            goto lb_bd;
        }
        else if (tab_bd == 2) {
            //them ban doc
            bd.them(bandoc_input,n_bd+1);
            list_bd[n_bd] = bandoc_input;
            n_bd++;
            
            bd.update_bd(list_bd, n_bd);

            goto lb_bd;
        }
        else if (tab_bd==0){
            goto menu;
        }
       
        goto lb_bd;

    }
    else {
    exit(0);
    }

}


int main()
{   
    
    sach s;
    if (dangNhap()){
        menu();
    }
    


}
