#ifndef DOKTER_H
#define DOKTER_H

#include <iostream>
#include <string>

using namespace std;

struct Pasien;

typedef struct Dokter* adrDokter;
typedef struct Pasien* adrPasien;

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
