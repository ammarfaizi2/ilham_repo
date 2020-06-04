#include <iostream>
#include <cstdio>
// #include <conio.h>
#include "Create_jadwal.cpp"

using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"

void Show(){

	FILE *handle;
	int pilih,i=1;
	struct Jadwal jadwal;
		
	string jenis_kendaraan [] = {

		"Pesawat Terbang",
		"Kereta Api",
		"Bus",
		"Back",
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
	cin >> pilih;
	cin.ignore();

	while(pilih != 4) {
		switch(pilih){
			case 1:
				cout << "Jadwal Keberangkatan Pesawat" << endl;
				handle = fopen(file_database_pesawat, "rb");
				if (handle == NULL){
					cout << "Database Kosong\n";
				} else {
					cout << "\nNama.\t\tKode\tTgl. Penerbangan  Tujuan\t\tKeberangkatan\t\tKedatangan\t\tTerminal\tStatus" << endl;
					while(!feof(handle)) {
						if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0) break;
						if (jadwal.deleted) continue;
						cout << jadwal.nama_maskapai << "\t\t";
						cout << jadwal.kode << "\t";
						cout << jadwal.tgl_keberangkatan << "\t  ";
						cout << jadwal.tujuan << "\t";
						cout << jadwal.keberangkatan << "\t\t";
						cout << jadwal.kedatangan << "\t";
						cout << jadwal.terminal << "\t\t";
						cout << jadwal.status << "\t";
						cout << endl;
						i++;
					}

					cout << "\nPress Enter to Back" << endl;
					//getch();
					fclose(handle);
				}
				goto Menu_jadwal;
				break;
			case 2:
			case 3:
			default:
				cout << "Pilihan tidak tersedia" << endl;
				//getch();
				goto Menu_jadwal;
				break;
		}
	}

	return;

	// if (pilih == 1){

	// 	cout << "Jadwal Keberangkatan Pesawat" << endl;
	// 	handle = fopen(file_database_pesawat,"r");
	// 	if (handle == NULL){
	// 		cout << "Database Kosong";
	// 	} else {
	// 		cout << "\nNama.\t\tKode\tTgl. Penerbangan  Tujuan\t\tKeberangkatan\t\tKedatangan\t\tTerminal\tStatus" << endl;
	// 		while(!feof(handle)){
	// 			if (fread(&jadwal, sizeof(jadwal), 1, handle) == 0) break;
	// 			cout << jadwal.nama_maskapai << "\t\t";
	// 			cout << jadwal.kode << "\t";
	// 			cout << jadwal.tgl_keberangkatan << "\t  ";
	// 			cout << jadwal.tujuan << "\t";
	// 			cout << jadwal.keberangkatan << "\t\t";
	// 			cout << jadwal.kedatangan << "\t";
	// 			cout << jadwal.terminal << "\t\t";
	// 			cout << jadwal.status << "\t";
	// 			cout << endl;
	// 			// cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
	// 			// cout << "Kode Penerbangan\t: " << jadwal.kode << endl;
	// 			// cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
	// 			// cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
	// 			// cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
	// 			// cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
	// 			// cout << "Terminal\t\t: " << jadwal.terminal << endl;
	// 			// cout << "Status\t\t\t: " << jadwal.status << endl;
	// 			// cout << endl;
	// 			i++;
	// 		}

	// 		cout << "\nPress Enter to Back" << endl;
	// 		getch();
	// 	}

	// } else if (pilih == 2){
	// 	/* code */
	// } else if (pilih == 3){
	// 	/* code */
	// } else if (pilih == 4){
	// 	return;
	// }else {
	// 	cout << "Pilihan tidak tersedia" << endl;
	// 	system("pause");
	// 	goto Menu_jadwal;
	// }

	
}
