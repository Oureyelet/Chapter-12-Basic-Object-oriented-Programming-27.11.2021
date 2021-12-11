#include <iostream>
#include <cassert>
#include <cstdlib> // for std::size_t

class IntArray
{
private:
    int *m_array{};
    int m_length{};
    
public:
    IntArray(int length)// constructor
    {
        assert(length > 0 && "No no no !");

        m_array = new int[ static_cast<std::size_t>(length) ]{};
        m_length = length;
    }

    ~IntArray()// destructor
    {
        // Dynamically delete the array we allocated earlier
        delete[] m_array;
    }

    void setValue(int index, int value)
    {
        m_array[index] = value;
    }

    int getValue(int index)
    {
        return m_array[index];
    }

    int getLength()
    {
        return m_length;
    }
};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Destructors" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A destructor is another special kind of class member function that is executed when an object of that class is destroyed. 
    Whereas constructors are designed to initialize a class, destructors are designed to help clean up.

    When an object goes out of scope normally, or a dynamically allocated object is explicitly deleted using the delete keyword, 
    the class destructor is automatically called (if it exists) to do any necessary clean up before the object is removed from 
    memory. For simple classes (those that just initialize the values of normal member variables), a destructor is not needed 
    because C++ will automatically clean up the memory for you.

    However, if your class object is holding any resources (e.g. dynamic memory, or a file or database handle), or if you need 
    to do any kind of maintenance before the object is destroyed, the destructor is the perfect place to do so, as it is 
    typically the last thing to happen before the object is destroyed.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Destructor naming" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Like constructors, destructors have specific naming rules:

        1. The destructor must have the same name as the class, preceded by a tilde (~).
        2. The destructor can not take arguments.
        3. The destructor has no return type.

    A class can only have a single destructor.

    Generally you should not call a destructor explicitly (as it will be called automatically when the object is destroyed), 
    since there are rarely cases where you’d want to clean up an object more than once. However, destructors may safely call 
    other member functions since the object isn’t destroyed until after the destructor executes.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "A destructor example" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Let’s take a look at a simple class that uses a destructor:
    */

    /*
    std::cout << "how many place: ";
    int place{};
    std::cin >> place;

    IntArray array{place};

    for(int i{ 0 }; i < place; i++)
    {
        std::cout << "Enter " << i+1 << " number: ";
        int value{};
        std::cin >> value;
        array.setValue(i, value );
    }

    for(int i{ 0 }; i < array.getLength(); i++)
    {
        std::cout << array.getValue(i) << ' ';
    }
    std::cout << std::endl;
    */

    IntArray ar( 10 );// allocate 10 integers
    for(int i{ 0 }; i < ar.getLength(); i++)
        ar.setValue(i, i+1);

    std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';




    return 0;
}// ar is destroyed here, so the ~IntArray() destructor function is called here