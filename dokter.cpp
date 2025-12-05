#include "dokter.h"
#include <iostream>

using namespace std;

void createListDokter(ListDokter &L) {
    L.first = nullptr;
    L.count = 0;
    L.namaRumahSakit = "";
    L.alamat = "";
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

void tambahDokter(ListDokter &L) {
    adrDokter newDokter = new Dokter;
    cout << "Masukkan Nama Dokter: ";
    cin >> newDokter->nama;
    cout << "Masukkan ID Dokter: ";
    cin >> newDokter->idDokter;
    cout << "Masukkan Spesialis: ";
    cin >> newDokter->spesialis;
    
    newDokter->next = nullptr;
    newDokter->firstPasien = nullptr;
    
    insertDokter(L, newDokter);
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
    L.count++;
}

adrDokter cariDokter(ListDokter L, string id) {
    adrDokter P = L.first;
    while (P != nullptr) {
        if (P->idDokter == id) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void editDokter(ListDokter L, string id) {
    adrDokter dokter = cariDokter(L, id);
    if (dokter) {
        cout << "Edit Nama Dokter: ";
        cin >> dokter->nama;
        cout << "Edit Spesialis: ";
        cin >> dokter->spesialis;
        cout << "Dokter berhasil diperbarui!" << endl;
    } else {
        cout << "Dokter tidak ditemukan!" << endl;
    }
}

void deleteDokter(ListDokter &L, string id) {
    if (L.first == nullptr) {
        cout << "Dokter tidak ditemukan!" << endl;
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
        L.count--;
        cout << "Dokter berhasil dihapus!" << endl;
    } else {
        cout << "Dokter tidak ditemukan!" << endl;
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

void cariDokterByID(ListDokter L, string id) {
    adrDokter P = L.first;
    while (P != nullptr) {
        if (P->idDokter == id) {
            cout << "Dokter ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idDokter << endl;
            cout << "Spesialis: " << P->spesialis << endl;
            return;
        }
        P = P->next;
    }
    cout << "Dokter dengan ID " << id << " tidak ditemukan!" << endl;
}

void cariDokterByNama(ListDokter L, string &nama) {
    adrDokter P = L.first;
    bool found = false;
    while (P != nullptr) {
        if (P->nama == nama) {
            cout << "Dokter ditemukan!" << endl;
            cout << "Nama: " << P->nama << endl;
            cout << "ID: " << P->idDokter << endl;
            cout << "Spesialis: " << P->spesialis << endl;
            found = true;
        }
        P = P->next;
    }
    if (!found) {
        cout << "Dokter dengan nama " << nama << " tidak ditemukan!" << endl;
    }
}

void showSemuaDokter(ListDokter L) {
    adrDokter P = L.first;
    cout << "Daftar Dokter:" << endl;
    cout << "Nama                ID          Spesialis" << endl;
    cout << "-----------------------------------------------------" << endl;

    while (P != nullptr) {
        cout << P->nama;
        cout << string(20 - P->nama.length(), ' ');

        cout << P->idDokter;
        cout << string(12 - P->idDokter.length(), ' ');

        cout << P->spesialis << endl;
        P = P->next;
    }
    cout << endl;
}
