// Mengelola antrian menggunakan array
// Implementasi Queue dengan Array

#include <iostream> // untuk input-output
using namespace std;

#define MAX 100 // batas maksimal antrian

class QueueArray {
private:
    string data[MAX]; // array untuk menyimpan nama pelanggan
    int front, rear;  // indeks depan dan belakang antrian

public:
    QueueArray() {
        front = rear = -1; // inisialisasi antrian kosong
    }

    // Fungsi untuk menambahkan pelanggan ke antrian
    void enqueue(string nama) {
        if (rear == MAX - 1) { // jika antrian penuh
            cout << "Antrian penuh!\n";
            return;
        }

        if (front == -1) front = 0; // jika antrian masih kosong

        rear++; // geser indeks belakang
        data[rear] = nama; // masukkan data ke array
        cout << nama << " masuk antrian.\n";
    }

    // Fungsi untuk menghapus pelanggan dari antrian
    void dequeue() {
        if (front == -1 || front > rear) { // jika antrian kosong
            cout << "Antrian kosong!\n";
            return;
        }

        cout << data[front] << " keluar dari antrian.\n";
        front++; // geser indeks depan

        if (front > rear) front = rear = -1; // reset jika antrian habis
    }

    // Menampilkan isi antrian
    void tampil() {
        if (front == -1) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << "Antrian saat ini:\n";
        for (int i = front; i <= rear; i++) {
            cout << "- " << data[i] << endl;
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