//
// Created by layty on 2023/3/10.
//

#ifndef TEST1_MYEXPROT_H
#define TEST1_MYEXPROT_H

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "fun1.h"

#ifdef _MSC_VER
#define XERCESLUA __declspec(dllexport)
#else
#define XERCESLUA
#endif

extern "C" XERCESLUA int luaopen_libEasy (lua_State* L) {
    register_easy(L);
  return 1;
}

#endif // TEST1_MYEXPROT_H
