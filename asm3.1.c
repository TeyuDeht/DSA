#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int stt;
    char hoTen[50];
} KhachHang;

typedef struct {
    KhachHang data[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(CircularQueue* q) {
    return q->count == MAX;
}

int isEmpty(CircularQueue* q) {
    return q->count == 0;
}

void enqueue(CircularQueue* q, KhachHang kh) {
    if (isFull(q)) {
        printf("Hang cho da day, khong the nhan thêm khach hang!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = kh;
    q->count++;
    printf("Da them khach hang '%s' (STT: %d) vao hang cho.\n", kh.hoTen, kh.stt);
}

void dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Hang cho rong, khong co khach hang de phuc vu!\n");
        return;
    }
    KhachHang kh = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Da phuc vu xong khach hang: %s (STT: %d)\n", kh.hoTen, kh.stt);
}

void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Hien tai khong co khach hang nao trong hang cho.\n");
        return;
    }
    printf("\n--- DANH SACH KHACH HANG ĐANG CHO ---\n");
    printf("%-10s %-30s\n", "STT", "Ho va Ten");
    printf("----------------------------------------\n");

    int i = q->front;
    for (int c = 0; c < q->count; c++) {
        printf("%-10d %-30s\n", q->data[i].stt, q->data[i].hoTen);
        i = (i + 1) % MAX;
    }
    printf("----------------------------------------\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice;
    int sttAuto = 1;

    do {
        printf("\n================ MENU ================\n");
        printf("1. Khach den (Enqueue)\n");
        printf("2. Phuc vu xong khach (Dequeue)\n");
        printf("3. Hien thi danh sach khach dang cho\n");
        printf("0. Thoat\n");
        printf("======================================\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1: {
            KhachHang kh;
            kh.stt = sttAuto++;
            printf("Nhap ho ten khach hang: ");
            fgets(kh.hoTen, sizeof(kh.hoTen), stdin);
            kh.hoTen[strcspn(kh.hoTen, "\n")] = 0;
            enqueue(&q, kh);
            break;
        }
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 0:
            printf("Da thoat chuong trinh.\n");
            break;
        default:
            printf("Lưa chon khong hop le, vui long chon lai!\n");
        }
    } while (choice != 0);

    return 0;
}