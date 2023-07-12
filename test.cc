#include <iostream>
#include <dlfcn.h>
#include "test.h"

int main() {
    void* handle = dlopen("wrapper.so", RTLD_LAZY);

    if (!handle) {
        std::cerr << "Не удалось загрузить библиотеку: " << dlerror() << std::endl;
        return 1;
    }

    // Получение указателя на метод из библиотеки
    typedef SmartCalc::data (SmartCalc::*ComputePolishNotationFunction)(std::string&, SmartCalc::data);
    ComputePolishNotationFunction computePolishNotation = (ComputePolishNotationFunction)dlsym(handle, "_ZN9SmartCalc20ComputePolishNotationERSsNS_4dataE");

    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Не удалось найти символ 'ComputePolishNotation': " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    // Создание объекта SmartCalc
    SmartCalc smartCalc;

    // Вызов метода из библиотеки
    std::string str = "6 + 6";
    SmartCalc::data x;
    // Здесь необходимо правильно заполнить объект x перед вызовом метода, если это требуется

    (smartCalc.*computePolishNotation)(str, x);

    dlclose(handle);
    return 0;
}
