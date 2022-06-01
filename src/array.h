//
// Created by gtygo on 2023/1/10.
//
#include <stdlib.h>
#include "deps/redismodule.h"

#ifndef REDISARRAY_ARRAY_H
#define REDISARRAY_ARRAY_H

#define MAX_DIMS_SIZE 5


/*
 * example:
 *
 * N     3
 * dims  |3|2|3|0|0|
 * steps |6|3|1|0|0|
 * data  |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|
 * ---------------------------------------------------
 *
 * convert 3*2*3 matrix:
 *
 *    0        1         2
 * |0|1|2| |6|7 |8 | |12|13|14|
 * |3|4|5| |9|10|11| |15|16|17|
 *
 *
 */
typedef struct {
    uint8_t N;
    uint32_t dims[MAX_DIMS_SIZE];

    uint64_t steps[MAX_DIMS_SIZE];
    uint64_t len;
    int *data;
} ArrayObjectValue_integer;

int initArrayObj(ArrayObjectValue_integer *obj, int N, const uint32_t *dims);

int lookupSingleData(ArrayObjectValue_integer *obj, const uint32_t *idx);

int setSingleData(ArrayObjectValue_integer *obj, int v, const uint32_t *idx);


#endif //REDISARRAY_ARRAY_H
