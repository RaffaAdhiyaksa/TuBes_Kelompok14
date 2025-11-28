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
};

void createListDokter(ListDokter &L);
adrDokter newElmDokter(string id, string nama, string spesialis);
void insertDokter(ListDokter &L, adrDokter D);
void deleteDokter(ListDokter &L, string id);
adrDokter searchDokter(ListDokter L, string id);
void showSemuaDokter(ListDokter L);

#endif


