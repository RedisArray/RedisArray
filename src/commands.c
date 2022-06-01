//
// Created by gtygo on 2022/11/15.
//

#include "deps/redismodule.h"
#include "commands.h"




int ArrayRange_RedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);
    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);

    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);
    RedisModule_ReplyWithLongLong(ctx,1);
    RedisModule_ReplyWithLongLong(ctx,2);
    RedisModule_ReplyWithLongLong(ctx,3);

    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);
    RedisModule_ReplyWithLongLong(ctx,10);
    RedisModule_ReplyWithLongLong(ctx,20);
    RedisModule_ReplyWithLongLong(ctx,30);
    RedisModule_ReplyWithLongLong(ctx,40);



    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);

    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);
    RedisModule_ReplyWithLongLong(ctx,1);
    RedisModule_ReplyWithLongLong(ctx,2);
    RedisModule_ReplyWithLongLong(ctx,3);

    RedisModule_ReplyWithArray(ctx,REDISMODULE_POSTPONED_ARRAY_LEN);
    RedisModule_ReplyWithLongLong(ctx,10);
    RedisModule_ReplyWithLongLong(ctx,20);
    RedisModule_ReplyWithLongLong(ctx,30);
    RedisModule_ReplyWithLongLong(ctx,40);


    RedisModule_ReplySetArrayLength(ctx,4);
    RedisModule_ReplySetArrayLength(ctx,3);
    RedisModule_ReplySetArrayLength(ctx,2); // Set len of top array
    RedisModule_ReplySetArrayLength(ctx,4);
    RedisModule_ReplySetArrayLength(ctx,3);
    RedisModule_ReplySetArrayLength(ctx,2); // Set len of top array
    RedisModule_ReplySetArrayLength(ctx,2);


    return REDISMODULE_OK;
}


int ArrayCreate_RedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    RedisModule_ReplyWithSimpleString(ctx, "OK");

    return REDISMODULE_OK;
}

int ArrayLen_RedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {

    int count = 3;

    RedisModule_ReplyWithArray(ctx, count);
    while (count--) {
        RedisModule_ReplyWithLongLong(ctx, 3);
    }

    return REDISMODULE_OK;
}



int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    if (RedisModule_Init(ctx, REDISARRAY_MODULE_NAME, REDISARRAY_VER, REDISMODULE_APIVER_1) == REDISMODULE_ERR) return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, REDISARRAY_CREATE_CMD, ArrayCreate_RedisCommand, REDISARRAY_WD_FLAG, 0, 0, 0) ==
        REDISMODULE_ERR)
        return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, REDISARRAY_RANGE_CMD, ArrayRange_RedisCommand, REDISARRAY_R_FLAG, 0, 0, 0) ==
        REDISMODULE_ERR)
        return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, REDISARRAY_LEN_CMD, ArrayLen_RedisCommand, REDISARRAY_R_FLAG, 0, 0, 0) ==
        REDISMODULE_ERR)
        return REDISMODULE_ERR;

    return REDISMODULE_OK;
}




