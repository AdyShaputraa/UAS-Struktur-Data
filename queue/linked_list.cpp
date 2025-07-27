// Mengelola antrian menggunakan linked list
// Implementasi Queue dengan Linked List

#include <iostream>
using namespace std;

struct Pelanggan {
    string nama;
    Pelanggan* next;
};

class QueueLinkedList {
    Pelanggan *front, *rear;

public:
    QueueLinkedList() {
        front = rear = nullptr;
    }

    void enqueue(string nama) {
        Pelanggan* baru = new Pelanggan{nama, nullptr};
        if (!rear)
            front = rear = baru;
        else {
            rear->next = baru;
            rear = baru;
        }
        cout << nama << " masuk antrian.\n";
    }

    void dequeue() {
        if (!front) {
            cout << "Antrian kosong!\n";
            return;
        }
        Pelanggan* temp = front;
        front = front->next;
        cout << temp->nama << " keluar dari antrian.\n";
        delete temp;
        if (!front) rear = nullptr;
    }

    void tampil() {
        Pelanggan* temp = front;
        if (!temp) {
            cout << "Antrian kosong!\n";
            return;
        }
        cout << "Antrian saat ini:\n";
        while (temp) {
            cout << "- " << temp->nama << endl;
            temp = temp->next;
        }
    }
};

int main() {
    QueueLinkedList q;
    q.enqueue("Ady");
    q.enqueue("Akbar");
    q.dequeue();
    q.enqueue("Diki");
    q.tampil();
    return 0;
}
