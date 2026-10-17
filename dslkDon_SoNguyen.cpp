// dslkDon_SoNguyen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
struct Node {
    int value;
    Node* next;
};
void initList(Node** head) {
    *head = NULL;
}
void initList2(Node*& head) {
    head = NULL;
}
Node* initList3(Node* head) {
    head = NULL;
    return head;
}
void insertBegin(Node** head, int _value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = _value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}
void insertBegin2(Node*& head, int _value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = _value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
Node* insertBegin3(Node* head, int _value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = _value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}
void hienThi(Node* head) {
    if (head == NULL) {
        printf("\nDanh sach rong");
        return;
    }
    printf("\nDanh sach chua: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}
void insertEnd(Node** head, int _value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = _value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}
void insertAfter(Node** head, Node* p, int value) {
    if (*head == NULL || p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = p->next;
    p->next = newNode;
}
Node* searchNode(Node* head, int value) {
    while (head != NULL) {
        if (head->value == value)
            return head;
        head = head->next;
    }
    return NULL;
}
//Do phuc tap O(n)
void insertBefore1(Node** head, Node* p, int value) {
    if (*head == NULL || p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    if (p == *head) {
        newNode->next = p;
        *head = newNode;
        return;
    }
    Node* ptr = *head;
    while (ptr->next != p)
        ptr = ptr->next;
    newNode->next = p;
    ptr->next = newNode;
}
//do phuc tap O(1)
void insertBefore2(Node** head, Node* p, int value) {
    if (*head == NULL || p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    // chen newNode vao sau p, roi hoan doi gia tri
    newNode->value = p->value;
    p->value = value;
    newNode->next = p->next;
    p->next = newNode;
}
//xoa ptu o dau danh sach
void deleteBegin(Node** head) {
    if (*head == NULL)
        return;
    Node* ptr = *head;
    *head = ptr->next;
    free(ptr);
}
void deleteEnd(Node** head) {
    if (*head == NULL)
        return;
    Node* ptr = *head;
    if (ptr->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}
//xoa ptu sau p
void deleteAfter(Node* p) {
    if (p == NULL || p->next == NULL)
        return;
    Node* temp = p->next;
    p->next = temp->next;
    free(temp);
}
//xoa ptu truoc p
void deteleBefore(Node** head, Node* p) {
    if (head == NULL || *head == NULL || p == NULL || *head == p)
        return;
    if ((*head)->next == p) {
        Node* temp = *head;
        *head = p;
        free(temp);
        return;
    }
    Node* ptr = *head;
    while (ptr->next != NULL && ptr->next->next != p) {
        ptr = ptr->next;
    }
    if (ptr->next != NULL && ptr->next->next == p) {
        Node* temp = ptr->next;
        ptr->next = p;
        free(temp);
    }
}
//xoa p
void deleteP(Node** head, Node* p) {
    if (head == NULL || *head == NULL || p == NULL)
        return;
    if (*head == p) {
        *head = p->next;
        free(p);
        return;
    }
    Node* ptr = *head;
    while (ptr->next != NULL && ptr->next != p) {
        ptr = ptr->next;
    }
    if (ptr->next == p) {
        ptr->next = p->next;
        free(p);
    }
}
void noiDanhSach(Node** head1, Node* head2) {
    if (head2 == NULL)
        return;
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    Node* ptr = *head1;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head2;
}
void noiDanhSachSauP(Node* p, Node* head2) {
    if (p == NULL || head2 == NULL)
        return;
    Node* tail2 = head2;
    while (tail2->next != NULL)
        tail2 = tail2->next;
    tail2->next = p->next;
    p->next = head2;
}
void daoNguoc(Node** head) {
    Node* prev = NULL;
    Node* cur = *head;
    while (cur != NULL) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}
void sapXepTang(Node* head) {
    for (Node* i = head; i != NULL && i->next != NULL; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->value < minNode->value)
                minNode = j;
        }
        if (minNode != i) {
            int tmp = i->value;
            i->value = minNode->value;
            minNode->value = tmp;
        }
    }
}

int main()
{
    Node* list = NULL;
    initList(&list);
    insertBegin(&list, 1);
    hienThi(list);
    deleteBegin(&list);
    hienThi(list);
    insertBegin(&list, 2);
    insertBegin(&list, 3);
    insertBegin(&list, 4);
    insertBegin(&list, 5);
    hienThi(list);
    insertEnd(&list, 6);
    hienThi(list);
    Node* p = searchNode(list, 4);
    insertAfter(&list, p, 11);
    hienThi(list);
    insertBefore2(&list, p, 12);
    hienThi(list);
    deleteBegin(&list);
    hienThi(list);
    deleteEnd(&list);
    hienThi(list);
    deleteAfter(p);
    hienThi(list);
    deteleBefore(&list, p);
    hienThi(list);
    deleteP(&list, p);
    hienThi(list);
    Node* ds1 = NULL;
    Node* ds2 = NULL;
    insertEnd(&ds1, 5);
    insertEnd(&ds1, 1);
    insertEnd(&ds1, 9);
    insertEnd(&ds2, 7);
    insertEnd(&ds2, 3);
    printf("\nds1:"); hienThi(ds1);
    printf("\nds2:"); hienThi(ds2);
    noiDanhSach(&ds1, ds2);
    printf("\nSau khi noi ds2 vao sau ds1:"); hienThi(ds1);
    daoNguoc(&ds1);
    printf("\nSau khi dao nguoc:"); hienThi(ds1);
    sapXepTang(ds1);
    printf("\nSau khi sap xep tang dan:"); hienThi(ds1);
    Node* a = NULL;
    Node* b = NULL;
    insertEnd(&a, 1);
    insertEnd(&a, 2);
    insertEnd(&a, 3);
    insertEnd(&b, 100);
    insertEnd(&b, 200);
    Node* q = searchNode(a, 2);
    noiDanhSachSauP(q, b);
    printf("\nNoi ds2 (100 200) vao sau phan tu 2 cua ds1 (1 2 3):"); hienThi(a);
    return 0;
}
