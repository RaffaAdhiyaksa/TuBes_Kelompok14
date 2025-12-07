#ifndef RUMAH_SAKIT_H
#define RUMAH_SAKIT_H

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
void createListPasien(ListPasien &L);
adrPasien newElmPasien(string id, string nama, int umur, string alamat, string keluhan);

void insertPasienFirst(ListPasien &L, adrPasien P);
void insertPasienLast(ListPasien &L, adrPasien P);
void insertPasienAfter(adrPasien Prec, adrPasien P);

void deletePasienFirst(ListPasien &L, adrPasien &P);
void deletePasienLast(ListPasien &L, adrPasien &P);
void deletePasienAfter(adrPasien Prec, adrPasien &P);

adrPasien searchPasienByID(ListPasien L, string id);
adrPasien searchPasienByNama(ListPasien L, string nama);
adrPasien searchPasienByUmur(ListPasien L, int umur);
adrPasien searchPasienByAlamat(ListPasien L, string alamat);
adrPasien searchPasienByKeluhan(ListPasien L, string keluhan);

void showSemuaPasien(ListPasien L);

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
void cariDokterByNama(ListDokter L, string &nama);
void showSemuaDokter(ListDokter L);

#endif
