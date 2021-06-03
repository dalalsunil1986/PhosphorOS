#ifndef VIDEO_H
#define VIDEO_H

#include <commondef.h>

uint16_t vmode;

int curx;
int cury;
uint8_t curtop;
uint8_t curbtm;
uint16_t charw;
uint16_t charh;
uint16_t screenw;
uint16_t screenh;
uint16_t textw;
uint16_t texth;
uint8_t tab;

uint8_t fgc, bgc;

void (* vsetchar)(int x, int y, char c);
char (* vgetchar)(int x, int y);
void (* vclearcolor)(uint8_t color);
void (* vblankcolor)(uint8_t color);
void (* vclearlinecolor)(int l, uint8_t color);
void (* vblanklinecolor)(int l, uint8_t color);
void (* updatecursor)(void);
void (* vscroll)(int l);
void (* vshiftline)(int l);
void (* vunshiftline)(int l);
uint8_t (* vgetfgc)(int x, int y);
uint8_t (* vgetbgc)(int x, int y);
void (* vhidecursor)(void);
void (* vcursorstyle)(uint8_t top, uint8_t bottom);
void (* vsetfgc)(int x, int y, uint8_t c);
void (* vsetbgc)(int x, int y, uint8_t c);
void (* vsavebuf)(void);
void (* vrestorebuf)(void);

#include "text-mode/text-mode.h"
#include "gfx-mode/gfx-mode.h"
#include "video.c"

#endif