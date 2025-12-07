#include "rumah_sakit.h"

void createListPasien(ListPasien &L) {
    L.first = nullptr;
}

adrPasien newElmPasien(string id, string nama, int umur, string alamat, string keluhan) {
    adrPasien P = new Pasien;
    P->idPasien = id;
    P->nama = nama;
    P->umur = umur;
    P->alamat = alamat;
    P->keluhan = keluhan;
    P->next = nullptr;
    return P;
}

void insertPasienFirst(ListPasien &L, adrPasien P) {
    if (L.first == nullptr){
        L.first = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}
void insertPasienLast(ListPasien &L, adrPasien P) {
    adrPasien Q = L.first;
    if (L.first == nullptr) {
        L.first = P;
    } else {
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertPasienAfter(adrPasien Prec, adrPasien P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}
void deletePasienFirst(ListPasien &L, adrPasien &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}
void deletePasienLast(ListPasien &L, adrPasien &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        adrPasien Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}
void deletePasienAfter(adrPasien Prec, adrPasien &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}
adrPasien searchPasienByID(ListPasien L, string id) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->idPasien == id){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByNama(ListPasien L, string nama) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->nama == nama){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByUmur(ListPasien L, int umur) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->umur == umur){
           return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByAlamat(ListPasien L, string alamat) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->alamat == alamat){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByKeluhan(ListPasien L, string keluhan) {
    adrPasien P = L.first;
    while (P != nullptr) {
        if (P->keluhan == keluhan){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void showSemuaPasien(ListPasien L) {
    adrPasien P = L.first;
    if (P == nullptr) {
        cout << "Tidak ada pasien." << endl;
    } else {
        while (P != nullptr) {
            cout << "ID       : " << P->idPasien << endl;
            cout << "Nama     : " << P->nama << endl;
            cout << "Umur     : " << P->umur << endl;
            cout << "Alamat   : " << P->alamat << endl;
            cout << "Keluhan  : " << P->keluhan << endl;
            cout << "-----------------------------" << endl;
            P = P->next;
        }
    }
}
