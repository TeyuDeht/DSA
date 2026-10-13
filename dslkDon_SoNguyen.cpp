// dslkDon_SoNguyen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    //Node* newNode = new Node;//C++
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
    //Node* newNode = new Node;//C++
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
    //Node* newNode = new Node;//C++
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
        printf("%d ", (head)->value);
        head = (head)->next;
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
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    if (*head == NULL)
        return;
    if (p == NULL)
        return;
    newNode->next = p->next;
    p->next = newNode;
}

Node* searchNode(Node* head, int value) {
    if (head == NULL)
        return NULL;
    while (head != NULL) {
        if (head->value == value)
            return head;
        head = head->next;
    }
    return NULL;
}
//Do phuc tap O(n)
void insertBefore1(Node** head, Node* p, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    if (*head == NULL)
        return;
    if (p == NULL)
        return;
    //danh sach chi co 1 ptu la p
    if (p == *head && p->next == NULL) {
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
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    if (*head == NULL)
        return;
    if (p == NULL)
        return;
    //danh sach chi co 1 ptu la p
    if (p == *head && p->next == NULL) {
        newNode->next = p;
        *head = newNode;
        return;
    }
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
    if (ptr->next == NULL){
        *head = NULL;
    free(ptr);
    }
    else {
        *head = ptr->next;
        free(ptr);
    }
}
void deleteEnd(Node** head) {
    if (*head == NULL)
        return;
    Node* ptr = *head;
    if (ptr->next == NULL) {
        delete *head;
        *head = NULL;
        return;
    }
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    delete ptr->next;
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
void deteleBefore(Node** head,Node* p) {
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
        if (*head == NULL)
            return;
        Node* ptr = *head;
        if (ptr->next == NULL) {
            *head = NULL;
            free(ptr);
        }
        else {
            *head = ptr->next;
            free(ptr);
        }
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
int main()
{
    Node* list=NULL;
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
    //bo sung 11 vao sau 4
    Node* p = searchNode(list, 4);
    insertAfter(&list, p, 11);
    hienThi(list);
    //bo sung 12 vao truoc 4
    //insertBefore1(&list,p,12);
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
    return 0;
    /*
    initList2(list);
    insertBegin2(list, 1);
    insertBegin2(list, 2);
    insertBegin2(list, 3);
    insertBegin2(list, 4);
    insertBegin2(list, 5);
    hienThi(&list);
    list=initList3(list);
    list=insertBegin3(list, 1);
    list=insertBegin3(list, 2);
    list=insertBegin3(list, 3);
    list=insertBegin3(list, 4);
    list=insertBegin3(list, 5);
    hienThi(&list);
    */

}
    list=insertBegin3(list, 5);
    hienThi(&list);
    */

}
