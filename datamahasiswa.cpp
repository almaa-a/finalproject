#include <iostream>
#include <limits> // for 'numeric_limits'
#include <string> // Add this for using 'string'
#include <cstdint> // for 'int64_t'

using namespace std;

void errorInput(int &input) {
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n>> Input bukan angka\n\n";
            cout << "> ";
            cin >> input;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

void errorInputFloat(float &input) {
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n>> Input bukan angka\n\n";
            cout << "> ";
            cin >> input;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

int64_t stringToInt64_t(const string namaMahasiswa) { // Mengubah nama mahasiswa menjadi nim
    int64_t nimMahasiswa = 0;
    for (char ch : namaMahasiswa) {
        if (ch != ' ') {
            nimMahasiswa += (tolower(ch) - 'a' + 1);
        }
    }

    return nimMahasiswa;
}

int64_t membuatNim(string namaMahasiswa, int64_t nimBawaan) { // Fungsi membuat nim

    int64_t asciiNamaMahasiswa = stringToInt64_t(namaMahasiswa);  // Ubah nama jadi int64_t
    string stringNamaMahasiswa = to_string(nimBawaan) + to_string(asciiNamaMahasiswa);  // Ubah nim dan nama jadi string, lalu tambah keduanya

    int64_t NimMahasiswa = stoll(stringNamaMahasiswa); // Khusus, ubah string ke int64_t
    return NimMahasiswa;
}

struct treeMahasiswaTI { // Inisialisasi tree mahasiswa TI

    int64_t  nimMahasiswaTI = 23051204;
    float ipMahasiswaTI;
    string namaMahasiswaTI;
    string umurMahasiswaTI;
    string alamatMahasiswaTI;

    treeMahasiswaTI* left;
    treeMahasiswaTI* right;
    treeMahasiswaTI* next;

    treeMahasiswaTI() : left(nullptr), right(nullptr) {} // Default double link list constructor

    treeMahasiswaTI(int64_t nim, float ip, string nama, string umur, string alamat) : // Default tree constructor
    nimMahasiswaTI(nim), ipMahasiswaTI(ip), namaMahasiswaTI(nama), umurMahasiswaTI(umur), alamatMahasiswaTI(alamat), left(nullptr), right(nullptr) {}
};

struct treeMahasiswaSI { // Inisialisasi tree mahasiswa SI

    int64_t nimMahasiswaSI = 23051205;
    float ipMahasiswaSI;
    string namaMahasiswaSI;
    string umurMahasiswaSI;
    string alamatMahasiswaSI;

    treeMahasiswaSI* left;
    treeMahasiswaSI* right;
    treeMahasiswaSI* next;

    treeMahasiswaSI() : left(nullptr), right(nullptr) {} // Default double link list constructor

    treeMahasiswaSI(int64_t nim, float ip, string nama, string umur, string alamat) : // Default tree constructor
    nimMahasiswaSI(nim), ipMahasiswaSI(ip), namaMahasiswaSI(nama), umurMahasiswaSI(umur), alamatMahasiswaSI(alamat), left(nullptr), right(nullptr) {}
};

struct treeMahasiswaPTI { // Inisialisasi tree mahasiswa PTI

    int64_t nimMahasiswaPTI = 23051206;
    float ipMahasiswaPTI;
    string namaMahasiswaPTI;
    string umurMahasiswaPTI;
    string alamatMahasiswaPTI;

    treeMahasiswaPTI* left;
    treeMahasiswaPTI* right;
    treeMahasiswaPTI* next;

    treeMahasiswaPTI() : left(nullptr), right(nullptr) {} // Default double link list constructor

    treeMahasiswaPTI(int64_t nim, float ip, string nama, string umur, string alamat) : // Default tree constructor
    nimMahasiswaPTI(nim), ipMahasiswaPTI(ip), namaMahasiswaPTI(nama), umurMahasiswaPTI(umur), alamatMahasiswaPTI(alamat), left(nullptr), right(nullptr) {}
};



class dataMahasiswa {

    private:

    treeMahasiswaTI* headTI;
    treeMahasiswaSI* headSI;
    treeMahasiswaPTI* headPTI;

    int currentIndexTI, currentIndexSI, currentIndexPTI;
    int totaldataTI, totaldataSI, totaldataPTI;

    treeMahasiswaTI* mahasiswaTIByIndex(int index) {
        treeMahasiswaTI* currTI = headTI;
        for(int i=0; i<index && currTI!=nullptr; i++) {
            currTI = currTI->next; 
        }
        return currTI;
    }

    treeMahasiswaSI* mahasiswaSIByIndex(int index) {
        treeMahasiswaSI* currSI = headSI;
        for(int i=0; i<index && currSI!=nullptr; i++) {
            currSI = currSI->next; 
        }
        return currSI;
    }

    treeMahasiswaPTI* mahasiswaPTIByIndex(int index) {
        treeMahasiswaPTI* currPTI = headPTI;
        for(int i=0; i<index && currPTI!=nullptr; i++) {
            currPTI = currPTI->next; 
        }
        return currPTI;
    }

    public:

    dataMahasiswa() : headTI(nullptr), headSI(nullptr), headPTI(nullptr), currentIndexTI(0),
    currentIndexSI(0), currentIndexPTI(0), totaldataTI(0), totaldataSI(0), totaldataPTI(0) {}

        // ----------------------------------------------------- Fungsi menambahkan data -----------------------------------------------------
    
        void tambahDataTI() {
            treeMahasiswaTI* newDataTI = new treeMahasiswaTI();

            float ipMahasiswa;
            string namaMahasiswa;
            string umurMahasiswa;
            string alamatMahasiswa;

            cin.ignore(); // To ignore the leftover newline character from the previous input

            cout << "\nNama Mahasiswa: ";
            getline(cin, namaMahasiswa);

            cout << "Usia Mahasiswa: ";
            getline(cin, umurMahasiswa);            

            cout << "Alamat Mahasiswa: ";
            getline(cin, alamatMahasiswa);

            cout << "Masukkan IP Mahasiswa: ";
            cin >> ipMahasiswa;
            errorInputFloat(ipMahasiswa);
    
            newDataTI->nimMahasiswaTI = membuatNim(namaMahasiswa, newDataTI->nimMahasiswaTI); // Panggil fungsi untuk membuat nim
            newDataTI->namaMahasiswaTI = namaMahasiswa;
            newDataTI->umurMahasiswaTI = umurMahasiswa;
            newDataTI->alamatMahasiswaTI = alamatMahasiswa;
            newDataTI->ipMahasiswaTI = ipMahasiswa;

            newDataTI->next = nullptr;

            if (!headTI) {
                headTI = newDataTI;
            } else {
                treeMahasiswaTI* temp = headTI;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newDataTI;
            }

            totaldataTI++;
            cout << "Data mahasiswa berhasil ditambahkan.\n";
        }

        void tambahDataSI() {
            treeMahasiswaSI* newDataSI = new treeMahasiswaSI();

            float ipMahasiswa;
            string namaMahasiswa;
            string umurMahasiswa;
            string alamatMahasiswa;

            cin.ignore(); // To ignore the leftover newline character from the previous input

            cout << "\nNama Mahasiswa: ";
            getline(cin, namaMahasiswa);

            cout << "Usia Mahasiswa: ";
            getline(cin, umurMahasiswa);            

            cout << "Alamat Mahasiswa: ";
            getline(cin, alamatMahasiswa);

            cout << "Masukkan IP Mahasiswa: ";
            cin >> ipMahasiswa;
            errorInputFloat(ipMahasiswa);
    
            newDataSI->nimMahasiswaSI = membuatNim(namaMahasiswa, newDataSI->nimMahasiswaSI); // Panggil fungsi untuk membuat nim
            newDataSI->namaMahasiswaSI = namaMahasiswa;
            newDataSI->umurMahasiswaSI = umurMahasiswa;
            newDataSI->alamatMahasiswaSI = alamatMahasiswa;
            newDataSI->ipMahasiswaSI = ipMahasiswa;

            newDataSI->next = nullptr;

            if (!headSI) {
                headSI = newDataSI;
            } else {
                treeMahasiswaSI* temp = headSI;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newDataSI;
            }

            totaldataSI++;
            cout << "Data mahasiswa berhasil ditambahkan.\n";
        }

        void tambahDataPTI() {
            treeMahasiswaPTI* newDataPTI = new treeMahasiswaPTI();

            float ipMahasiswa;
            string namaMahasiswa;
            string umurMahasiswa;
            string alamatMahasiswa;

            cin.ignore(); // To ignore the leftover newline character from the previous input

            cout << "\nNama Mahasiswa: ";
            getline(cin, namaMahasiswa);

            cout << "Usia Mahasiswa: ";
            getline(cin, umurMahasiswa);            

            cout << "Alamat Mahasiswa: ";
            getline(cin, alamatMahasiswa);

            cout << "Masukkan IP Mahasiswa: ";
            cin >> ipMahasiswa;
            errorInputFloat(ipMahasiswa);
    
            newDataPTI->nimMahasiswaPTI = membuatNim(namaMahasiswa, newDataPTI->nimMahasiswaPTI); // Panggil fungsi untuk membuat nim
            newDataPTI->namaMahasiswaPTI = namaMahasiswa;
            newDataPTI->umurMahasiswaPTI = umurMahasiswa;
            newDataPTI->alamatMahasiswaPTI = alamatMahasiswa;
            newDataPTI->ipMahasiswaPTI = ipMahasiswa;

            newDataPTI->next = nullptr;

            if (!headPTI) {
                headPTI = newDataPTI;
            } else {
                treeMahasiswaPTI* temp = headPTI;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newDataPTI;
            }

            totaldataPTI++;
            cout << "Data mahasiswa berhasil ditambahkan.\n";
        }   

        void tambahData() {
            while (true) {
                int prodiPath;

                cout << "\nPilih prodi mahasiswa\n";
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

                cout << "\nApakah Anda ingin menambah data mahasiswa lain? (1: Ya, 0: Tidak)\n> ";
                int tambahLagi;
                cin >> tambahLagi;
                errorInput(tambahLagi);

                if (tambahLagi == 0) {
                    break;
                }
            }
        }

        // ----------------------------------------------------- Fungsi menampilkan data -----------------------------------------------------

        void tampilDataTI() {
            if (!headTI) {
            cout << "\nTidak ada data yang tersedia.\n";
            return;
            }

            bool exitRequested = false;

            while (!exitRequested) {
                treeMahasiswaTI* currTI = mahasiswaTIByIndex(currentIndexTI); // Mengambil data supir pada indeks currentIndexTI

                if (currTI) {                                                                                                                                                                                              
                    cout << "\nNama Mahasiswa: " << currTI->namaMahasiswaTI << endl;
                    cout << "Usia Mahasiswa: " << currTI->umurMahasiswaTI << endl;
                    cout << "Alamat Mahasiswa: " << currTI->alamatMahasiswaTI << endl;
                    cout << "NIM Mahasiswa: " << currTI->nimMahasiswaTI <<endl;
                    cout << "IP Mahasiswa: " << currTI->ipMahasiswaTI << endl;
                    cout << endl;

                    string choice;
                    cout << "1. berikutnya\n"; 
                    cout << "2. sebelumnya\n";
                    cout << "0. kembali ke menu sebelumnya\n";
                    cout << "Masukkan pilihan (0-2): ";
                    cin >> choice;

                    if (choice == "1") {
                        currentIndexTI = (currentIndexTI + 1) % totaldataTI; // Pindah ke data berikutnya
                    } else if (choice == "2") {
                        currentIndexTI = (currentIndexTI == 0) ? totaldataTI - 1 : currentIndexTI - 1; // Pindah ke data sebelumnya
                    } else if (choice == "0") {
                        exitRequested = true; // Keluar dari iterasi
                    } else {
                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    }
                }
            }
        }

        void tampilDataSI() {
            if (!headSI) {
            cout << "\nTidak ada data yang tersedia.\n";
            return;
            }
        

            bool exitRequested = false;

            while (!exitRequested) {
                treeMahasiswaSI* currSI = mahasiswaSIByIndex(currentIndexSI); // Mengambil data supir pada indeks currentIndexSI
                if (currSI) {                                                                                                                                                                                              
                    cout << "\nNama Mahasiswa: " << currSI->namaMahasiswaSI << endl;
                    cout << "Usia Mahasiswa: " << currSI->umurMahasiswaSI << endl;
                    cout << "Alamat Mahasiswa: " << currSI->alamatMahasiswaSI << endl;
                    cout << "NIM Mahasiswa: " << currSI->nimMahasiswaSI << endl;
                    cout << "IP Mahasiswa: " << currSI->ipMahasiswaSI << endl;
                    cout << endl;

                    string choice;
                    cout << "1. berikutnya\n"; 
                    cout << "2. sebelumnya\n";
                    cout << "0. kembali ke menu sebelumnya\n";
                    cout << "Masukkan pilihan (0-2): ";
                    cin >> choice;

                    if (choice == "1") {
                        currentIndexSI = (currentIndexSI + 1) % totaldataSI; // Pindah ke data supir berikutnya
                    } else if (choice == "2") {
                        currentIndexSI = (currentIndexSI == 0) ? totaldataSI - 1 : currentIndexSI - 1; // Pindah ke data supir sebelumnya
                    } else if (choice == "0") {
                        exitRequested = true; // Keluar dari iterasi
                    } else {
                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    }
                }
            }
        }
    

        void tampilDataPTI() {
            if (!headPTI) {
                cout << "\nTidak ada data yang tersedia.\n";
                return;
            }

            bool exitRequested = false;

            while (!exitRequested) {
                treeMahasiswaPTI* currPTI = mahasiswaPTIByIndex(currentIndexPTI); // Mengambil data pada indeks currentIndexPTI

                if (currPTI) {                                                                                                                                                                                              
                    cout << "\nNama Mahasiswa: " << currPTI->namaMahasiswaPTI << endl;
                    cout << "Usia Mahasiswa: " << currPTI->umurMahasiswaPTI << endl;
                    cout << "Alamat Mahasiswa: " << currPTI->alamatMahasiswaPTI << endl;
                    cout << "NIM Mahasiswa: " << currPTI->nimMahasiswaPTI << endl;
                    cout << "IP Mahasiswa: " << currPTI->ipMahasiswaPTI << endl;
                    cout << endl;

                    string choice;
                    cout << "1. berikutnya\n"; 
                    cout << "2. sebelumnya\n";
                    cout << "0. kembali ke menu sebelumnya\n";
                    cout << "Masukkan pilihan (0-2): ";
                    cin >> choice;

                    if (choice == "1") {
                        currentIndexPTI = (currentIndexPTI + 1) % totaldataPTI; // Pindah ke data berikutnya
                    } else if (choice == "2") {
                        currentIndexPTI = (currentIndexPTI == 0) ? totaldataPTI - 1 : currentIndexPTI - 1; // Pindah ke data sebelumnya
                    } else if (choice == "0") {
                        exitRequested = true; // Keluar dari iterasi
                    } else {
                        cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                    }
                }
            }
        }
    

        void tampilData() {
            while (true) {
                int prodi;
            
                cout << "\nPilih prodi mahasiswa\n";
                cout << "1) Teknik Informatika\n";
                cout << "2) Sistem Informasi\n";
                cout << "3) Pendidikan Teknologi Informasi\n";
                cout << "0) Kembali ke menu utama\n";
                cout << "> ";

                cin >> prodi;
                errorInput(prodi); // Handling error input

                if (prodi == 1) {
                    tampilDataTI();
                } else if (prodi == 2) {
                    tampilDataSI();
                } else if (prodi == 3) {
                    tampilDataPTI();
                } else if (prodi == 0) {
                    cout << "\n>> Kembali ke menu utama\n";
                    break; // Exit loop
                } else {
                    cout << "\n>> Input tidak valid\n";
                    continue; // Invalid input, ask again
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
            dm.tampilData();
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

