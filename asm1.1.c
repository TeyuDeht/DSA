#include <stdio.h>
#include <stdlib.h>

void boSung(int* arr, int* n, int index, int value) {
    if (index < 0 || index > *n) {
        printf("Vi tri chen khong hop le\n");
        return;
    }
    for (int i = *n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*n)++;
}

void loaiBo(int* arr, int* n, int index) {
    if (index < 0 || index >= *n) {
        printf("Vi tri xoa khong hop le\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int getValue(int* arr, int n, int index) {
    if (index < 0 || index >= n) {
        printf("Vi tri truy cap khong hop le\n");
        return -1;
    }
    return arr[index];
}

void inMang(int* arr, int n) {
    printf("Mang hien tai (%d phan tu): ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // TH1: Mảng tĩnh
    int arrTinh[100] = { 10, 20, 30, 40, 50 };
    int nTinh = 5;

    inMang(arrTinh, nTinh);

    boSung(arrTinh, &nTinh, 3, 69);
    inMang(arrTinh, nTinh);

    loaiBo(arrTinh, &nTinh, 4);
    inMang(arrTinh, nTinh);

    int val1 = getValue(arrTinh, nTinh, 1);
    if (val1 != -1) {
        printf("Gia tri tai index 1 la: %d\n", val1);
    }


    // TH2: Mảng động
    int nDong;
    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &nDong);

    int* arrDong = (int*)malloc((nDong + 50) * sizeof(int));
    if (arrDong == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }

    printf("Nhap các phan tu cua mang:\n");
    for (int i = 0; i < nDong; i++) {
        scanf("%d", &arrDong[i]);
    }

    inMang(arrDong, nDong);
    int idx, val;
    printf("Nhap vi tri va gia tri can chen: ");
    scanf("%d %d", &idx, &val);
    boSung(arrDong, &nDong, idx, val);
    inMang(arrDong, nDong);

    printf("Nhap vi tri me can xoa: ");
    scanf("%d", &idx);
    loaiBo(arrDong, &nDong, idx);
    inMang(arrDong, nDong);

    printf("Nhap vi tri can truy cap: ");
    scanf("%d", &idx);
    int val2 = getValue(arrDong, nDong, idx);
    if (val2 != -1) {
        printf("Gia tri tai index %d la: %d\n", idx, val2);
    }
    free(arrDong);
    return 0;
}