/*
 * The static keryword can be used to declare variables
 * The inline keyword suggests that the compiler SHOULD
 * substitute the code within the function definition in
 * place of each call to that function.
 * 
 * In theory this makes the code faster, although the
 * trade off is that the size of the program can increase.
 * 
 * However, the inline substitution is done at compiler's
 * discretion (i.e. the compiler can ignore the inline
 * keyword if it decides it is too large).
 */
#include <iostream>

class InlineClass {
    /*
     * Imnplicit inline
     */
    InlineClass ()
    {
        std::cout << "InlineClass Instance Created..." << std::endl;
    }

    void InlineFunction ();
};

