#include <iostream>
#include <dlfcn.h>



int main() {
    void* handle = dlopen("w.so", RTLD_LAZY);

    if (!handle) {
        std::cerr << "Не удалось загрузить библиотеку: " << dlerror() << std::endl;
        return 1;
    }

    // Получение указателя на функцию из библиотеки
    typedef void (*HelloFunction)();
    HelloFunction hello = (HelloFunction)dlsym(handle, "hello");

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Не удалось найти символ 'hello': " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    // Вызов функции из библиотеки
    hello();

    dlclose(handle);
    return 0;
}
