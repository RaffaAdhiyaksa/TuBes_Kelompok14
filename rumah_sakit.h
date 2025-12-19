#ifndef RUMAHSAKIT_H_INCLUDED
#define RUMAHSAKIT_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

struct Pasien;
struct Dokter;

typedef Pasien* adrPasien;
typedef Dokter* adrDokter;

struct Pasien {
    string idPasien;
    string nama;
    int umur;
    string alamat;
    string keluhan;
    string dokterFavorit; 
    adrPasien next;
};

struct ListPasien {
    adrPasien first;
};

struct Dokter {
    string idDokter;
    string nama;
    string spesialis;
    adrDokter next;
    adrPasien firstPasien;
};

struct ListDokter {
    adrDokter first;
    int count;
    string namaRumahSakit;
    string alamat;
};

// --- PRIMITIF PASIEN ---
void createListPasien(ListPasien &LP);

// Update parameter newElmPasien dengan dokterFavorit
adrPasien newElmPasien(string id, string nama, int umur, string alamat, string keluhan, string dokterFavorit);

void insertPasienFirst(ListPasien &LP, adrPasien P);
void insertPasienLast(ListPasien &LP, adrPasien P);
void insertPasienAfter(adrPasien Prec, adrPasien P);

void deletePasienFirst(ListPasien &LP, adrPasien &P);
void deletePasienLast(ListPasien &LP, adrPasien &P);
void deletePasienAfter(adrPasien Prec, adrPasien &P);

adrPasien searchPasienByID(ListPasien LP, string id);
adrPasien searchPasienByNama(ListPasien LP, string nama);
adrPasien searchPasienByUmur(ListPasien LP, int umur);
adrPasien searchPasienByAlamat(ListPasien LP, string alamat);
adrPasien searchPasienByKeluhan(ListPasien LP, string keluhan);

void showSemuaPasien(ListPasien LP);
void tambahPasienKeDokter(adrDokter D, adrPasien P);
void showPasienDokter(adrDokter D);

// --- FITUR TAMBAHAN (BARU) ---
void hitungDokterFavorit(ListPasien LP);

// --- MENU ---
void menuUtama(int &pilihan);
void menuAdmin(int &pilihan);
void menuDokter(int &pilihan);
void menuPasien(int &pilihan);

// --- PRIMITIF DOKTER ---
void createListDokter(ListDokter &L);
adrDokter newElmDokter(string id, string nama, string spesialis);

void tambahDokter(ListDokter &L);
void insertDokter(ListDokter &L, adrDokter D);
void deleteDokter(ListDokter &L, string id);

adrDokter cariDokter(ListDokter L, string id);
void editDokter(ListDokter L, string id);
adrDokter searchDokter(ListDokter L, string id);
void cariDokterByID(ListDokter L, string id);
adrDokter cariDokterByNama(ListDokter L, string nama);
void showSemuaDokter(ListDokter L);

#endif
