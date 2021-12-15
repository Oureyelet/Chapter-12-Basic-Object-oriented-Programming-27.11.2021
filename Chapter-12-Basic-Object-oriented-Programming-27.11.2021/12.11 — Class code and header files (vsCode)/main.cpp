#include <iostream>
#include <iomanip>
#include "date.cpp"

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

    double m_value1{};
    double m_value2{};
    double m_value3{};

public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    Date(double value1, double value2, double value3);

    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    void setValue(double value1, double value2, double value3);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay() { return m_day; }

    double getValue1() { return m_value1; }
    double getValue2() { return m_value2; }
    double getValue3() { return m_value3; }
};


// Date constructor
Date::Date(double value1, double value2, double value3)
{
    setValue(value1, value2, value3);
}

// Date member function
void Date::setValue(double value1, double value2, double value3)
{
    m_value1 = value1;
    m_value2 = value2;
    m_value3 = value3;
}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Defining member functions outside the class definition" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    All of the classes that we have written so far have been simple enough that we have been able to implement the member 
    functions directly inside the class definition itself. For example, here’s our ubiquitous Date class:
    */
    Date date{ 2021, 12, 15 };
    std::cout << date.getYear() << ' ' << date.getMonth() << ' ' << date.getDay() << '\n';

    /*
    However, as classes get longer and more complicated, having all the member function definitions inside the class can make 
    the class harder to manage and work with. Using an already-written class only requires understanding its public interface 
    (the public member functions), not how the class works underneath the hood. The member function implementation details 
    just get in the way.

    Fortunately, C++ provides a way to separate the “declaration” portion of the class from the “implementation” portion. 
    This is done by defining the class member functions outside of the class definition. To do so, simply define the member 
    functions of the class as if they were normal functions, but prefix the class name to the function using the scope 
    resolution operator (::) (same as for a namespace).

    Here is our Date class with the Date constructor and setDate() function defined outside of the class definition. Note 
    that the prototypes for these functions still exist inside the class definition, but the actual implementation has been 
    moved outside:
    */

    std::cout << std::fixed << std::setprecision(2); // for keeping zero after floating point.

    Date value{2.22, 4.67, 45.34};
    std::cout << value.getValue1() << ' ' << value.getValue2() << ' ' << value.getValue3() << '\n';

    /*
    This is pretty straightforward. Because access functions are often only one line, they are typically left in the class 
    definition, even though they could be moved outside.

    Here is another example that includes an externally defined constructor with a member initialization list:
    
    see more: https://www.learncpp.com/cpp-tutorial/class-code-and-header-files/
    */

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Putting class definitions in a header file" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the lesson on header files, you learned that you can put function declarations inside header files in order to use 
    those functions in multiple files or even multiple projects. Classes are no different. Class definitions can be put in 
    header files in order to facilitate reuse in multiple files or multiple projects. Traditionally, the class definition is 
    put in a header file of the same name as the class, and the member functions defined outside of the class are put in 
    a .cpp file of the same name as the class.

    Here’s our Date class again, broken into a .cpp and .h file:

    Date.h:
    */
    Rota rota{7, 9, 12};
    std::cout << rota.getMon() << ' ' << rota.getTue() << ' ' << rota.getWed() << '\n';

    /*
    Now any other header or code file that wants to use the Date class can simply #include "Date.h". Note that Date.cpp 
    also needs to be compiled into any project that uses Date.h so the linker knows how Date is implemented.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Doesn't defining a class in a header file violate the one-definition rule?" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */

    return 0;
}