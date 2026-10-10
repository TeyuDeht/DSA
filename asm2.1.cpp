#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char title[100];
    long price;
} Book;

typedef struct {
    Book data[MAX];
    int top;
} Stack;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(const Stack* s) {
    return s->top == -1;
}

int isFull(const Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, Book b) {
    if (isFull(s)) {
        printf("Stack da day!\n");
        return;
    }
    s->data[++(s->top)] = b;
}

double averagePrice(const Stack* s) {
    if (isEmpty(s)) return 0.0;

    double total = 0;
    for (int i = 0; i <= s->top; i++) {
        total += s->data[i].price;
    }
    return total / (s->top + 1);
}

int main() {
    Stack s;
    init(&s);

    int n;
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    clearInputBuffer();

    if (n > MAX) {
        printf("So luong vuot qua suc chua Stack (Toi da %d). Tu dong dat n = %d\n", MAX, MAX);
        n = MAX;
    }

    for (int i = 0; i < n; i++) {
        Book b;
        printf("\nNhap thong tin sach thu %d:\n", i + 1);

        printf("Ma so sach: ");
        scanf("%d", &b.id);
        clearInputBuffer();

        printf("Ten sach: ");
        fgets(b.title, sizeof(b.title), stdin);
        b.title[strcspn(b.title, "\n")] = 0;

        printf("Don gia: ");
        scanf("%ld", &b.price);
        clearInputBuffer();

        push(&s, b);
    }

    printf("\n--- KET QUA ---");
    printf("\nDon gia trung binh cua cac cuon sach: %.2f\n", averagePrice(&s));

    return 0;
}