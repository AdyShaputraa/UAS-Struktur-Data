// Mengelola menu makanan menggunakan linked list
// Implementasi Menu dengan Linked List

#include <iostream>
using namespace std;

struct Menu {
    int kode;
    string nama;
    int harga;
    Menu* next;
};

class MenuList {
    Menu* head;

public:
    MenuList() {
        head = nullptr;
    }

    void tambahMenu(int kode, string nama, int harga) {
        Menu* baru = new Menu{kode, nama, harga, nullptr};
        if (!head)
            head = baru;
        else {
            Menu* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = baru;
        }
        cout << "Menu berhasil ditambahkan.\n";
    }

    void hapusMenu(int kode) {
        if (!head) {
            cout << "Menu kosong.\n";
            return;
        }
        if (head->kode == kode) {
            Menu* temp = head;
            head = head->next;
            delete temp;
            cout << "Menu dihapus.\n";
            return;
        }
        Menu* curr = head;
        while (curr->next && curr->next->kode != kode)
            curr = curr->next;

        if (curr->next) {
            Menu* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Menu dihapus.\n";
        } else {
            cout << "Kode menu tidak ditemukan.\n";
        }
    }

    void tampilMenu() {
        if (!head) {
            cout << "Menu kosong.\n";
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
