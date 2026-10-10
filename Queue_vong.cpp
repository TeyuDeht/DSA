// Queue_vong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX 5
struct CircleQueue {
    int data[MAX];
    int f;
    int r;
};
void initCircleQueue(CircleQueue* q){
    q->f = q->r = -1;
}
int isEmpty(CircleQueue* q) {
    return q->f == -1;
}
int isFull(CircleQueue* q) {
    return((q->f == 0 && q->r == MAX - 1) || (q->f == q->r + 1));
    //return q->f==(q->r+1)%MAX
}

void enCircleQueue(CircleQueue* q,int value) {
    if (isFull(q)) {
        printf("\nHang doi day");
    }
    if (isEmpty(q)) {
        q->f = q->r = 0;
        q->data[q->f] = value;
        return; 
    }
    q->r = (q->r + 1) % MAX;
    q->data[q->r] = value;
}

void deCircleQueue(CircleQueue* q) {
    if (isEmpty(q)) {
        printf("\nHang doi rong");
        return;
    }
    if (q->f == q->r) {//có 1 ptu
        q->f = q->r = -1;//đưa về rỗng
        return;
    }
    q->f = (q->f + 1) % MAX;
}
int deCircleQueue2(CircleQueue* q) {
    if (isEmpty(q)) {
        printf("\nHang doi rong");
        return -1;
    }
    int val = q->data[q->f];
    if (q->f == q->r) {
        q->f = q->r = -1;
    }
    else {
        q->f = (q->f + 1) % MAX;
    }
    return val;
}
void hienthi(CircleQueue* q) {
    if (isEmpty(q)) {
        printf("\nHang doi rong");
    }
    printf("\nHang doi vong chua: ");
    if (q->f <= q->r) {
        for (int i = q->f;i <= q->r;i++) {
            printf("%d ",q->data[i]);
        }
    }
    else {
        for (int i = q->f;i < MAX;i++)
            printf("%d ", q->data[i]);
        for (int i = 0;i <= q->r;i++)
            printf("%d ", q->data[i]);
    }
}
int main()
{
    CircleQueue q;
    initCircleQueue(&q);
    enCircleQueue(&q, 1);
    enCircleQueue(&q, 2);
    enCircleQueue(&q, 3);
    enCircleQueue(&q, 4);
    enCircleQueue(&q, 5);
    hienthi(&q);
    deCircleQueue(&q);
    deCircleQueue(&q);
    hienthi(&q);
    int removeVal = deCircleQueue2(&q);
    if (removeVal != -1) {
        printf("\nDa lay ra phan tu: %d", removeVal);
    }
    hienthi(&q);
}

