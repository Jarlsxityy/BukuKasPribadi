// Buku kas pribadi - Kelompok 6

#include <iostream>
using namespace std;

const int MAX = 100;
int pilihanMenu;
int jumlahTransaksi = 0;

string tanggal[MAX];
int jenis[MAX];
int kategori[MAX];
string keterangan[MAX];
long long nominal[MAX];

long long hitungPemasukan();
long long hitungPengeluaran();
long long hitungSaldo();

string namaKategori(int nomor);

void tampilMenu() {
    cout << "===== BUKU KAS PRIBADI =====" << endl;
    cout << "Saldo Pemasukan:  Rp. " << hitungPemasukan() << endl;
    cout << "Saldo Pengeluaran:  Rp. " << hitungPengeluaran() << endl;
    cout << "Total: Rp. " << hitungSaldo() << endl;
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

    if (jenis[jumlahTransaksi] == 1) {
        cout << "Kategori:" << endl;
        cout << "1. Gaji" << endl;
        cout << "2. Lainnya" << endl;
        cout << "Pilih         : "; cin >> kategori[jumlahTransaksi];
        if (cin.fail() || kategori[jumlahTransaksi] < 1 || kategori[jumlahTransaksi] > 2) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Pilihan Tidak Valid!" << endl;
            return;
        }
        if (kategori[jumlahTransaksi] == 2) {
            kategori[jumlahTransaksi] = 5;
        }
    } else if (jenis[jumlahTransaksi] == 2) {
        cout << "Kategori:" << endl;
        cout << "1. Makanan" << endl;
        cout << "2. Transportasi" << endl;
        cout << "3. Belanja" << endl;
        cout << "4. Lainnya" << endl;
        cout << "Pilih         : "; cin >> kategori[jumlahTransaksi];
        if (cin.fail() || kategori[jumlahTransaksi] < 1 || kategori[jumlahTransaksi] > 4) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Pilihan Tidak Valid!" << endl;
            return;
        }
        kategori[jumlahTransaksi]++;
    } else {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Harus menginputkan 1 atau 2." << endl;
        return;
    }

    cin.ignore(1000, '\n');
    cout << "Keterangan    : "; getline(cin, keterangan[jumlahTransaksi]);
    cout << "Nominal       : Rp "; cin >> nominal[jumlahTransaksi];
    if (cin.fail() || nominal[jumlahTransaksi] <= 0) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Pilihan Tidak Valid!" << endl;
        return;
    }
    jumlahTransaksi++;
    cout << "\nTransaksi berhasil ditambahkan!" << endl;
}

void tampilTransaksi() {
    cout << "\n=== Tampilan Transaksi ===" << endl;

    if (jumlahTransaksi == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }

    for (int indeksTransaksi = 0; indeksTransaksi < jumlahTransaksi; indeksTransaksi++) {
        cout << indeksTransaksi + 1 << ". " << tanggal[indeksTransaksi] << " | ";
        if (jenis[indeksTransaksi] == 1) {
            cout << "Pemasukan | ";
        } else {
            cout << "Pengeluaran | ";
        }
        cout << namaKategori(kategori[indeksTransaksi]) << " | ";
        cout << keterangan[indeksTransaksi] << " | ";
        cout << "Rp " << nominal[indeksTransaksi] << endl;
    }

    cout << "----------------------------" << endl;
    cout << "Total Pemasukan   : Rp " << hitungPemasukan() << endl;
    cout << "Total Pengeluaran : Rp " << hitungPengeluaran() << endl;
    cout << "Saldo             : Rp " << hitungSaldo() << endl;
}

void ubahTransaksi() {
    if (jumlahTransaksi == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }
    tampilTransaksi();

    int nomor;
    cout << "Nomor yang diubah: ";
    cin >> nomor;
    if (cin.fail() || nomor < 1 || nomor > jumlahTransaksi) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Nomor tidak valid!" << endl;
        return;
    }
    int indeksUbah = nomor - 1;

    string tanggalBaru, keteranganBaru;
    int jenisBaru, kategoriBaru;
    long long nominalBaru;

    cin.ignore(1000, '\n');
    cout << "\n=== UBAH TRANSAKSI ===" << endl;
    cout << "Tanggal       : "; getline(cin, tanggalBaru);
    cout << "Jenis Transaksi:" << endl;
    cout << "1. Pemasukan" << endl;
    cout << "2. Pengeluaran" << endl;
    cout << "Pilih         : "; cin >> jenisBaru;

    if (jenisBaru == 1) {
        cout << "Kategori:" << endl;
        cout << "1. Gaji" << endl;
        cout << "2. Lainnya" << endl;
        cout << "Pilih         : "; cin >> kategoriBaru;
        if (cin.fail() || kategoriBaru < 1 || kategoriBaru > 2) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Pilihan Tidak Valid!" << endl;
            return;
        }
        if (kategoriBaru == 2) {
            kategoriBaru = 5;
        }
    } else if (jenisBaru == 2) {
        cout << "Kategori:" << endl;
        cout << "1. Makanan" << endl;
        cout << "2. Transportasi" << endl;
        cout << "3. Belanja" << endl;
        cout << "4. Lainnya" << endl;
        cout << "Pilih         : "; cin >> kategoriBaru;
        if (cin.fail() || kategoriBaru < 1 || kategoriBaru > 4) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Pilihan Tidak Valid!" << endl;
            return;
        }
        kategoriBaru++;  
    } else {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Harus menginputkan 1 atau 2." << endl;
        return;
    }

    cin.ignore(1000, '\n');
    cout << "Keterangan    : "; getline(cin, keteranganBaru);
    cout << "Nominal       : Rp "; cin >> nominalBaru;
    if (cin.fail() || nominalBaru <= 0) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Pilihan Tidak Valid!" << endl;
        return;
    }

    tanggal[indeksUbah] = tanggalBaru;
    jenis[indeksUbah] = jenisBaru;
    kategori[indeksUbah] = kategoriBaru;
    keterangan[indeksUbah] = keteranganBaru;
    nominal[indeksUbah] = nominalBaru;

    cout << "\nTransaksi berhasil diubah!" << endl;
}

void hapusTransaksi() {
    if (jumlahTransaksi == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }
    tampilTransaksi();
    int nomor;
    cout << "Nomor yang dihapus: ";
    cin >> nomor;
    if (cin.fail() || nomor < 1 || nomor > jumlahTransaksi) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Nomor tidak valid!" << endl;
        return;
    }
    for (int indeksGeser = nomor - 1; indeksGeser < jumlahTransaksi - 1; indeksGeser++) {
        tanggal[indeksGeser] = tanggal[indeksGeser + 1];
        keterangan[indeksGeser] = keterangan[indeksGeser + 1];
        jenis[indeksGeser] = jenis[indeksGeser + 1];
        kategori[indeksGeser] = kategori[indeksGeser + 1];
        nominal[indeksGeser] = nominal[indeksGeser + 1];
    }
    jumlahTransaksi--;

    cout << "Transaksi berhasil dihapus!" << endl;
}

void ringkasanKategori() {
    cout << "\n=== RINGKASAN PER KATEGORI ===" << endl;

    if (jumlahTransaksi == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }

    for (int kodeKategori = 1; kodeKategori <= 5; kodeKategori++) {
        long long masuk = 0;
        long long keluar = 0;
        for (int indeksTransaksi = 0; indeksTransaksi < jumlahTransaksi; indeksTransaksi++) {
            if (kategori[indeksTransaksi] == kodeKategori) {
                if (jenis[indeksTransaksi] == 1) {
                    masuk += nominal[indeksTransaksi];
                } else {
                    keluar += nominal[indeksTransaksi];
                }
            }
        }
        cout << namaKategori(kodeKategori) << endl;
        cout << "   Pemasukan   : Rp " << masuk << endl;
        cout << "   Pengeluaran : Rp " << keluar << endl;
    }
}

long long hitungPemasukan() {
    long long penampungPemasukan = 0;
    for (int indeksTransaksi = 0; indeksTransaksi < jumlahTransaksi; indeksTransaksi++) {
        if (jenis[indeksTransaksi] == 1)
        {
            penampungPemasukan += nominal[indeksTransaksi];
        }
    }
    return penampungPemasukan;
}

long long hitungPengeluaran() {
    long long penampunganPengeluaran = 0;
    for (int indeksTransaksi = 0; indeksTransaksi < jumlahTransaksi; indeksTransaksi++) {
        if (jenis[indeksTransaksi] == 2)
        {
            penampunganPengeluaran += nominal[indeksTransaksi];
        }
    }
    return penampunganPengeluaran;
}

long long hitungSaldo() {
    return hitungPemasukan() - hitungPengeluaran();
}

string namaKategori(int nomor) {
    if (nomor == 1) return "Gaji";
    if (nomor == 2) return "Makanan";
    if (nomor == 3) return "Transportasi";
    if (nomor == 4) return "Belanja";
    if (nomor == 5) return "Lainnya";
    return "";
}

int main() {
    do {
        tampilMenu();
        cin >> pilihanMenu;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihanMenu = -1;
            cout << "Pilihan Tidak Valid!" << endl;
            continue;
        }

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
