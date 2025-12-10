#include "rumah_sakit.h"

void createListPasien(ListPasien &LP) {
    LP.first = nullptr;
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

void insertPasienFirst(ListPasien &LP, adrPasien P) {
    if (LP.first == nullptr){
        LP.first = P;
    }else{
        P->next = LP.first;
        LP.first = P;
    }
}
void insertPasienLast(ListPasien &LP, adrPasien P) {
    adrPasien Q = LP.first;
    if (LP.first == nullptr) {
        LP.first = P;
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
void deletePasienFirst(ListPasien &LP, adrPasien &P) {
    if (LP.first == nullptr) {
        P = nullptr;
    } else {
        P = LP.first;
        LP.first = P->next;
        P->next = nullptr;
    }
}
void deletePasienLast(ListPasien &LP, adrPasien &P) {
    if (LP.first == nullptr) {
        P = nullptr;
    } else if (LP.first->next == nullptr) {
        P = LP.first;
        LP.first = nullptr;
    } else {
        adrPasien Q = LP.first;
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
adrPasien searchPasienByID(ListPasien LP, string id) {
    adrPasien P = LP.first;
    while (P != nullptr) {
        if (P->idPasien == id){
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idPasien << endl;
            cout << "Umur: " << P->umur << endl;
            cout << "Alamat: " << P->alamat << endl;
            cout << "Keluhan: " << P->keluhan << endl;

            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByNama(ListPasien LP, string nama) {
    adrPasien P = LP.first;
    while (P != nullptr) {
        if (P->nama == nama){
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idPasien << endl;
            cout << "Umur: " << P->umur << endl;
            cout << "Alamat: " << P->alamat << endl;
            cout << "Keluhan: " << P->keluhan << endl;
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByUmur(ListPasien LP, int umur) {
    adrPasien P = LP.first;
    while (P != nullptr) {
        if (P->umur == umur){
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idPasien << endl;
            cout << "Umur: " << P->umur << endl;
            cout << "Alamat: " << P->alamat << endl;
            cout << "Keluhan: " << P->keluhan << endl;

           return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByAlamat(ListPasien LP, string alamat) {
    adrPasien P = LP.first;
    while (P != nullptr) {
        if (P->alamat == alamat){
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idPasien << endl;
            cout << "Umur: " << P->umur << endl;
            cout << "Alamat: " << P->alamat << endl;
            cout << "Keluhan: " << P->keluhan << endl;
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPasien searchPasienByKeluhan(ListPasien LP, string keluhan) {
    adrPasien P = LP.first;
    while (P != nullptr) {
        if (P->keluhan == keluhan){
            cout << "Pasien ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idPasien << endl;
            cout << "Umur: " << P->umur << endl;
            cout << "Alamat: " << P->alamat << endl;
            cout << "Keluhan: " << P->keluhan << endl;
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void showSemuaPasien(ListPasien LP) {
    adrPasien P = LP.first;
    if (P == nullptr) {
        cout << "Tidak ada pasien." << endl;
    } else {
        cout << "==========================="<< endl;
        cout << "=======Daftar Pasien=======";
        cout << endl;
        while (P != nullptr) {
            cout << "ID       : " << P->idPasien << endl;
            cout << "Nama     : " << P->nama << endl;
            cout << "Umur     : " << P->umur << endl;
            cout << "Alamat   : " << P->alamat << endl;
            cout << "Keluhan  : " << P->keluhan << endl;
            cout << "==========================" << endl;

            P = P->next;
        }
    }
}
void tambahPasienKeDokter(adrDokter D, adrPasien P) {
    if (D == nullptr || P == nullptr) return;

    // Insert P ke akhir list pasien dokter D
    if (D->firstPasien == nullptr) {
        D->firstPasien = P;
        P->next = nullptr;
    } else {
        adrPasien Q = D->firstPasien;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
        P->next = nullptr;
    }
}
void showPasienDokter(adrDokter D) {
    if (D == nullptr) return;

    cout << "\n===== Daftar Pasien Dokter " << D->nama << " =====\n";

    adrPasien P = D->firstPasien;
    if (P == nullptr) {
        cout << "Tidak ada pasien.\n";
        return;
    }

    while (P != nullptr) {
        cout << "ID      : " << P->idPasien << endl;
        cout << "Nama    : " << P->nama << endl;
        cout << "Umur    : " << P->umur << endl;
        cout << "Alamat  : " << P->alamat << endl;
        cout << "Keluhan : " << P->keluhan << endl;
        cout << "----------------------------------\n";
        P = P->next;
    }
}

