#include <iostream>
#include <limits> // for 'numeric_limits'

using namespace std;

void errorInput(int &input) { // Failsafe kalo input gagal baca integer
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // If input not integer, repeat
            cout << "\n>> Input bukan angka\n\n";
            cout << "> ";
            cin >> input;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

struct treeMahasiswaTI { // Define tree mahasiswa prodi TI
    int valueMahasiswaTI;
    string namaMahasiswaTI;
    string umurMahasiswaTI;
    string alamatMahasiswaTI;
    string ipMahasiswaTI;
    string nimMahasiswaTI = "23051204";
    string tigaNimMahasiwaTI;

    treeMahasiswaTI* left;
    treeMahasiswaTI* right;

    treeMahasiswaTI() : left(nullptr), right(nullptr) {} // Default constructor
    treeMahasiswaTI(int value, string name, string age, string alamat, string ip, string tigaNim) : 
        valueMahasiswaTI(value), namaMahasiswaTI(name), umurMahasiswaTI(age), alamatMahasiswaTI(alamat), ipMahasiswaTI(ip), tigaNimMahasiwaTI(tigaNim), left(nullptr), right(nullptr) {}
};

struct treeMahasiswaSI { // Define tree mahasiswa prodi SI
    int valueMahasiswaSI;
    string namaMahasiswaSI;
    string umurMahasiswaSI;
    string alamatMahasiswaSI;
    string ipMahasiswaSI;
    string nimMahasiswaSI = "23051205";
    string tigaNimMahasiwaSI;

    treeMahasiswaSI* left;
    treeMahasiswaSI* right;

    treeMahasiswaSI() : left(nullptr), right(nullptr) {} // Default constructor
    treeMahasiswaSI(int value, string name, string age, string alamat, string ip, string tigaNim) : 
        valueMahasiswaSI(value), namaMahasiswaSI(name), umurMahasiswaSI(age), alamatMahasiswaSI(alamat), ipMahasiswaSI(ip), tigaNimMahasiwaSI(tigaNim), left(nullptr), right(nullptr) {}
};

struct treeMahasiswaPTI { // Define tree mahasiswa prodi PTI
    int valueMahasiswaPTI;
    string namaMahasiswaPTI;
    string umurMahasiswaPTI;
    string alamatMahasiswaPTI;
    string ipMahasiswaPTI;
    string nimMahasiswaPTI = "23051206";
    string tigaNimMahasiwaPTI;

    treeMahasiswaPTI* left;
    treeMahasiswaPTI* right;

    treeMahasiswaPTI() : left(nullptr), right(nullptr) {} // Default constructor
    treeMahasiswaPTI(int value, string name, string age, string alamat, string ip, string tigaNim) : 
        valueMahasiswaPTI(value), namaMahasiswaPTI(name), umurMahasiswaPTI(age), alamatMahasiswaPTI(alamat), ipMahasiswaPTI(ip), tigaNimMahasiwaPTI(tigaNim), left(nullptr), right(nullptr) {}
};

class dataMahasiswa {
    public:
        void tambahDataTI() {
            treeMahasiswaTI dataTI;
            cout << "\nNama Mahasiswa: ";
            cin.ignore();
            getline(cin, dataTI.namaMahasiswaTI);

            cout << "Usia Mahasiswa: ";
            cin >> dataTI.umurMahasiswaTI;
            cin.ignore();

            cout << "Alamat Mahasiswa: ";
            getline(cin, dataTI.alamatMahasiswaTI);

            cout << "Masukkan IP Mahasiswa: ";
            cin >> dataTI.ipMahasiswaTI;
            cin.ignore();

            cout << "Masukkan 3 digit NIM terakhir Mahasiswa: ";
            cin >> dataTI.tigaNimMahasiwaTI;
            cin.ignore();
        }

        void tambahDataSI() {
            treeMahasiswaSI dataSI;
            cout << "\nNama Mahasiswa: ";
            cin.ignore();
            getline(cin, dataSI.namaMahasiswaSI);

            cout << "Usia Mahasiswa: ";
            cin >> dataSI.umurMahasiswaSI;
            cin.ignore();

            cout << "Alamat Mahasiswa: ";
            getline(cin, dataSI.alamatMahasiswaSI);

            cout << "Masukkan IP Mahasiswa: ";
            cin >> dataSI.ipMahasiswaSI;
            cin.ignore();

            cout << "Masukkan 3 digit NIM terakhir Mahasiswa: ";
            cin >> dataSI.tigaNimMahasiwaSI;
            cin.ignore();
        }

        void tambahDataPTI() {
            treeMahasiswaPTI dataPTI;
            cout << "\nNama Mahasiswa: ";
            cin.ignore();
            getline(cin, dataPTI.namaMahasiswaPTI);

            cout << "Usia Mahasiswa: ";
            cin >> dataPTI.umurMahasiswaPTI;
            cin.ignore();

            cout << "Alamat Mahasiswa: ";
            getline(cin, dataPTI.alamatMahasiswaPTI);

            cout << "Masukkan IP Mahasiswa: ";
            cin >> dataPTI.ipMahasiswaPTI;
            cin.ignore();

            cout << "Masukkan 3 digit NIM terakhir Mahasiswa: ";
            cin >> dataPTI.tigaNimMahasiwaPTI;
            cin.ignore();
        }

        void tambahData() {
            while (true) {
                int prodiPath;

                cout << "\n1. Pilih prodi mahasiswa\n";
                cout << "1) Teknik Informatika\n";
                cout << "2) Sistem Informasi\n";
                cout << "3) Pendidikan Teknologi Informasi\n";
                cout << "0) Kembali ke menu utama\n";
                cout << "> ";

                cin >> prodiPath;
                errorInput(prodiPath); // Handling error input

                if (prodiPath == 1) {
                    tambahDataTI();
                } else if (prodiPath == 2) {
                    tambahDataSI();
                } else if (prodiPath == 3) {
                    tambahDataPTI();
                } else if (prodiPath == 0) {
                    cout << "\n>> Kembali ke menu utama\n";
                    break; // Exit loop
                } else {
                    cout << "\n>> Input tidak valid\n";
                    continue; // Invalid input, ask again
                }

                cout << "\n>> Apakah Anda ingin menambah data mahasiswa lain? (1: Ya, 0: Tidak)\n> ";
                int tambahLagi;
                cin >> tambahLagi;
                errorInput(tambahLagi);

                if (tambahLagi == 0) {
                    break;
                }
            }
        }
};

int main() {
    dataMahasiswa dm;

    cout << "\n----------Program manajemen data mahasiswa TI----------\n";

    do {
        int homePath;

        cout << "\n1. Tambahkan data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Tampilkan data seluruh mahasiswa\n";
        cout << "4. Tampilkan data mahasiswa eligible\n";
        cout << "5. Cari data mahasiswa berdasarkan NIM\n";
        cout << "0. Keluar dari program\n";
        cout << "\n";
        cout << "> ";

        cin >> homePath;
        errorInput(homePath); // Handling error input

        if (homePath == 1) {
            dm.tambahData();
        } else if (homePath == 2) {
            // Implementasi hapus data mahasiswa
        } else if (homePath == 3) {
            // Implementasi tampilkan data seluruh mahasiswa
        } else if (homePath == 4) {
            // Implementasi tampilkan data mahasiswa eligible
        } else if (homePath == 5) {
            // Implementasi cari data mahasiswa berdasarkan NIM
        } else if (homePath == 0) {
            cout << "\n>> Keluar dari program\n";
            break; // Exit loop
        } else {
            cout << "\n>> Input tidak valid\n";
        }
    } while (true);

    return 0;
}
