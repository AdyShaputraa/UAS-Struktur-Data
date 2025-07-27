// Mengelola antrian menggunakan array
// Implementasi Queue dengan Array

#include <iostream>
using namespace std;

#define SIZE 10

class QueueArray {
    string antrian[SIZE]; // Array antrian pelanggan
    int front, rear;

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    // Tambah pelanggan
    void enqueue(string nama) {
        if (rear == SIZE - 1) {
            cout << "Antrian penuh!\n";
            return;
        }
        if (front == -1) front = 0;
        antrian[++rear] = nama;
        cout << nama << " masuk antrian.\n";
    }

    // Proses pelanggan (hapus dari depan)
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Antrian kosong!\n";
            return;
        }
        cout << antrian[front++] << " keluar dari antrian.\n";
    }

    void tampil() {
        if (front == -1 || front > rear) {
            cout << "Antrian kosong!\n";
            return;
        }
        cout << "Antrian saat ini:\n";
        for (int i = front; i <= rear; i++) {
            cout << "- " << antrian[i] << endl;
        }
    }
};

int main() {
    QueueArray q;
    q.enqueue("Ady");
    q.enqueue("Akbar");
    q.dequeue();
    q.enqueue("Diki");
    q.tampil();
    return 0;
}