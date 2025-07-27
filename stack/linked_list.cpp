// Undo transaksi terakhir menggunakan linked list
// Implementasi Stack dengan linked list

#include <iostream>
using namespace std;

struct Transaksi {
    string nama;
    int total;
    Transaksi* next;
};

class StackLinkedList {
    Transaksi* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(string nama, int total) {
        top = new Transaksi{nama, total, top};
        cout << "Transaksi " << nama << " disimpan.\n";
    }

    void pop() {
        if (!top) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Undo: " << top->nama << " - Rp " << top->total << endl;
        Transaksi* temp = top;
        top = top->next;
        delete temp;
    }

    void tampil() {
        if (!top) {
            cout << "Stack kosong!\n";
            return;
        }
        Transaksi* temp = top;
        cout << "Riwayat:\n";
        while (temp) {
            cout << temp->nama << " - Rp " << temp->total << endl;
            temp = temp->next;
        }
    }
};

int main() {
    StackLinkedList s;
    s.push("Ady", 10000);
    s.push("Akbar", 18000);
    s.pop();
    s.push("Diki", 18000);
    s.tampil();
    return 0;
}
