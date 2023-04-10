#include "framebuffer.hpp"
#include "template_singleton.hpp"
using namespace std;
int main(){
    cout << "Cmake succeed2" <<endl;
    framebuffer* Scr = template_singleton<framebuffer>::Get_handle();
    Scr->setcolor();
    cout << "Cmake succeed2" <<endl;
    template_singleton<framebuffer>::Delete_handle();
    return 0;
}
