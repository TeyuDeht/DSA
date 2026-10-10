#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

struct Document {
    string fileName;
    int totalPages;
};

struct Node {
    Document data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initQueue(Queue& q) {
    q.front = nullptr;
    q.rear = nullptr;
}

bool isEmpty(const Queue& q) {
    return q.front == nullptr;
}

void enqueue(Queue& q, string fileName, int totalPages) {
    Node* newNode = new Node();
    newNode->data.fileName = fileName;
    newNode->data.totalPages = totalPages;
    newNode->next = nullptr;

    if (isEmpty(q)) {
        q.front = newNode;
        q.rear = newNode;
    }
    else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    cout << "-> Da them file '" << fileName << "' (" << totalPages << " trang) vao hang doi in.\n";
}

void dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "-> Hang doi rong! Khong co file nao de in.\n";
        return;
    }

    Node* temp = q.front;
    cout << "-> Dang in va hoàn thanh file: '" << temp->data.fileName
        << "' (" << temp->data.totalPages << " trang).\n";

    q.front = q.front->next;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }

    delete temp;
}
void displayQueue(const Queue& q) {
    if (isEmpty(q)) {
        cout << "-> Hang doi dang rong, khong co file nao dang cho in.\n";
        return;
    }

    cout << "\n=== DANH SACH FILE DANG CHO IN ===\n";
    Node* current = q.front;
    int stt = 1;
    while (current != nullptr) {
        cout << stt++ << ". Ten file: " << current->data.fileName
            << " | So trang: " << current->data.totalPages << endl;
        current = current->next;
    }
    cout << "===================================\n";
}

int main() {
    Queue printQueue;
    initQueue(printQueue);

    int choice;
    do {
        cout << "\n------ CHUONG TRINH MO PHONG MAY IN ------\n";
        cout << "1. Them file vao hang doi in (Enqueue)\n";
        cout << "2. May in thuc hien in (Dequeue)\n";
        cout << "3. Xem danh sach file dang cho in\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string fileName;
            int pages;
            cout << "Nhap ten file: ";
            cin.ignore();
            getline(cin, fileName);
            cout << "Nhap so trang: ";
            cin >> pages;
            enqueue(printQueue, fileName, pages);
            break;
        }
        case 2:
            dequeue(printQueue);
            break;
        case 3:
            displayQueue(printQueue);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hợp le! Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}