/*
 * in C++ it is allowed to specify the size of an array using a const variable
 * This is not allowed in C
 */
const int constSize = 255;
int arr [constSize];

/*
 * const keyword specifies that the value of a variable is constant 
 * and indicates compiler to prevent the programmer to modify it.
 */
void constValue(){
    const int constVal = 0; // this value cannot be modified
    constVal++; // COMPILER ERROR: this will trigger a compiler error as we are trying to modify a const declared variable
}

/*
 * const keyword can also be used in pointer declarations
 * if keyword is used at the beginning of declaration, pointed value cannot be modified
 * if keyword is used after type declaration, pointer itself cannot be modified
 * if kerword is used at the beggining and after type declaration, pointer not pointed value can be modified
 */
void constPtr(){
    int val = 0; // this value can be modified
    const int constVal = 0; // this value cannot be modified

    const int* ptrToConstVal = &val;
    *ptrToConstVal = 0; // COMPILER ERROR: pointed value cannot be modified
    ptrToConstVal = nullptr;

    int* const constPtrToVal = &val;
    *constPtrToVal = 10;
    constPtrToVal = nullptr; // COMPILER ERROR: pointer cannot be modified

    const int* const constPtrToConstVal = &val;
    *constPtrToConstVal = 10; // COMPILER ERROR: pointed value cannot be modified
    constPtrToConstVal = nullptr; // COMPILER ERROR: pointer cannot be modified

    int* constPtrToConstVal2 = &constVal; // COMPILER ERROR: a pointer to a const variable shall be const too
    const int* constPtrToConstVal3 = &constVal; // a pointer to a const variable shall be const too
}

class constClass {
    int m_member = 0;

    /*
     * const keyword cannot be used in constructors/destructors
     */
    constClass() const; // COMPILER ERROR
    ~constClass() const; // COMPILER ERROR

    /*
     * const keyword can be used at the beginning of a function declaration to indicate a const return value
     */
    const int constReturnFunction ();

    /*
     * const keyword can be used at the end of a function to indicate function body cannot modify members of the class
     */
    int constFunction () const{
        m_member = 10; // COMPILER ERROR: cannot modify non const integer due to function declaration as const
    }
};