//
// Created by layty on 2023/3/10.
//
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <memory>
#include <iostream>

#include "LuaBridge/LuaBridge.h"
#include "fun1.h"
#include <iomanip>
#include <memory>
#include <string>
#include "sstream"

std::vector<unsigned char> LuaGetVec(const std::string& str) {
    std::vector<unsigned char> vec(str.begin(), str.end());
    return vec;
}


// 打印一个vector
void LuaPrintVec(std::vector<uint8_t> v)
{
    for(auto ch: v)
    {
        printf("%02X",ch);
    }
    printf("\n");
}
std::string LuaVecToString(std::vector<uint8_t> v)
{
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setfill('0');
    for (const auto& c : v) {
        ss << std::setw(2) << static_cast<unsigned int>(c);
    }
    return ss.str();
}


void register_easy (lua_State* luaState) {

    // 辅助函数
    luabridge::getGlobalNamespace(luaState)
        .beginClass<std::vector<uint8_t>>("vecU8").endClass()
        .addFunction("LuaGetVec",&LuaGetVec)
        .addFunction("LuaPrintVec",&LuaPrintVec)
        .addFunction("LuaVecToString",&LuaVecToString);
}
