#pragma once

template <class T>
class template_singleton
{
public:
    static T* Get_handle();
    static void Delete_handle();
private:
    static T* m_handle;
    template_singleton();
    ~template_singleton();
};

template <class T>
inline T *template_singleton<T>::Get_handle()
{
    if(m_handle == nullptr) {
        m_handle = new T();
        m_handle->init();
        return m_handle;
    }
    else{
        return m_handle;
    }
}

template <class T>
inline void template_singleton<T>::Delete_handle()
{
    if(m_handle!=nullptr)
        m_handle->uinit();
    m_handle = nullptr;
}

template <typename T>
template_singleton<T>::template_singleton(/* args */)
{
}

template <typename T>
template_singleton<T>::~template_singleton()
{
}

template<typename T>
T* template_singleton<T>::m_handle = nullptr;

