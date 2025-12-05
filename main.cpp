#include "dokter.h"
#include "pasien.h" // Wajib di-include agar fungsi pasien bisa dipakai
#include <iostream>

using namespace std;

int main() {
    // Buat List Utama (List Dokter)
    ListDokter L;
    createListDokter(L);

    int pilihan = 0;

    while (true) {
        cout << "\n========== MENU RUMAH SAKIT ==========" << endl;
        cout << "1. Tambah Dokter Baru" << endl;
        cout << "2. Tampilkan Semua Dokter" << endl;
        cout << "3. Cari Dokter (ID)" << endl;
        cout << "4. Hapus Dokter" << endl;
        cout << "--------------------------------------" << endl;
        cout << "5. Tambah Pasien ke Dokter (Insert Child)" << endl;
        cout << "6. Tampilkan Pasien milik Dokter (View Child)" << endl;
        cout << "7. Hapus Pasien dari Dokter (Delete Child)" << endl;
        cout << "--------------------------------------" << endl;
        cout << "0. Keluar" << endl;
        cout << "======================================" << endl;
        cout << "Pilih opsi : ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Panggil fungsi dari dokter.cpp
            tambahDokter(L);

        } else if (pilihan == 2) {
            showSemuaDokter(L);

        } else if (pilihan == 3) {
            string id;
            cout << "Masukkan ID Dokter yang dicari: ";
            cin >> id;
            cariDokterByID(L, id);

        } else if (pilihan == 4) {
            string id;
            cout << "Masukkan ID Dokter yang akan dihapus: ";
            cin >> id;
            deleteDokter(L, id);

        } else if (pilihan == 5) {
            // === LOGIKA TAMBAH PASIEN (CHILD) ===
            string idDokter;
            cout << "Masukkan ID Dokter tujuan: ";
            cin >> idDokter;

            // Cari dulu dokternya ada atau tidak
            adrDokter D = cariDokter(L, idDokter);
            if (D != nullptr) {
                cout << "-- Data Pasien --" << endl;
                string idPas, namaPas, alamatPas, keluhan;
                int umur;

                cout << "ID Pasien   : "; cin >> idPas;
                cout << "Nama Pasien : "; cin >> namaPas;
                cout << "Umur        : "; cin >> umur;
                cout << "Alamat      : "; cin >> alamatPas;
                cout << "Keluhan     : "; cin >> keluhan;

                // 1. Buat elemen pasien baru
                adrPasien P = newElmPasien(idPas, namaPas, umur, alamatPas, keluhan);

                // 2. BUNGKUS pointer firstPasien milik dokter ke dalam ListPasien sementara
                //    Ini trik agar kita bisa pakai fungsi insertPasienLast dari pasien.cpp
                ListPasien LP;
                LP.first = D->firstPasien;

                // 3. Masukkan pasien
                insertPasienLast(LP, P);

                // 4. Update kembali pointer milik dokter
                D->firstPasien = LP.first;

                cout << "Pasien berhasil ditambahkan ke Dokter " << D->nama << endl;
            } else {
                cout << "Dokter tidak ditemukan!" << endl;
            }

        } else if (pilihan == 6) {
            // === LOGIKA TAMPILKAN PASIEN (CHILD) ===
            string idDokter;
            cout << "Lihat pasien dari Dokter (ID): ";
            cin >> idDokter;

            adrDokter D = cariDokter(L, idDokter);
            if (D != nullptr) {
                cout << "\nPasien yang ditangani dr. " << D->nama << ":" << endl;

                // Bungkus lagi ke ListPasien sementara
                ListPasien LP;
                LP.first = D->firstPasien;

                // Panggil fungsi show dari pasien.cpp
                showSemuaPasien(LP);
            } else {
                cout << "Dokter tidak ditemukan!" << endl;
            }

        } else if (pilihan == 7) {
            // === LOGIKA HAPUS PASIEN (CHILD) ===
            // Karena fungsi delete di pasien.cpp butuh pointer presisi,
            // di sini kita pakai cara sederhana hapus Last atau First saja sebagai contoh,
            // atau modifikasi sedikit jika ingin hapus by ID.
            // Untuk kesederhanaan sesuai request, kita pakai deletePasienLast (hapus antrian terakhir).

            string idDokter;
            cout << "Hapus pasien terakhir dari Dokter (ID): ";
            cin >> idDokter;

            adrDokter D = cariDokter(L, idDokter);
            if (D != nullptr) {
                if (D->firstPasien == nullptr) {
                    cout << "Belum ada pasien." << endl;
                } else {
                    ListPasien LP;
                    LP.first = D->firstPasien;

                    adrPasien P;
                    deletePasienLast(LP, P); // Hapus pasien paling belakang

                    D->firstPasien = LP.first; // Update pointer dokter
                    cout << "Data pasien antrian terakhir berhasil dihapus." << endl;
                }
            } else {
                cout << "Dokter tidak ditemukan!" << endl;
            }

        } else if (pilihan == 0) {
            cout << "Keluar program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
