#include <iostream>
//#include <conio.h>
#include "Create_jadwal.cpp"
#include "Show_jadwal.cpp"
#include "Update_jadwal.cpp"
#include "Delete_jadwal.cpp"

using namespace std;

void Admin() {

	int pilih;
	char tmp_buffer[64];
	string menu_admin [] = {

		"Create Jadwal",
		"Show Jadwal",
		"Update Jadwal",
		"Delete Jadwal",
		"Back",
	};

	Menu:
	system("cls");
	cout << "====================" << endl;
	cout << "Menu Admin" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < (sizeof(menu_admin)/sizeof(menu_admin[0])); ++i)
	{
		cout << i+1 << ". " << menu_admin[i] << endl;
	}
	cout << "====================" << endl;
	cout << "\nPilih Menu: ";
	// cin >> pilih;
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);

	enum option{CREATE = 1, READ, UPDATE, DELETE, FINISH};

	while(pilih != FINISH) {
		switch(pilih){
			case CREATE: Create(); break;
			case READ: Show(); break;
			case UPDATE: Update(); break;
			case DELETE: Delete(); break;
			default: cout << "Menu tidak tersedia" << endl; /*getch();*/ break;
		}
		goto Menu;
	}

	// if (pilih == CREATE){
	// 	Create();
	// } else if (pilih == READ){
	// 	Show();
	// 	goto Menu;
	// } else if (pilih == UPDATE){
	// 	Update();
	// } else if (pilih == DELETE){
	// 	// DELETE
	// } else if (pilih == FINISH){
	// 	return;
	// }else {
	// 	cout << "Pilihan tidak tersedia" << endl;
	// 	system("pause");
	// 	goto Menu;
	// }
	return;


}
