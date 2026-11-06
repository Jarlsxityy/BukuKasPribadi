// Kelompok 6 - Buku Kas Pribadi

#include <iostream>
using namespace std;

const int MAX = 100;
int pilihanMenu;
int jumlahTransaksi = 0;

// Array untuk menyimpan data transaksi
string tanggal[MAX];
int jenis[MAX];
string kategori[MAX];
string keterangan[MAX];
long long nominal[MAX];

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
    if (jumlahTransaksi >= MAX) {
        cout << "Data transaksi sudah penuh!" << endl;
        return;
    }

    cout << "\n=== TAMBAH TRANSAKSI ===" << endl;
    cout << "Tanggal       : "; getline(cin, tanggal[jumlahTransaksi]);
    cout << "Jenis Transaksi:" << endl;
    cout << "1. Pemasukan" << endl;
    cout << "2. Pengeluaran" << endl;
    cout << "Pilih         : "; cin >> jenis[jumlahTransaksi];

    if (jenis[jumlahTransaksi] != 1 &&
        jenis[jumlahTransaksi] != 2) {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }
    
    cin.ignore(1000, '\n');
    cout << "Kategori      : "; getline(cin, kategori[jumlahTransaksi]);
    cout << "Keterangan    : "; getline(cin, keterangan[jumlahTransaksi]);
    cout << "Nominal       : Rp "; cin >> nominal[jumlahTransaksi];
    jumlahTransaksi++;
    cout << "\nTransaksi berhasil ditambahkan!" << endl;
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
    long long penampungPemasukan = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (jenis[i] == 1)
        {
            penampungPemasukan += nominal[i];
        }
    }
    return penampungPemasukan;
}

long long hitungPengeluaran() {
    long long penampunganPengeluaran = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (jenis[i] == 2)
        {
            penampunganPengeluaran += nominal[i];
        }
    }
    return penampunganPengeluaran;
}

long long hitungSaldo() {
    return hitungPemasukan() - hitungPengeluaran();
}

string namaKategori(int nomor) {
    return "";
}

int main() {
    do {
        tampilMenu();
        cin >> pilihanMenu;
        cin.ignore(1000, '\n');

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
