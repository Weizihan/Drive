#pragma once
#include <iostream>
#include <string>

// open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// fb_var_screen
#include <linux/fb.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>

#include "template_singleton.hpp"

typedef unsigned int uint;
typedef unsigned char* u_pchar;


struct screen_info_t{
    uint line_width;
    uint pixel_width;
    uint screen_size;
};

class framebuffer
{
    friend class template_singleton<framebuffer>;
private:
    /* data */
    screen_info_t m_ScrInfo;
    u_pchar m_ScrMap;
    int m_fb;

    framebuffer() = default;
    ~framebuffer();

    void init();
    void uinit();
public:
    void setcolor();

};

