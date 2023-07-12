#include <iostream>

extern "C" void hello() // Добавляем extern "C" перед объявлением функции
{
    std::cout << "Hello world" << std::endl;
}