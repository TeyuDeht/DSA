// hangDoiUuTien.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define MAX 50
using namespace std;
//cài đặt hàng đợi ưu tiên lưu trữ các số nguyên
struct Element {
    int value;
    int priority;
};
struct PriorityQueue {
    Element data[MAX];
    int size;
};
void init(PriorityQueue& q) {
    q.size = 0;
}

bool isEmpty(PriorityQueue q) {
    return q.size == 0;
}

bool isFull(PriorityQueue q) {
    return q.size == MAX;
}

bool enqueue(PriorityQueue& q, int val, int pri) {
    if (isFull(q)) {
        return false;
    }
    q.data[q.size].value = val;
    q.data[q.size].priority = pri;
    q.size++;
    return true;
}

bool dequeue(PriorityQueue& q, Element& res) {
    if (isEmpty(q)) {
        return false;
    }
    int bestIdx = 0;
    for (int i = 1; i < q.size; i++) {
        if (q.data[i].priority > q.data[bestIdx].priority) {
            bestIdx = i;
        }
    }
    res = q.data[bestIdx];
    for (int i = bestIdx; i < q.size - 1; i++) {
        q.data[i] = q.data[i + 1];
    }
    q.size--;
    return true;
}
int main() {
    PriorityQueue q;
    init(q);
    enqueue(q, 10, 2);
    enqueue(q, 20, 5);
    enqueue(q, 30, 2);
    enqueue(q, 40, 1);
    cout << "Thu tu lay cac phan tu ra khoi hang doi uu tien:\n";
    Element e;
    while (!isEmpty(q)) {
        dequeue(q, e);
        cout << "- Gia tri: " << e.value << " (Do uu tien: " << e.priority << ")\n";
    }
    return 0;
}