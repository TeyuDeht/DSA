// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX 50
struct Queue {
    int data[MAX];
    int f;//chỉ số ptu đầu hàng đợi 
    int r;//chỉ số ptu cuối hàng đợi
};
void initQueue(Queue* q) {
    q->f = q->r = -1;
}
int isFull(Queue q) {
    return q.r == MAX - 1;
}
int isEmpty(Queue q) {
    return q.f == -1;
}
//Bổ sung ptu vào hàng đợi
void enQueue(Queue* q, int value) {
    if (isFull(*q)) {
        printf("\nHang doi day");
        return;
    }
    if (isEmpty(*q)) {
        q->f = q->r = 0;
        //(*q).r=(*q).r=0  tương đương lệnh trên
        q->data[q->f] = value;
        return;
    }
    q->r++;
    q->data[q->r] = value;
}

//Bỏ ptu khỏi hàng đợi
void deQueue(Queue* q) {
    if (isEmpty(*q)) {
        printf("\nHang doi rong");
        return;
    }
    if (q->f == q->r) {//có 1 ptu
        q->f = q->r = -1;
        return;
    }
    q->f++;
}
//Bỏ ptu và trả về
int deQueue2(Queue* q) {
    if (isEmpty(*q)) {
        printf("\nHang doi rong");
        return -1;
    }
    int value=q->data[q->f]
    if (q->f == q->r) {
        q->f = q->r = -1;
    }
    else {
        (q->f)++;
    }
    return value;
}
void hienthiHangdoi(Queue* q) {
    if (isEmpty(*q)) {
        printf("\nHang doi rong");
        return;
    }
    printf("\nHang doi chua: ");
    for (int i = q->f;i <= q->r;i++) {
        printf("%d ", q->data[i]);
    }
}
int main()
{
    Queue q;
    initQueue(&q);
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 6);
    hienthiHangdoi(&q);
    deQueue(&q);
    hienthiHangdoi(&q);
    deQueue2(&q);
    hienthiHangdoi(&q);
}