
#include "Create_jadwal.cpp"

void Delete(){
  FILE *handle;
  int pilih,i=1,tmp=0,nread = 0;
  struct Jadwal jadwal;
  struct Jadwal *fixArray;
  char tmp_kode[12];
    
  string jenis_kendaraan [] = {
    "Pesawat Terbang",
    "Kereta Api",
    "Bus",
    "Back",
  };

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

      if (!strcmp(jadwal.kode, tmp_kode)) {
        i++;
        jadwal.deleted = true;
        fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
        fwrite(&jadwal, 1, sizeof(jadwal), handle);
        break;
      }
    }
    

    if (i == 0){
      cout << "Kode tidak ditemukan" << endl;
    }
    cout << "Data berhasil dihapus" << endl;
    fclose(handle);
  }
}
