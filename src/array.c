//
// Created by gtygo on 2023/1/10.
//

#include "array.h"
#include <inttypes.h>
#include <string.h>


int initArrayObj(ArrayObjectValue_integer *obj, int N, const uint32_t *dims) {
    obj->N = N;
    memset(obj->dims, 0, sizeof(obj->dims));
    memset(obj->steps, 0, sizeof(obj->steps));
    uint64_t tSize = 1;
    for (int i = 0; i < N; i++) {
        uint64_t cb1_ = (i + 1) < N ? dims[i + 1] : 1;
        uint64_t cb2_ = (i + 2) < N ? dims[i + 2] : 1;
        tSize *= dims[i];
        obj->dims[i] = dims[i];
        obj->steps[i] = cb1_ * cb2_;
    }
    obj->len = tSize;

    //todo : change RedisModule_alloc
    obj->data = (int *) malloc(tSize * sizeof(int));
    if (!obj->data)
        return 0;
    memset(obj->data, 0, tSize * sizeof(int));
    return 1;

}


int lookupSingleData(ArrayObjectValue_integer *obj, const uint32_t *idx) {
    uint64_t lk_ = 0;

    for (int i = 0; i < obj->N; i++) {
        lk_ += obj->steps[i] * idx[i];
    }
    return obj->data[lk_];
}

int setSingleData(ArrayObjectValue_integer *obj, int v, const uint32_t *idx) {
    uint64_t lk_ = 0;
    int ans;
    for (int i = 0; i < obj->N; i++) {
        lk_ += obj->steps[i] * idx[i];
    }
    ans = obj->data[lk_];
    obj->data[lk_] = v;
    return ans;
}