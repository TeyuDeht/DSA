#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

void binarizeImage(const uint8_t* image, int* binaryImage, int N, int M, int threshold) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int index = i * M + j;
            if (image[index] >= threshold) {
                binaryImage[index] = 1;
            }
            else {
                binaryImage[index] = 0;
            }
        }
    }
}

int main() {
    int N, M, X;

    printf("Nhap so hang N va so cot M cua anh: ");
    scanf("%d %d", &N, &M);
    uint8_t* image = (uint8_t*)malloc(N * M * sizeof(uint8_t));
    int* binaryImage = (int*)malloc(N * M * sizeof(int));

    if (image == NULL || binaryImage == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    printf("Nhap gia tri cac diem anh (0 - 255):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            scanf("%d", &val);
            image[i * M + j] = (uint8_t)val;
        }
    }
    printf("Nhap nguong X: ");
    scanf("%d", &X);

    binarizeImage(image, binaryImage, N, M, X);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", binaryImage[i * M + j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int index = i * M + j;
            printf("image[%d][%d] (chi so 1D: %d) tai dia chi: %p\n",
                i, j, index, (void*)&image[index]);
        }
    }
    free(image);
    free(binaryImage);

    return 0;
}