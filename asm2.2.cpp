#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void init(CharStack* s) {
    s->top = -1;
}

void push(CharStack* s, char c) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(CharStack* s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0';
}

int isPalindrome(char str[]) {
    CharStack s;
    init(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("Nhap chuoi can kiem tra: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    if (isPalindrome(str)) {
        printf("Chuoi \"%s\" LA chuoi doi xung.\n", str);
    }
    else {
        printf("Chuoi \"%s\" KHONG PHAI la chuoi doi xung.\n", str);
    }

    return 0;
}