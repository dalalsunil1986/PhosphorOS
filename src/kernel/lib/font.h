#ifndef FONT_8x16_H
#define FONT_8x16_H

uint8_t font[256][16] = {
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x7e,0x81,0xa5,0xa5,0x81,0x81,0xbd,0x99,0x81,0x7e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x7e,0xff,0xdb,0xdb,0xff,0xff,0xc3,0xe7,0xff,0x7e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x66,0xff,0xff,0xff,0xff,0x7e,0x3c,0x18,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x3c,0x7e,0xff,0xff,0x7e,0x3c,0x18,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x18,0x3c,0x3c,0x5a,0xff,0xff,0x5a,0x18,0x18,0x3c,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x18,0x3c,0x7e,0xff,0xff,0xff,0x5a,0x18,0x18,0x3c,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xc3,0xc3,0xe7,0xff,0xff,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0x00,0x3c,0x66,0x42,0x42,0x66,0x3c,0x00,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0xff,0xc3,0x99,0xbd,0xbd,0x99,0xc3,0xff,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x78,0x70,0x58,0x4c,0x1e,0x33,0x33,0x33,0x33,0x1e,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x3c,0x18,0x7e,0x18,0x18,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x10,0x30,0x70,0xd0,0x10,0x10,0x10,0x1e,0x1f,0x0e,0x00,0x00,0x00,0x00},
    {0x00,0x08,0x18,0x38,0x68,0x58,0x68,0x48,0x4e,0x4f,0x46,0x70,0x78,0x30,0x00,0x00},
    {0x00,0x00,0x18,0x18,0xdb,0x7e,0x3c,0xff,0x3c,0x7e,0xdb,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x00,0x06,0x0e,0x1e,0x3e,0x7e,0x7e,0x3e,0x1e,0x0e,0x06,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x60,0x70,0x78,0x7c,0x7e,0x7e,0x7c,0x78,0x70,0x60,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x08,0x1c,0x3e,0x7f,0x1c,0x1c,0x1c,0x1c,0x7f,0x3e,0x1c,0x08,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x66,0x00,0x00,0x00},
    {0x00,0xfe,0xdb,0xdb,0xdb,0xdb,0xde,0xdc,0xf8,0xd8,0xd8,0xd8,0xd8,0x00,0x00,0x00},
    {0x00,0x78,0x0c,0x0c,0x1e,0x3b,0x73,0xe7,0xce,0xdc,0x78,0x30,0x30,0x1e,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x7e,0x7e,0x7e,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x08,0x1c,0x3e,0x7f,0x1c,0x1c,0x1c,0x7f,0x3e,0x1c,0x08,0x00,0x7f,0x00},
    {0x00,0x00,0x08,0x1c,0x3e,0x7f,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x00,0x00},
    {0x00,0x00,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x7f,0x3e,0x1c,0x08,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x10,0x30,0x7f,0xff,0x7f,0x30,0x10,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x08,0x0c,0xfe,0xff,0xfe,0x0c,0x08,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0xff,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x24,0x66,0xff,0xff,0x66,0x24,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x3c,0x3c,0x7e,0x7e,0xff,0xff,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0xff,0xff,0x7e,0x7e,0x3c,0x3c,0x18,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x33,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0xff,0x66,0x66,0x66,0xff,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x3c,0x66,0x66,0x06,0x3c,0x60,0x66,0x66,0x3c,0x18,0x18,0x00,0x00},
    {0x00,0x0e,0x1b,0x1b,0x0e,0xc0,0x70,0x1c,0x07,0x70,0xd8,0xd8,0x70,0x00,0x00,0x00},
    {0x00,0x1c,0x36,0x36,0x36,0x1e,0x0c,0x7c,0x36,0x36,0x36,0x36,0x6c,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x0c,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x60,0x30,0x18,0x18,0x0c,0x0c,0x0c,0x0c,0x0c,0x18,0x18,0x30,0x60,0x00,0x00},
    {0x00,0x06,0x0c,0x18,0x18,0x30,0x30,0x30,0x30,0x30,0x18,0x18,0x0c,0x06,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x18,0xff,0x3c,0x3c,0x66,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xff,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x0c,0x04,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x30,0x30,0x30,0x18,0x18,0x18,0x0c,0x0c,0x0c,0x06,0x06,0x06,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x76,0x7e,0x6e,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x1c,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3c,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x60,0x60,0x60,0x3c,0x06,0x06,0x66,0x66,0x7e,0x00,0x00,0x00},
    {0x00,0x7e,0x66,0x66,0x30,0x30,0x38,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x60,0x70,0x70,0x78,0x68,0x6c,0x64,0x66,0xfe,0x60,0x60,0x60,0x00,0x00,0x00},
    {0x00,0x7e,0x66,0x66,0x06,0x06,0x3e,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x06,0x06,0x3e,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x7e,0x66,0x66,0x60,0x30,0x30,0x18,0x18,0x0c,0x0c,0x0c,0x0c,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x66,0x3c,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x0c,0x00,0x00,0x00},
    {0x00,0x00,0x60,0x30,0x18,0x0c,0x06,0x06,0x0c,0x18,0x30,0x60,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x06,0x0c,0x18,0x30,0x60,0x60,0x30,0x18,0x0c,0x06,0x00,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x60,0x60,0x30,0x18,0x18,0x18,0x00,0x00,0x18,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x76,0x76,0x76,0x76,0x76,0x36,0x06,0x06,0x3c,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x7e,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x3e,0x66,0x66,0x66,0x66,0x3e,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00},
    {0x00,0x7c,0x06,0x06,0x06,0x06,0x1e,0x06,0x06,0x06,0x06,0x06,0x7c,0x00,0x00,0x00},
    {0x00,0x7c,0x06,0x06,0x06,0x06,0x3e,0x06,0x06,0x06,0x06,0x06,0x06,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x06,0x06,0x06,0x76,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x66,0x66,0x7e,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x78,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x66,0x36,0x1e,0x1e,0x36,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x66,0x7e,0x00,0x00,0x00},
    {0x00,0x63,0x77,0x7f,0x6b,0x6b,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x6e,0x7e,0x76,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x3e,0x06,0x06,0x06,0x06,0x06,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x60,0x60,0x40},
    {0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x3e,0x36,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x06,0x06,0x3c,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x7e,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x3c,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x6b,0x6b,0x7f,0x77,0x63,0x63,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x3c,0x3c,0x18,0x18,0x3c,0x3c,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x66,0x66,0x66,0x66,0x66,0x3c,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x7e,0x60,0x60,0x30,0x30,0x18,0x18,0x0c,0x0c,0x06,0x06,0x7e,0x00,0x00,0x00},
    {0x00,0x7c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x7c,0x00,0x00,0x00},
    {0x00,0x06,0x06,0x06,0x0c,0x0c,0x0c,0x18,0x18,0x18,0x30,0x30,0x30,0x00,0x00,0x00},
    {0x00,0x3e,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3e,0x00,0x00,0x00},
    {0x00,0x18,0x3c,0x66,0xc3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00},
    {0x00,0x18,0x18,0x30,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x60,0x60,0x7c,0x66,0x66,0x66,0x66,0x7c,0x00,0x00,0x00},
    {0x00,0x06,0x06,0x06,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x06,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x60,0x60,0x60,0x7c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x7e,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x70,0x18,0x18,0x18,0x3c,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x08,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x3e},
    {0x00,0x06,0x06,0x06,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x18,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x10,0x00,0x00,0x00},
    {0x00,0x18,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x08},
    {0x00,0x06,0x06,0x06,0x46,0x66,0x66,0x66,0x3e,0x66,0x66,0x66,0x66,0x40,0x00,0x00},
    {0x00,0x08,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x7f,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x06,0x06,0x06},
    {0x00,0x00,0x00,0x00,0x7c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x60},
    {0x00,0x00,0x00,0x00,0x38,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x06,0x3c,0x60,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x18,0x78,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x10,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x3c,0x3c,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x7f,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x66,0x66,0x3c,0x3c,0x18,0x3c,0x3c,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x60},
    {0x00,0x00,0x00,0x00,0x7e,0x60,0x30,0x30,0x18,0x0c,0x0c,0x06,0x7e,0x00,0x00,0x00},
    {0x00,0x70,0x18,0x18,0x18,0x18,0x0e,0x0e,0x18,0x18,0x18,0x18,0x70,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x0e,0x18,0x18,0x18,0x18,0x70,0x70,0x18,0x18,0x18,0x18,0x0e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x6e,0x3b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x08,0x1c,0x36,0x63,0x63,0x63,0x63,0x7f,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x7c,0xc6,0xc3,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xc6,0x7c,0x30,0x1e,0x00},
    {0x00,0x66,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00},
    {0x30,0x18,0x0c,0x00,0x3c,0x66,0x66,0x7e,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x30,0x78,0xcc,0x00,0x7c,0xc0,0xfc,0xc6,0xc3,0xc3,0xc3,0xfe,0x00,0x00,0x00},
    {0x00,0x00,0x6c,0x6c,0x00,0x7c,0xc0,0xfc,0xc6,0xc3,0xc3,0xc3,0xfe,0x00,0x00,0x00},
    {0x00,0x0c,0x18,0x30,0x00,0x7c,0xc0,0xfc,0xc6,0xc3,0xc3,0xc3,0xfe,0x00,0x00,0x00},
    {0x38,0x6c,0x6c,0x38,0x00,0x7c,0xc0,0xfc,0xc6,0xc3,0xc3,0xc3,0xfe,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x7c,0xc6,0x03,0x03,0x03,0x03,0xc6,0x7c,0x30,0x1e,0x00},
    {0x18,0x3c,0x66,0x00,0x3c,0x66,0x66,0x7e,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x66,0x00,0x00,0x3c,0x66,0x66,0x7e,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x0c,0x18,0x30,0x00,0x3c,0x66,0x66,0x7e,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x00,0x66,0x66,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x18,0x3c,0x66,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x06,0x0c,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0xc3,0xdb,0x18,0x3c,0x24,0x66,0x66,0x66,0x7e,0xc3,0xc3,0xc3,0xc3,0x00,0x00,0x00},
    {0x3c,0x66,0x3c,0x3c,0x24,0x66,0x66,0x66,0x7e,0xc3,0xc3,0xc3,0xc3,0x00,0x00,0x00},
    {0x30,0x18,0x7f,0x03,0x03,0x03,0x7f,0x03,0x03,0x03,0x03,0x03,0x7f,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x7e,0xd8,0xde,0xfb,0x1b,0x1b,0xdb,0x76,0x00,0x00,0x00},
    {0x00,0xfe,0x33,0x33,0x33,0x33,0xff,0x33,0x33,0x33,0x33,0x33,0xf3,0x00,0x00,0x00},
    {0x00,0x18,0x3c,0x66,0x00,0x7e,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x66,0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x06,0x0c,0x18,0x00,0x7e,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x18,0x3c,0x66,0x00,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x06,0x0c,0x18,0x00,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x00,0x66,0x66,0x00,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x66,0x3c,0x18,0x0c,0x07},
    {0x66,0x00,0x3c,0x66,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x66,0x3c,0x00,0x00,0x00},
    {0x66,0x00,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x10,0x10,0x7c,0xd6,0x13,0x13,0x13,0x13,0xd6,0x7c,0x10,0x10,0x00},
    {0x00,0x3c,0x66,0x06,0x06,0x1f,0x06,0x1f,0x06,0x06,0x06,0xc6,0x7e,0x00,0x00,0x00},
    {0x00,0xc3,0xc3,0xc3,0x66,0x66,0x3c,0x18,0x7e,0x18,0x7e,0x18,0x18,0x18,0x00,0x00},
    {0x00,0x7f,0xc3,0xc3,0xc3,0xc3,0x63,0x3b,0x0f,0x63,0xf3,0x63,0x63,0xc0,0x00,0x00},
    {0x00,0x78,0xcc,0xcc,0xcc,0x0c,0x3e,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x07,0x00,0x00},
    {0x00,0x60,0x30,0x18,0x00,0x7c,0xc0,0xfc,0xc6,0xc3,0xc3,0xc3,0xfe,0x00,0x00,0x00},
    {0x00,0x60,0x30,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x60,0x30,0x18,0x00,0x7e,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x30,0x18,0x0c,0x00,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x00,0x6e,0x3b,0x00,0x7b,0xcf,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x00,0x00,0x00},
    {0x6e,0x3b,0x00,0xc3,0xc3,0xc7,0xcf,0xdb,0xf3,0xe3,0xc3,0xc3,0xc3,0x00,0x00,0x00},
    {0x00,0x00,0x7c,0xc0,0xfc,0xc6,0xc3,0xc3,0xc3,0xfe,0x00,0x00,0xff,0x00,0x00,0x00},
    {0x00,0x00,0x7e,0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0xff,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x00,0x18,0x18,0x18,0x0e,0x03,0x03,0x03,0xc3,0x7e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x60,0x60,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x06,0x87,0xc6,0x66,0x36,0x18,0x0c,0x06,0x73,0xd9,0x60,0x30,0xf8,0x00,0x00},
    {0x00,0x06,0x87,0xc6,0x66,0x36,0x18,0x0c,0x66,0x73,0x69,0xfc,0x60,0x60,0x00,0x00},
    {0x00,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0xd8,0x6c,0x36,0x1b,0x1b,0x36,0x6c,0xd8,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x1b,0x36,0x6c,0xd8,0xd8,0x6c,0x36,0x1b,0x00,0x00,0x00,0x00},
    {0x11,0x44,0x11,0x44,0x11,0x44,0x11,0x44,0x11,0x44,0x11,0x44,0x11,0x44,0x11,0x44},
    {0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa},
    {0xdd,0x77,0xdd,0x77,0xdd,0x77,0xdd,0x77,0xdd,0x77,0xdd,0x77,0xdd,0x77,0xdd,0x77},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x18,0x1f,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x67,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x18,0x18,0x1f,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x67,0x60,0x60,0x67,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x60,0x60,0x63,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x63,0x60,0x60,0x3f,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x1f,0x18,0x18,0x0f,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xff,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0x18,0xf8,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0xe6,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0xc6,0x06,0x06,0xfc,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x06,0x06,0xc6,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0xe7,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xe7,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0xe6,0x06,0x06,0xe6,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x66,0x66,0x66,0x66,0x66,0x66,0xe7,0x00,0x00,0xe7,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x18,0x18,0x18,0x18,0x18,0x18,0xff,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x18,0x18,0x18,0x18,0x18,0x18,0xf8,0x18,0x18,0xf0,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x18,0x18,0xf8,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x66,0x66,0x66,0x66,0x66,0x66,0x66,0xff,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66},
    {0x18,0x18,0x18,0x18,0x18,0x18,0xff,0x00,0x00,0xff,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f},
    {0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0xee,0x33,0x33,0x33,0x33,0x7b,0xce,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x63,0x63,0x23,0x1b,0x23,0x63,0x63,0x63,0x63,0x3b,0x03,0x01,0x00},
    {0x00,0x7e,0x66,0x66,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x02,0x00,0x00},
    {0x00,0x00,0x00,0x00,0xc0,0x7e,0x67,0x66,0x66,0x66,0x66,0x66,0x22,0x00,0x00,0x00},
    {0x00,0x7f,0x03,0x06,0x0c,0x18,0x30,0x18,0x0c,0x06,0x03,0x03,0x7f,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0xfe,0x0f,0x1b,0x1b,0x1b,0x1b,0x1b,0x0e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x06,0x06,0x03},
    {0x00,0x00,0x00,0x00,0x76,0x1d,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x00,0x00,0x00},
    {0x00,0x18,0x18,0x7e,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x7e,0x18,0x18,0x00,0x00,0x00},
    {0x00,0x00,0x3c,0x66,0xc3,0xc3,0xc3,0xff,0xc3,0xc3,0xc3,0x66,0x3c,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0xc3,0xc3,0xc3,0xc3,0xc3,0x66,0x24,0x24,0xa5,0xe7,0x00,0x00,0x00},
    {0x00,0x7c,0x06,0x0c,0x18,0x30,0x7e,0x63,0x63,0x63,0x63,0x63,0x3e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x76,0xdb,0xdb,0xdb,0xdb,0xdb,0x6e,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x40,0x20,0x3e,0x73,0x6b,0x67,0x3e,0x02,0x01,0x00,0x00,0x00,0x00},
    {0x00,0x78,0x0c,0x06,0x06,0x06,0x7e,0x06,0x06,0x06,0x06,0x0c,0x78,0x00,0x00,0x00},
    {0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x18,0x18,0x18,0x7e,0x18,0x18,0x18,0x00,0x7e,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x0c,0x18,0x30,0x60,0x30,0x18,0x0c,0x00,0x7e,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x30,0x18,0x0c,0x06,0x0c,0x18,0x30,0x00,0x7e,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x70,0xd8,0xd8,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
    {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1b,0x1b,0x0e,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x7e,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x6e,0x3b,0x00,0x6e,0x3b,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x3c,0x66,0x66,0x66,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0xc0,0x40,0x60,0x20,0x30,0x10,0x1b,0x0a,0x0e,0x04,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x1e,0x33,0x18,0x0c,0x06,0x03,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
};

#endif
