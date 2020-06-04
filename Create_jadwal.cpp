#ifndef JADWAL
#define JADWAL
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"

struct Jadwal{
	bool deleted = false;
	char kode[8];
	char nama_maskapai[32];
	char tgl_keberangkatan[16];
	char tujuan[32];
	char keberangkatan[32];
	char kedatangan[32];
	char terminal[16];
	char status[8];
};

int Create(){

	FILE *handle;
	int pilih,latest_code;
	char x, tmp_buffer[64] = {0};
	Jadwal jadwal, tmp;

	memset(&tmp, 0, sizeof(tmp));
	memset(&jadwal, 0, sizeof(jadwal));

	string jenis_kendaraan [] = {

		"Pesawat Terbang",
		"Kereta Api",
		"Bus",
	};

	Menu_jadwal:
	system("cls");
	cout << "========================" << endl;
	cout << "Jadwal Keberangkatan" << endl;
	cout << "========================" << endl;
	for (int i = 0; i < (sizeof(jenis_kendaraan)/sizeof(jenis_kendaraan[0])); ++i)
	{
		cout << i+1 << ". " << jenis_kendaraan[i] << endl;
	}
	cout << "========================" << endl;
	cout << "\nPilih Jenis Kendaraan : ";
	// cin >> pilih;
	// cin.ignore();
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);

	if (pilih == 1)
	{
		// Pesawat
		cout << "Create Jadwal Pesawat" << endl;
		cout << "Nama Maskapai\t\t: ";
		cin.getline(jadwal.nama_maskapai,31);
		cout << "Tanggal Keberangkatan\t: ";
		cin.getline(jadwal.tgl_keberangkatan,15);
		cout << "Tujuan\t\t\t: ";
		cin.getline(jadwal.tujuan,31);
		cout << "Keberangkatan\t\t: ";
		cin.getline(jadwal.keberangkatan,31);
		cout << "Kedatangan\t\t: ";
		cin.getline(jadwal.kedatangan,31);
		cout << "Terminal\t\t: ";
		cin.getline(jadwal.terminal,15);
		cout << "Status\t\t\t: ";
		cin.getline(jadwal.status,7);
		cout << endl;

		cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
		cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
		cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
		cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
		cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
		cout << "Terminal\t\t: " << jadwal.terminal << endl;
		cout << "Status\t\t\t: " << jadwal.status << endl;
		cout << "\nSimpan jadwal baru ? [y/n] : ";
		cin >> x;

		if (x == 'Y' || x == 'y'){
			handle = fopen(file_database_pesawat,"ab+");
			if (handle == NULL){
				strcpy(jadwal.kode,"PS01");
			} else {
				while(!feof(handle)){
					fread(&tmp, sizeof(struct Jadwal), 1, handle);
				}
				latest_code = atoi(&(tmp.kode[2])) + 1;
				sprintf(jadwal.kode, "PS%02d", latest_code);
				fwrite(&jadwal, sizeof(jadwal), 1, handle);
				fclose(handle);
			}

			// handle = fopen(file_database_pesawat,"a");

			cout << "Data Berhasil Disimpan" << endl;
			
		} else {
			cout << "Data Gagal Disimpan" << endl;

		}

	} else if (pilih == 2){
		// Kereta
		cout << "Create Jadwal Kereta Api" << endl;
		cout << "Nama Maskapai\t\t: ";
		cin.getline(jadwal.nama_maskapai,31);
		cout << "Tanggal Keberangkatan\t: ";
		cin.getline(jadwal.tgl_keberangkatan,15);
		cout << "Tujuan\t\t\t: ";
		cin.getline(jadwal.tujuan,31);
		cout << "Keberangkatan\t\t: ";
		cin.getline(jadwal.keberangkatan,31);
		cout << "Kedatangan\t\t: ";
		cin.getline(jadwal.kedatangan,31);
		cout << "Terminal\t\t: ";
		cin.getline(jadwal.terminal,15);
		cout << "Status\t\t\t: ";
		cin.getline(jadwal.status,7);
		cout << endl;

		cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
		cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
		cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
		cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
		cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
		cout << "Terminal\t\t: " << jadwal.terminal << endl;
		cout << "Status\t\t\t: " << jadwal.status << endl;
		cout << "\nSimpan jadwal baru ? [y/n] : ";
		cin >> x;

		if (x == 'Y' || x == 'y'){

			
			handle = fopen(file_database_kereta,"a");
			fwrite(&jadwal, sizeof(jadwal), 1, handle);
			fclose(handle);

			cout << "Data Berhasil Disimpan" << endl;
			
		} else {
			cout << "Data Gagal Disimpan" << endl;

		}

	} else if (pilih == 3){
		// Bus
		cout << "Create Jadwal Bus" << endl;
		cout << "Nama Maskapai\t\t: ";
		cin.getline(jadwal.nama_maskapai,31);
		cout << "Tanggal Keberangkatan\t: ";
		cin.getline(jadwal.tgl_keberangkatan,15);
		cout << "Tujuan\t\t\t: ";
		cin.getline(jadwal.tujuan,31);
		cout << "Keberangkatan\t\t: ";
		cin.getline(jadwal.keberangkatan,31);
		cout << "Kedatangan\t\t: ";
		cin.getline(jadwal.kedatangan,31);
		cout << "Terminal\t\t: ";
		cin.getline(jadwal.terminal,15);
		cout << "Status\t\t\t: ";
		cin.getline(jadwal.status,7);
		cout << endl;

		cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
		cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
		cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
		cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
		cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
		cout << "Terminal\t\t: " << jadwal.terminal << endl;
		cout << "Status\t\t\t: " << jadwal.status << endl;
		cout << "\nSimpan jadwal baru ? [y/n] : ";
		// cin >> x;
		fgets(tmp_buffer, 5, stdin);
		x = tmp_buffer[0];

		if (x == 'Y' || x == 'y'){

			handle = fopen(file_database_bus,"a");
			fwrite(&jadwal, sizeof(jadwal), 1, handle);
			fclose(handle);
			
			cout << "Data Berhasil Disimpan" << endl;
			
		} else {
			cout << "Data Gagal Disimpan" << endl;

		}
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		system("pause");
		goto Menu_jadwal;
	}

	return 0;
}

#endif