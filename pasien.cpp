#include "rumah_sakit.h"

void createListPasien(ListPasien &LP) {
    LP.first = nullptr;
}

adrPasien newElmPasien(string id, string nama, int umur, string alamat, string keluhan, string dokterFavorit) {
    adrPasien P = new Pasien;
    P->idPasien = id;
    P->nama = nama;
    P->umur = umur;
    P->alamat = alamat;
    P->keluhan = keluhan;
    P->dokterFavorit = dokterFavorit;
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
            cout << "ID             : " << P->idPasien << endl;
            cout << "Nama           : " << P->nama << endl;
            cout << "Umur           : " << P->umur << endl;
            cout << "Alamat         : " << P->alamat << endl;
            cout << "Keluhan        : " << P->keluhan << endl;
            cout << "Dokter Favorit : " << P->dokterFavorit << endl;
            cout << "==========================" << endl;

            P = P->next;
        }
    }
}

// PERBAIKAN LOGIKA: Membuat salinan (copy) agar List Utama tidak putus
void tambahPasienKeDokter(adrDokter D, adrPasien P) {
    if (D == nullptr || P == nullptr) return;

    // Kita buat Node BARU yang datanya sama dengan P.
    // Ini penting supaya pointer 'next' di List Utama (LP) tidak terganggu.
    adrPasien P_Baru = newElmPasien(P->idPasien, P->nama, P->umur, P->alamat, P->keluhan, P->dokterFavorit);

    // Insert P_Baru ke akhir list pasien milik DOKTER
    if (D->firstPasien == nullptr) {
        D->firstPasien = P_Baru;
    } else {
        adrPasien Q = D->firstPasien;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P_Baru;
    }
}

// PERBAIKAN SYNTAX: Menggunakan D->firstPasien, bukan LP.first
void showPasienDokter(adrDokter D) {
    if (D == nullptr) return; // Cek safety

    cout << "\n===== Daftar Pasien Dokter " << D->nama << " =====\n";

    // AMBIL DARI LIST DOKTER, BUKAN LP
    adrPasien P = D->firstPasien;

    if (P == nullptr) {
        cout << "Tidak ada pasien.\n";
    } else {
        while (P != nullptr) {
            cout << "ID             : " << P->idPasien << endl;
            cout << "Nama           : " << P->nama << endl;
            cout << "Umur           : " << P->umur << endl;
            cout << "Alamat         : " << P->alamat << endl;
            cout << "Keluhan        : " << P->keluhan << endl;
            cout << "Dokter Favorit : " << P->dokterFavorit << endl;
            cout << "----------------------------------\n";

            P = P->next;
        }
    }
}

// --- FUNGSI BARU: MENGHITUNG DOKTER FAVORIT SECARA OTOMATIS ---
void hitungDokterFavorit(ListPasien LP) {
    if (LP.first == nullptr) {
        cout << "Belum ada data pasien untuk dianalisis." << endl;
        return;
    }

    string namaTerfavorit = "-";
    int jumlahTerbanyak = 0;

    // Loop Utama: Cek setiap pasien di dalam list
    adrPasien P = LP.first;
    while (P != nullptr) {
        string dokterSaatIni = P->dokterFavorit;
        int hitung = 0;

        // Loop Dalam: Hitung berapa kali 'dokterSaatIni' muncul di seluruh list
        adrPasien Q = LP.first;
        while (Q != nullptr) {
            if (Q->dokterFavorit == dokterSaatIni) {
                hitung++;
            }
            Q = Q->next;
        }

        // Cek apakah ini rekor baru?
        if (hitung > jumlahTerbanyak) {
            jumlahTerbanyak = hitung;
            namaTerfavorit = dokterSaatIni;
        }

        P = P->next;
    }

    cout << "\n=== STATISTIK DOKTER FAVORIT ===" << endl;
    cout << "Dokter Paling Diminati : " << namaTerfavorit << endl;
    cout << "Jumlah Pemilih         : " << jumlahTerbanyak << " Pasien" << endl;
    cout << "================================" << endl;
}

void menuUtama(int &pilihan) {
    cout << "\n============ MENU RUMAH SAKIT ============\n";
    cout << "1. Admin\n";
    cout << "2. Dokter\n";
    cout << "3. Pasien\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
    cin >> pilihan;
}
void menuAdmin(int &pilihan) {
    cout << "\n============= MENU ADMIN =============\n";
    cout << "1. Tambah Dokter\n";
    cout << "2. Tambah Pasien\n";
    cout << "3. Hapus Pasien\n";
    cout << "4. Hapus Dokter\n";
    cout << "5. Cari Dokter\n";
    cout << "6. Cari Pasien\n";
    cout << "7. Show Semua Dokter\n";
    cout << "8. Show Semua Pasien\n";
    cout << "9. Tambah Pasien ke Dokter\n";
    cout << "10. LIHAT DOKTER PALING FAVORIT\n"; // Menu Baru
    cout << "0. Kembali\n";
    cout << "Pilih: ";
    cin >> pilihan;
}
void menuDokter(int &pilihan) {
    cout << "\n============= MENU DOKTER =============\n";
    cout << "1. Show Pasien Dokter\n";
    cout << "2. Show Semua Dokter\n";
    cout << "3. Cari Dokter\n";
    cout << "4. Hapus Dokter\n";
    cout << "5. Hapus Pasien Dari dokter\n";
    cout << "6. Menambahkan Pasien ke Dokter\n";
    cout << "0. Kembali\n";
    cout << "Pilih: ";
    cin >> pilihan;
}
void menuPasien(int &pilihan) {
    cout << "\n============= MENU PASIEN =============\n";
    cout << "1. Daftar Pasien\n";
    cout << "2. Show Dokter\n";
    cout << "0. Kembali\n";
    cout << "Pilih: ";
    cin >> pilihan;
}
