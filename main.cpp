#include "rumah_sakit.h"
#include <iostream>

using namespace std;

int main() {
    // Buat List Utama (List Dokter)
    ListDokter L;
    createListDokter(L);

    // Buat List Pasien
    ListPasien LP;
    createListPasien(LP);

    int menu = -1;
    // Menu login Pengguna (Admin, Dokter, Pasien)
    while (menu != 0) {
        menuUtama(menu);

        // ==================== ADMIN ====================
        if (menu == 1) {
            int pilihAdmin = -1;
            while (pilihAdmin != 0) {
                menuAdmin(pilihAdmin);

                if (pilihAdmin == 1) {
                    tambahDokter(L);
                    cout << "\nDokter berhasil Ditambahkan!";
                } else if (pilihAdmin == 2) {
                    int umur;
                    string idPasien, nama, keluhan, alamat, favDokter;

                    cout << endl;
                    cout << "Data Pasien" << endl;
                    cout << "Masukan ID Pasien   : "; cin >> idPasien;
                    cout << "Masukan Nama Pasien : "; cin >> nama;
                    cout << "Masukan Umur        : "; cin >> umur;
                    cout << "Masukan Alamat      : "; cin >> alamat;
                    cout << "Keluhan Pasien      : "; cin >> keluhan;
                    cout << "Dokter Favorit      : "; cin >> favDokter; // Input Dokter Favorit
                    cout << endl;

                    // Masukkan favDokter ke parameter terakhir
                    adrPasien P = newElmPasien(idPasien, nama, umur, alamat, keluhan, favDokter);

                    insertPasienLast(LP, P);
                    cout << "Pasien Berhasil Ditambahkan!" << endl;

                } else if (pilihAdmin == 3) {
                    int hapus = 0;
                    string id, nama;
                    cout << "=========================" << endl;
                    cout << "1. Hapus berdasarkan ID" << endl;
                    cout << "2. Hapus berdasarkan Nama" << endl;
                    cout << "=========================" << endl;
                    cout << "Pilih opsi: ";
                    cin >> hapus;

                    adrPasien target, prec, P;
                    if (hapus == 1) {
                        cout << "Masukan ID pasien :";
                        cin >> id;
                        target = searchPasienByID(LP, id);
                        if (target == nullptr) {
                            cout << "Pasien dengan ID tersebut tidak ditemukan!" << endl;
                        } else {
                            if (target == LP.first) {
                                deletePasienFirst(LP, P);
                            } else if (target->next == nullptr) {
                                deletePasienLast(LP, P);
                            } else {
                                prec = LP.first;
                                while (prec->next != target) {
                                    prec = prec->next;
                                }
                                deletePasienAfter(prec, P);
                            }
                            cout << "Pasien berhasil dihapus!" << endl;
                        }
                    } else if (hapus == 2) {
                        cout << "Masukan nama pasien: ";
                        cin >> nama;

                        target = searchPasienByNama(LP, nama);
                        if (target == nullptr) {
                            cout << "Pasien dengan nama tersebut tidak ditemukan!" << endl;
                        } else {
                            if (target == LP.first) {
                                deletePasienFirst(LP, P);
                            } else if (target->next == nullptr) {
                                deletePasienLast(LP, P);
                            } else {
                                prec = LP.first;
                                while (prec->next != target) {
                                    prec = prec->next;
                                }
                                deletePasienAfter(prec, P);
                            }
                            cout << "Pasien berhasil dihapus!" << endl;
                        }
                    }
                } else if (pilihAdmin == 4) {
                    string Id;
                    cout << "Masukan ID dokter: ";
                    cin >> Id;
                    deleteDokter(L, Id);
                } else if (pilihAdmin == 5) {
                    string Id;
                    cout << "Masukan ID dokter: ";
                    cin >> Id;
                    cariDokterByID(L, Id);
                } else if (pilihAdmin == 6) {
                    string idPas, namaPas, keluhanPas, alamatPas;
                    int searchPas, umurPas;
                    cout << "=========================" << endl;
                    cout << "1. Cari pasien berdasarkan ID" << endl;
                    cout << "2. Cari pasien berdasarkan NAMA" << endl;
                    cout << "3. Cari pasien berdasarkan UMUR" << endl;
                    cout << "4. Cari pasien berdasarkan KELUHAN" << endl;
                    cout << "5. Cari pasien berdasarkan ALAMAT" << endl;
                    cout << "=========================" << endl;
                    cout << "Pilih opsi: ";
                    cin >> searchPas;
                    if (searchPas == 1) {
                        cout << "Masukan ID Pasien: "; cin >> idPas;
                        if (LP.first == nullptr) cout << "Data Kosong!" << endl;
                        else searchPasienByID(LP, idPas);
                    } else if (searchPas == 2) {
                        cout << "Masukan NAMA Pasien: "; cin >> namaPas;
                        if (LP.first == nullptr) cout << "Data Kosong!" << endl;
                        else searchPasienByNama(LP, namaPas);
                    } else if (searchPas == 3) {
                        cout << "Masukan UMUR Pasien: "; cin >> umurPas;
                        if (LP.first == nullptr) cout << "Data Kosong!" << endl;
                        else searchPasienByUmur(LP, umurPas);
                    } else if (searchPas == 4) {
                        cout << "Masukan Keluhan Pasien: "; cin >> keluhanPas;
                        if (LP.first == nullptr) cout << "Data Kosong!" << endl;
                        else searchPasienByKeluhan(LP, keluhanPas);
                    } else if (searchPas == 5) {
                        cout << "Masukan Alamat Pasien: "; cin >> alamatPas;
                        if (LP.first == nullptr) cout << "Data Kosong!" << endl;
                        else searchPasienByAlamat(LP, alamatPas);
                    }
                } else if (pilihAdmin == 7) {
                    cout << endl;
                    if (L.first == nullptr) {
                        cout << "Maaf Dokter saat ini sedang kosong." << endl;
                    } else {
                        showSemuaDokter(L);
                    }
                } else if (pilihAdmin == 8) {
                    cout << endl;
                    if (LP.first == nullptr) {
                        cout << "Maaf belum ada pasien terdaftar!" << endl;
                    } else {
                        showSemuaPasien(LP);
                    }
                } else if (pilihAdmin == 9) {
                    string namaPas, namaDok;
                    cout << "Masukan nama pasien: ";
                    cin >> namaPas;

                    adrPasien Ppas = searchPasienByNama(LP, namaPas);

                    if (Ppas == nullptr) {
                        cout << "Pasien dengan nama tersebut tidak ditemukan!" << endl;
                    } else {
                        cout << "Masukan nama dokter: ";
                        cin >> namaDok;

                        adrDokter Pdok = cariDokterByNama(L, namaDok);

                        if (Pdok == nullptr) {
                            cout << "Dokter dengan nama tersebut tidak ditemukan!" << endl;
                        } else {
                            tambahPasienKeDokter(Pdok, Ppas);
                            cout << "\nPasien berhasil di tambahkan ke dokter!";
                            showPasienDokter(Pdok);
                        }
                    }
                } else if (pilihAdmin == 10) {
                    // --- FITUR BARU: HITUNG DOKTER FAVORIT ---
                    cout << endl;
                    hitungDokterFavorit(LP);
                }
            }

        // ==================== DOKTER ====================
        } else if (menu == 2) {
            int pilihDokter = -1;
            while (pilihDokter != 0) {
                menuDokter(pilihDokter);

                if (pilihDokter == 1) {
                    string idDokter;
                    cout << "Lihat pasien dari Dokter (ID): ";
                    cin >> idDokter;

                    adrDokter D = cariDokter(L, idDokter);
                    if (D != nullptr) {
                        cout << "\nPasien yang ditangani dr. " << D->nama << ":" << endl;
                        // Bungkus lagi ke ListPasien sementara untuk show
                        ListPasien LP_Temp;
                        LP_Temp.first = D->firstPasien;
                        showSemuaPasien(LP_Temp);
                    } else {
                        cout << "Dokter tidak ditemukan!" << endl;
                    }

                } else if (pilihDokter == 2) {
                    cout << endl;
                    if (L.first == nullptr) {
                        cout << "Maaf dokter sedang sibuk/kosong!" << endl;
                    } else {
                        showSemuaDokter(L);
                    }
                } else if (pilihDokter == 3) {
                    string id;
                    cout << "Masukkan ID dokter yang dicari: ";
                    cin >> id;
                    cariDokterByID(L, id);
                } else if (pilihDokter == 4) {
                    string id;
                    cout << "Masukan ID Dokter yang akan dihapus: ";
                    cin >> id;
                    deleteDokter(L, id);
                } else if (pilihDokter == 5) {
                    string idDokter, idP;
                    cout << "Hapus pasien dari dokter (ID): ";
                    cin >> idDokter;

                    adrDokter D = cariDokter(L, idDokter);
                    if (D != nullptr) {
                        if (D->firstPasien == nullptr) {
                            cout << "Belum ada Pasien." << endl;
                        } else {
                            cout << "Masukan ID Pasien yang ingin dihapus: ";
                            cin >> idP;

                            adrPasien P = D->firstPasien;
                            adrPasien prev = nullptr;

                            while (P != nullptr && P->idPasien != idP) {
                                prev = P;
                                P = P->next;
                            }
                            if (P == nullptr) {
                                cout << "Pasien Tidak ditemukan." << endl;
                            } else {
                                if (prev == nullptr) {
                                    D->firstPasien = P->next;
                                } else {
                                    prev->next = P->next;
                                }
                                P->next = nullptr;
                                cout << "Pasien berhasil dihapus: " << P->nama << endl;
                            }
                        }
                    }
                } else if (pilihDokter == 6) {
                    if (LP.first == nullptr) {
                        cout << "Belum ada pasien yang terdaftar!" << endl;
                    } else {
                        showSemuaPasien(LP);
                        string namaPas;
                        cout << "Masukan nama pasien yang ingin ditambahkan: ";
                        cin >> namaPas;

                        adrPasien Ppas = searchPasienByNama(LP, namaPas);
                        if (Ppas == nullptr) {
                            cout << "Pasien dengan NAMA tersebut tidak ditemukan!" << endl;
                        } else {
                            string idDokter;
                            cout << "Masukan ID Dokter: ";
                            cin >> idDokter;

                            adrDokter D = cariDokter(L, idDokter);
                            if (D == nullptr) {
                                cout << "Dokter tidak ditemukan!" << endl;
                            } else {
                                ListPasien tempLP;
                                tempLP.first = D->firstPasien;
                                insertPasienLast(tempLP, Ppas);
                                D->firstPasien = tempLP.first;

                                cout << "Pasien " << Ppas->nama << " Berhasil ditambahkan ke Dokter " << D->nama << endl;
                            }
                        }
                    }
                }
            }

        // ==================== PASIEN ====================
        } else if (menu == 3) {
            int pilihPasien = -1;
            while (pilihPasien != 0) {
                menuPasien(pilihPasien);

                if (pilihPasien == 1) {
                    showSemuaDokter(L);
                    string namaDokter;
                    cout << "Masukan Nama Dokter yang akan menangani anda: ";
                    cin >> namaDokter;

                    adrDokter D = cariDokterByNama(L, namaDokter);

                    if (D != nullptr) {
                        cout << "Silahkan Input Data Anda: " << endl;
                        string idPas, namaPas, KeluhanPas, AlamatPas, FavDok;
                        int umurPas;

                        cout << "ID Pasien      : "; cin >> idPas;
                        cout << "Nama Pasien    : "; cin >> namaPas;
                        cout << "Umur           : "; cin >> umurPas;
                        cout << "Alamat         : "; cin >> AlamatPas;
                        cout << "Keluhan        : "; cin >> KeluhanPas;
                        cout << "Dokter Favorit : "; cin >> FavDok; // Input Dokter Favorit

                        // Masukkan FavDok ke parameter fungsi newElmPasien
                        adrPasien P = newElmPasien(idPas, namaPas, umurPas, AlamatPas, KeluhanPas, FavDok);
                        insertPasienLast(LP, P);

                        tambahPasienKeDokter(D, P);

                        cout << "Anda Berhasil Mendaftar Jadi Pasien Dokter " << D->nama << endl;

                    } else {
                        cout << "Dokter Tidak ditemukan!" << endl;
                    }

                } else if (pilihPasien == 2) {
                    cout << endl;
                    if (L.first == nullptr) {
                        cout << "Maaf Dokter Sedang kosong." << endl;
                    } else {
                        showSemuaDokter(L);
                    }
                }
            }
        }
    }
    cout << endl;
    cout << "Terimakasih Telah menggunakan sistem kami, sampai jumpa kembali!\n";
    return 0;
}
