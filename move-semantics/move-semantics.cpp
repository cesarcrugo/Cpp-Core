#include <iostream>
#include <string.h>

class String
{
public:
    String() = default;
    String(const char* string)
    {
        std::cout << "Constructor Called..." << std::endl;

        m_size = strlen(string);
        m_data = new char[m_size];

        memcpy(m_data, string, m_size);
    }

    /*
     * Copy constructor that takes lvalue reference as parameter.
     * This constructor is intended to do a deep copy of the input
     * to create a new String instance.
     */
    String (const String& other){
        std::cout << "Copy Constructor Called..." << std::endl;

        m_size = other.m_size;
        m_data = new char[m_size];

        memcpy(m_data, other.m_data, m_size);
    }

    /*
     * Move constructor that takes rvalue reference as parameter.
     * This constructor moves (shallow copy) data from input to a 
     * new String instance and cleans old string (IMPORTANT: cleans
     * instance, not pointed data)
     */
    String (String&& other){
        std::cout << "Move Constructor Called..." << std::endl;

        m_size = other.m_size;
        m_data = other.m_data;

        other.m_data = nullptr;
        other.m_size = 0;
    }

    /*
     * Assignment operator does pretty much the same as the move
     * constructor, but it is called when assigning an String to
     * another existing String.
     * 
     * Note it returns an lvalue reference.
     */
    String& operator=(String&& other)
    {
        std::cout << "Assignment Operator Called..." << std::endl;

        delete[] m_data; // delete data in this instance to move data from other instance

        if (this != &other){
            m_size = other.m_size;
            m_data = other.m_data;

            other.m_data = nullptr;
            other.m_size = 0;
        }

        return *this;
    }

    /*
     * If called without [], behavior is undefined. Delete
     * call shall match the initialization.
     */
    ~String(){
        std::cout << "Destructor Called..." << std::endl;

        delete[] m_data;
    }

    void Print() {
        for (int i = 0; i < m_size; i++)
            std::cout << m_data[i];
        std::cout << std::endl;
    } 
    
    char* m_data;
    int m_size;
};

/*
 * An lvalue is a variable with an actual location in memory.
 * An rvalue is a temporary without storage.
 */
int main()
{
    String str = "Hello World"; // constructor being called
    String str2 ("Hello World"); // constructor being called (equivalent to above)

    String str3 (str); // copy constructor being called

    std::cout << std::endl;

    // both str and str3 shall contain the same string
    std::cout << "str: ";
    str.Print();

    std::cout << "str3: ";
    str3.Print();

    std::cout << std::endl;

    /*
     * std::move casts its parameter to a temporary rvalue (&&).
     * This equivalent best practice to C style casting (String&&)(_)
     * 
     * This is also equivalent to String str4 = std::move(str);
     */
    String str4 (std::move(str));

    // str was moved to str4. str shall be empty
    std::cout << "str: ";
    str.Print();

    std::cout << "str4: ";
    str4.Print();

    std::cout << std::endl;

    String str5; // note that this is being created empty
    /*
     * This calls the assignment operator and moves data from
     * str3 to str5
     */
    str5 = std::move(str3);

    // str3 was moved to str5. str3 shall be empty
    std::cout << "str3: ";
    str3.Print();

    std::cout << "str5: ";
    str5.Print();

    std::cout << std::endl;
}
