#include "rumah_sakit.h" // Wajib di-include agar fungsi pasien bisa dipakai
#include <iostream>

using namespace std;

int main() {
    // Buat List Utama (List Dokter)
    ListDokter L;
    createListDokter(L);

    ListPasien LP;
    createListPasien(LP);

    int pilihan = 0;
    // ini menu login Pengguna, Bisa login sebagai(Admin, Dokter, Dan Pasien)
    while (true) {
        cout << "\n============ MENU RUMAH SAKIT ============" << endl;
        cout << "Hallo, Selamat Datang!" << endl;
        cout << "Terima kasih telah mempercayai layanan kami," << endl;
        cout << "Silakan pilih login sesuai kebutuhan Anda."<< endl;
        cout << endl;
        cout << "1. Admin" << endl;
        cout << "2. Dokter" << endl;
        cout << "3. Pasien" << endl;
        cout << "0. Keluar" << endl;
        cout << endl;
        cout << "==========================================" << endl;
        cout << "Login Sebagai : ";
        cin >> pilihan;

        if (pilihan == 1) {
            //Berisi Fitur-fitur yang bisa dilakukan oleh admin
            int Admin = 0;
            cout << "\n============= Menu Admin =============" << endl;
            cout << "1. Tambah Dokter Baru" << endl;
            cout << "2. Tambah Pasien Baru" << endl;
            cout << "3. Hapus Pasien" << endl;
            cout << "4. Hapus Dokter" << endl;
            cout << "5. Cari Dokter" << endl;
            cout << "6. Cari Pasien" << endl;
            cout << "7. Show semua Dokter" << endl;
            cout << "8. Show Semua Pasien" << endl;
            cout << "9. Tambahkan Pasien Ke Dokter" << endl;
            cout << "Pilih Opsi: ";
            cin >> Admin;
            if (Admin == 1){
                // Panggil fungsi dari dokter.cpp
                tambahDokter(L);
                cout << "\nDokter Berhasil Ditambahkan!"<<endl;
            }else if (Admin == 2) {
                int umur;
                string idPasien, nama, keluhan, alamat;

                cout<<endl;
                cout << "Data Pasien"<<endl;
                cout<< "Masukan ID Pasien: "; cin >> idPasien;
                cout<< "Masukan nama pasien: "; cin >> nama;
                cout<< "Masukan Umur: "; cin >> umur;
                cout<< "Masukan Alamat: "; cin >> alamat;
                cout<< "Keluhan Pasien: "; cin >> keluhan;
                cout << endl;

                adrPasien P = newElmPasien(idPasien, nama, umur, alamat, keluhan);

                insertPasienLast(LP, P);
                cout << "Pasien Berhasil Ditambahkan!" << endl;

            }else if (Admin == 7) {
                cout<<endl;
                // jika dokter belum di input or dokter sibuk.
                if (L.first == nullptr){
                    cout << "Maaf Dokter Sedang kosong, Silahkan kembali lagi nanti. Terima Kasih"<< endl;
                }else {
                // output terjadi apabila dokter telah terisi/ dokter tidak sibuk.
                    showSemuaDokter(L);
                }

            }else if (Admin == 5) {
                string Id;
                cout << "Masukan ID Dokter yang dicari: ";
                cin >> Id;
                cariDokterByID(L, Id);

            }else if (Admin == 4) {
                string Id;
                cout << "Masukan ID Dokter yang akan dihapus: ";
                cin >> Id;
                cariDokterByID(L, Id);
            }else if (Admin == 8) {
                cout << endl;
                if (LP.first == nullptr) {
                    cout << "Belum Ada Pasien saat ini"<< endl;
                }else {
                    showSemuaPasien(LP);

                }


            }else if (Admin == 3){
                int hapus = 0;
                string id, nama;
                cout << "=========================" << endl;
                cout << "1. Hapus Berdasarkan ID" << endl;
                cout << "2. Hapus Berdasarkan Nama" << endl;
                cout << "=========================" << endl;
                cout << "Pilih Opsi: ";
                cin >> hapus;

                adrPasien target, prec, P;
                if (hapus == 1) {
                    cout << "Masukan ID pasien : ";
                    cin >> id;

                    target = searchPasienByID(LP, id);
                    if (target == nullptr) {
                        cout << "Dokter dengan ID tersebut tidak ditemukan!"<< endl;
                    }else {
                        if (target == LP.first) {
                            deletePasienFirst(LP, P);

                        }else if (target->next == nullptr){
                            deletePasienLast(LP, P);

                        }else {
                            prec = LP.first;
                            while (prec->next != target){
                                prec = prec->next;
                            }
                            deletePasienAfter(prec, P);

                        }
                        cout << "Pasien Berhasil Dihapus!" << endl;
                    }
                }else if (hapus == 2) {

                    cout << "Masukan nama pasien: ";
                    cin >> nama;

                    target = searchPasienByNama(LP, nama);

                    if (target == nullptr) {
                        cout << "Pasien dengan nama tersebut tidak ditemukan!"<< endl;
                    }else {

                        if (target == LP.first) {
                            deletePasienFirst(LP, P);
                        }else if (target ->next == nullptr) {
                            deletePasienLast(LP, P);

                        }else {
                            prec = LP.first;
                            while (prec->next != target) {
                                prec = prec->next;
                            }
                            deletePasienAfter(prec, P);

                        }

                        cout << "Pasien berhasil di hapus!" << endl;

                    }
                }
            }else if (Admin == 6) {
                int searchPas = 0;
                string idPas, namaPas, keluhanPas, AlamatPas;
                int umurPas;
                cout << "=========================" << endl;
                cout << "1. Cari Pasien Berdasarkan ID" << endl;
                cout << "2. Cari Pasien Berdasarkan Nama" << endl;
                cout << "3. Cari Pasien Berdasarkan Umur" << endl;
                cout << "2. Cari Pasien Berdasarkan Keluhan" << endl;
                cout << "2. Cari Pasien Berdasarkan Alamat" << endl;
                cout << "=========================" << endl;
                cout << "Pilih Opsi: ";
                cin >> searchPas;
                if (searchPas == 1) {
                    cout << "Masukan ID pasien yang dicari: ";
                    cin >> idPas;
                    cout << endl;
                    if (LP.first==nullptr) {
                        cout << "Maaf pasien dengan ID tersebut tidak terdaftar!"  << endl;
                    }else {
                        searchPasienByID(LP, idPas);
                    }
                }else if (searchPas == 2) {
                    cout << "Masukan Nama pasien yang dicari: ";
                    cin >> namaPas;
                    cout << endl;
                    if (LP.first==nullptr) {
                        cout << "Maaf pasien dengan Nama tersebut tidak terdaftar!" << endl;
                    }else {
                        searchPasienByNama(LP, namaPas);
                    }

                }else if (searchPas == 3) {
                    cout << "Masukan Umur pasien yang dicari: ";
                    cin >> umurPas;
                    cout << endl;
                    if (LP.first==nullptr) {
                        cout << "Maaf pasien dengan Umur tersebut tidak terdaftar!"  << endl;
                    }else {
                        searchPasienByUmur(LP, umurPas);
                    }
                }else if (searchPas == 4) {
                    cout << "Masukan Keluhan pasien yang dicari: ";
                    cin >> keluhanPas;
                    cout << endl;
                    if (LP.first==nullptr) {
                        cout << "Maaf pasien dengan keluhan tersebut tidak terdaftar!"  << endl;
                    }else {
                        searchPasienByKeluhan(LP, keluhanPas);
                    }
                }else if (searchPas == 5) {
                    cout << "Masukan Alamat pasien yang dicari: ";
                    cin >> AlamatPas;
                    cout << endl;
                    if (LP.first==nullptr) {
                        cout << "Maaf pasien dengan Alamat tersebut tidak terdaftar!"  << endl;
                    }else {
                        searchPasienByAlamat(LP, AlamatPas);
                    }
                }

            }else if (Admin == 9)  {
                string namaPas, namaDok;
                cout << "Masukan nama pasien: ";
                cin >> namaPas;

                adrPasien Ppas = searchPasienByNama(LP, namaPas);

                if (Ppas == nullptr) {
                    cout << "Pasien dengan nama tersebut tidak ditemukan!"<< endl;
                }else {
                    cout << "Masukan nama dokter: ";
                    cin >> namaDok;

                    adrDokter Pdok = cariDokterByNama(L, namaDok);

                    if (Pdok == nullptr) {
                        cout << "Dokter dengan nama tersebut tidak ditemukan!"<< endl;
                    }else {
                        tambahPasienKeDokter(Pdok, Ppas);

                        cout <<"\nPasien berhasil di tambahkan ke dokter!";

                        showPasienDokter(Pdok);
                    }

                }

            }

        } else if (pilihan == 2) {
            int Dokter = 0;
            cout << "\n============= Menu Dokter =============" << endl;
            cout << "1. Show Pasien Milik Dokter" << endl;
            cout << "2. Show Semua Dokter" << endl;
            cout << "3. Cari Dokter" << endl;
            cout << "4. Hapus Dokter" << endl;
            cout << "5. Hapus Pasien Dari Dokter" << endl;
            cout << "6. Menambahkan Pasien ke dokter" << endl;
            cout << "Pilih Opsi: ";
            cin >> Dokter;
            if (Dokter == 1) {
                string idDokter;
                cout << "Lihat pasien dari Dokter (ID): ";
                cin >> idDokter;

                adrDokter D = cariDokter(L, idDokter);
                if (D != nullptr) {
                cout << "\nPasien yang ditangani dr. " << D->nama << ":" << endl;

                // Bungkus lagi ke ListPasien sementara
                ListPasien LP;
                LP.first = D->firstPasien;

                // Panggil fungsi show dari pasien.cpp
                showSemuaPasien(LP);
                } else {
                    cout << "Dokter tidak ditemukan!" << endl;
                }
            } else if (Dokter == 2) {
                cout << endl;
                if (L.first == nullptr) {
                    cout << "Maaf dokter sedang sibuk!, silahkan kembali lagi nanti, Terima kasih!"<< endl;
                }else {
                    showSemuaDokter(L);

                }
            } else if (Dokter == 3) {
                string id;
                cout << "Masukkan ID dokter yang dicari: ";
                cin >> id;
                cariDokterByID(L, id);

            }else if (Dokter == 4) {
                string id;
                cout << "Masukan ID Dokter yang akan dihapus: ";
                cin >>id;
                deleteDokter(L, id);
            }else if (Dokter == 5) {
                string idDokter;
                cout << "Hapus pasien dari dokter (ID): ";
                cin >> idDokter;

                adrDokter D = cariDokter(L, idDokter);
                if (D != nullptr) {
                    if (D->firstPasien == nullptr) {
                        cout << "Belum ada Pasien." << endl;
                    }else {
                        LP.first = D->firstPasien;
                        adrPasien P; // pointer pasien yang dihapus
                        adrPasien Prec;

                        //hapus pasien yang pertama
                        if  (LP.first != nullptr && LP.first->next == nullptr) {
                            deletePasienFirst(LP, P);
                            cout << "Pasien berhasil dihapus: " << P->nama << endl;
                        } else if (LP.first != nullptr && LP.first->next != nullptr && LP.first->next->next == nullptr) {
                            deletePasienLast(LP, P);
                            cout << "Pasien berhasil dihapus: " << P->nama << endl;
                        } else if (LP.first != nullptr && LP.first->next != nullptr) {
                            Prec = LP.first;
                            deletePasienAfter(Prec, P);
                            cout << "Pasien berhasil dihapus: " << P->nama << endl;
                        } else {
                            cout << "Belum ada pasien" << endl;
                        }

                    }
                }



            } else if (Dokter == 6) {
                if (LP.first == nullptr) {
                    cout << "Belum ada pasien  yang terdaftar!" << endl;
                }else  {
                    showSemuaPasien(LP);
                    string namaPas;
                    cout << "Masukan nama pasien yang ingin ditambahkan: ";
                    cin >> namaPas;

                    adrPasien Ppas = searchPasienByNama(LP, namaPas);
                    if (Ppas == nullptr) {
                        cout << "Pasien dengan NAMA tersebut tidak ditemukan!"<<endl;
                    }else {
                        string idDokter;
                        cout <<"Masukan ID Dokter: ";
                        cin >> idDokter;

                        adrDokter D = cariDokter(L, idDokter);
                        if (D == nullptr) {
                            cout << "Dokter tidak ditemukan!" << endl;
                        }else {
                            ListPasien tempLP;
                            tempLP.first = D->firstPasien;
                            insertPasienLast(tempLP, Ppas);
                            D->firstPasien = tempLP.first;

                            cout << "Pasien" << Ppas->nama << "Berhasil ditambahkan ke Dokter" << D->nama <<endl;
                        }
                    }

                }
            }
        }else if (pilihan == 3) {
            int pasien = 0;
            cout << "\n================= Pasien =================" << endl;
            cout << "1. Daftar Menjadi Pasien" << endl;
            cout << "2. Show Semua Dokter" << endl;
            cout << "3. Cari Dokter" << endl;
            cout << "4. Jadwal Kontrol" << endl;
            cout << "==========================================" << endl;
            cout << "Pilih Opsi: ";
            cin >> pasien;
            if (pasien == 1) {
                showSemuaDokter(L);
                string namaDokter;
                cout << "Masukan Nama Dokter yang dipilih: ";
                cin >> namaDokter;

                adrDokter D = cariDokterByNama(L, namaDokter);

                if (D != nullptr) {
                    cout << "Silahkan Input Data Anda: " << endl;
                    string idPas, namaPas, KeluhanPas, AlamatPas;
                    int umurPas;

                    cout << "ID Pasien   : "; cin >> idPas;
                    cout << "Nama Pasien : "; cin >> namaPas;
                    cout << "Umur        : "; cin >> umurPas;
                    cout << "Alamat      : "; cin >> AlamatPas;
                    cout << "Keluhan     : "; cin >> KeluhanPas;

                    adrPasien P = newElmPasien(idPas, namaPas, umurPas, AlamatPas, KeluhanPas);
                    insertPasienLast(LP, P);

                    tambahPasienKeDokter(D, P);

                    cout << "Anda Berhasil Mendaftar Jadi Pasien Dokter " << D->nama << endl;

                }else {
                    cout << "Dokter Tidak ditemukan!" << endl;
                }

            } else if (pasien == 2) {
                cout<<endl;
                // jika dokter belum di input or dokter sibuk.
                if (L.first == nullptr){
                    cout << "Maaf Dokter Sedang kosong, Silahkan kembali lagi nanti. Terima Kasih"<< endl;
                }else {
                // output terjadi apabila dokter telah terisi/ dokter tidak sibuk.
                    showSemuaDokter(L);
                }

            } else if (pasien == 3) {
                string Id;
                cout << "Masukan ID Dokter yang dicari: ";
                cin >> Id;
                cariDokterByID(L, Id);

            // jadwal kontrol selanjutnya pasien.
            } else if (pasien == 4) {

            }

        }else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan sistem kami. Sampai jumpa kembali!" << endl;
            break;
        }else {
            cout << "Maaf pilihan anda tidak valid!";

        }
    }
}
