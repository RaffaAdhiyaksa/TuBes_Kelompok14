#include "rumah_sakit.h"
#include <iostream>

using namespace std;

int main() {
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
            string idDokter;
            cout << "Masukkan ID Dokter tujuan: ";
            cin >> idDokter;

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


                adrPasien P = newElmPasien(idPas, namaPas, umur, alamatPas, keluhan);

                ListPasien LP;
                LP.first = D->firstPasien;

                insertPasienLast(LP, P);

                D->firstPasien = LP.first;

                cout << "Pasien berhasil ditambahkan ke Dokter " << D->nama << endl;
            } else {
                cout << "Dokter tidak ditemukan!" << endl;
            }

        } else if (pilihan == 6) {
            string idDokter;
            cout << "Lihat pasien dari Dokter (ID): ";
            cin >> idDokter;

            adrDokter D = cariDokter(L, idDokter);
            if (D != nullptr) {
                cout << "\nPasien yang ditangani dr. " << D->nama << ":" << endl;
                ListPasien LP;
                LP.first = D->firstPasien;

                showSemuaPasien(LP);
            } else {
                cout << "Dokter tidak ditemukan!" << endl;
            }

        } else if (pilihan == 7) {
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
                    deletePasienLast(LP, P); 

                    D->firstPasien = LP.first;
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
