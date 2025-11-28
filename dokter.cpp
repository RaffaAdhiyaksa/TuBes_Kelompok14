#include "dokter.h"

void createListDokter(ListDokter &L) {
    L.first = nullptr;
}

adrDokter newElmDokter(string id, string nama, string spesialis) {
    adrDokter D = new Dokter;
    D->idDokter = id;
    D->nama = nama;
    D->spesialis = spesialis;
    D->next = nullptr;
    D->firstPasien = nullptr;
    return D;
}

void insertDokter(ListDokter &L, adrDokter D) {
    if (L.first == nullptr) {
        L.first = D;
    } else {
        adrDokter temp = L.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = D;
    }
}

void deleteDokter(ListDokter &L, string id) {
    if (L.first == nullptr) {
        return;
    }

    adrDokter P = L.first;
    adrDokter prec = nullptr;
    bool ketemu = false;

    while (P != nullptr && !ketemu) {
        if (P->idDokter == id) {
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
    }
}

adrDokter searchDokter(ListDokter L, string id) {
    adrDokter P = L.first;
    while (P != nullptr) {
        if (P->idDokter == id) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showSemuaDokter(ListDokter L) {
    if (L.first == nullptr) {
        cout << "--- DATA KOSONG ---" << endl;
    } else {
        adrDokter P = L.first;
        int i = 1;
        cout << "\n=== DATA DOKTER ===" << endl;
        while (P != nullptr) {
            cout << i << ". [" << P->idDokter << "] " << P->nama 
                 << " (" << P->spesialis << ")" << endl;
            
            P = P->next;
            i++;
        }
        cout << "===================" << endl;
    }
}


