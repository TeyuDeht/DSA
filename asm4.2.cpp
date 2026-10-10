// asm4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack s) {
    return s.top == -1;
}

int isFull(struct Stack s) {
    return s.top == MAX - 1;
}

int push(struct Stack* s, int val) {
    if (isFull(*s)) {
        return 0;
    }
    s->data[++s->top] = val;
    return 1;
}

int pop(struct Stack* s, int* val) {
    if (isEmpty(*s)) {
        return 0;
    }
    *val = s->data[s->top--];
    return 1;
}

int evaluatePostfix(char expr[]) {
    struct Stack s;
    initStack(&s);
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&s, atoi(token));
        }
        else {
            int op1, op2;
            pop(&s, &op2);
            pop(&s, &op1);
            int res = 0;

            if (strcmp(token, "+") == 0) {
                res = op1 + op2;
            }
            else if (strcmp(token, "-") == 0) {
                res = op1 - op2;
            }
            else if (strcmp(token, "*") == 0) {
                res = op1 * op2;
            }
            else if (strcmp(token, "/") == 0) {
                if (op2 != 0) {
                    res = op1 / op2;
                }
                else {
                    printf("Loi: Loi chia cho 0!\n");
                    return 0;
                }
            }
            push(&s, res);
        }
        token = strtok(NULL, " ");
    }
    int finalResult;
    pop(&s, &finalResult);
    return finalResult;
}
int main() {
    char expr[100] = "5 3 + 2 *";
    printf("Bieu thuc hau to: %s\n", expr);
    int kq = evaluatePostfix(expr);
    printf("Gia tri cua bieu thuc la: %d\n", kq);
    return 0;
}