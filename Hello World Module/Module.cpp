// Module.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


static int LuaFunctionHelloWorld(lua_State* pState)
{
	puts("Hello World!");
	return 0;
}

// The table name, so Module.HelloWorld.anything would be where the functions are
extern "C" __declspec(dllexport) const char* MODULE_NAME = "HelloWorld";

// Ignore pReserved for now, in the future it maybe an interface or context
extern "C" __declspec(dllexport) void _cdecl RegisterFunctions(lua_State* pState, void* pReserved)
{
	// Simply register functions like so, your table is last on the stack
	// Due to sandboxing you cannot register globals
	// You could use setfield and register variables in the table

	// Module.HelloWorld.HelloWorld
	lua_pushstring(pState,"HelloWorld");
	lua_pushcfunction(pState,LuaFunctionHelloWorld);
	lua_settable(pState,-3);

	// Module.HelloWorld.ONE
	lua_pushinteger(pState,1);
	lua_setfield(pState,-2,"ONE");
}
