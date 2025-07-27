// Mengelola menu makanan menggunakan linked list
// Implementasi Menu dengan Linked List

#include <iostream>
using namespace std;

// Node untuk menyimpan menu makanan
struct Menu {
    int kode;          // kode unik
    string nama;       // nama makanan
    int harga;         // harga
    Menu* next;        // penunjuk ke node selanjutnya
};

class MenuList {
    Menu* head; // pointer ke awal list

    public:
    MenuList() {
        head = nullptr; // awalnya kosong
    }

    // Tambah menu ke akhir list
    void tambahMenu(int kode, string nama, int harga) {
        Menu* baru = new Menu{kode, nama, harga, nullptr};
        if (!head) {
            head = baru; // jika kosong, jadi head
        } else {
            Menu* temp = head;
            while (temp->next) temp = temp->next; // cari ujung list
            temp->next = baru; // tambahkan ke akhir
        }
        cout << "Menu ditambahkan.\n";
    }

    // Hapus menu berdasarkan kode
    void hapusMenu(int kode) {
        if (!head) { // Jika list kosong (tidak ada node sama sekali)
            cout << "List kosong\n"; // Tampilkan pesan bahwa list kosong
            return; // Keluar dari fungsi
        }

        if (head->kode == kode) { // Jika node pertama (head) adalah node yang ingin dihapus
            Menu* tmp = head; // Simpan pointer ke node head yang akan dihapus
            head = head->next; // Geser head ke node berikutnya
            delete tmp; // Hapus node head dari memori
            cout << "Menu dihapus.\n"; // Tampilkan pesan bahwa menu dihapus
            return; // Keluar
        }

        Menu* curr = head; // Inisialisasi pointer curr ke node pertama (head)
        while (curr->next && curr->next->kode != kode) // Selama node berikutnya ada dan kode pada node berikutnya bukan yang dicari
            curr = curr->next; // Geser curr ke node berikutnya

        if (curr->next) { // Jika node berikutnya ada (berarti ditemukan node dengan kode yang dicari)
            Menu* tmp = curr->next; // Simpan pointer ke node yang akan dihapus
            curr->next = tmp->next; // Hubungkan curr ke node setelah node yang dihapus
            delete tmp; // Hapus node yang ditemukan dari memori
            cout << "Menu dihapus.\n"; // Tampilkan pesan bahwa menu dihapus
        } else { // Jika node berikutnya tidak ada (kode tidak ditemukan)
            cout << "Menu tidak ditemukan.\n"; // Tampilkan pesan bahwa menu
        }
    }

    // Tampilkan semua menu
    void tampilMenu() {
        if (!head) { // Jika list kosong (tidak ada node sama sekali)
            cout << "Belum ada menu.\n"; // Tampilkan pesan bahwa belum ada menu
            return; // Keluar dari fungsi
        }

        Menu* temp = head; // Inisialisasi pointer temp ke node pertama (head)
        cout << "Daftar Menu:\n"; // Tampilkan judul daftar menu
        while (temp) { // Selama temp tidak null (masih ada node)
            cout << temp->kode << ". " << temp->nama << " - Rp " << temp->harga << endl; // Tampilkan data menu pada node saat ini
            temp = temp->next; // Geser temp ke node berikutnya
        }
    }
};

int main() {
    MenuList menu; // Membuat objek MenuList untuk mengelola daftar menu
    menu.tambahMenu(1, "Nasi Goreng", 15000); // Menambahkan menu baru dengan kode 1
    menu.tambahMenu(2, "Mie Ayam", 12000); // Menambahkan menu baru dengan kode 2
    menu.hapusMenu(1); // Menghapus menu dengan kode 1 dari daftar
    menu.tampilMenu(); // Menampilkan seluruh menu yang tersisa
    return 0;
}
