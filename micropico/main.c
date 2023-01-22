#include "../src/ssd1351.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "picoglue.h"
#include "math.h"
#include "stdlib.h"

#define DEMO_RECTANGLES

void bail(lua_State *L, char *msg){
	fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
		msg, lua_tostring(L, -1));
	exit(1);
}

int main(){
  lua_State *L;

  L = luaL_newstate();                        /* Create Lua state variable */
  luaL_openlibs(L);                           /* Load Lua libraries */
  lua_pushcfunction(L, P8_drawLine);          /* Push binding to lua stack*/
  lua_setglobal(L, "line");

  SSD1351_init();
  SSD1351_fill(COLOR_BLACK);
  if (luaL_loadfile(L, "../helloscript.lua"))    /* Load but don't run the Lua script */
    bail(L, "luaL_loadfile() failed");      /* Error out if file can't be read */
  
  printf("In C, calling Lua\n");

  if (lua_pcall(L, 0, 0, 0))                  /* Run the loaded Lua script */
    bail(L, "lua_pcall() failed");          /* Error out if Lua file has an error */

  SSD1351_update();
  printf("Back in C again\n");

  lua_close(L);                               /* Clean up, free the Lua state var */

  return 0;
}