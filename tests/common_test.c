//
// Created by gtygo on 2023/1/10.
//
#include "src/array.h"

void printArr(ArrayObjectValue_integer *obj, int flag);

int main() {
    printf("asdasdasd\n");

    ArrayObjectValue_integer obj;

    const uint32_t dims[] = {3, 2};
    initArrayObj(&obj, 2, dims);

    printArr(&obj, 1);

    int c = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            const uint32_t x[] = {i, j};
            setSingleData(&obj, c, x);
            c++;
        }
    }
    const uint32_t x[] = {2, 1};
    setSingleData(&obj,1001,x);


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            const uint32_t x[] = {i, j};
            printf("%d ", lookupSingleData(&obj, x));
        }
        printf("\n");
    }
    printArr(&obj, 1);


}

void printArr(ArrayObjectValue_integer *obj, int flag) {
    if (flag) {
        for (int i = 0; i < obj->len; i++) {
            printf("%d ", obj->data[i]);
        }

        printf("\n");
        return;
    }

}