#include <inline.hpp>

/*
 * This function will be inserted at declaratio at inline.hpp
 */
inline void InlineClass::InlineFunction ()
{
    std::cout << "InlineFunction Called..." << std::endl;
}

