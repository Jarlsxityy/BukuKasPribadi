<div align="center">

# 📒 Buku Kas Pribadi

**Aplikasi pencatat keuangan pribadi berbasis konsol (CLI) menggunakan C++**

Proyek UAS · Teknik Informatika Kelas C · Universitas Tadulako · 2026

![C++](https://img.shields.io/badge/C%2B%2B-Console-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-Apache%202.0-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-In%20Development-orange?style=for-the-badge)

</div>

---

## 📖 Tentang Proyek

**Buku Kas Pribadi** adalah program sederhana untuk mencatat pemasukan dan pengeluaran sehari-hari langsung dari terminal. Setiap transaksi disimpan beserta tanggal, jenis, kategori, keterangan, dan nominalnya, sedangkan saldo dihitung otomatis dan selalu tampil di menu utama.

Proyek ini dikerjakan oleh **Kelompok 6** sebagai tugas Ujian Akhir Semester (UAS).

## ✨ Fitur

| Fitur | Deskripsi | Status |
|-------|-----------|:------:|
| Tambah Transaksi | Mencatat pemasukan atau pengeluaran baru | ✅ Selesai |
| Saldo Otomatis | Total pemasukan dikurangi total pengeluaran, tampil di menu | ✅ Selesai |
| Tampilkan Transaksi | Menampilkan seluruh riwayat transaksi | 🚧 Dalam pengerjaan |
| Ubah Transaksi | Mengedit data transaksi yang sudah dicatat | 🚧 Dalam pengerjaan |
| Hapus Transaksi | Menghapus transaksi dari catatan | 🚧 Dalam pengerjaan |
| Ringkasan per Kategori | Rekap transaksi berdasarkan kategori | 🚧 Dalam pengerjaan |

## 🖥️ Tampilan Program

```text
===== BUKU KAS PRIBADI =====
Saldo: Rp. 0
----------------------------
1. Tambah Transaksi
2. Tampilkan Transaksi
3. Ubah Transaksi
4. Hapus Transaksi
5. Ringkasan per Kategori
0. Keluar
Pilih:
```

Contoh menambah transaksi:

```text
=== TAMBAH TRANSAKSI ===
Tanggal : 06-11-2026
Jenis Transaksi:
1. Pemasukan
2. Pengeluaran
Pilih : 1
Kategori : Uang Saku
Keterangan : Kiriman bulanan
Nominal : Rp 1500000

Transaksi berhasil ditambahkan!
```

## 🚀 Cara Menjalankan

### Prasyarat

- Compiler C++ (misalnya **g++**/MinGW) atau IDE seperti Code::Blocks, Dev-C++, atau Visual Studio Code

### Langkah-langkah

```bash
# 1. Clone repository
git clone https://github.com/Jarlsxityy/BukuKasPribadi.git

# 2. Masuk ke folder proyek
cd BukuKasPribadi

# 3. Kompilasi
g++ uas.cpp -o bukukas

# 4. Jalankan
./bukukas        # Linux / macOS
bukukas.exe      # Windows
```

## 🧱 Struktur Proyek

```text
BukuKasPribadi/
├── uas.cpp      # Kode sumber utama
├── LICENSE      # Lisensi Apache 2.0
└── README.md    # Dokumentasi proyek
```

## ⚙️ Cara Kerja Singkat

- Data transaksi disimpan dalam **array paralel** (`tanggal`, `jenis`, `kategori`, `keterangan`, `nominal`) dengan kapasitas maksimal **100 transaksi**.
- Kode `jenis`: `1` untuk **pemasukan** dan `2` untuk **pengeluaran**.
- Fungsi `hitungPemasukan()`, `hitungPengeluaran()`, dan `hitungSaldo()` menghitung saldo dengan menelusuri seluruh transaksi.
- Menu utama berjalan dalam perulangan `do-while` dengan percabangan `switch-case` sampai pengguna memilih `0` (Keluar).

> ⚠️ **Catatan:** Data hanya tersimpan di memori selama program berjalan, sehingga hilang saat program ditutup.

## 🗺️ Rencana Pengembangan

- [x] Menu utama dan perhitungan saldo
- [x] Tambah transaksi
- [ ] Tampilkan daftar transaksi
- [ ] Ubah transaksi
- [ ] Hapus transaksi
- [ ] Ringkasan per kategori
- [ ] Penyimpanan data ke file agar tidak hilang saat program ditutup

## 👥 Tim Pengembang

**Kelompok 6** · Teknik Informatika, Kelas C, Universitas Tadulako

<!-- Tambahkan nama anggota kelompok di sini, contoh:
| Nama | NIM | Peran |
|------|-----|-------|
| Nama Anggota | F55xxxxxx | Pengembang |
-->

## 📄 Lisensi

Proyek ini dirilis di bawah lisensi **Apache License 2.0**. Lihat berkas [LICENSE](LICENSE) untuk detail lengkapnya.

---

<div align="center">

Dibuat dengan ☕ dan C++ · Universitas Tadulako 2026

</div>
