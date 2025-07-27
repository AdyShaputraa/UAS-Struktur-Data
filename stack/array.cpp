// Undo transaksi terakhir menggunakan array
// Implementasi Stack dengan Array

#include <iostream>
using namespace std;

#define MAX 10
class StackArray {
    private:
    string nama[MAX]; // array untuk nama pembeli
    int total[MAX];   // array untuk total belanja
    int top;          // indeks atas stack

    public:
    StackArray() {
        top = -1; // inisialisasi stack kosong
    }

    // Menambahkan transaksi ke stack
    void push(string n, int t) {
        if (top == MAX - 1) {
            cout << "Stack penuh.\n";
            return;
        }
        top++; // naikkan indeks
        nama[top] = n;
        total[top] = t;
        cout << "Transaksi " << n << " disimpan.\n";
    }

    // Menghapus transaksi terakhir
    void pop() {
        if (top == -1) {
            cout << "Stack kosong.\n";
            return;
        }
        cout << "Undo transaksi: " << nama[top] << " - Rp " << total[top] << endl;
        top--; // turunkan indeks
    }

    // Menampilkan transaksi
    void display() {
        if (top == -1) {
            cout << "Tidak ada transaksi.\n";
            return;
        }
        cout << "Riwayat Transaksi:\n";
        for (int i = top; i >= 0; i--) {
            cout << nama[i] << " - Rp " << total[i] << endl;
        }
    }
};

int main() {
    StackArray s;
    s.push("Ady", 15000);
    s.push("Akbar", 12000);
    s.pop();
    s.push("Diki", 13000);
    s.display();
    return 0;
}