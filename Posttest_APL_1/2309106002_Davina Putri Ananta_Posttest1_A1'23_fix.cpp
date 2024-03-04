#include <iostream>
using namespace std;

  int pilihanmenu;

int main(){
    string nama;//untuk input nama
    string nim;//untuk input nim
    int ulang = 0;//Total Perulangan
    int menu;
    double jumlah;
   
    double rupiah, dollar, euro, yen;

    while (ulang<3){
        cout<<"Masukan Nama: \n";cin>>nama;
        cout<<"Masukan NIM: \n";cin>>nim;
        if (nama=="Dapin" && nim=="2309106002"){
            while (true){
                cout << "\nMenu Konversi Mata Uang:" << endl;
                cout << "1. Konversi Rupiah ke (Dollar, Euro, Yen)" << endl;
                cout << "2. Konversi Dollar ke (Rupiah, Euro, Yen)" << endl;
                cout << "3. Konversi Euro ke (Rupiah, Dollar, Yen)" << endl;
                cout << "4. Konversi Yen ke (Rupiah, Dollar, Euro)" << endl;
                cout << "5. Keluar" << endl;

                cout << "Pilih menu (1/2/3/4/5): ";
                cin >> menu;

                switch (menu) {
		                    case 1:
		                        cout << "Masukkan jumlah Rupiah: ";
		                        cin >> rupiah;
		                        cout << "Konversi ke USD: " << rupiah/15700<< endl;
		                        cout << "Konversi ke Euro: " << rupiah/17000 << endl;
		                        cout << "Konversi ke Yen: " << rupiah/104 << endl;
		                        break;
		                    case 2:
		                        cout << "Masukkan jumlah Dollar: ";
		                        cin >> dollar;
		                        cout << "Konversi ke Rupiah: " << dollar*15700 << endl;
		                        cout << "Konversi ke Euro: " << dollar*0.92<< endl;
		                        cout << "Konversi ke Yen: " <<dollar*150 << endl;
		                        break;
		                    case 3:
		                        cout << "Masukkan jumlah euro: ";
		                        cin >> euro;
		                        cout << "Konversi ke Rupiah: " <<euro*17000 << endl;
		                        cout << "Konversi ke Dollar: " <<euro*1.09 << endl;
		                        cout << "Konversi ke Yen: " <<euro *162 << endl;
		                        break;
		                    case 4:
		                        cout << "Masukkan jumlah Yen: ";
		                        cin >> yen;
		                        cout << "Konversi ke Rupiah: " << yen *104<< endl;
		                        cout << "Konversi ke Dollar: " << yen*0.0067 << endl;
		                        cout << "Konversi ke Euro: " << yen* 0.0061<< endl;
		                        break;
		                    case 5:
		                        cout << "Terima kasih telah menggunakan program konversi mata uang." << endl;
		                        break;
		                    default:
		                        cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar." << endl;
		                }
            }
            
        }

        else{
            cout<<"NAMA ATAU NIM ANDA SALAH\n";
            ulang++;
        }
        
        
    }
    
}





