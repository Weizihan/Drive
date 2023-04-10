#include <iostream>
#include "framebuffer.hpp"

void framebuffer::init(){
    m_fb = open("/dev/fb0", O_RDWR);
    if(m_fb == -1)
    {
        char ErrorStr[256] = {0};
        int i = errno;
        sprintf(ErrorStr,"[%s:%d(%s)]:Fialed to open /dev/fb0 ,ERRORNO:%d",__FILE__,__LINE__,__FUNCTION__,errno);
        
    }

    fb_var_screeninfo var;
        
    if(ioctl(m_fb,FBIOGET_VSCREENINFO,&var) == -1)
    {
        char ErrorStr[64] = {0};
        sprintf(ErrorStr,"[%s->%d:%s]:Fialed to Get var_screen_info",__FILE__,__LINE__,__FUNCTION__);
    }

    m_ScrInfo.line_width = var.xres*var.bits_per_pixel/8;
    m_ScrInfo.pixel_width = var.bits_per_pixel/8;
    m_ScrInfo.screen_size = var.xres*var.yres*var.bits_per_pixel/8;

    m_ScrMap = (u_pchar)mmap(NULL,m_ScrInfo.screen_size,PROT_READ|PROT_WRITE,MAP_SHARED,m_fb,0);
        
}

void framebuffer::uinit(){
    munmap(m_ScrMap,m_ScrInfo.screen_size);
    close(m_fb);
}

void framebuffer::setcolor(){
    memset(m_ScrMap,0xff,m_ScrInfo.screen_size);
}
