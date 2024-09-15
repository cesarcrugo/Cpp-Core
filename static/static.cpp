#include <static.hpp>

/*
 * When used at global or namespace scope to declare 
 * a variable, object or function, the static keyword
 * specifies internal linkage (local visibility).
 * 
 * In the example below, static keyword prevents val
 * and func from colliding with previous definitions at 
 * static_.cpp, preventing multiple definitions linker 
 * error.
 */
static int val = 0;
static void func (){}

/*
 * Declare static variables to avoid undefined reference
 * linker error.
 */
int StaticClass::m_staticMember1;
const int StaticClass::m_staticMember2;

StaticClass::StaticClass()
{
    m_staticMember1 = 1;
}

void StaticClass::helloWorld ()
{
    std::cout << "Hello world from static class with members: "

              /*
               * A static function cannot access non-static 
               * members of a class, as function does not 
               * have an implicit this pointer.
               */
              //<< m_member << ", "

              << m_staticMember1 << ", "
              << m_staticMember2 << std::endl;
              
}

/*
 * A local static variable is kept as is between function calls
 */
void StaticClass::localStaticVariable ()
{
    static int calls = 0;
    calls++;
    std::cout << "localStaticVariable calls: " << calls << std::endl;
}

