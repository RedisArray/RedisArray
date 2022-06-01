cmake_minimum_required(VERSION 3.23)
project(RedisArray C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(deps)

add_executable(test tests/common_test.c src/array.h src/array.c deps/redismodule.h)

add_library(redisarray.so SHARED
        deps/redismodule.h
        src/commands.c src/commands.h src/array.c src/array.h)
add_compile_options(redisarray.so -fPIC)

set_target_properties(redisarray.so PROPERTIES PREFIX "" SUFFIX "")