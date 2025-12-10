#ifndef RUMAHSAKIT_H_INCLUDED
#define RUMAHSAKIT_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

// Forward Declaration
struct Pasien;
struct Dokter;

// Typedef
typedef Pasien* adrPasien;
typedef Dokter* adrDokter;

// --- STRUKTUR DATA PASIEN ---
struct Pasien {
    string idPasien;
    string nama;
    int umur;
    string alamat;
    string keluhan;
    adrPasien next;
};

struct ListPasien {
    adrPasien first;
};

// --- STRUKTUR DATA DOKTER ---
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
adrPasien newElmPasien(string id, string nama, int umur, string alamat, string keluhan);

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
