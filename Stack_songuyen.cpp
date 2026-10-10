//Stack số nguyên

#include <iostream>
#define MAX 50
struct stack {
    int data[MAX];
    int n; //so phan tu hien co
};

void khoitaoNganxep(stack* s) {
    (*s).n = 0;
}
void push(stack* s, int value) {
    if ((*s).n == MAX) {
        printf("\n Ngan xep day");
        return;
    }
    (*s).data[(*s).n] = value;
    (*s).n++;
}

void hienthiNganxep(stack s) {
    if (s.n == 0) {
        printf("\n Ngan xep rong");
        return;
    }
    printf("\n Ngan xep chua: ");
    for (int i = 0;i < s.n;i++) {
        printf("%d ", s.data[i]);
    }
}
void pop(stack* s) {
    if ((*s).n==0) {
        printf("\n Ngan xep rong");
        return;
    }
    (*s).n--;
}

int pop_return(stack* s) {
    if ((*s).n == 0) {
        printf("\n Ngan xep rong");
        return -1;
    }
    int value = (*s).data[(*s).n - 1];
    (*s).n--;
    return value;
}

int peek(stack s) {
    if (s.n == 0) {
        printf("\n Ngan xep rong");
        return -1;
    }
    return s.data[s.n - 1];
}

void doiCoso2(int n) {
    stack s;
    khoitaoNganxep(&s);
    while (n != 0) {
        push(&s, n % 2);
        n = n / 2;
    }
    while (s.n != 0) {
        printf("%d ", pop_return(&s));
    }
}

int kiemtradaungoac(const char* str) {
    stack s;
    khoitaoNganxep(&s);
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '{')
            push(&s, str[i]);
        else if (str[i] == '}') {
            if (s.n == 0)
                return 0;
            else
                pop(&s);
        }i++;
         
        
    }   return (!s.n);
}

int main()
{
    //stack s;
    //khoitaoNganxep(&s);
    //push(&s, 1);
    //push(&s, 2);
    //push(&s, 3);
    //push(&s, 4);
    //push(&s, 5);
    //hienthiNganxep(s);
    //pop(&s);
    //hienthiNganxep(s);
    //int value = pop_return(&s);
    //hienthiNganxep(s);
    //printf("\n Gia tri vua loai bo la: %d",value);
    //doiCoso2(13);
    printf("%d", kiemtradaungoac("{{{}}"));
}