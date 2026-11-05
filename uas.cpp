// Kelompok 6 - Buku Kas Pribadi

#include <iostream>
using namespace std;

const int MAX = 100;
int pilihanMenu;

void tampilMenu();
void tambahTransaksi();
void tampilTransaksi();
void ubahTransaksi();
void hapusTransaksi();
void ringkasanKategori();

long long hitungPemasukan();
long long hitungPengeluaran();
long long hitungSaldo();

string namaKategori(int nomor);

void tampilMenu() {
    cout << "===== BUKU KAS PRIBADI =====" << endl;
    cout << "Saldo: Rp. " << hitungSaldo() << endl;
    cout << "----------------------------" << endl;
    cout << "1. Tambah Transaksi" << endl;
    cout << "2. Tampilkan Transaksi" << endl;
    cout << "3. Ubah Transaksi" << endl;
    cout << "4. Hapus Transaksi" << endl;
    cout << "5. Ringkasan per Kategori" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
}

void tambahTransaksi() {
}

void tampilTransaksi() {
}

void ubahTransaksi() {
}

void hapusTransaksi() {
}

void ringkasanKategori() {
}

long long hitungPemasukan() {
    return 0;
}

long long hitungPengeluaran() {
    return 0;
}

long long hitungSaldo() {
    return 0;
}

string namaKategori(int nomor) {
    return "";
}

int main() {
    do {
        tampilMenu();
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                tambahTransaksi();
                break;

            case 2:
                tampilTransaksi();
                break;

            case 3:
                ubahTransaksi();
                break;

            case 4:
                hapusTransaksi();
                break;

            case 5:
                ringkasanKategori();
                break;

            case 0:
                cout << "Terima Kasih!" << endl;
                break;

            default:
                cout << "Pilihan Tidak Valid!" << endl;
                break;
        }

    } while (pilihanMenu != 0);

    return 0;
}
