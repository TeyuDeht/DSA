#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define URL_LEN 100

typedef struct {
    char data[MAX][URL_LEN];
    int top;
} StringStack;

void init(StringStack* s) {
    s->top = -1;
}

int isEmpty(const StringStack* s) {
    return s->top == -1;
}

int isFull(const StringStack* s) {
    return s->top == MAX - 1;
}

void push(StringStack* s, const char url[]) {
    if (isFull(s)) {
        return;
    }
    s->top++;
    strcpy(s->data[s->top], url);
}

void pop(StringStack* s, char outUrl[]) {
    if (!isEmpty(s)) {
        strcpy(outUrl, s->data[s->top]);
        s->top--;
    }
}

StringStack backStack;
StringStack forwardStack;
char currentURL[URL_LEN] = "Home";

void visit(const char newUrl[]) {
    if (strlen(currentURL) > 0) {
        push(&backStack, currentURL);
    }
    strcpy(currentURL, newUrl);
    init(&forwardStack);
    printf("Truy cap trang: %s\n", currentURL);
}

void back() {
    if (isEmpty(&backStack)) {
        printf("[Back Order] Khong the Back! (Da o trang dau tien)\n");
        return;
    }
    push(&forwardStack, currentURL);
    pop(&backStack, currentURL);
    printf("Back ve trang: %s\n", currentURL);
}

void next() {
    if (isEmpty(&forwardStack)) {
        printf("[Next Order] Khong the Next! (Chua thuc hien Back hoac da o trang moi nhat)\n");
        return;
    }
    push(&backStack, currentURL);
    pop(&forwardStack, currentURL);
    printf("Next den trang: %s\n", currentURL);
}

int main() {
    init(&backStack);
    init(&forwardStack);

    printf("=== MO PHONG DIAN HUONG WEBSITE ===\n");
    printf("Trang khoi dau: %s\n\n", currentURL);

    visit("google.com");
    visit("github.com");
    visit("facebook.com");

    printf("\n--- Thuc hien thao tac Back / Next ---\n");
    back();
    back();
    next();

    printf("\n--- Truy cap trang moi sau khi Back --- \n");
    visit("youtube.com");
    next();

    return 0;
}