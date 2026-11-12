<div align="center">

# 📒 Buku Kas Pribadi

**Aplikasi pencatat keuangan pribadi berbasis konsol (CLI) menggunakan C++**

Proyek UAS · Teknik Informatika Kelas C · Universitas Tadulako · 2026

![C++](https://img.shields.io/badge/C%2B%2B-Console-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-Apache%202.0-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)

</div>

---

## 📖 Tentang Proyek

**Buku Kas Pribadi** adalah program sederhana untuk mencatat pemasukan dan pengeluaran sehari-hari langsung dari terminal. Setiap transaksi disimpan beserta tanggal, jenis, kategori, keterangan, dan nominalnya. Total pemasukan, total pengeluaran, dan saldo dihitung otomatis serta selalu tampil di menu utama.

Proyek ini dikerjakan oleh **Kelompok 6** sebagai tugas Ujian Akhir Semester (UAS).

## ✨ Fitur

| Fitur | Deskripsi | Status |
|-------|-----------|:------:|
| Tambah Transaksi | Mencatat pemasukan atau pengeluaran baru lengkap dengan kategori | ✅ Selesai |
| Saldo Otomatis | Total pemasukan, total pengeluaran, dan saldo tampil di menu utama | ✅ Selesai |
| Tampilkan Transaksi | Menampilkan seluruh riwayat transaksi beserta ringkasan saldo | ✅ Selesai |
| Ubah Transaksi | Mengedit data transaksi berdasarkan nomor urut | ✅ Selesai |
| Hapus Transaksi | Menghapus transaksi dari catatan berdasarkan nomor urut | ✅ Selesai |
| Ringkasan per Kategori | Rekap pemasukan dan pengeluaran untuk setiap kategori | ✅ Selesai |
| Validasi Input | Menolak pilihan menu, kategori, nomor, dan nominal yang tidak valid | ✅ Selesai |

### 🏷️ Kategori Transaksi

| Jenis | Pilihan Kategori |
|-------|------------------|
| Pemasukan | Gaji, Lainnya |
| Pengeluaran | Makanan, Transportasi, Belanja, Lainnya |

## 🖥️ Tampilan Program

```text
===== BUKU KAS PRIBADI =====
Saldo Pemasukan:  Rp. 0
Saldo Pengeluaran:  Rp. 0
Total: Rp. 0
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
Tanggal       : 06-11-2026
Jenis Transaksi:
1. Pemasukan
2. Pengeluaran
Pilih         : 1
Kategori:
1. Gaji
2. Lainnya
Pilih         : 2
Keterangan    : Kiriman bulanan
Nominal       : Rp 1500000

Transaksi berhasil ditambahkan!
```

Contoh menampilkan transaksi:

```text
=== Tampilan Transaksi ===
1. 06-11-2026 | Pemasukan | Lainnya | Kiriman bulanan | Rp 1500000
2. 07-11-2026 | Pengeluaran | Makanan | Makan siang | Rp 15000
----------------------------
Total Pemasukan   : Rp 1500000
Total Pengeluaran : Rp 15000
Saldo             : Rp 1485000
```

Contoh ringkasan per kategori:

```text
=== RINGKASAN PER KATEGORI ===
Gaji
   Pemasukan   : Rp 0
   Pengeluaran : Rp 0
Makanan
   Pemasukan   : Rp 0
   Pengeluaran : Rp 15000
...
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

- Data transaksi disimpan dalam **array paralel** (`tanggal`, `jenis`, `kategori`, `keterangan`, `nominal`) dengan kapasitas maksimal **100 transaksi** (`MAX`), dan jumlah data aktif dicatat oleh `jumlahTransaksi`.
- Kode `jenis`: `1` untuk **pemasukan** dan `2` untuk **pengeluaran**.
- Kode `kategori` disimpan secara internal: `1` Gaji, `2` Makanan, `3` Transportasi, `4` Belanja, `5` Lainnya. Fungsi `namaKategori()` mengubah kode tersebut menjadi nama kategori.
- Fungsi `hitungPemasukan()`, `hitungPengeluaran()`, dan `hitungSaldo()` menghitung saldo dengan menelusuri seluruh transaksi.
- Fungsi `tambahTransaksi()`, `tampilTransaksi()`, `ubahTransaksi()`, `hapusTransaksi()`, dan `ringkasanKategori()` menangani menu 1 sampai 5.
- Penghapusan dilakukan dengan menggeser data setelah indeks yang dihapus ke satu posisi sebelumnya, lalu `jumlahTransaksi` dikurangi.
- Input divalidasi menggunakan `cin.fail()`, `cin.clear()`, dan `cin.ignore()`; nominal harus lebih dari 0.
- Menu utama berjalan dalam perulangan `do-while` dengan percabangan `switch-case` sampai pengguna memilih `0` (Keluar).

> ⚠️ **Catatan:** Data hanya tersimpan di memori selama program berjalan, sehingga hilang saat program ditutup.

## 🗺️ Rencana Pengembangan

- [x] Menu utama dan perhitungan saldo
- [x] Tambah transaksi
- [x] Tampilkan daftar transaksi
- [x] Ubah transaksi
- [x] Hapus transaksi
- [x] Ringkasan per kategori
- [x] Validasi input
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
