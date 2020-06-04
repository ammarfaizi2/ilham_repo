#include <iostream>


using namespace std;

void User()
{
	int pilihan;
	string menu_user[] = {

		"Registration Form",
		"Informasi Penerbangan",
		"Perubahan Jadwal",
		"Cancel Penerbangan",
		"Booking Tiket",
		"Kembali"
	};

	Menu1:
	system("cls");
	cout << "=================" << endl;
	cout << "Menu User" << endl;
	cout << "=================" << endl;
	for (int i = 0; i < (sizeof(menu_user)/sizeof(menu_user[0])); ++i)
	{
		cout << i+1 << ". " << menu_user[i] << endl;
	}
	cout << "\nPilih Menu : ";
	cin >> pilihan;

	if (pilihan == 1)
	{
		// Registration
	} else if (pilihan == 2)
	{
		// Informasi
	} else if (pilihan == 3)
	{
		// Perubahan Jadwal
	} else if (pilihan == 4)
	{
		// Cancel
	} else if (pilihan == 5)
	{
		// Booking
	} else if (pilihan == 6){
		return;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		system("pause");
		goto Menu1;
	}

}
