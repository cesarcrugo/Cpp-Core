#include <iostream>

int GetRValue()
{
    return 10;
}

/*
 * Return type (int&) is known as lvalue reference
 */
int& GetLValue()
{
    static int lvalue = 22; // storage modifier to keep lvalue after leaving scope
    return lvalue;
}

/*
 * Passing an lvalue reference as parameter. Adding the const
 * allows to accept both lvalues and rvalues (a temporary rvalue 
 * can be though as a const as well, although it is only a workaround).
 */
void SetValue (const int& lvalue)
{
}

/*
 * Passing an rvalue reference (int&&) as parameter. Calls to 
 * SetValue with an rvalue would prefer this override over the 
 * previous definition.
 */
void SetValue (int&& rvalue)
{
}

/*
 * An lvalue is a variable with an actual location in memory.
 * An rvalue is a temporary without storage.
 */
int main()
{
    /*
     * This is an rvalue (10) being assigned to an lvalue.
     */
    int lvalue = 10;

    /*
     * This is an lvalue being assigned to an lvalue.
     */
    int another_lvalue = lvalue;

    int value = GetRValue();
    value = GetLValue();

    /*
     * As GetLValue returns a lvalue reference, it can also
     * be used to set local static lvalue variable.
     */
    GetLValue() = 12;

    /*
     * COMPILER ERROR: Trying to do the same with GetRValue 
     * would launch a compiler error.
     * "Expression must be a modifiable lvalue"
     */
    //GetRValue() = 12;

    SetValue(12); // calls SetValue version at line 32
    SetValue(value); // calls SetValue version at line 23

    std::string firstName = "Cesar";
    std::string lastName = "Cruz";

    /*
     * At the right we have an rvalue because the compiler
     * creates a temporary variable to add both lvalue strings.
     */
    std::string fullName = firstName + lastName;
}
