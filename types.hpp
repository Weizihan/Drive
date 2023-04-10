#pragma once
#include <sys/types.h>
#include <unistd.h>

#define LOG_ERROR;
#define LOG_DEBUG;

typedef unsigned int uint;
typedef unsigned char* u_pchar;

struct screen_info_t{
    uint xres;          //Screen_X
    uint yres;          //Screen_X
    uint screen_size;
    uint bpp;
};


struct color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};
