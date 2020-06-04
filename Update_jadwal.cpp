#include <iostream>
#include <cstdio>
#include <string.h>
#include "Create_jadwal.cpp"

using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"


void Update() {

	FILE *handle;
	int pilih,i=1,tmp = 0;
	char tmp_kode[8] = {0};
	unsigned int nread;
	Jadwal jadwal;

	memset(tmp_kode, 0, sizeof(tmp_kode));
	memset(&jadwal, 0, sizeof(jadwal));

	string jenis_kendaraan [] = {

		"Pesawat Terbang",
		"Kereta Api",
		"Bus",
		"Back",
	};

	Menu:
	system("cls");
	cout << "================================" << endl;
	cout << "Edit Jadwal Keberangkatan" << endl;
	cout << "================================" << endl;
	for (int i = 0; i < (sizeof(jenis_kendaraan)/sizeof(jenis_kendaraan[0])); ++i)
	{
		cout << i+1 << ". " << jenis_kendaraan[i] << endl;
	}
	cout << "================================" << endl;
	cout << "\nPilih Kendaraan : ";
	cin >> pilih;
	cin.ignore();

	if (pilih == 1){
		handle = fopen(file_database_pesawat, "rb+");
		if (handle == NULL) {
			cout << "Database Kosong";
		} else {

			// Pesawat
			cout << "Masukkan kode penerbangan : ";
			cin.getline(tmp_kode, 8);
			i = 0;
			while (!feof(handle)) {
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
				if (nread == 0){
					break;
				}

				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode) && !jadwal.deleted) {
					i++;
					// // bp
					// cout << "1\n";
					// fread (&jadwal, 1, sizeof(jadwal), handle);
					// // bp
					// cout << "2\n";

					cout << "New Nama Maskapai\t\t: ";
					cin.getline(jadwal.nama_maskapai,31);
					cout << "New Tanggal Keberangkatan\t: ";
					cin.getline(jadwal.tgl_keberangkatan,15);
					cout << "New Tujuan\t\t\t: ";
					cin.getline(jadwal.tujuan,31);
					cout << "New Keberangkatan\t\t: ";
					cin.getline(jadwal.keberangkatan,31);
					cout << "New Kedatangan\t\t: ";
					cin.getline(jadwal.kedatangan,31);
					cout << "New Terminal\t\t: ";
					cin.getline(jadwal.terminal,15);
					cout << "New Status\t\t\t: ";
					cin.getline(jadwal.status,7);

					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
				}
			}
			

			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil diedit" << endl;
			fclose(handle);
		}

		// cout << sizeof(jadwal) << endl;
		// cout << tmp << endl;
		system("pause");

		// fseek(handle,tmp-(sizeof(jadwal)),SEEK_SET);
		// fwrite(&jadwal,sizeof(jadwal),1,handle);

		
		// fclose(handle);
		// system("pause");

		// handle = fopen(file_database_pesawat,"a");
		// fwrite(&jadwal, sizeof(jadwal), 1, handle);
		// fclose(handle);
		

	} else if (pilih == 2){
		// Kereta
	} else if (pilih == 3){
		// Bus
	} else if (pilih == 4){
		return;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		system("pause");
		goto Menu;
	}



}