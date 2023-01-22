#include "../src/ssd1351.h"
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "picoglue.h"
#include "math.h"
#include "stdlib.h"

int P8_drawLine(lua_State *L){
  int16_t x0, y0, x1, y1;
  uint8_t c_index;
  uint16_t color;
  if (lua_gettop(L) == 5){
    x0 = luaL_checknumber(L, 1);
    y0 = luaL_checknumber(L, 2);
    x1 = luaL_checknumber(L, 3);
    y1 = luaL_checknumber(L, 4);
    c_index = luaL_checknumber(L, 5);
    color = color_palette[c_index];
    SSD1351_draw_line(x0, y0, x1, y1, color);
  }
  lua_pushnil(L);
  return 1;
}