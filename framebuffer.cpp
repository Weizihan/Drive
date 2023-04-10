#include <iostream>
#include "framebuffer.hpp"

void framebuffer::init(){
    m_fb = open("/dev/fb0", O_RDWR);
    if(m_fb == -1)
    {
        char ErrorStr[256] = {0};
        int i = errno;
        sprintf(ErrorStr,"[%s:%d(%s)]:Fialed to open /dev/fb0 ,ERRORNO:%d",__FILE__,__LINE__,__FUNCTION__,errno);
        return;
    }

    fb_var_screeninfo var;
        
    if(ioctl(m_fb,FBIOGET_VSCREENINFO,&var) == -1)
    {
        char ErrorStr[64] = {0};
        sprintf(ErrorStr,"[%s->%d:%s]:Fialed to Get var_screen_info",__FILE__,__LINE__,__FUNCTION__);
    }

    m_ScrInfo.xres = var.xres*var.bits_per_pixel/8;
    m_ScrInfo.yres = var.yres*var.bits_per_pixel/8;
    m_ScrInfo.bpp = var.bits_per_pixel/8;
    m_ScrInfo.screen_size = var.xres*var.yres*var.bits_per_pixel/8;

    m_ScrMap = (u_pchar)mmap(nullptr,m_ScrInfo.screen_size,PROT_READ|PROT_WRITE,MAP_SHARED,m_fb,0);
        
}

void framebuffer::uinit(){
    munmap(m_ScrMap,m_ScrInfo.screen_size);
    close(m_fb);
}

void framebuffer::setcolor(){
    
}

void framebuffer::drawRect(int pos_x , int pos_y ,int rect_w , int rect_h){
    int c = 0x009ad6;
    // int i=0, j=0, offset = 0;
	// 	for(i=0; i<rect_h; i++)
	// 	{
	// 		offset = pos_x*m_ScrInfo.bpp + (pos_y+i)*m_ScrInfo.xres;
	// 		for(j=0; j<rect_w; j++)
	// 		{
	// 			int *tmp = (int *)&m_ScrMap[offset];
	// 			*tmp = c;
	// 			offset += m_ScrInfo.bpp;
	// 		}
	// 	}
    u_pchar tmp = m_ScrMap + pos_x * m_ScrInfo.bpp + pos_y * m_ScrInfo.xres; 
    for(int i = 0 ;i < rect_h; i++)
    {
        memset(tmp,c,rect_w);
        tmp += m_ScrInfo.xres;
    }
}
