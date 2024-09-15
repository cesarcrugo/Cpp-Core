#pragma once
#include <iostream>

/*
 * The static keyword is a storage modifier.
 * Variables and objects with automatic storage can only
 * be seen within the current scope ({}), and the memory
 * resources are assigned at scope execution, and released 
 * when out of scope.
 */

/*
 * The static keryword can be used to declare variables
 * and functions at the global, namespace, class and local
 * scopes.
 * 
 * Static storage means that the variable or object is created
 * at program initialization and destroyed at program end.
 */

class StaticClass {
 public:
    int m_member = 0;

    /*
     * All instances of staticClass share the same static members
     */
    static int m_staticMember1;

    /*
     * A static integer declared with const can have initializer
     */
    static const int m_staticMember2 = 2;

    StaticClass();

    static void helloWorld ();

    static void localStaticVariable ();
};