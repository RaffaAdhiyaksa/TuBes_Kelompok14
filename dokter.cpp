#include "dokter.h"

void createListDokter(ListDokter &L) {
    L.first = nullptr;
}

adrDokter newElmDokter(string id, string nama, string spesialis) {
    adrDokter P = new Dokter;
    P->idDokter = id;
    P->nama = nama;
    P->spesialis = spesialis;
    P->next = nullptr;
    P->firstPasien = nullptr;
    return P;
}

void insertDokter(ListDokter &L, adrDokter P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrDokter Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteDokter(ListDokter &L, string x) {
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    adrDokter P = L.first;
    adrDokter prec = nullptr;
    bool ketemu = false;

    while (P != nullptr && !ketemu) {
        if (P->idDokter == x) {
            ketemu = true;
        } else {
            prec = P;
            P = P->next;
        }
    }

    if (ketemu) {
        if (prec == nullptr) { 
            L.first = P->next;
        } else { 
            prec->next = P->next;
        }
        P->next = nullptr;
        delete P;
    } else {
        cout << "Data dokter tidak ditemukan" << endl;
    }
}

adrDokter searchDokter(ListDokter L, string x) {
    adrDokter P = L.first;
    while (P != nullptr) {
        if (P->idDokter == x) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showSemuaDokter(ListDokter L) {
    if (L.first == nullptr) {
        cout << "List Dokter kosong" << endl;
    } else {
        adrDokter P = L.first;
        int i = 1;
        cout << "=== DATA DOKTER ===" << endl;
        while (P != nullptr) {
            cout << i << ". " << P->idDokter << " - " << P->nama 
                 << " (" << P->spesialis << ")" << endl;
            P = P->next;
            i++;
        }
        cout << endl;
    }
}
