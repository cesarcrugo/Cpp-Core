#include <iostream>
#include <static.hpp>

int main ()
{
    std::cout << "Hello World!" << std::endl;

    StaticClass::helloWorld();
    StaticClass instance;
    StaticClass::helloWorld();

    instance.localStaticVariable();
    instance.localStaticVariable();
    instance.localStaticVariable();
}