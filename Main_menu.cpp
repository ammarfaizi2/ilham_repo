#include <iostream>
#include "User.cpp"
#include "Admin.cpp"

using namespace std;

int main()
{
	
	int pilih;
	char x;
	string menu [] = {

		"User",
		"Admin",
		"Exit"
	};

	Menu:
	system("cls");
	cout << "=========================" << endl;
	cout << "Program Tiket" << endl;
	cout << "=========================" << endl;
	for (int i = 0; i < (sizeof(menu)/sizeof(menu[0])); ++i)
	{
		cout << i+1 << ". " << menu[i] << endl;
	}
	cout << "\nPilih menu : ";
	cin >> pilih;

	if (pilih == 1){
		User();
	} else if (pilih == 2){
		Admin();
	} else if (pilih == 3){
		
		cout << "Apakah Anda Yakin Keluar Program ? [y/n] : ";
		cin >> x;

		if (x == 'y' || x == 'Y') {
			exit(0);
		} else {
			goto Menu;
		}

	} else {

		cout << "Menu Tidak Tersedia" << endl;
		system("pause");
		goto Menu;
	}
	
	goto Menu;
	return 0;
}
