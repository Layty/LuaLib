//
// Created by layty on 2023/3/10.
//

#ifndef TEST1_FUN1_H
#define TEST1_FUN1_H

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

void register_easy (lua_State* L);

#endif // TEST1_FUN1_H
