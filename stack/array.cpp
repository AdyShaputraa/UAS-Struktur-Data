// Undo transaksi terakhir menggunakan array
// Implementasi Stack dengan Array

#include <iostream>
using namespace std;

#define SIZE 10

class StackArray {
    string pelanggan[SIZE];
    int total[SIZE];
    int top;

public:
    StackArray() {
        top = -1;
    }

    void push(string nama, int harga) {
        if (top == SIZE - 1) {
            cout << "Stack penuh!\n";
            return;
        }
        top++;
        pelanggan[top] = nama;
        total[top] = harga;
        cout << "Transaksi " << nama << " disimpan.\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Tidak ada transaksi.\n";
            return;
        }
        cout << "Undo: " << pelanggan[top] << " - Rp " << total[top] << endl;
        top--;
    }

    void tampil() {
        if (top == -1) {
            cout << "Stack kosong\n";
            return;
        }
        cout << "Riwayat Transaksi:\n";
        for (int i = top; i >= 0; i--)
            cout << pelanggan[i] << " - Rp " << total[i] << endl;
    }
};

int main() {
    StackArray s;
    s.push("Ady", 15000);
    s.push("Akbar", 12000);
    s.pop();
    s.push("Diki", 13000);
    s.tampil();
    return 0;
}