#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define TEXT_LEN 200

typedef struct {
    char data[MAX][TEXT_LEN];
    int top;
} TextStack;

void init(TextStack* s) {
    s->top = -1;
}

int isEmpty(const TextStack* s) {
    return s->top == -1;
}

int isFull(const TextStack* s) {
    return s->top == MAX - 1;
}

void push(TextStack* s, const char text[]) {
    if (isFull(s)) {
        return;
    }
    s->top++;
    strcpy(s->data[s->top], text);
}

void pop(TextStack* s, char outText[]) {
    if (!isEmpty(s)) {
        strcpy(outText, s->data[s->top]);
        s->top--;
    }
}

TextStack undoStack;
TextStack redoStack;
char currentText[TEXT_LEN] = "";

void typeText(const char newText[]) {
    push(&undoStack, currentText);
    strcat(currentText, newText);
    init(&redoStack);
    printf("Van ban hien tai: \"%s\"\n", currentText);
}

void undo() {
    if (isEmpty(&undoStack)) {
        printf("[Undo] Khong the Undo! (Chua co thao tac nao)\n");
        return;
    }
    push(&redoStack, currentText);
    pop(&undoStack, currentText);
    printf("[Undo] Van ban: \"%s\"\n", currentText);
}

void redo() {
    if (isEmpty(&redoStack)) {
        printf("[Redo] Khong the Redo! (Chua thuc hien Undo hoac da nhap van ban moi)\n");
        return;
    }
    push(&undoStack, currentText);
    pop(&redoStack, currentText);
    printf("[Redo] Van ban: \"%s\"\n", currentText);
}

int main() {
    init(&undoStack);
    init(&redoStack);

    printf("=== MO PHONG UNDO / REDO TRAN WORD ===\n\n");
    typeText("Xin chao ");
    typeText("C language! ");
    typeText("Stack rat hay.");

    printf("\n--- Thuc hien Undo / Redo ---\n");
    undo();
    undo();
    redo();

    printf("\n--- Nhap them van ban moi ---\n");
    typeText("Lap trinh C.");
    redo();

    return 0;
}