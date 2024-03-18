#include <iostream>
#include <string>
using namespace std;

string Genre[100];
string Judul[100];
int jumlah_data = 0;

void menu(){
    cout<<"\n============Menu==========\n";
    cout<<"1. Menambahkan Judul Webtoon\n";
    cout<<"2. Menghapus Judul Webtoon\n";
    cout<<"3. Update Judul Webtoon\n";
    cout<<"4. Lihat Semua Judul Webtoon\n";
    cout<<"0. Shutdown\n";
    cout<<"==========================\n";
}

void lihatJudulWebtoon(){  
    cout<<"-------------------------------\n";
    cout<<"--------List Judul Webtoon--------\n";
    cout<<"No.  Genre     Judul\n";
    for (int i = 0; i < jumlah_data; i++) {
        cout <<i+1<<". "<<Genre[i]<<" - "<< Judul[i] << " \n";
    }
    cout<<"-------------------------------\n";
}

bool cekNomorValid(int nomor, int jumlah_data) {
    return (nomor >= 1 && nomor <= jumlah_data);
}

int jumlahJudulWebtoon() {
    return jumlah_data;
}

bool login(int attempt = 3){
    if (attempt == 0) {
        return false;
    }

    string nama, nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan NIM: ";
    cin >> nim;
    if (nama == "Dapin" && nim == "2309106002") {
        return true;
    }
    else{
        cout << "NAMA ATAU NIM ANDA SALAH\n";
        return login(attempt - 1);
    }
}

int main(){
    if(!login()){
        cout << "Anda gagal login. Program akan keluar." << endl;
        return 0;
    }

    string pilihanmenu;

    while(true){
        menu();
        cout<<"Pilih Menu: ";cin>>pilihanmenu;
        if(pilihanmenu=="1"){
            string genre, judul;
            cout<<"Masukkan Genre Webtoon: ";cin>>genre;
            cout<<"Masukkan Judul Webtoon: ";cin.ignore();getline(cin, judul);
            Genre[jumlah_data] = genre;
            Judul[jumlah_data] = judul;
            jumlah_data++;
        }
        else if(pilihanmenu=="2"){
            int nomor_hapus;
            if(jumlah_data>=1){
                lihatJudulWebtoon();
                cout<<"Masukkan Nomor Judul yang ingin dihapus: ";cin>>nomor_hapus;
                if (cekNomorValid(nomor_hapus, jumlah_data)) {
                    for (int i = nomor_hapus - 1; i < jumlah_data - 1; i++) {
                        Genre[i] = Genre[i + 1];
                        Judul[i] = Judul[i + 1];
                    }
                    jumlah_data--;
                }
                else {
                    cout << "Nomor Judul tidak valid!" << endl;
                }
            }
            else{
                cout<<"Belum ada Judul Webtoon yang tersedia." << endl;
            }            
        }
        else if(pilihanmenu=="3"){
            int nomor_update;
            if(jumlah_data>=1){
                lihatJudulWebtoon();
                cout<<"Masukkan Nomor Judul yang ingin diupdate: ";cin>>nomor_update;
                if (cekNomorValid(nomor_update, jumlah_data)) {
                    cout<<"Masukkan Genre Webtoon baru: ";cin>>Genre[nomor_update-1];
                    cout<<"Masukkan Judul Webtoon baru: ";cin.ignore();getline(cin, Judul[nomor_update-1]);
                }
                else {
                    cout << "Nomor Judul tidak valid!" << endl;
                }
            }
            else{
                cout<<"Belum ada Judul Webtoon yang tersedia." << endl;
            }        
        }
        else if(pilihanmenu=="4"){
            if(jumlah_data>=1){
                lihatJudulWebtoon();
            }
            else{
                cout<<"Belum ada Judul Webtoon yang tersedia." << endl;
            } 
        }
        else if(pilihanmenu=="0"){
            cout<<"SHUTDOWN";
            return 0;
        }
        else{
            cout<<"Maaf Pilihan tidak Tersedia";
        }
    }
    return 0;
}
