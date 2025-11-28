#ifndef PASIEN_H
#define PASIEN_H

#include <iostream>
#include <string>

using namespace std;

typedef struct Pasien* adrPasien;

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

#endif
