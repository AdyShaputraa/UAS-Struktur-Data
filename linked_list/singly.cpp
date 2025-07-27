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
        if (!head) {
            cout << "List kosong\n";
            return;
        }

        if (head->kode == kode) {
            Menu* tmp = head;
            head = head->next;
            delete tmp;
            cout << "Menu dihapus.\n";
            return;
        }

        Menu* curr = head;
        while (curr->next && curr->next->kode != kode)
            curr = curr->next;

        if (curr->next) {
            Menu* tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
            cout << "Menu dihapus.\n";
        } else {
            cout << "Menu tidak ditemukan.\n";
        }
    }

    // Tampilkan semua menu
    void tampilMenu() {
        if (!head) {
            cout << "Belum ada menu.\n";
            return;
        }

        Menu* temp = head;
        cout << "Daftar Menu:\n";
        while (temp) {
            cout << temp->kode << ". " << temp->nama << " - Rp " << temp->harga << endl;
            temp = temp->next;
        }
    }
};

int main() {
    MenuList menu;
    menu.tambahMenu(1, "Nasi Goreng", 15000);
    menu.tambahMenu(2, "Mie Ayam", 12000);
    menu.hapusMenu(1);
    menu.tampilMenu();
    return 0;
}
