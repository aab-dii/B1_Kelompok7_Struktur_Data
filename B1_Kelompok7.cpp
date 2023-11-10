#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int id_pengunjung = -1;

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define MAGENTA_TEXT "\033[1;35m"
#define RESET_TEXT "\033[0m"

// Fungsi untuk mencetak teks dengan warna
void printColoredText(const char *text, const char *colorCode)
{
    std::cout << colorCode << text << RESET_TEXT;
}
// Tempat DATA =================================================================
struct sewa
{
    int id_kendaraan;
    int id_penyewa;
    string nama_kendaraan;
    sewa *next = NULL;
    sewa *prev = NULL;
};

struct kendaraan
{
    int id_kendaraan;
    string nama_kendaraan;
    string jenis_kendaraan;
    int kapasitas;
    int harga_sewa;
    string status_kendaraan;
    kendaraan *next = NULL;
    kendaraan *prev = NULL;
};

struct pakan
{
    string nama_makanan;
    int stok;
    int harga;
    pakan *next = NULL;
    pakan *prev = NULL;
};

struct hewan
{
    string nama;
    string jenis_hewan;
    int umur;
    string habitat;
    string status_konservasi;
    string jenis_makanan;
    hewan *next = NULL;
    hewan *prev = NULL;
};

struct tiket
{
    string jenis_tiket;
    int harga;
    int stok;
    tiket *next = NULL;
    tiket *prev = NULL;
};

struct pengunjung
{
    int id_pengunjung;
    string username;
    string password;
    pengunjung *next = NULL;
    pengunjung *prev = NULL;
};

struct transaksi
{
    string nama_pembeli;
    string jenis_transaksi;
    int nominal_transaksi;
    int jumlah_pembelian;
    time_t waktu_pembelian;
    transaksi *next = NULL;
    transaksi *prev = NULL;
};

// Error Handling Input Integer
int cekInput()
{
    int num;
    while (true)
    {
        cin >> num;
        if (cin.fail()) // memeriksa apakah input gagal
        {
            printColoredText(" ------ Input tidak valid. Masukkan bilangan bulat ------ \n", RED_TEXT);
            cin.clear(); // menghapus status error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (num < 1)
        {
            printColoredText(" ------ Input tidak valid. Masukkan bilangan bulat ------ \n", RED_TEXT);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    return num;
}

// Error handling mengecek apakah username sudah diapakai atau tidak
bool isUsernameExists(pengunjung *head, string &username)
{
    pengunjung *temp = head;
    while (temp != nullptr)
    {
        if (temp->username == username)
        {
            // Username sudah ada
            return true;
        }
        temp = temp->next;
    }
    // Username belum ada
    return false;
}

// Error Handling apakah akun ada atau tidak
bool login(pengunjung *head, string &username, string &password, int &id_pengunjung)
{
    pengunjung *temp = head;
    while (temp != NULL)
    {
        if (temp->username == username && temp->password == password)
        {
            id_pengunjung = temp->id_pengunjung; // Setel ID pengunjung saat ini
            return true;                         // Data pengguna ditemukan, login berhasil
        }
        temp = temp->next;
    }
    return false; // Data pengguna tidak ditemukan, login gagal
}

bool ceksewa(sewa *head, int id_pengunjung)
{
    if (head != NULL)
    {
        sewa *temp = head;
        while (temp != NULL)
        {
            if (temp->id_penyewa == id_pengunjung)
            {
                return true;
            }
            temp = temp->next;
        }
    }
    return false; // Jika tidak ada kecocokan ditemukan
}

bool cekkendaraan(kendaraan *head, int idx)
{
    kendaraan *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    if (temp->status_kendaraan == "Tersedia")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int cekPId(pengunjung *head)
{
    if (head != nullptr)
    {
        int id = head->id_pengunjung;
        id++;
        return id;
    }
    else
    {
        // Node pengunjung kosong, Anda dapat mengembalikan nilai default atau -1
        return 0; // Atau nilai lain yang sesuai sebagai penanda kesalahan
    }
}

int cekKId(kendaraan *head)
{
    if (head == nullptr) // jika linked list kosong
    {
        return 1; // kembalikan nilai 1
    }
    int maxId = 0; // Inisialisasi nilai maksimum
    kendaraan *current = head;

    while (current != nullptr)
    {
        if (current->id_kendaraan > maxId)
        {
            maxId = current->id_kendaraan;
            maxId++; // Perbarui nilai maksimum jika ID yang ditemukan lebih besar
        }
        current = current->next;
    }
    return maxId;
}

int lengthh(hewan *head)
{
    int panjang = 0;     // Inisialisasi variabel lokal panjang dengan nilai awal 0, yang akan digunakan untuk menyimpan jumlah node.
    hewan *temp = head;  // Inisialisasi pointer temp dengan alamat node pertama dari linked list
    while (temp != NULL) // jika temp tidak kosong
    {
        temp = temp->next; // temp berpindah ke node selanjutnya
        panjang++;         // increment panjang
    }
    return panjang; // mengembalikan nilai panjang
}
int lengthpk(pakan *head)
{
    int panjang = 0;     // Inisialisasi variabel lokal panjang dengan nilai awal 0, yang akan digunakan untuk menyimpan jumlah node.
    pakan *temp = head;  // Inisialisasi pointer temp dengan alamat node pertama dari linked list
    while (temp != NULL) // jika temp tidak kosong
    {
        temp = temp->next; // temp berpindah ke node selanjutnya
        panjang++;         // increment panjang
    }
    return panjang; // mengembalikan nilai panjang
}
int lengtht(tiket *head)
{
    int panjang = 0;     // Inisialisasi variabel lokal panjang dengan nilai awal 0, yang akan digunakan untuk menyimpan jumlah node.
    tiket *temp = head;  // Inisialisasi pointer temp dengan alamat node pertama dari linked list
    while (temp != NULL) // jika temp tidak kosong
    {
        temp = temp->next; // temp berpindah ke node selanjutnya
        panjang++;         // increment panjang
    }
    return panjang; // mengembalikan nilai panjang
}

int lengthk(kendaraan *head)
{
    int panjang = 0;        // Inisialisasi variabel lokal panjang dengan nilai awal 0, yang akan digunakan untuk menyimpan jumlah node.
    kendaraan *temp = head; // Inisialisasi pointer temp dengan alamat node pertama dari linked list
    while (temp != NULL)    // jika temp tidak kosong
    {
        temp = temp->next; // temp berpindah ke node selanjutnya
        panjang++;         // increment panjang
    }
    return panjang; // mengembalikan nilai panjang
}

// Error handling apakah data kosong atau tidak
bool isEmptyk(kendaraan *head, kendaraan *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true; // Data Kosong
    }
    return false; // Data tidak kosong
}

bool isEmptypk(pakan *head, pakan *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}

bool isEmptyh(hewan *head, hewan *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}

bool isEmptyt(tiket *head, tiket *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}

bool isEmptyp(pengunjung *head, pengunjung *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}

bool isEmptyb(transaksi *head, transaksi *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}

bool isEmptys(sewa *head, sewa *tail)
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}
// Fungsi untuk membaca file csv masing masing data=============
void simpanCSVk(kendaraan *head, string &filename)
{
    ofstream file(filename); // Output file stream, membuat dan menulis kedalam file

    if (!file) // mengecek apakah file bisa dibuka atau tidak
    {
        cout << "--------- Gagal menyimpan file ---------" << endl;
        return;
    }

    kendaraan *current = head; // inisialisasi pointer current dengan alamat awal linked list kendaraan
    while (current)            // iterasi current selama tidak null
    {
        file << current->id_kendaraan << "," << current->nama_kendaraan << "," << current->jenis_kendaraan << "," << current->kapasitas << "," << current->harga_sewa << "," << current->status_kendaraan << "\n";
        current = current->next;
    } // menulis kedalam file
    file.close();
}

void simpanCSVpk(pakan *head, string &filename, string username)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "--------- Gagal menyimpan file ---------" << endl;
        return;
    }

    pakan *current = head;
    while (current)
    {
        file << current->nama_makanan << "," << current->stok << "," << current->harga << "\n";
        current = current->next;
    }
    if (username == "admin")
    {
        printColoredText("---------- Data berhasil disimpan dalam file ---------\n", GREEN_TEXT);
    }
    else
    {
        printColoredText("--------- Pembelian Pakan Berhasil ---------- \n", GREEN_TEXT);
    }
    file.close();
}

void simpanCSVh(hewan *head, string &filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "--------- Gagal menyimpan file ---------" << endl;
        return;
    }

    hewan *current = head;
    while (current)
    {
        file << current->nama << "," << current->jenis_hewan << "," << current->umur << "," << current->habitat << "," << current->status_konservasi << "," << current->jenis_makanan << "\n";
        current = current->next;
    }
    printColoredText("---------- Data berhasil disimpan dalam file ---------\n", GREEN_TEXT);
    file.close();
}

void simpanCSVt(tiket *head, string &filename, string username)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "--------- Gagal menyimpan file ---------" << endl;
        return;
    }

    tiket *current = head;
    while (current)
    {
        file << current->jenis_tiket << "," << current->harga << "," << current->stok << "\n";
        current = current->next;
    }
    if (username == "admin")
    {
        printColoredText("---------- Data berhasil disimpan dalam file ---------\n", GREEN_TEXT);
    }
    else
    {
        printColoredText("--------- Pembelian Tiket Berhasil ----------\n", GREEN_TEXT);
    }
    file.close();
}

void simpanCSVp(pengunjung *head, string &filename)
{
    ofstream file(filename);

    if (!file)
    {
        printColoredText("--------- Registrasi Gagal ---------\n", RED_TEXT);
        return;
    }

    pengunjung *current = head;
    while (current)
    {
        file << current->id_pengunjung << "," << current->username << "," << current->password << "\n";
        current = current->next;
    }
    printColoredText("---------- Registrasi Berhasil ---------\n", GREEN_TEXT);
    file.close();
}

void simpanCSVb(transaksi *head, string &filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "--------- Pembelian Gagal ---------" << endl;
        return;
    }

    transaksi *current = head;
    while (current)
    {
        file << current->nama_pembeli << "," << current->jenis_transaksi << "," << current->nominal_transaksi << "," << current->jumlah_pembelian << ","
             << to_string(current->waktu_pembelian) << "\n";
        current = current->next;
    }
    file.close();
}

void simpanCSVs(sewa *head, string &filename)
{
    ofstream file(filename);

    if (!file)
    {
        cout << "--------- Sewa Gagal ---------" << endl;
        return;
    }

    sewa *current = head;
    while (current)
    {
        file << current->id_kendaraan << "," << current->id_penyewa << "," << current->nama_kendaraan << "\n";
        current = current->next;
    }

    file.close();
}

// Fungsi Membaca File CSV masing masing data
void bacaCSVh(hewan **head, hewan **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    hewan *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        hewan *data_baru = new hewan;
        istringstream ss(line);

        getline(ss, data_baru->nama, ',');
        getline(ss, data_baru->jenis_hewan, ',');
        ss >> data_baru->umur;
        ss.ignore();
        getline(ss, data_baru->habitat, ',');
        getline(ss, data_baru->status_konservasi, ',');
        getline(ss, data_baru->jenis_makanan);

        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // set temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

void bacaCSVs(sewa **head, sewa **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    sewa *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        sewa *data_baru = new sewa;
        istringstream ss(line);

        ss >> data_baru->id_kendaraan;
        ss.ignore();
        ss >> data_baru->id_penyewa;
        ss.ignore();
        getline(ss, data_baru->nama_kendaraan);
        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // Geser temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

void bacaCSVk(kendaraan **head, kendaraan **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    kendaraan *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        kendaraan *data_baru = new kendaraan;
        istringstream ss(line);

        ss >> data_baru->id_kendaraan;
        ss.ignore();
        getline(ss, data_baru->nama_kendaraan, ',');
        getline(ss, data_baru->jenis_kendaraan, ',');
        ss >> data_baru->kapasitas;
        ss.ignore();
        ss >> data_baru->harga_sewa;
        ss.ignore();
        getline(ss, data_baru->status_kendaraan);

        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // Geser temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

void bacaCSVpk(pakan **head, pakan **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    pakan *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        pakan *data_baru = new pakan;
        istringstream ss(line);

        getline(ss, data_baru->nama_makanan, ',');
        ss >> data_baru->stok;
        ss.ignore();
        ss >> data_baru->harga;
        ss.ignore();

        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // Geser temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

void bacaCSVt(tiket **head, tiket **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    tiket *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        tiket *data_baru = new tiket;
        istringstream ss(line);

        getline(ss, data_baru->jenis_tiket, ',');
        ss >> data_baru->harga;
        ss.ignore();
        ss >> data_baru->stok;
        ss.ignore();

        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // Geser temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

void bacaCSVp(pengunjung **head, pengunjung **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    pengunjung *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        pengunjung *data_baru = new pengunjung;
        istringstream ss(line);

        ss >> data_baru->id_pengunjung;
        ss.ignore();
        getline(ss, data_baru->username, ',');
        getline(ss, data_baru->password);

        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // Geser temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

void bacaCSVb(transaksi **head, transaksi **tail, const string &filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "--------- Gagal membaca file ---------" << endl;
        return;
    }

    string line;
    transaksi *temp = nullptr; // Variabel bantu

    while (getline(file, line))
    {
        transaksi *data_baru = new transaksi;
        istringstream ss(line);

        getline(ss, data_baru->nama_pembeli, ',');
        getline(ss, data_baru->jenis_transaksi, ',');
        ss >> data_baru->nominal_transaksi;
        ss.ignore();
        ss >> data_baru->jumlah_pembelian;
        ss.ignore();
        string waktu_pembelian_str;
        if (getline(ss, waktu_pembelian_str))
        {
            // Konversi string waktu kembali menjadi time_t
            data_baru->waktu_pembelian = std::stoll(waktu_pembelian_str);
        }

        data_baru->next = NULL;

        if (*head == NULL)
        {
            *head = data_baru;
            data_baru->prev = NULL; // Set prev dari elemen baru ke nullptr
            *tail = data_baru;      // elemen baru juga menjadi tail karena ini elemen pertama
            temp = data_baru;       // Set temp ke elemen baru
        }
        else
        {
            // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
            temp->next = data_baru;
            data_baru->prev = temp;
            temp = data_baru;  // Geser temp ke elemen baru
            *tail = data_baru; // Set tail ke elemen baru
        }
    }
    file.close();
}

// Fungsi Menampilkan detail dari masing masing data
void tampildetailh(hewan *head)
{
    // Cetakan informasi hewan
    cout << " |Nama Hewan       : " << head->nama << endl;
    cout << "  |Jenis Hewan      : " << head->jenis_hewan << endl;
    cout << "  |Umur             : " << head->umur << " tahun" << endl;
    cout << "  |Habitat          : " << head->habitat << endl;
    cout << "  |Status Konservasi: " << head->status_konservasi << endl;
    cout << "  |Jenis Makanan    : " << head->jenis_makanan << endl;
    cout << "---------------------------------------" << endl;
}

void tampildetailk(kendaraan *head, string username)
{
    // Cetakan informasi kendaraan
    cout << " |Nama Kendaraan   : " << head->nama_kendaraan << endl;
    cout << "  |Jenis Kendaraan  : " << head->jenis_kendaraan << endl;
    cout << "  |Kapasitas        : " << head->kapasitas << endl;
    cout << "  |Harga Sewa       : " << head->harga_sewa << endl;
    cout << "  |Status Kendaraan : " << head->status_kendaraan << endl;
    cout << "---------------------------------------" << endl;
}

void tampildetails(sewa *sewahead, pengunjung *pengunjunghead, kendaraan *kendaraanhead, const string &username)
{
    sewa *stemp = sewahead;
    int i = 1; // Untuk nomor urut

    while (stemp != nullptr)
    {
        kendaraan *ktemp = kendaraanhead;

        while (ktemp != nullptr)
        {
            if (stemp->id_kendaraan == ktemp->id_kendaraan)
            {
                pengunjung *ptemp = pengunjunghead;
                while (ptemp != nullptr)
                {
                    if (stemp->id_penyewa == ptemp->id_pengunjung && ptemp->username == username)
                    {
                        cout << i << ". |Nama Penyewa     : " << ptemp->username << endl;
                        cout << "  |Nama Kendaraan   : " << ktemp->nama_kendaraan << endl;
                        cout << "  |Harga Sewa       : " << ktemp->harga_sewa << endl;
                        cout << "  |Status Kendaraan : " << ktemp->status_kendaraan << endl;
                        cout << "---------------------------------------" << endl;
                        i++;
                    }
                    ptemp = ptemp->next;
                }
            }
            ktemp = ktemp->next;
        }

        stemp = stemp->next;
    }
}

void tampildetailpk(pakan *head)
{
    // Cetakan informasi hewan
    cout << " |Nama Makanan : " << head->nama_makanan << endl;
    cout << "  |Stok         : " << head->stok << endl;
    cout << "  |Harga        : " << head->harga << endl;
    cout << "---------------------------------------" << endl;
}

void tampildetailt(tiket *head)
{
    // Cetakan informasi hewan
    cout << " |Jenis Tiket  : " << head->jenis_tiket << endl;
    cout << "  |Harga        : " << head->harga << endl;
    cout << "  |Stok         : " << head->stok << endl;
    cout << "---------------------------------------" << endl;
}

void tampildetailb(transaksi *head)
{
    // Cetakan informasi hewan
    cout << " |Nama Pembeli     : " << head->nama_pembeli << endl;
    cout << "  |Jenis Pembelian  : " << head->jenis_transaksi << endl;
    cout << "  |Harga Pembelian  : " << head->nominal_transaksi << endl;
    cout << "  |Jumlah Pembelian : " << head->jumlah_pembelian << endl;

    // Pisahkan dengan garis pembatas
    cout << "---------------------------------------" << endl;
}

void tampilHeads(sewa *head, sewa *tail, pengunjung *pengunjunghead, kendaraan *kendaraanhead, const string &username)
{
    int i = 0; // Reset nomor urut ke 0
    if (isEmptys(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        sewa *temp = head;
        while (temp) // Periksa jika temp bukan NULL
        {
            i++;
            cout << i << ". ";
            tampildetails(temp, pengunjunghead, kendaraanhead, username);
            temp = temp->next;
        }
    }
}

void tampilHeadh(hewan *head, hewan *tail)
{
    int i = 0; // Reset nomor urut ke 0
    if (isEmptyh(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        hewan *temp = head;
        while (temp) // Periksa jika temp bukan NULL
        {
            i++;
            cout << i;
            tampildetailh(temp);
            temp = temp->next;
        }
        while (temp)
        {
            temp = temp->prev;
        }
    }
}

void tampilHeadk(kendaraan *head, kendaraan *tail, string username)
{
    int i = 0; // Reset nomor urut ke 0
    if (isEmptyk(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        kendaraan *temp = head;
        while (temp) // Periksa jika temp bukan NULL
        {
            i++;
            cout << i;
            tampildetailk(temp, username);
            temp = temp->next;
        }
        while (temp)
        {
            temp = temp->prev;
        }
    }
}

void tampilHeadpk(pakan *head, pakan *tail)
{
    int i = 0; // Reset nomor urut ke 0
    if (isEmptypk(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        pakan *temp = head;
        while (temp) // Periksa jika temp bukan NULL
        {
            i++;
            cout << i;
            tampildetailpk(temp);
            temp = temp->next;
        }
        while (temp)
        {
            temp = temp->prev;
        }
    }
}

void tampilHeadt(tiket *head, tiket *tail)
{
    int i = 0; // Reset nomor urut ke 0
    if (isEmptyt(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        tiket *temp = head;
        while (temp) // Periksa jika temp bukan NULL
        {
            i++;
            cout << i;
            tampildetailt(temp);
            temp = temp->next;
        }
        while (temp)
        {
            temp = temp->prev;
        }
    }
}

void tampilHeadb(transaksi *head, transaksi *tail)
{
    int i = 0; // Reset nomor urut ke 0
    if (isEmptyb(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        transaksi *temp = head;
        while (temp) // Periksa jika temp bukan NULL
        {
            i++;
            cout << i;
            tampildetailb(temp);
            temp = temp->next;
        }
        while (temp)
        {
            temp = temp->prev;
        }
    }
}

void tampilTailh(hewan *head, hewan *tail)
{
    int i = 0;
    if (isEmptyh(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        hewan *temp = tail;
        while (head)
        {
            temp = head;
            head = head->next;
        }
        while (temp)
        {
            i++;
            cout << i;
            tampildetailh(temp);
            temp = temp->prev;
        }
    }
}

void tampilTailk(kendaraan *head, kendaraan *tail, string username)
{
    int i = 0;
    if (isEmptyk(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        kendaraan *temp = tail;
        while (head)
        {
            temp = head;
            head = head->next;
        }
        while (temp)
        {
            i++;
            cout << i;
            tampildetailk(temp, username);
            temp = temp->prev;
        }
    }
}

void tampilTailpk(pakan *head, pakan *tail)
{
    int i = 0;
    if (isEmptypk(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        pakan *temp = tail;
        while (head)
        {
            temp = head;
            head = head->next;
        }
        while (temp)
        {
            i++;
            cout << i;
            tampildetailpk(temp);
            temp = temp->prev;
        }
    }
}

void tampilTailt(tiket *head, tiket *tail)
{
    int i = 0;
    if (isEmptyt(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        tiket *temp = tail;
        while (head)
        {
            temp = head;
            head = head->next;
        }
        while (temp)
        {
            i++;
            cout << i;
            tampildetailt(temp);
            temp = temp->prev;
        }
    }
}

void tampilTailb(transaksi *head, transaksi *tail)
{
    int i = 0;
    if (isEmptyb(head, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        transaksi *temp = tail;
        while (head)
        {
            temp = head;
            head = head->next;
        }
        while (temp)
        {
            i++;
            cout << i;
            tampildetailb(temp);
            temp = temp->prev;
        }
    }
}

void tampilKendaraanDisewa(sewa *sewahead, sewa *tail, pengunjung *pengunjunghead, kendaraan *kendaraanhead)
{
    sewa *stemp = sewahead;
    int i = 1; // Untuk nomor urut
    if (isEmptys(sewahead, tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
    }
    else
    {
        while (stemp != nullptr)
        {
            kendaraan *ktemp = kendaraanhead;

            while (ktemp != nullptr)
            {
                if (stemp->id_kendaraan == ktemp->id_kendaraan)
                {
                    pengunjung *ptemp = pengunjunghead;
                    while (ptemp != nullptr)
                    {
                        if (stemp->id_penyewa == ptemp->id_pengunjung)
                        {
                            cout << i << ". |Nama Penyewa    : " << ptemp->username << endl;
                            cout << "   |Nama Kendaraan  : " << ktemp->nama_kendaraan << endl;
                            cout << "   |Harga Sewa      : " << ktemp->harga_sewa << endl;
                            cout << "---------------------------------------" << endl;
                            i++;
                        }
                        ptemp = ptemp->next;
                    }
                }
                ktemp = ktemp->next;
            }

            stemp = stemp->next;
        }
    }
}

// Fungsi menambahkan data baru
kendaraan *newkendaraan(int &nextIDk)
{
    kendaraan *data_baru = new kendaraan;
    cout << "Masukkan Data !" << endl;
    do
    {
        cout << "Masukkan Nama Kendaraan : ";
        cin.ignore();
        fflush(stdin);
        getline(cin, data_baru->nama_kendaraan);
        if (data_baru->nama_kendaraan.empty())
        {
            cout << "Nama Hewan tidak boleh kosong. Silakan coba lagi." << endl;
        }
    } while (data_baru->nama_kendaraan.empty());
    string jeniskendaraan;
    do
    {
        cout << "Pilih Jenis Kendaraan : " << endl;
        cout << "1. Bus" << endl;
        cout << "2. Minibus " << endl;
        cout << "Masukkan Jenis Kendaraan : ";
        fflush(stdin);
        getline(cin, jeniskendaraan);
        if (jeniskendaraan == "1")
        {
            data_baru->jenis_kendaraan = "Bus";
        }
        else if (jeniskendaraan == "2")
        {
            data_baru->jenis_kendaraan = "Minibus";
        }
        else
        {
            cout << "Pilihan jenis kendaraan tidak valid. Silakan coba lagi." << endl;
        }
    } while (jeniskendaraan != "1" && jeniskendaraan != "2");

    cout << "Masukkan Kapasitas Kendaraan : ";
    data_baru->kapasitas = cekInput();

    cout << "Masukkan Harga Sewa : ";
    data_baru->harga_sewa = cekInput();

    data_baru->status_kendaraan = "Tersedia";
    data_baru->id_kendaraan = nextIDk;
    nextIDk++;
    return data_baru;
}

pakan *newpakan()
{
    pakan *data_baru = new pakan;
    cout << "Masukkan Data!" << endl;
    do
    {
        cout << "Masukkan Nama Pakan : ";
        fflush(stdin);
        getline(cin, data_baru->nama_makanan);
        if (data_baru->nama_makanan.empty())
        {
            cout << "Nama Pakan tidak boleh kosong!" << endl;
        }
    } while (data_baru->nama_makanan.empty());

    cout << "Masukkan Stok : ";
    data_baru->stok = cekInput();

    cout << "Masukkan harga : ";
    data_baru->harga = cekInput();
    return data_baru;
}

hewan *newhewan()
{
    hewan *data_baru = new hewan;
    cout << "Masukkan Data!" << endl;
    do
    {
        cout << "Masukkan Nama Hewan : "; // Membersihkan newline dari buffer sebelumnya
        fflush(stdin);
        getline(cin, data_baru->nama);

        // Periksa apakah nama kosong
        if (data_baru->nama.empty())
        {
            cout << "Nama Hewan tidak boleh kosong. Silakan coba lagi." << endl;
        }
    } while (data_baru->nama.empty());
    string jenisHewan;
    do
    {
        cout << "Pilih Jenis Hewan: " << endl;
        cout << "1. Mamalia" << endl;
        cout << "2. Reptil" << endl;
        cout << "3. Burung" << endl;
        cout << "Masukkan jenis hewan: ";
        fflush(stdin);
        getline(cin, jenisHewan);

        if (jenisHewan == "1")
        {
            data_baru->jenis_hewan = "Mamalia";
        }
        else if (jenisHewan == "2")
        {
            data_baru->jenis_hewan = "Reptil";
        }
        else if (jenisHewan == "3")
        {
            data_baru->jenis_hewan = "Burung";
        }
        else
        {
            cout << "Pilihan jenis hewan tidak valid. Silakan coba lagi." << endl;
        }
    } while (jenisHewan != "1" && jenisHewan != "2" && jenisHewan != "3");

    cout << "Masukkan Umur Hewan: ";
    data_baru->umur = cekInput();

    string habitatHewan;
    do
    {
        cout << "Pilih Habitat Hewan: " << endl;
        cout << "1. Savana" << endl;
        cout << "2. Hutan" << endl;
        cout << "3. Air" << endl;
        cout << "4. Tundra" << endl;
        cout << "Masukkan nomor habitat hewan: ";
        fflush(stdin);
        getline(cin, habitatHewan);

        if (habitatHewan == "1")
        {
            data_baru->habitat = "Savana";
        }
        else if (habitatHewan == "2")
        {
            data_baru->habitat = "Hutan";
        }
        else if (habitatHewan == "3")
        {
            data_baru->habitat = "Air";
        }
        else if (habitatHewan == "4")
        {
            data_baru->habitat = "Tundra";
        }
        else
        {
            cout << "Pilihan habitat hewan tidak valid. Silakan coba lagi." << endl;
        }
    } while (habitatHewan != "1" && habitatHewan != "2" && habitatHewan != "3" && habitatHewan != "4");

    string statusKonservasi;
    do
    {
        cout << "Pilih Status Konservasi Hewan: " << endl;
        cout << "1. Punah" << endl;
        cout << "2. Kritis" << endl;
        cout << "3. Rentan" << endl;
        cout << "4. Hampir Terancam" << endl;
        cout << "5. Tidak Terancam" << endl;
        cout << "Masukkan nomor status konservasi: ";
        fflush(stdin);
        getline(cin, statusKonservasi);

        if (statusKonservasi == "1")
        {
            data_baru->status_konservasi = "Punah";
        }
        else if (statusKonservasi == "2")
        {
            data_baru->status_konservasi = "Kritis";
        }
        else if (statusKonservasi == "3")
        {
            data_baru->status_konservasi = "Rentan";
        }
        else if (statusKonservasi == "4")
        {
            data_baru->status_konservasi = "Hampir Terancam";
        }
        else if (statusKonservasi == "5")
        {
            data_baru->status_konservasi = "Tidak Terancam";
        }
        else
        {
            cout << "Pilihan status konservasi tidak valid. Silakan coba lagi." << endl;
        }
    } while (statusKonservasi != "1" && statusKonservasi != "2" && statusKonservasi != "3" && statusKonservasi != "4" && statusKonservasi != "5");

    string jenisMakanan;
    do
    {
        cout << "Pilih Kategori Makanan Hewan: " << endl;
        cout << "1. Omnivora" << endl;
        cout << "2. Karnivora" << endl;
        cout << "3. Herbivora" << endl;
        cout << "4. Insectivora" << endl;
        cout << "Masukkan nomor jenis makanan: ";
        getline(cin, jenisMakanan);

        if (jenisMakanan == "1")
        {
            data_baru->jenis_makanan = "Omnivora";
        }
        else if (jenisMakanan == "2")
        {
            data_baru->jenis_makanan = "Karnivora";
        }
        else if (jenisMakanan == "3")
        {
            data_baru->jenis_makanan = "Herbivora";
        }
        else if (jenisMakanan == "4")
        {
            data_baru->jenis_makanan = "Insectivora";
        }
        else
        {
            cout << "Pilihan jenis makanan tidak valid. Silakan coba lagi." << endl;
        }
    } while (jenisMakanan != "1" && jenisMakanan != "2" && jenisMakanan != "3" && jenisMakanan != "4");
    return data_baru;
}

tiket *newtiket()
{
    tiket *data_baru = new tiket;
    string jenisTiket;
    do
    {
        cout << "Masukkan Jenis Tiket" << endl;
        cout << "1. Anak " << endl;
        cout << "2. Dewasa " << endl;
        cout << ">> ";
        cin >> jenisTiket;
        if (jenisTiket == "1")
        {
            data_baru->jenis_tiket = "Anak";
        }
        else if (jenisTiket == "2")
        {
            data_baru->jenis_tiket = "Dewasa";
        }
        else
        {
            cout << "Pilihan jenis tiket tidak valid." << endl;
        }
    } while (jenisTiket != "1" && jenisTiket != "2");

    cout << "Masukkan Harga Tiket: ";
    data_baru->harga = cekInput();
    cout << "Masukkan Stok Tiket: ";
    data_baru->stok = cekInput();
    return data_baru;
}

pengunjung *newpengunjung(pengunjung *head, int &nextIDp)
{
    pengunjung *data_baru = new pengunjung;
    cout << "Masukkan Username: ";
    cin >> data_baru->username;

    // Memeriksa apakah username sudah ada
    if (isUsernameExists(head, data_baru->username))
    {
        cout << "Username sudah digunakan. Silakan pilih username lain." << endl;
        delete data_baru;
        return nullptr;
    }

    cout << "Masukkan Password: ";
    cin >> data_baru->password;
    data_baru->id_pengunjung = nextIDp;
    nextIDp++;

    return data_baru;
}

// Fungsi menambahkan data diawal
void addFirsth(hewan **head, hewan **tail)
{
    hewan *nodeBaru = newhewan();
    if (isEmptyh(*head, *tail))
    {
        *head = nodeBaru;
        *tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = *head;
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
}

void addFirstk(kendaraan **head, kendaraan **tail, int &nextIDk)
{
    kendaraan *nodeBaru = newkendaraan(nextIDk);
    if (isEmptyk(*head, *tail))
    {
        *head = nodeBaru;
        *tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = *head;
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
}

void addFirstpk(pakan **head, pakan **tail)
{
    pakan *nodeBaru = newpakan();
    if (isEmptypk(*head, *tail))
    {
        *head = nodeBaru;
        *tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = *head;
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
}

void addFirstt(tiket **head, tiket **tail)
{
    tiket *nodeBaru = newtiket();
    if (isEmptyt(*head, *tail))
    {
        *head = nodeBaru;
        *tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = *head;
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
}

void addFirstp(pengunjung **head, pengunjung **tail, int nextIDp, string filename)
{
    pengunjung *nodeBaru = newpengunjung(*head, nextIDp);

    if (nodeBaru == nullptr)
    {

        printColoredText("----- Registrasi gagal -----\n", RED_TEXT);
        return;
    }

    if (isEmptyp(*head, *tail))
    {
        *head = nodeBaru;
        *tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = *head;
        (*head)->prev = nodeBaru;
        *head = nodeBaru;
    }
    simpanCSVp(*head, filename);
}

void addLasth(hewan **head, hewan **tail)
{
    hewan *data_baru = newhewan();
    (*tail)->next = data_baru;
    data_baru->prev = *tail;
    *tail = data_baru;
}

sewa *newsewa(int id_kendaraan, int id_penyewa, string nama)
{
    sewa *data_baru = new sewa;
    data_baru->id_kendaraan = id_kendaraan;
    data_baru->id_penyewa = id_penyewa;
    data_baru->nama_kendaraan = nama;
    return data_baru;
}

void addLasts(sewa **head, sewa **tail, int idk, int idp, string nama)
{
    sewa *data_baru = newsewa(idk, idp, nama);
    if (isEmptys(*head, *tail))
    {
        // Jika linked list kosong, maka node baru menjadi head dan tail
        *head = data_baru;
        *tail = data_baru;
    }
    else
    {
        // Jika linked list tidak kosong, tambahkan node baru ke tail
        (*tail)->next = data_baru;
        data_baru->prev = *tail;
        *tail = data_baru;
    }
}

void addLastk(kendaraan **head, kendaraan **tail, int nextIDk)
{
    kendaraan *data_baru = newkendaraan(nextIDk);
    (*tail)->next = data_baru;
    data_baru->prev = *tail;
    *tail = data_baru;
}

void addLastpk(pakan **head, pakan **tail)
{
    pakan *data_baru = newpakan();
    (*tail)->next = data_baru;
    data_baru->prev = *tail;
    *tail = data_baru;
}

void addLastt(tiket **head, tiket **tail)
{
    tiket *data_baru = newtiket();
    (*tail)->next = data_baru;
    data_baru->prev = *tail;
    *tail = data_baru;
}

void addSpesifich(hewan **head, hewan **tail, string filename)
{
    int count = 0;
    hewan *temp = *head;
    if (isEmptyh(*head, *tail))
    {
        addFirsth(head, tail);
    }
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << "Ingin Tambah pada data ke berapa :" << endl;
        tampilHeadh(*head, *tail);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        if (idx > 0 && idx <= count)
        {
            if (idx == 1)
            {
                if (count > 1)
                {
                    addFirsth(head, tail);
                }
                else if (count == 1)
                {
                    string pilih;
                    do
                    {
                        cout << "====================" << endl;
                        cout << "|  [1]. Add First  |" << endl;
                        cout << "|  [2]. Add Last   |" << endl;
                        cout << "====================" << endl;
                        cout << ">> ";
                        fflush(stdin);
                        getline(cin, pilih);
                        if (pilih == "1")
                        {
                            addFirsth(head, tail);
                        }
                        else if (pilih == "2")
                        {
                            addLasth(head, tail);
                        }
                        else
                        {
                            printColoredText("---------- Pilihan Tidak Ada ---------\n", RED_TEXT);
                            return;
                        }
                    } while (pilih != "1" && pilih != "2");
                }
            }
            else if (idx == count)
            {
                addLasth(head, tail);
            }
            else
            {
                hewan *temp = *head;
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->next;
                }

                hewan *data_baru = newhewan();
                data_baru->prev = temp->prev;
                data_baru->next = temp;
                temp->prev->next = data_baru;
                temp->prev = data_baru;
            }
            printColoredText("---------- Data Berhasil Ditambahkan ---------\n", GREEN_TEXT);
            simpanCSVh(*head, filename);
        }
        else if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menambahkan Data ---------\n", RED_TEXT);
        }
    }
}

void addSpesifick(kendaraan **head, kendaraan **tail, string username, int nextIDk, string filename)
{
    int count = 0;
    kendaraan *tempCount = *head;
    if (isEmptyk(*head, *tail))
    {
        addFirstk(head, tail, nextIDk);
    }
    else
    {
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        cout << count << endl;
        cout << "Ingin Tambah pada data ke berapa :" << endl;
        tampilHeadk(*head, *tail, username);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        if (idx > 0 && idx <= count)
        {
            if (idx == 1)
            {
                if (count > 1)
                {
                    addFirstk(head, tail, nextIDk);
                }
                else if (count == 1)
                {
                    string pilih;
                    do
                    {
                        cout << "====================" << endl;
                        cout << "|  [1]. Add First  |" << endl;
                        cout << "|  [2]. Add Last   |" << endl;
                        cout << "====================" << endl;
                        cout << ">> ";
                        fflush(stdin);
                        getline(cin, pilih);
                        if (pilih == "1")
                        {
                            addFirstk(head, tail, nextIDk);
                        }
                        else if (pilih == "2")
                        {
                            addLastk(head, tail, nextIDk);
                        }
                        else
                        {
                            printColoredText("---------- Pilihan Tidak Ada ---------\n", RED_TEXT);
                        }
                    } while (pilih != "1" && pilih != "2");
                }
            }
            else if (idx == count)
            {
                addLastk(head, tail, nextIDk);
            }
            else
            {
                kendaraan *temp = *head;
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->next;
                }
                kendaraan *data_baru = newkendaraan(nextIDk);
                data_baru->prev = temp->prev;
                data_baru->next = temp;
                temp->prev->next = data_baru;
                temp->prev = data_baru;
            }
            printColoredText("---------- Data Berhasil Ditambahkan ---------\n", GREEN_TEXT);
            simpanCSVk(*head, filename);
        }
        else if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menambahkan Data ---------\n", RED_TEXT);
            return;
        }
    }
}

void addSpesificpk(pakan **head, pakan **tail, string filename, string username)
{
    int count = 0;
    pakan *tempCount = *head;
    if (isEmptypk(*head, *tail))
    {
        addFirstpk(head, tail);
    }
    else
    {
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        cout << count << endl;
        cout << "Ingin Tambah pada data ke berapa :" << endl;
        tampilHeadpk(*head, *tail);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        if (idx > 0 && idx <= count)
        {
            if (idx == 1)
            {
                if (count > 1)
                {
                    addFirstpk(head, tail);
                }
                else if (count == 1)
                {
                    string pilih;
                    do
                    {
                        cout << "====================" << endl;
                        cout << "|  [1]. Add First  |" << endl;
                        cout << "|  [2]. Add Last   |" << endl;
                        cout << "====================" << endl;
                        cout << ">> ";
                        fflush(stdin);
                        getline(cin, pilih);
                        if (pilih == "1")
                        {
                            addFirstpk(head, tail);
                        }
                        else if (pilih == "2")
                        {
                            addLastpk(head, tail);
                        }
                        else
                        {
                            printColoredText("---------- Pilihan Tidak Ada ---------\n", RED_TEXT);
                        }
                    } while (pilih != "1" && pilih != "2");
                }
            }
            else if (idx == count)
            {
                addLastpk(head, tail);
            }
            else
            {
                pakan *temp = *head;
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->next;
                }
                pakan *data_baru = newpakan();
                data_baru->prev = temp->prev;
                data_baru->next = temp;
                temp->prev->next = data_baru;
                temp->prev = data_baru;
            }
            printColoredText("---------- Data Berhasil Ditambahkan ---------\n", GREEN_TEXT);
            simpanCSVpk(*head, filename, username);
        }
        else if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menambahkan Data ---------\n", RED_TEXT);
        }
    }
}

void addSpesifict(tiket **head, tiket **tail, string filename3, string username)
{
    int count = 0;
    tiket *tempCount = *head;
    if (isEmptyt(*head, *tail))
    {
        addFirstt(head, tail);
    }
    else
    {
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        cout << count << endl;
        cout << "Ingin Tambah pada data ke berapa :" << endl;
        tampilHeadt(*head, *tail);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        if (idx > 0 && idx <= count)
        {
            if (idx == 1)
            {
                if (count > 1)
                {
                    addFirstt(head, tail);
                }
                else if (count == 1)
                {
                    string pilih;
                    do
                    {
                        cout << "====================" << endl;
                        cout << "|  [1]. Add First  |" << endl;
                        cout << "|  [2]. Add Last   |" << endl;
                        cout << "====================" << endl;
                        cout << ">> ";
                        fflush(stdin);
                        getline(cin, pilih);
                        if (pilih == "1")
                        {
                            addFirstt(head, tail);
                        }
                        else if (pilih == "2")
                        {
                            addLastt(head, tail);
                        }
                        else
                        {
                            printColoredText("---------- Pilihan Tidak Ada ---------\n", RED_TEXT);
                        }
                    } while (pilih != "1" && pilih != "2");
                }
            }
            else if (idx == count)
            {
                addLastt(head, tail);
            }
            else if (idx <= 0 || idx > count)
            {
                printColoredText("-------Tidak Dapat Menambahkan Dataasil ---------\n", RED_TEXT);
            }
            else
            {
                tiket *temp = *head;
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->next;
                }
                tiket *data_baru = newtiket();
                data_baru->prev = temp->prev;
                data_baru->next = temp;
                temp->prev->next = data_baru;
                temp->prev = data_baru;
            }
            printColoredText("---------- Data Berhasil Ditambahkan ---------\n", GREEN_TEXT);
            simpanCSVt(*head, filename3, username);
        }
        else if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menambahkan Data ---------\n", RED_TEXT);
        }
    }
}

void updateDatah(hewan *head, hewan *tail, string filename)
{
    int panjang = lengthh(head);
    cout << "Pilih data yang ingin dubah :" << endl;
    tampilHeadh(head, tail);
    cout << "Masukkan Pilihan :";
    int idx = cekInput();
    if (idx > panjang)
    {
        printColoredText("---------- Tidak Dapat Mengupdate Data ---------\n", RED_TEXT);
        return;
    }
    hewan *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    cout << "Masukkan Data Baru " << endl;
    cout << "Masukkan Nama Hewan: ";
    fflush(stdin);
    getline(cin, temp->nama);
    string jenisHewan;
    do
    {
        cout << "Pilih Jenis Hewan: " << endl;
        cout << "1. Mamalia" << endl;
        cout << "2. Reptil" << endl;
        cout << "3. Burung" << endl;
        cout << ">> ";
        fflush(stdin);
        getline(cin, jenisHewan);

        if (jenisHewan == "1")
        {
            temp->jenis_hewan = "Mamalia";
        }
        else if (jenisHewan == "2")
        {
            temp->jenis_hewan = "Reptil";
        }
        else if (jenisHewan == "3")
        {
            temp->jenis_hewan = "Burung";
        }
        else
        {
            cout << "Pilihan jenis hewan tidak valid. Silakan coba lagi." << endl;
        }
    } while (jenisHewan != "1" && jenisHewan != "2" && jenisHewan != "3");

    cout << "Masukkan Umur Hewan: ";
    temp->umur = cekInput();

    string habitatHewan;
    do
    {
        cout << "Pilih Habitat Hewan: " << endl;
        cout << "1. Savana" << endl;
        cout << "2. Hutan" << endl;
        cout << "3. Air" << endl;
        cout << "4. Tundra" << endl;
        cout << ">> ";
        fflush(stdin);
        getline(cin, habitatHewan);

        if (habitatHewan == "1")
        {
            temp->habitat = "Savana";
        }
        else if (habitatHewan == "2")
        {
            temp->habitat = "Hutan";
        }
        else if (habitatHewan == "3")
        {
            temp->habitat = "Air";
        }
        else if (habitatHewan == "4")
        {
            temp->habitat = "Tundra";
        }
        else
        {
            cout << "Pilihan habitat hewan tidak valid. Silakan coba lagi." << endl;
        }
    } while (habitatHewan != "1" && habitatHewan != "2" && habitatHewan != "3" && habitatHewan != "4");

    string statusKonservasi;
    do
    {
        cout << "Pilih Status Konservasi Hewan: " << endl;
        cout << "1. Punah" << endl;
        cout << "2. Kritis" << endl;
        cout << "3. Rentan" << endl;
        cout << "4. Hampir Terancam" << endl;
        cout << "5. Tidak Terancam" << endl;
        cout << ">> ";
        fflush(stdin);
        getline(cin, statusKonservasi);

        if (statusKonservasi == "1")
        {
            temp->status_konservasi = "Punah";
        }
        else if (statusKonservasi == "2")
        {
            temp->status_konservasi = "Kritis";
        }
        else if (statusKonservasi == "3")
        {
            temp->status_konservasi = "Rentan";
        }
        else if (statusKonservasi == "4")
        {
            temp->status_konservasi = "Hampir Terancam";
        }
        else if (statusKonservasi == "5")
        {
            temp->status_konservasi = "Tidak Terancam";
        }
        else
        {
            cout << "Pilihan status konservasi tidak valid. Silakan coba lagi." << endl;
        }
    } while (statusKonservasi != "1" && statusKonservasi != "2" && statusKonservasi != "3" && statusKonservasi != "4" && statusKonservasi != "5");

    string jenisMakanan;
    do
    {
        cout << "Pilih Kategori Makanan Hewan: " << endl;
        cout << "1. Omnivora" << endl;
        cout << "2. Karnivora" << endl;
        cout << "3. Herbivora" << endl;
        cout << "4. Insectivora" << endl;
        cout << ">> ";
        fflush(stdin);
        getline(cin, jenisMakanan);

        if (jenisMakanan == "1")
        {
            temp->jenis_makanan = "Omnivora";
        }
        else if (jenisMakanan == "2")
        {
            temp->jenis_makanan = "Karnivora";
        }
        else if (jenisMakanan == "3")
        {
            temp->jenis_makanan = "Herbivora";
        }
        else if (jenisMakanan == "4")
        {
            temp->jenis_makanan = "Insectivora";
        }
        else
        {
            cout << "Pilihan jenis makanan tidak valid. Silakan coba lagi." << endl;
        }
    } while (jenisMakanan != "1" && jenisMakanan != "2" && jenisMakanan != "3" && jenisMakanan != "4");
    simpanCSVh(head, filename);
    printColoredText("---------- Data Berhasil Diupdate ---------\n", GREEN_TEXT);
}

void updateDatak(kendaraan *head, int idx, string username)
{
    int panjang = lengthk(head);
    if (idx > panjang)
    {
        printColoredText("---------- Tidak Dapat Mengupdate Data ---------\n", RED_TEXT);
        return;
    }

    kendaraan *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    if (username == "admin")
    {
        string jeniskendaraan;
        do
        {
            cout << "Pilih Jenis Kendaraan : " << endl;
            cout << "1. Bus" << endl;
            cout << "2. Minibus " << endl;
            cout << "Masukkan Jenis Kendaraan : ";
            fflush(stdin);
            getline(cin, jeniskendaraan);
            if (jeniskendaraan == "1")
            {
                temp->jenis_kendaraan = "Bus";
            }
            else if (jeniskendaraan == "2")
            {
                temp->jenis_kendaraan = "Minibus";
            }
            else
            {
                cout << "Pilihan jenis Kendaraan tidak valid. Silakan coba lagi." << endl;
            }
        } while (jeniskendaraan != "1" && jeniskendaraan != "2");

        cout << "Masukkan Kapasitas Kendaraan : ";
        temp->kapasitas = cekInput();

        cout << "Masukkan Harga Sewa : ";
        temp->harga_sewa = cekInput();

        temp->status_kendaraan = "Tersedia";
        printColoredText("------ Data Berhasil Diupdate-----\n", GREEN_TEXT);
    }

    else
    {
        temp->status_kendaraan = "Tidak Tersedia";
    }
}

void updateDatapk(pakan *head, int idx, string username)
{
    int panjang = lengthpk(head);
    if (idx > panjang)
    {
        printColoredText("---------- Tidak Dapat Mengupdate Data ---------\n", RED_TEXT);
        return;
    }
    pakan *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    if (username == "admin")
    {
        cout << "Masukkan Data!" << endl;

        cout << "Masukkan Stok : ";
        temp->stok = cekInput();

        cout << "Masukkan harga : ";
        temp->harga = cekInput();
        printColoredText("---------- RegistraData Berhasil Diupdate--\n", GREEN_TEXT);
    }

    else
    {
        cout << "Ingin beli berapa ? " << endl;
        int beli = cekInput();
        temp->stok = temp->stok - beli;
    }
}

void updateDatat(tiket *head, tiket *tail, string filename, string username)
{
    int panjang = lengtht(head);
    cout << "Pilih data yang ingin dubah :" << endl;
    tampilHeadt(head, tail);
    cout << "Masukkan Pilihan :";
    int idx = cekInput();
    if (idx > panjang)
    {
        printColoredText("---------- Tidak Dapat Mengupdate Data ---------\n", RED_TEXT);
        return;
    }
    tiket *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }
    string jenisTiket;
    do
    {
        cout << "Masukkan Jenis Tiket" << endl;
        cout << "1 Anak " << endl;
        cout << "2 Dewasa " << endl;
        fflush(stdin);
        cin >> jenisTiket;
        if (jenisTiket == "1")
        {
            temp->jenis_tiket = "Anak";
        }
        else if (jenisTiket == "2")
        {
            temp->jenis_tiket = "Dewasa";
        }
        else
        {
            cout << "Pilihan jenis tiket tidak valid." << endl;
        }
    } while (jenisTiket != "1" && jenisTiket != "2");

    cout << "Masukkan Harga Tiket: ";
    cin >> temp->harga;
    cout << "Masukkan Stok Tiket: ";
    cin >> temp->stok;
    printColoredText("---------- Data Berhasil Diupdate ---------\n", GREEN_TEXT);
    simpanCSVt(head, filename, username);
}

void deleteFirsth(hewan **head, hewan **tail)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
}

void deleteFirstk(kendaraan **head, kendaraan **tail)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
}

void deleteFirstpk(pakan **head, pakan **tail)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
}

void deleteFirstt(tiket **head, tiket **tail)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
}

void deleteFirstb(transaksi **head, transaksi **tail)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
}

void deleteFirsts(sewa **head, sewa **tail)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
}

void deleteLasth(hewan **head, hewan **tail)
{
    delete *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
}

void deleteLastk(kendaraan **head, kendaraan **tail)
{
    delete *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
}

void deleteLastpk(pakan **head, pakan **tail)
{
    delete *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
}

void deleteLastt(tiket **head, tiket **tail)
{
    delete *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
}

void deleteLasts(sewa **head, sewa **tail)
{
    delete *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
}

void deleteSpesifich(hewan **head, hewan **tail)
{
    int count = 0;
    hewan *tempCount = *head;
    if (isEmptyh(*head, *tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
        return;
    }
    else
    {
        cout << "Pilih data yang ingin dihapus :" << endl;
        tampilHeadh(*head, *tail);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menghapus Diluar Data ---------\n", RED_TEXT);
            return;
        }
        else if (idx == 1)
        {
            deleteFirsth(head, tail);
        }
        else if (idx == count)
        {
            deleteLasth(head, tail);
        }
        else
        {
            hewan *temp = *head;
            for (int i = 1; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            hewan *Delete = temp->next;
            temp->next = Delete->next;
            delete Delete;
        }
        printColoredText("---------- Data Berhasil Dihapus ---------\n", GREEN_TEXT);
    }
}

void deleteSpesifick(kendaraan **head, kendaraan **tail, string username)
{
    int count = 0;
    kendaraan *tempCount = *head;
    if (isEmptyk(*head, *tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
        return;
    }
    else
    {
        cout << "Pilih data yang ingin dihapus :" << endl;
        tampilHeadk(*head, *tail, username);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menghapus Diluar Data ---------\n", RED_TEXT);
            return;
        }
        else if (idx == 1)
        {
            deleteFirstk(head, tail);
        }
        else if (idx == count)
        {
            deleteLastk(head, tail);
        }
        else
        {
            kendaraan *temp = *head;
            for (int i = 1; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            kendaraan *Delete = temp->next;
            temp->next = Delete->next;
            delete Delete;
        }
        printColoredText("---------- Data Berhasil Dihapus ---------\n", GREEN_TEXT);
    }
}

void deleteSpesificpk(pakan **head, pakan **tail)
{
    int count = 0;
    pakan *tempCount = *head;
    if (isEmptypk(*head, *tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
        return;
    }
    else
    {
        cout << "Pilih data yang ingin dihapus :" << endl;
        tampilHeadpk(*head, *tail);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menghapus Diluar Data ---------\n", RED_TEXT);
            return;
        }
        else if (idx == 1)
        {
            deleteFirstpk(head, tail);
        }
        else if (idx == count)
        {
            deleteLastpk(head, tail);
        }
        else
        {
            pakan *temp = *head;
            for (int i = 1; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            pakan *Delete = temp->next;
            temp->next = Delete->next;
            delete Delete;
        }
        printColoredText("---------- Data Berhasil Dihapus ---------\n", GREEN_TEXT);
    }
}

void deleteSpesifict(tiket **head, tiket **tail)
{
    int count = 0;
    tiket *tempCount = *head;
    if (isEmptyt(*head, *tail))
    {
        printColoredText("---------- Data Tidak Tersedia ---------\n", RED_TEXT);
        return;
    }
    else
    {
        cout << "Pilih data yang ingin dihapus :" << endl;
        tampilHeadt(*head, *tail);
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        while (tempCount != NULL)
        {
            count++;
            tempCount = tempCount->next;
        }
        if (idx <= 0 || idx > count)
        {
            printColoredText("---------- Tidak Dapat Menghapus Diluar Data ---------\n", RED_TEXT);
            return;
        }
        else if (idx == 1)
        {
            deleteFirstt(head, tail);
        }
        else if (idx == count)
        {
            deleteLastt(head, tail);
        }
        else
        {
            tiket *temp = *head;
            for (int i = 1; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            tiket *Delete = temp->next;
            temp->next = Delete->next;
            delete Delete;
        }
        printColoredText("---------- Data Berhasil Dihapus ---------\n", GREEN_TEXT);
    }
}

void tambahPembelian(transaksi **head, transaksi **tail, string nama_pembeli, string jenis_transaksi, int nominal_transaksi, int jumlah_pembelian)
{
    transaksi *data_baru = new transaksi();
    data_baru->nama_pembeli = nama_pembeli;
    data_baru->jenis_transaksi = jenis_transaksi;
    data_baru->nominal_transaksi = nominal_transaksi;
    data_baru->jumlah_pembelian = jumlah_pembelian;

    if (isEmptyb(*head, *tail))
    {
        *head = data_baru;
        *tail = data_baru;
    }
    else
    {
        (*tail)->next = data_baru;
        data_baru->prev = *tail;
        *tail = data_baru;
    }
    int count = 1;
    transaksi *temp = *head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count > 10)
    {
        deleteFirstb(head, tail);
    }
}

void detailBayar(tiket **head, tiket **tail, string username, transaksi **pembelianhead, transaksi **pembeliantail, string filename3, string filename4)
{
    tampilHeadt(*head, *tail);
    if (isEmptyt(*head, *tail))
    {
        return;
    }
    else
    {
        int count = 1;
        int max = 0;
        tiket *temp = *head;
        tiket *maks = *head;
        while (maks != nullptr)
        {
            max++;
            maks = maks->next;
        }
        cout << "Masukkan Pilihan :";
        int idx = cekInput();
        if (idx > max)
        {
            printColoredText("------- Tiket Tidak Tersedia ------\n", RED_TEXT);
            return;
        }
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }

        cout << "Masukkan Jumlah yang akan dibeli : ";
        int jumlah = cekInput();

        if (temp->stok - jumlah < 0)
        {
            printColoredText("Tidak dapat membeli lebih dari stok yang tersedia\n", RED_TEXT);
            return;
        }
        else
        {
            string jenis = "Tiket";
            int total = temp->harga * jumlah;

            cout << "====================" << endl;
            cout << "| Struk Pembayaran |" << endl;
            cout << "====================" << endl;
            cout << "| Nama   : " << username << endl;
            cout << "| Jenis  : " << jenis << endl;
            cout << "| Jumlah : " << jumlah << endl;
            cout << "| Total  : " << total << endl;
            cout << "====================" << endl;

            temp->stok = temp->stok - jumlah;

            if (temp->stok == 0)
            {
                if (count == 1)
                {
                    deleteFirstt(head, tail);
                }
                else if (count == max)
                {
                    deleteLastt(head, tail);
                }
                else
                {
                    tiket *del = *head;
                    for (int i = 1; i < count - 1; i++)
                    {
                        del = del->next;
                    }
                    tiket *Delete = del->next;
                    del->next = Delete->next;
                    delete Delete;
                }
            }
            simpanCSVt(*head, filename3, username);
            tambahPembelian(pembelianhead, pembeliantail, username, jenis, total, jumlah);
            simpanCSVb(*pembelianhead, filename4);
        }
    }
}

void detailBayarpk(pakan **head, pakan **tail, int idx, string username, transaksi **pembelianhead, transaksi **pembeliantail, string filename6, string filename4)
{
    if (isEmptypk(*head, *tail))
    {
        return;
    }
    else
    {
        int count = 1;
        int max = 0;
        pakan *temp = *head;
        pakan *maks = *head;
        while (maks != nullptr)
        {
            max++;
            maks = maks->next;
        }
        if (idx > max)
        {
            printColoredText("----- Pakan Tidak Ada -----\n", RED_TEXT);
            return;
        }
        for (int i = 1; i < idx; i++)
        {
            count++;
            temp = temp->next;
        }
        cout << "Masukkan Jumlah yang akan dibeli :";
        int jumlah = cekInput();

        if (temp->stok - jumlah < 0)
        {
            printColoredText("Tidak dapat membeli lebih dari stok yang tersedia\n", RED_TEXT);
            return;
        }
        else
        {
            string jenis = "Pakan";
            int total = temp->harga * jumlah;

            cout << "====================" << endl;
            cout << "| Struk Pembayaran |" << endl;
            cout << "====================" << endl;
            cout << "| Nama   : " << username << endl;
            cout << "| Jenis  : " << jenis << endl;
            cout << "| Jumlah : " << jumlah << endl;
            cout << "| Total  : " << total << endl;
            cout << "====================" << endl;

            temp->stok = temp->stok - jumlah;
            if (temp->stok == 0)
            {
                if (count == 1)
                {
                    deleteFirstpk(head, tail);
                }
                else if (count == max)
                {
                    deleteLastpk(head, tail);
                }
                else
                {
                    pakan *del = *head;
                    for (int i = 1; i < count - 1; i++)
                    {
                        del = del->next;
                    }
                    pakan *Delete = del->next;
                    del->next = Delete->next;
                    delete Delete;
                }
            }
            simpanCSVpk(*head, filename6, username);
            tambahPembelian(pembelianhead, pembeliantail, username, jenis, total, jumlah);
            simpanCSVb(*pembelianhead, filename4);
        }
    }
}

void detailBayark(kendaraan **head, kendaraan **tail, int idx, string username, transaksi **pembelianhead, transaksi **pembeliantail, string filename5, string filename4, sewa **sewahead, sewa **sewatail, string filename7)
{
    if (isEmptyk(*head, *tail))
    {
        return;
    }
    else
    {
        kendaraan *temp = *head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }

        // cek apakah pengguna sedang menyewa kendaraan atau tidak
        if (ceksewa(*sewahead, id_pengunjung))
        {
            printColoredText("Anda sudah memiliki sewaan yang sedang berlangsung.\n", RED_TEXT);
            return; // Keluar
        }

        int total = temp->harga_sewa;
        string jenis_tr = "Sewa Kendaraan";
        string nama = temp->nama_kendaraan;
        string jenis_k = temp->jenis_kendaraan;
        int kapasitas = temp->kapasitas;

        cout << "============================" << endl;
        cout << "|     Struk Pembayaran     |" << endl;
        cout << "============================" << endl;
        cout << "|Nama : " << username << endl;
        cout << "|Nama Kendaraan : " << nama << endl;
        cout << "|Jenis Transaksi : " << jenis_tr << endl;
        cout << "|Jenis Kendaraan : " << jenis_k << endl;
        cout << "|Harga Sewa : " << total << endl;
        cout << "============================" << endl;
        temp->status_kendaraan = "Tidak Tersedia";

        // Tambahkan sewa baru
        addLasts(sewahead, sewatail, temp->id_kendaraan, id_pengunjung, nama);
        simpanCSVs(*sewahead, filename7);

        int jumlah_pembelian = 0;
        simpanCSVk(*head, filename5);
        tambahPembelian(pembelianhead, pembeliantail, username, jenis_tr, total, jumlah_pembelian);
        simpanCSVb(*pembelianhead, filename4);
        printColoredText("------- Sewa Kendaraan Berhasil -------\n", GREEN_TEXT);
    }
}

void displayPembelianByUsername(transaksi *pembelianhead, string &username)
{
    transaksi *temp = pembelianhead;
    bool found = false;
    int i = 0;
    cout << "Transaksi " << username << endl;
    cout << "---------------------------------------" << endl;
    while (temp != nullptr)
    {
        if (temp->nama_pembeli == username)
        {
            found = true;
            i++;
            cout << i;
            cout << "  |Jenis Pembelian  :" << temp->jenis_transaksi << endl;
            cout << "    |Harga Pembelian  :" << temp->nominal_transaksi << endl;
            cout << "    |Jumlah Pembelian :" << temp->jumlah_pembelian << endl;
            cout << "---------------------------------------" << endl;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << "Data transaksi untuk username '" << username << "' tidak ditemukan." << endl;
    }
}

void kembalikankendaraan(kendaraan **kendaraanhead, string filename5, sewa **sewahead, sewa **sewatail, string filename7, int id_pengunjung)
{
    int count = 1; // inisialisasi count
    int max = 0;   // inisialisasi max
    sewa *maks = *sewahead;
    while (maks != nullptr) // menghitung banyak data sewa
    {
        maks = maks->next; // pindah maks ke node selanjutnya
        max++;             // increment max
    }
    sewa *stemp = *sewahead;                   // Mencari id pengunjung pada data sewa
    while (stemp->id_penyewa != id_pengunjung) // jika id sewa != id pengunjug
    {
        count++;             // increment count
        stemp = stemp->next; // pindah stemp ke node selanjutnya
    }

    // Temukan kendaraan yang sesuai dengan sewa
    kendaraan *ktemp = *kendaraanhead; // inisialisasi pointer ktemp
    while (ktemp != nullptr && ktemp->id_kendaraan != stemp->id_kendaraan)
    {                        // perulangan mencari id kendaraan pada ll kendaraan == id kendaraan pada ll sewa
        ktemp = ktemp->next; // pindah ktemp ke node selanjutnya
    }
    ktemp->status_kendaraan = "Tersedia"; // ubah status kendaraan
    // Hapus data sewa
    if (count == 1) // jika count == 1
    {
        deleteFirsts(sewahead, sewatail); // hapus data pertama sewa
    }
    else if (count == max) // jika count == max
    {
        deleteLasts(sewahead, sewatail); // hapus data terakhir sewa
    }
    else // hapus data sewa yang berada di tengah
    {
        sewa *temp = *sewahead;
        for (int i = 1; i < count - 1; i++) // Perulangan untuk menggerakkan pointer temp ke node sebelum node yang akan dihapus
        {
            temp = temp->next; // pindah temp ke node selanjutnya
        }
        sewa *Delete = temp->next; // Menginisialisasi pointer Delete dengan node yang akan dihapus, yaitu node setelah temp
        temp->next = Delete->next; // Mengubah pointer next dari node sebelum node yang akan dihapus agar menunjuk ke node setelah node yang dihapus.
        delete Delete;             // Menghapus node yang telah diambil oleh pointer
    }
    // Simpan perubahan status kendaraan ke dalam file
    simpanCSVk(*kendaraanhead, filename5);

    // Simpan perubahan data sewa ke dalam file
    simpanCSVs(*sewahead, filename7);
    printColoredText("------- Kendaraan Berhasil Dikembalikan -------\n", GREEN_TEXT);
}

// Definisi fungsi swapnodesh untuk menukar dua node dalam linked list
void swapnodesh(hewan **head, hewan *a, hewan *b)
{
    // Jika a dan b adalah sama, tidak perlu dilakukan pertukaran
    if (a == b)
        return;

    // Cari node sebelum a dan b
    hewan *prevA = NULL, *prevB = NULL, *curr = *head;
    while (curr)
    {
        // Periksa apakah node berikutnya adalah a atau b
        if (curr->next == a)
            prevA = curr;
        if (curr->next == b)
            prevB = curr;
        // Pindahkan pointer curr ke node berikutnya dalam linked list
        curr = curr->next;
    }

    // Atur head baru jika a atau b berada di posisi head
    if (a == *head)
        *head == b;
    else if (b == *head)
        *head = a;

    // Atur next dari node sebelum a agar menunjuk ke b
    if (prevA)
    {
        prevA->next = b;
    }
    // Atur next dari node sebelum b agar menunjuk ke a
    if (prevB)
    {
        prevB->next = a;
    }
    // Tukar next untuk a dan b
    hewan *temp = a->next;
    a->next = b->next;
    b->next = temp;
}

void swapnodesk(kendaraan **head, kendaraan *a, kendaraan *b)
{
    if (a == b)
        return;

    // Cari node sebelum a dan b
    kendaraan *prevA = NULL, *prevB = NULL, *curr = *head;
    while (curr)
    {
        if (curr->next == a)
            prevA = curr;
        if (curr->next == b)
            prevB = curr;
        curr = curr->next;
    }

    if (a == *head)
        *head == b;
    else if (b == *head)
        *head = a;

    if (prevA)
    {
        prevA->next = b;
    }
    if (prevB)
    {
        prevB->next = a;
    }
    // Tukar next untuk a dan b
    kendaraan *temp = a->next;
    a->next = b->next;
    b->next = temp;
}

// Definisi fungsi findnodeh untuk menemukan node hewan pada indeks tertentu
hewan *findnodeh(hewan *head, int idx)
{
    // Inisialisasi pointer temp dengan pointer ke head linked list
    hewan *temp = head;

    // Loop untuk mencari node pada indeks tertentu
    for (int i = 0; i < idx; i++)
    {
        // Pindahkan pointer temp ke node berikutnya dalam linked list
        temp = temp->next;
    }

    // Mengembalikan pointer ke node yang ditemukan pada indeks tertentu
    return temp;
}

// Definisi fungsi findnodeh untuk menemukan node kendaraan pada indeks tertentu
kendaraan *findnodek(kendaraan *head, int idx)
{
    // Inisialisasi pointer temp dengan pointer ke head linked list
    kendaraan *temp = head;

    // Loop untuk mencari node pada indeks tertentu
    for (int i = 0; i < idx; i++)
    {
        // Pindahkan pointer temp ke node berikutnya dalam linked list
        temp = temp->next;
    }

    // Mengembalikan pointer ke node yang ditemukan pada indeks tertentu
    return temp;
}

// Definisi template untuk fungsi Shell Sort menurun pada linked list kendaraan
template <typename T>
void shellSortAsch(hewan **head, hewan **tail, int n, T hewan::*attribut)
{
    // Loop untuk gap decrement hingga 1
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Loop untuk melakukan pengurutan menggunakan algoritma Shell Sort
        for (int i = gap; i < n; i++)
        {
            // Temukan node pada indeks i
            hewan *temp = findnodeh(*head, i);
            int j;
            // Loop untuk melakukan pertukaran berdasarkan atribut
            for (j = i; j >= gap && (((*findnodeh(*head, j - gap)).*attribut) > ((*temp).*attribut)); j -= gap)
            {
                // Temukan dua node yang akan ditukar
                hewan *node1 = findnodeh(*head, j);
                hewan *node2 = findnodeh(*head, j - gap);
                // Panggil fungsi untuk pertukaran node
                swapnodesh(head, node1, node2);
            }
        }
    }
    // Setelah selesai, atur tail ke node terakhir
    *tail = findnodeh(*head, n - 1);
    // Iterasi mundur untuk menemukan head yang baru
    hewan *temp = *tail;
    while (temp != NULL)
    {
        temp = temp->next;
    }
}

template <typename T> // Definisi template untuk fungsi Shell Sort menurun pada linked list kendaraan
void shellSortDsck(kendaraan **head, kendaraan **tail, int n, T kendaraan::*attribut)
{
    for (int gap = n / 2; gap > 0; gap /= 2) // Loop untuk gap decrement hingga 1
    {
        for (int i = gap; i < n; i++) // Loop untuk melakukan pengurutan menggunakan algoritma Shell Sort
        {
            // Temukan node pada indeks i
            kendaraan *temp = findnodek(*head, i);
            int j;
            // Loop untuk melakukan pertukaran berdasarkan atribut
            for (j = i; j >= gap && (((*findnodek(*head, j - gap)).*attribut) < ((*temp).*attribut)); j -= gap)
            {
                // Temukan dua node yang akan ditukar
                kendaraan *node1 = findnodek(*head, j);
                kendaraan *node2 = findnodek(*head, j - gap);
                // Panggil fungsi untuk pertukaran node
                swapnodesk(head, node1, node2);
            }
        }
    }
    // Setelah selesai, atur tail ke node terakhir
    *tail = findnodek(*head, n - 1);
    // Iterasi mundur untuk menemukan head yang baru
    kendaraan *temp = *tail;
    while (temp != NULL)
    {
        temp = temp->prev;
    }
}

void fixPrevh(hewan **head, hewan **tail)
{
    hewan *temp = *head; // Inisialisasi pointer 'temp' ke 'head' linked list.
    hewan *prev = NULL;  // Inisialisasi pointer 'prev' ke 'NULL'.

    while (temp != NULL) // Selama 'temp' tidak 'NULL':
    {
        temp->prev = prev; // Set prev ke node sebelumnya
        prev = temp;       // Pindah ke node berikutnya
        temp = temp->next;
    }
    *tail = prev; // Set tail ke node terakhir
}

void fixPrevk(kendaraan **head, kendaraan **tail)
{
    kendaraan *temp = *head;
    kendaraan *prev = NULL;
    while (temp != NULL)
    {
        temp->prev = prev;
        prev = temp;
        temp = temp->next;
    }
    *tail = prev;
}

const int NO_OF_CHARS = 256;
void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
{

    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}

template <typename T>
void search(hewan *head, string pat, T hewan::*attribut)
{
    int m = pat.size();
    int count = 0;
    hewan *temp = head;
    while (temp != NULL)
    {
        string attribut_value = temp->*attribut;
        transform(attribut_value.begin(), attribut_value.end(), attribut_value.begin(), ::tolower); // Konversi ke huruf kecil
        transform(pat.begin(), pat.end(), pat.begin(), ::tolower);                                  // Konversi string pencarian ke huruf kecil
        int n = attribut_value.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;
        while (s <= (n - m))
        {
            int j = m - 1;
            while (j >= 0 && pat[j] == attribut_value[s + j])
            {
                j--;
            }
            if (j < 0)
            {
                cout << "Nama Hewan        : " << temp->nama << endl;
                cout << "Jenis Hewan       : " << temp->jenis_hewan << endl;
                cout << "Umur              : " << temp->umur << " tahun" << endl;
                cout << "Habitat           : " << temp->habitat << endl;
                cout << "Status Konservasi : " << temp->status_konservasi << endl;
                cout << "Jenis Makanan     : " << temp->jenis_makanan << endl;
                cout << "---------------------------------------" << endl;
                count++;
                break;
            }
            else
            {
                s += max(1, j - badChar[attribut_value[s + j]]);
            }
        }
        temp = temp->next;
    }
    if (count == 0)
    {
        printColoredText("Data tidak ditemukan\n", RED_TEXT);
    }
}

// Fungsi untuk menampilkan data transaksi berdasarkan username

void tampilkandari()
{
    printColoredText("===========================\n", YELLOW_TEXT);
    printColoredText("|      Tampilkan Dari     |\n", YELLOW_TEXT);
    printColoredText("===========================\n", YELLOW_TEXT);
    printColoredText("|  [1]. Head              |\n", YELLOW_TEXT);
    printColoredText("|  [2]. Tail              |\n", YELLOW_TEXT);
    printColoredText("|  [3]. Kembali           |\n", YELLOW_TEXT);
    printColoredText("===========================\n", YELLOW_TEXT);
    printColoredText("Masukkan Pilihan: ", YELLOW_TEXT);
}

void menudata()
{
    printColoredText("|  [1]. Data Hewan        |\n", YELLOW_TEXT);
    printColoredText("|  [2]. Data Tiket        |\n", YELLOW_TEXT);
    printColoredText("|  [3]. Data Kendaraan    |\n", YELLOW_TEXT);
    printColoredText("|  [4]. Data Pakan        |\n", YELLOW_TEXT);
    printColoredText("|  [5]. Kembali           |\n", YELLOW_TEXT);
    printColoredText("===========================\n", YELLOW_TEXT);
    printColoredText("Masukkan Pilihan: ", YELLOW_TEXT);
}

int main()
{
    // Deklarasi pointer head dan tail masing masing linkedlist
    hewan *hewanhead = NULL;
    hewan *hewantail = NULL;
    pengunjung *pengunjunghead = NULL;
    pengunjung *pengunjungtail = NULL;
    tiket *tikethead = NULL;
    tiket *tikettail = NULL;
    transaksi *pembelianhead = NULL;
    transaksi *pembeliantail = NULL;
    kendaraan *kendaraanhead = NULL;
    kendaraan *kendaraantail = NULL;
    pakan *pakanhead = NULL;
    pakan *pakantail = NULL;
    sewa *sewahead = NULL;
    sewa *sewatail = NULL;

    // Deklarasi nama file dan membaca file
    string filename = "data_hewan.csv";
    bacaCSVh(&hewanhead, &hewantail, filename);
    string filename2 = "data_pengunjung.csv";
    bacaCSVp(&pengunjunghead, &pengunjungtail, filename2);
    string filename3 = "data_tiket.csv";
    bacaCSVt(&tikethead, &tikettail, filename3);
    string filename4 = "data_pembelian.csv";
    bacaCSVb(&pembelianhead, &pembeliantail, filename4);
    string filename5 = "data_kendaraan.csv";
    bacaCSVk(&kendaraanhead, &kendaraantail, filename5);
    string filename6 = "data_pakan.csv";
    bacaCSVpk(&pakanhead, &pakantail, filename6);
    string filename7 = "data_sewa.csv";
    bacaCSVs(&sewahead, &sewatail, filename7);

    int nextIDp = cekPId(pengunjunghead); // Mengecek ID pengunjung
    int nextIDk = cekKId(kendaraanhead);  // mengecek ID Kendaraan
    int pilih, idx, carii;                // Deklarasi variabel integer
    string username, password, caris;     // Deklarasi variabel string
    system("cls");
    while (pilih != 4)
    {
        printColoredText("====================================================\n", YELLOW_TEXT);
        printColoredText("|      Selamat datang di Program Taman Safari      |\n", YELLOW_TEXT);
        printColoredText("-==================================================-\n", YELLOW_TEXT);
        printColoredText("| [1]. Register                                    |\n", YELLOW_TEXT);
        printColoredText("| [2]. Login                                       |\n", YELLOW_TEXT);
        printColoredText("| [4]. Keluar                                      |\n", YELLOW_TEXT);
        printColoredText("====================================================\n", YELLOW_TEXT);
        printColoredText("Masukkan Pilihan: ", YELLOW_TEXT);
        pilih = cekInput();
        system("cls");
        switch (pilih)
        {
        case 1:
            printColoredText("===========================\n", YELLOW_TEXT);
            printColoredText("|         Register        |\n", YELLOW_TEXT);
            printColoredText("===========================\n", YELLOW_TEXT);
            addFirstp(&pengunjunghead, &pengunjungtail, nextIDp, filename2);

            break;
        case 2:
            printColoredText("===========================\n", YELLOW_TEXT);
            printColoredText("|          Login          |\n", YELLOW_TEXT);
            printColoredText("===========================\n", YELLOW_TEXT);
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;
            if (username == "admin" && password == "admin")
            {
                system("cls");
                printColoredText("Login Admin Berhasil\n", GREEN_TEXT);
                while (pilih != 9)
                {
                    printColoredText("=================================\n", YELLOW_TEXT);
                    printColoredText("|          Menu Admin           |\n", YELLOW_TEXT);
                    printColoredText("=================================\n", YELLOW_TEXT);
                    printColoredText("| [1]. Create Data              |\n", YELLOW_TEXT);
                    printColoredText("| [2]. Read Data                |\n", YELLOW_TEXT);
                    printColoredText("| [3]. Update Data              |\n", YELLOW_TEXT);
                    printColoredText("| [4]. Delete Data              |\n", YELLOW_TEXT);
                    printColoredText("| [5]. Searching Data           |\n", YELLOW_TEXT);
                    printColoredText("| [6]. Sorting Data             |\n", YELLOW_TEXT);
                    printColoredText("| [7]. Tampilkan Data Penjualan |\n", YELLOW_TEXT);
                    printColoredText("| [8]. Tampilkan Data Sewa      |\n", YELLOW_TEXT);
                    printColoredText("| [9]. Logout                   |\n", YELLOW_TEXT);
                    printColoredText("=================================\n", YELLOW_TEXT);
                    printColoredText("Masukkan Pilihan: ", YELLOW_TEXT);
                    pilih = cekInput();
                    system("cls");
                    switch (pilih)
                    {
                    case 1:
                        // Ini Tambah Data ------------------------------------------
                        printColoredText("===========================\n", YELLOW_TEXT);
                        printColoredText("|       Tambah Data       |\n", YELLOW_TEXT);
                        printColoredText("===========================\n", YELLOW_TEXT);
                        menudata();
                        pilih = cekInput();
                        system("cls");
                        switch (pilih)
                        {
                        case 1:
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|    Menu Tambah Hewan    |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            // ini Tambah hewan--------------------------------------------------------
                            addSpesifich(&hewanhead, &hewantail, filename);
                            break;
                        case 2:
                            // Ini Tambah TIket--------------------------------------------------------
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|    Menu Tambah Tiket    |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            addSpesifict(&tikethead, &tikettail, filename3, username);
                            break;
                        case 3:
                            // Tambah Kendaraan
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|  Menu Tambah Kendaraan  |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            addSpesifick(&kendaraanhead, &kendaraantail, username, nextIDk, filename5);
                            printColoredText("-------- Kendaraan Berhasil Ditambah -----", GREEN_TEXT);
                            break;
                        case 4:
                            // Tambah Pakan
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|    Menu Tambah Pakan    |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            addSpesificpk(&pakanhead, &pakantail, filename6, username);
                            break;
                        case 5:
                            break;
                        default:
                            printColoredText("Pilihan Tidak Tersedia \n", RED_TEXT);
                            break;
                        }
                        break;
                        // Ini Tampil Data ---------------------------------------------------
                    case 2:
                        printColoredText("===========================\n", YELLOW_TEXT);
                        printColoredText("|      Tampilkan Data     |\n", YELLOW_TEXT);
                        printColoredText("===========================\n", YELLOW_TEXT);
                        menudata();
                        pilih = cekInput();
                        system("cls");
                        switch (pilih)
                        {
                            // Tampil data hewan ------------------------------------------
                        case 1:
                            tampilHeadh(hewanhead, hewantail);
                            break;
                            // Tampil data tiket -------------------------------------------
                        case 2:
                            tampilTailt(tikethead, tikettail);
                            break;
                        case 3:
                            // tampil data kendaraan
                            tampilkandari();
                            pilih = cekInput();
                            switch (pilih)
                            {
                            case 1:
                                tampilHeadk(kendaraanhead, kendaraantail, username);
                                break;
                            case 2:
                                tampilTailk(kendaraanhead, kendaraantail, username);
                                break;
                            case 3:
                                break;
                            default:
                                printColoredText("Pilihan Tidak Tersedia \n", RED_TEXT);
                                break;
                            }
                            break;
                        case 4:
                            tampilHeadpk(pakanhead, pakantail);
                            break;
                        case 5:
                            break;
                        default:
                            printColoredText("Pilihan Tidak Tersedia \n", RED_TEXT);
                            break;
                        }
                        break;
                        // Ini Update Data ----------------------------------------------
                    case 3:
                        printColoredText("===========================\n", YELLOW_TEXT);
                        printColoredText("|       Update Data       |\n", YELLOW_TEXT);
                        printColoredText("===========================\n", YELLOW_TEXT);
                        menudata();
                        pilih = cekInput();
                        system("cls");
                        switch (pilih)
                        {
                        case 1:
                            if (isEmptyh(hewanhead, hewantail))
                            {
                                printColoredText("----- Hewan Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                updateDatah(hewanhead, hewantail, filename);
                            }
                            break;
                        case 2:
                            if (isEmptyt(tikethead, tikettail))
                            {
                                printColoredText("----- Tiket Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                updateDatat(tikethead, tikettail, filename3, username);
                            }
                            break;
                        case 3:
                            if (isEmptyk(kendaraanhead, kendaraantail))
                            {
                                printColoredText("----- Kendaraan Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                cout << "Pilih data yang ingin dubah :" << endl;
                                tampilHeadk(kendaraanhead, kendaraantail, username);
                                cout << "Masukkan Pilihan :";
                                idx = cekInput();
                                updateDatak(kendaraanhead, idx, username);
                                simpanCSVk(kendaraanhead, filename5);
                            }
                            break;
                        case 4:
                            if (isEmptypk(pakanhead, pakantail))
                            {
                                printColoredText("----- Pakan Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                cout << "Pilih data yang ingin dubah :" << endl;
                                tampilHeadpk(pakanhead, pakantail);
                                cout << "Masukkan Pilihan :";
                                idx = cekInput();
                                updateDatapk(pakanhead, idx, username);
                                simpanCSVpk(pakanhead, filename6, username);
                            }
                            break;
                        case 5:
                            break;
                        default:
                            printColoredText("Pilihan Tidak Tersedia \n", RED_TEXT);
                            break;
                        }
                        break;
                        // Ini delete Data ----------------------------------------------------
                    case 4:
                        printColoredText("===========================\n", YELLOW_TEXT);
                        printColoredText("|       Delete Data       |\n", YELLOW_TEXT);
                        printColoredText("===========================\n", YELLOW_TEXT);
                        menudata();
                        pilih = cekInput();
                        system("cls");
                        switch (pilih)
                        {
                        case 1:
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|    Menu Delete Hewan    |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            if (isEmptyh(hewanhead, hewantail))
                            {
                                printColoredText("----- Hewan Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                deleteSpesifich(&hewanhead, &hewantail);
                                simpanCSVh(hewanhead, filename);
                            }
                            break;
                        case 2:
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|    Menu Delete Tiket    |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            if (isEmptyt(tikethead, tikettail))
                            {
                                printColoredText("----- Tiket Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                deleteSpesifict(&tikethead, &tikettail);
                                simpanCSVt(tikethead, filename3, username);
                            }
                            break;
                        case 3:
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|  Menu Delete Kendaraan  |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            if (isEmptyk(kendaraanhead, kendaraantail))
                            {
                                printColoredText("----- kendaraan Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                deleteSpesifick(&kendaraanhead, &kendaraantail, username);
                                simpanCSVk(kendaraanhead, filename5);
                            }
                            break;
                        case 4:
                            printColoredText("===========================\n", YELLOW_TEXT);
                            printColoredText("|    Menu Delete Pakan    |\n", YELLOW_TEXT);
                            printColoredText("===========================\n", YELLOW_TEXT);
                            if (isEmptypk(pakanhead, pakantail))
                            {
                                printColoredText("----- Pakan Tidak Tersedia -----\n", RED_TEXT);
                                break;
                            }
                            else
                            {
                                deleteSpesificpk(&pakanhead, &pakantail);
                                simpanCSVpk(pakanhead, filename6, username);
                            }
                            break;
                        case 5:
                            break;
                        default:
                            printColoredText("Pilihan Tidak Tersedia \n", RED_TEXT);
                            break;
                        }
                        break;
                    case 5:
                        cout << "Masukkan Nama Hewan : ";
                        cin >> caris;
                        search(hewanhead, caris, &hewan::nama);
                        break;
                    case 6:
                        printColoredText("============================\n", YELLOW_TEXT);
                        printColoredText("|       Urutkan Data       |\n", YELLOW_TEXT);
                        printColoredText("============================\n", YELLOW_TEXT);
                        printColoredText("|  [1]. Hewan              |\n", YELLOW_TEXT);
                        printColoredText("|  [2]. Kendaraan          |\n", YELLOW_TEXT);
                        printColoredText("============================\n", YELLOW_TEXT);
                        printColoredText(" Masukkan Pilihan :", YELLOW_TEXT);
                        pilih = cekInput();
                        switch (pilih)
                        {
                        case 1:
                            shellSortAsch(&hewanhead, &hewantail, lengthh(hewanhead), &hewan::nama);
                            fixPrevh(&hewanhead, &hewantail);
                            break;
                        case 2:
                            shellSortDsck(&kendaraanhead, &kendaraantail, lengthk(kendaraanhead), &kendaraan::nama_kendaraan);
                            fixPrevk(&kendaraanhead, &kendaraantail);
                            break;
                        default:
                            printColoredText("Pilihan tidak tersedia\n", RED_TEXT);
                            break;
                        }
                        break;
                    case 7:
                        tampilHeadb(pembelianhead, pembeliantail);
                        break;
                    case 8:
                        tampilKendaraanDisewa(sewahead, sewatail, pengunjunghead, kendaraanhead);
                        break;
                    case 9:
                        break;
                    default:
                        printColoredText("Pilihan Tidak Tersedia \n", RED_TEXT);
                        break;
                    }
                }
            }

            // Ini menu pengunjung---------------------------
            else if (login(pengunjunghead, username, password, id_pengunjung))
            {
                system("cls");
                printColoredText("------ Login Berhasil ------\n", GREEN_TEXT);
                while (pilih != 9)
                {
                    printColoredText("===============================\n", YELLOW_TEXT);
                    printColoredText("|     Program Taman Safari    |\n", YELLOW_TEXT);
                    printColoredText("===============================\n", YELLOW_TEXT);
                    printColoredText("|  [1]. Beli Tiket            |\n", YELLOW_TEXT);
                    printColoredText("|  [2]. Sewa Kendaraan        |\n", YELLOW_TEXT);
                    printColoredText("|  [3]. Beli Pakan            |\n", YELLOW_TEXT);
                    printColoredText("|  [4]. Tampilkan Data Hewan  |\n", YELLOW_TEXT);
                    printColoredText("|  [5]. Searching Data Hewan  |\n", YELLOW_TEXT);
                    printColoredText("|  [6]. Riwayat Transaksi     |\n", YELLOW_TEXT);
                    bool ceksewaresult = ceksewa(sewahead, id_pengunjung); // Periksa apakah pengguna telah menyewa kendaraan
                    if (ceksewaresult)
                    {
                        printColoredText("|  [7]. Kembalikan Kendaraan  |\n", YELLOW_TEXT);
                    }
                    printColoredText("|  [9]. Log out               |\n", YELLOW_TEXT);
                    printColoredText("===============================\n", YELLOW_TEXT);
                    printColoredText("Masukkan Pilihan: ", YELLOW_TEXT);
                    pilih = cekInput();
                    system("cls");
                    switch (pilih)
                    {
                    case 1:
                        if (isEmptyt(tikethead, tikettail))
                        {
                            printColoredText("----- Tiket Tidak Tersedia -----\n", RED_TEXT);
                            break;
                        }
                        else
                        {
                            detailBayar(&tikethead, &tikettail, username, &pembelianhead, &pembeliantail, filename3, filename4);
                        }
                        break;
                    case 2:
                        if (isEmptyk(kendaraanhead, kendaraantail))
                        {
                            printColoredText("----- Kendaraan Tidak Tersedia -----\n", RED_TEXT);
                            break;
                        }
                        else
                        {
                            tampilHeadk(kendaraanhead, kendaraantail, username);
                            cout << "Masukkan Pilihan :";
                            idx = cekInput();
                            int max = 0;
                            kendaraan *maks = kendaraanhead;
                            while (maks != nullptr)
                            {
                                max++;
                                maks = maks->next;
                            }
                            if (idx > max)
                            {
                                printColoredText("----- Kendaraan Tidak Ada -----\n", RED_TEXT);
                                break;
                            }
                            if (cekkendaraan(kendaraanhead, idx))
                            {
                                detailBayark(&kendaraanhead, &kendaraantail, idx, username, &pembelianhead, &pembeliantail, filename5, filename4, &sewahead, &sewatail, filename7);
                            }
                            else
                            {
                                printColoredText("Maaf, kendaraan tidak tersedia. Silahkan pilih kendaraan yang lain\n", RED_TEXT);
                            }
                        }
                        break;
                    case 3:
                        if (isEmptypk(pakanhead, pakantail))
                        {
                            printColoredText("----- Pakan Tidak Tersedia -----\n", RED_TEXT);
                            break;
                        }
                        else
                        {
                            tampilHeadpk(pakanhead, pakantail);
                            cout << "Masukkan Pilihan :";
                            idx = cekInput();
                            detailBayarpk(&pakanhead, &pakantail, idx, username, &pembelianhead, &pembeliantail, filename6, filename4);
                        }
                        break;
                    case 4:
                        tampilHeadh(hewanhead, hewantail);
                        break;
                    case 5:
                        if (isEmptyh(hewanhead, hewantail))
                        {
                            printColoredText("----- Hewan Tidak Tersedia -----\n", RED_TEXT);
                            break;
                        }
                        else
                        {
                            cout << "Masukkan Nama Hewan : ";
                            cin >> caris;
                            search(hewanhead, caris, &hewan::nama);
                        }
                        break;
                    case 6:
                        displayPembelianByUsername(pembelianhead, username);
                        break;
                    case 7:
                        // Periksa apakah pengguna telah menyewa kendaraan
                        if (ceksewaresult)
                        {
                            kembalikankendaraan(&kendaraanhead, filename5, &sewahead, &sewatail, filename7, id_pengunjung);
                        }
                        else
                        {
                            printColoredText("Pilihan yang anda masukkan salah\n", RED_TEXT);
                        }
                        break;
                    case 9:
                        break;
                    default:
                        printColoredText("Pilihan yang anda masukkan salah\n", RED_TEXT);
                        break;
                    }
                }
            }
            else
            {
                printColoredText("----- Username atau Password salah -----\n", RED_TEXT);
            }
            break;
        case 4:
            printColoredText("==============================================\n", MAGENTA_TEXT);
            printColoredText("| Terimakasih Telah Menggunakan Program Kami |\n", MAGENTA_TEXT);
            printColoredText("==============================================\n", MAGENTA_TEXT);
            break;
        default:
            printColoredText("Pilihan yang anda masukkan salah\n", RED_TEXT);
            break;
        }
    }
    return 0;
}
