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
int main()
{
    Node* list=NULL;
    initList(&list);
    insertBegin(&list, 1);
    insertBegin(&list, 2);
    insertBegin(&list, 3);
    insertBegin(&list, 4);
    insertBegin(&list, 5);
    hienThi(list);
    insertEnd(&list, 6);
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