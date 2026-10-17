// asm5.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien {
    char mssv[15];
    char hoTen[50];
    float cpa;
} SinhVien;

typedef struct Node {
    SinhVien data;
    struct Node* next;
} Node;

Node* newNode(SinhVien sv) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = sv;
    p->next = NULL;
    return p;
}
SinhVien taoSV(const char* mssv, const char* hoTen, float cpa) {
    SinhVien sv;
    strncpy(sv.mssv, mssv, sizeof(sv.mssv) - 1);
    sv.mssv[sizeof(sv.mssv) - 1] = '\0';
    strncpy(sv.hoTen, hoTen, sizeof(sv.hoTen) - 1);
    sv.hoTen[sizeof(sv.hoTen) - 1] = '\0';
    sv.cpa = cpa;
    return sv;
}
Node* timSV(Node* head, const char* x) {
    while (head != NULL) {
        if (strcmp(head->data.mssv, x) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

// 1. Bo sung SV vao dau ds
void themDau(Node** head, SinhVien sv) {
    Node* p = newNode(sv);
    p->next = *head;
    *head = p;
}
// 2. Bo sung SV vao cuoi ds
void themCuoi(Node** head, SinhVien sv) {
    Node* p = newNode(sv);
    if (*head == NULL) {
        *head = p;
        return;
    }
    Node* ptr = *head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = p;
}
// 3. Bo sung SV vao sau SV co ma so la X (tra ve 0 neu khong tim thay X)
int themSauX(Node** head, const char* x, SinhVien sv) {
    Node* q = timSV(*head, x);
    if (q == NULL)
        return 0;
    Node* p = newNode(sv);
    p->next = q->next;
    q->next = p;
    return 1;
}
// 5. Xoa SV o dau ds
void xoaDau(Node** head) {
    if (*head == NULL)
        return;
    Node* tmp = *head;
    *head = tmp->next;
    free(tmp);
}
// 6. Xoa SV o cuoi ds
void xoaCuoi(Node** head) {
    if (*head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* ptr = *head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    free(ptr->next);
    ptr->next = NULL;
}
// 4. Xoa SV co ma so la X (tra ve 0 neu khong tim thay)
int xoaX(Node** head, const char* x) {
    if (*head == NULL)
        return 0;
    if (strcmp((*head)->data.mssv, x) == 0) {
        xoaDau(head);
        return 1;
    }
    Node* ptr = *head;
    while (ptr->next != NULL && strcmp(ptr->next->data.mssv, x) != 0)
        ptr = ptr->next;
    if (ptr->next == NULL)
        return 0;
    Node* tmp = ptr->next;
    ptr->next = tmp->next;
    free(tmp);
    return 1;
}
// 7. Cap nhat CPA cho SV co ma so la X
int capNhatCPA(Node* head, const char* x, float cpaMoi) {
    Node* p = timSV(head, x);
    if (p == NULL)
        return 0;
    p->data.cpa = cpaMoi;
    return 1;
}
// 8. Tinh CPA trung binh cua tat ca SV
float cpaTrungBinh(Node* head) {
    if (head == NULL)
        return 0;
    float tong = 0;
    int dem = 0;
    while (head != NULL) {
        tong += head->data.cpa;
        dem++;
        head = head->next;
    }
    return tong / dem;
}

void hienThi(Node* head) {
    if (head == NULL) {
        printf("\nDanh sach rong");
        return;
    }
    printf("\n%-12s%-22s%s", "MSSV", "Ho ten", "CPA");
    while (head != NULL) {
        printf("\n%-12s%-22s%.2f", head->data.mssv, head->data.hoTen, head->data.cpa);
        head = head->next;
    }
}
void giaiPhong(Node** head) {
    while (*head != NULL)
        xoaDau(head);
}

int main()
{
    Node* ds = NULL;
    themDau(&ds, taoSV("SV002", "Tran Thi B", 3.2f));
    themDau(&ds, taoSV("SV001", "Nguyen Van A", 3.5f));
    themCuoi(&ds, taoSV("SV004", "Pham Van D", 2.8f));
    printf("Sau khi them dau, them cuoi:");
    hienThi(ds);

    themSauX(&ds, "SV002", taoSV("SV003", "Le Van C", 3.9f));
    printf("\n\nThem SV003 vao sau SV002:");
    hienThi(ds);

    capNhatCPA(ds, "SV004", 3.0f);
    printf("\n\nCap nhat CPA cua SV004 thanh 3.0:");
    hienThi(ds);

    printf("\n\nCPA trung binh: %.2f", cpaTrungBinh(ds));

    xoaX(&ds, "SV003");
    printf("\n\nXoa SV003:");
    hienThi(ds);

    xoaDau(&ds);
    printf("\n\nXoa dau:");
    hienThi(ds);

    xoaCuoi(&ds);
    printf("\n\nXoa cuoi:");
    hienThi(ds);

    giaiPhong(&ds);
    return 0;
}
