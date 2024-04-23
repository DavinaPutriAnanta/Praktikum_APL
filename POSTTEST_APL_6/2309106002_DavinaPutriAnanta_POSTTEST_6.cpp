#include <iostream>
#include <string>
using namespace std;

struct Rilis {
    int tanggal;
    int bulan;
    int tahun;
};

const int MAX_JUDUL = 100;
string Genre[MAX_JUDUL];
string Judul[MAX_JUDUL];
Rilis rilis[MAX_JUDUL];
int jumlah_data = 0;

int sequentialSearchGenre(string key) {
    for (int i = 0; i < jumlah_data; i++) {
        if (Genre[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearchJudul(string key) {
    int left = 0;
    int right = jumlah_data - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (Judul[mid] == key) {
            return mid;
        }
        else if (Judul[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; 
}

void menu() {
    cout << "\n============Menu==========\n";
    cout << "1. Menambahkan Judul Webtoon\n";
    cout << "2. Menghapus Judul Webtoon\n";
    cout << "3. Update Judul Webtoon\n";
    cout << "4. Lihat Semua Judul Webtoon\n";
    cout << "0. Shutdown\n";
    cout << "==========================\n";
}

void lihatJudulWebtoon() {
    cout << "-------------------------------\n";
    cout << "--------List Judul Webtoon--------\n";
    cout << "No.  Genre     Judul          Tanggal Rilis\n";
    for (int i = 0; i < jumlah_data; i++) {
        cout << i + 1 << ". " << *&Genre[i] << " - " << *&Judul[i] << "    " << *&rilis[i].tanggal << "/" << *&rilis[i].bulan << "/" << *&rilis[i].tahun << "\n";
    }
    cout << "-------------------------------\n";
}

bool cekNomorValid(int nomor, int jumlah_data) {
    return (nomor >= 1 && nomor <= jumlah_data);
}

int jumlahJudulWebtoon() {
    return jumlah_data;
}

bool login(int attempt = 3) {
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
    else {
        cout << "NAMA ATAU NIM ANDA SALAH\n";
        return login(attempt - 1);
    }
}

void tambahJudulWebtoon() {
    if (jumlah_data < MAX_JUDUL) {
        cout << "Masukkan Genre Webtoon: ";
        cin >> Genre[jumlah_data];
        cout << "Masukkan Judul Webtoon: ";
        cin.ignore();
        getline(cin, Judul[jumlah_data]);
        cout << "Masukkan tanggal rilis webtoon (DD MM YYYY) :";
        cin >> rilis[jumlah_data].tanggal >> rilis[jumlah_data].bulan >> rilis[jumlah_data].tahun;
        jumlah_data++;
    }
    else {
        cout << "Maaf, batas maksimal judul webtoon telah tercapai." << endl;
    }
}

void hapusJudulWebtoon(int nomor_hapus) {
    if (jumlah_data >= 1) {
        if (cekNomorValid(nomor_hapus, jumlah_data)) {
            for (int i = nomor_hapus - 1; i < jumlah_data - 1; i++) {
                Genre[i] = Genre[i + 1];
                Judul[i] = Judul[i + 1];
                rilis[i] = rilis[i + 1];
            }
            jumlah_data--;
        }
        else {
            cout << "Nomor Judul tidak valid!" << endl;
        }
    }
    else {
        cout << "Belum ada Judul Webtoon yang tersedia." << endl;
    }
}

void updateJudulWebtoon(int nomor_update) {
    if (jumlah_data >= 1) {
        if (cekNomorValid(nomor_update, jumlah_data)) {
            cout << "Masukkan Genre Webtoon baru: ";
            cin >> Genre[nomor_update - 1];
            cout << "Masukkan Judul Webtoon baru: ";
            cin.ignore();
            getline(cin, Judul[nomor_update - 1]);
            cout << "Masukkan tanggal rilis webtoon baru: ";
            cin >> rilis[nomor_update - 1].tanggal >> rilis[nomor_update - 1].bulan >> rilis[nomor_update - 1].tahun;
        }
        else {
            cout << "Nomor Judul tidak valid!" << endl;
        }
    }
    else {
        cout << "Belum ada Judul Webtoon yang tersedia." << endl;
    }
}

void lihatSemuaJudulWebtoon() {
    if (jumlah_data >= 1) {
        lihatJudulWebtoon();
    }
    else {
        cout << "Belum ada Judul Webtoon yang tersedia." << endl;
    }
}

void insertionSortDesc(string arr[], string arr_genre[], Rilis arr_rilis[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        string key_genre = arr_genre[i];
        Rilis key_rilis = arr_rilis[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            arr_genre[j + 1] = arr_genre[j];
            arr_rilis[j + 1] = arr_rilis[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        arr_genre[j + 1] = key_genre;
        arr_rilis[j + 1] = key_rilis;
    }
}

void merge(string arr[], string arr_genre[], Rilis arr_rilis[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    string L[n1], R[n2];
    string L_genre[n1], R_genre[n2];
    Rilis L_rilis[n1], R_rilis[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        L_genre[i] = arr_genre[l + i];
        L_rilis[i] = arr_rilis[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        R_genre[j] = arr_genre[m + 1 + j];
        R_rilis[j] = arr_rilis[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            arr_genre[k] = L_genre[i];
            arr_rilis[k] = L_rilis[i];
            i++;
        } else {
            arr[k] = R[j];
            arr_genre[k] = R_genre[j];
            arr_rilis[k] = R_rilis[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        arr_genre[k] = L_genre[i];
        arr_rilis[k] = L_rilis[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        arr_genre[k] = R_genre[j];
        arr_rilis[k] = R_rilis[j];
        j++;
        k++;
    }
}

void mergeSortAsc(string arr[], string arr_genre[], Rilis arr_rilis[], int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSortAsc(arr, arr_genre, arr_rilis, l, m);
    mergeSortAsc(arr, arr_genre, arr_rilis, m + 1, r);
    merge(arr, arr_genre, arr_rilis, l, m, r);
}

void swapData(string& str1, string& str2, int& bulan1, int& bulan2, int& tanggal1, int& tanggal2) {
    swap(str1, str2);
    swap(bulan1, bulan2);
    swap(tanggal1, tanggal2);
}

void bubbleSortAsc(Rilis arr[], string arr_genre[], string arr_judul[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].tahun > arr[j + 1].tahun) {
                swap(arr[j], arr[j + 1]);
                swapData(arr_genre[j], arr_genre[j + 1], arr[j].bulan, arr[j + 1].bulan, arr[j].tanggal, arr[j + 1].tanggal);
                swap(arr_judul[j], arr_judul[j + 1]);
            }
        }
    }
}

void MenuLihat() {
    cout << "\n======Menu Lihat=======\n";
    cout << "1. Sorting Genre\n";
    cout << "2. Sorting Judul\n";
    cout << "3. Sorting Tahun\n";
    cout << "4. Search Genre\n";
    cout << "5. Search Judul\n";
    cout << "0. Kembali\n";
    cout << "==========================\n";
}

int main() {
    if (!login()) {
        cout << "Anda gagal login. Program akan keluar." << endl;
        return 0;
    }

    string pilihanmenu;

    while (true) {
        menu();
        cout << "Pilih Menu: ";
        cin >> pilihanmenu;
        if (pilihanmenu == "1") {
            tambahJudulWebtoon();
        }
        else if (pilihanmenu == "2") {
            int nomor_hapus;
            cout << "Masukkan Nomor Judul yang ingin dihapus: ";
            cin >> nomor_hapus;
            hapusJudulWebtoon(nomor_hapus);
        }
        else if (pilihanmenu == "3") {
            int nomor_update;
            cout << "Masukkan Nomor Judul yang ingin diupdate: ";
            cin >> nomor_update;
            updateJudulWebtoon(nomor_update);
        }
        else if (pilihanmenu == "4") {

            while (true){
                MenuLihat();
                string menuLiat;
                cout << "Masukan Pilihan: ";
                cin >> menuLiat;
                if (menuLiat == "1"){
                    insertionSortDesc(Genre, Judul, rilis, jumlah_data);
                    cout << "Genre telah diurutkan secara descending." << endl;
                    lihatJudulWebtoon();
                    break;
                }
                else if (menuLiat == "2"){
                    mergeSortAsc(Judul, Genre, rilis, 0, jumlah_data - 1);
                    cout << "Judul telah diurutkan secara ascending." << endl;
                    lihatJudulWebtoon();
                    break;
                }
                else if (menuLiat == "3"){
                    bubbleSortAsc(rilis, Genre, Judul, jumlah_data);
                    cout << "Tahun telah diurutkan secara ascending." << endl;
                    lihatJudulWebtoon();
                    break;
                }
                else if (menuLiat == "4"){
                    string keyword;
                    cout << "Masukkan Genre yang ingin dicari: ";
                    cin >> keyword;
                    int index = sequentialSearchGenre(keyword);
                    if (index != -1) {
                        cout << "Judul ditemukan pada index: " << index + 1 << endl;
                        cout << "Genre: " << Genre[index] << ", Judul: " << Judul[index] << ", Tanggal Rilis: " << rilis[index].tanggal << "/" << rilis[index].bulan << "/" << rilis[index].tahun << endl;
                    }
                    else {
                        cout << "Genre tidak ditemukan." << endl;
                    }
                    break;
                }
                else if (menuLiat == "5"){
                    string keyword;
                    cout << "Masukkan Judul yang ingin dicari: ";
                    cin.ignore();
                    getline(cin, keyword);
                    mergeSortAsc(Judul, Genre, rilis, 0, jumlah_data - 1); // Pastikan data sudah terurut
                    int index = binarySearchJudul(keyword);
                    if (index != -1) {
                        cout << "Judul ditemukan pada index: " << index + 1 << endl;
                        cout << "Genre: " << Genre[index] << ", Judul: " << Judul[index] << ", Tanggal Rilis: " << rilis[index].tanggal << "/" << rilis[index].bulan << "/" << rilis[index].tahun << endl;
                    }
                    else {
                        cout << "Judul tidak ditemukan." << endl;
                    }
                    break;
                }
                else if (menuLiat == "0"){
                    break;
                }
                else{
                    cout << "MAAF PILIHAN TIDAK TERSEDIA";
                }
            }
        }
        else if (pilihanmenu == "0") {
            cout << "SHUTDOWN";
            return 0;
        }
        else {
            cout << "Maaf Pilihan tidak Tersedia";
        }
    }
    return 0;
}

