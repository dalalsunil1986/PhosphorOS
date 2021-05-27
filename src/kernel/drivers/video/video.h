#ifndef VIDEO_H
#define VIDEO_H

#include <commondef.h>

int vmode;

int curx;
int cury;
uint8_t curtop;
uint8_t curbtm;
int charw;
int charh;
int screenw;
int screenh;
int textw;
int texth;
int tab;

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
void (* vcursorstyle)(uint8_t top, uint64_t bottom);
void (* vsetfgc)(int x, int y, uint8_t c);
void (* vsetbgc)(int x, int y, uint8_t c);

#include "text-mode/text-mode.h"
#include "gfx-mode/gfx-mode.h"
#include "video.c"

#endif