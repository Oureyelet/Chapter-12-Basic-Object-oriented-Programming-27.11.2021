#include <iostream>

class Something
{
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};

public:
    Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' }// Initialize our member variables
    {
        // No need for assignment here
    }

    Something(int value1, double value2, char value3 = 'c') : m_value1{ value1 }, m_value2{ value2 }, m_value3{ value3 }// directly initialize our member variables
    {
        // No need for assignment here
    }

    void print()
    {
        std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};

class Bilbe
{
private:
    const int m_array[5];

public:
    //since C++11, you can fully initialize a member array using uniform initialization:
    Bilbe() : m_array{ 1, 2, 3, 4, 5 }// use uniform initialization to initialize our member array
    {

    }
};

class A
{
public:
    A(int x = 0)
    {
        std::cout << "A " << x << '\n';
    }
};

class B
{
private:
    A m_a {};

public:
    B(int y)
        : m_a{ y - 1 }// call A(int) constructor to initialize member m_a
    {
        std::cout << "B " << y << '\n';
    }

};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Constructor member initializer lists" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the previous lesson, for simplicity, we initialized our class member data in the constructor using the assignment 
    operator. For example:
    */

    // These are all assignments, not initializations
    int m_value_1 = 1;
    int m_value_2 = 2;
    int m_value_3 = 3;

    /*
    When the class’s constructor is executed, m_value1, m_value2, and m_value3 are created. Then the body of the 
    constructor is run, where the member data variables are assigned values. This is similar to the flow of the 
    following code in non-object-oriented C++

    While this is valid within the syntax of the C++ language, it does not exhibit good style (and may be less efficient than 
    initialization).

    However, as you have learned in previous lessons, some types of data (e.g. const and reference variables) must be 
    initialized on the line they are declared. Consider the following example:
    
    class Something
    {
    private:
        const int m_value;

    public:
        Something()
        {
            m_value = 1; // error: const vars can not be assigned to
        }
    };
    
    This produces code similar to the following:

    const int m_value; // error: const vars must be initialized with a value
    m_value = 5; //  error: const vars can not be assigned to

    Assigning values to const or reference member variables in the body of the constructor is clearly not 
    possible in some cases.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Member initializer lists" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    To solve this problem, C++ provides a method for initializing class member variables (rather than assigning values to 
    them after they are created) via a member initializer list (often called a “member initialization list”). Do not confuse 
    these with the similarly named initializer list that we can use to assign values to arrays.

    In lesson 1.4 -- Variable assignment and initialization, you learned that you could initialize variables in three ways: 
    copy, direct, and via uniform initialization.

    int value1 = 1; // copy initialization
    double value2(2.2); // direct initialization
    char value3 {'c'}; // uniform initialization

    Using an initialization list is almost identical to doing direct initialization or uniform initialization.

    This is something that is best learned by example. Revisiting our code that does assignments in the constructor body:

    class Something
    {
    private:
        int m_value1 {};
        double m_value2 {};
        char m_value3 {};

    public:
        Something()
        {
            // These are all assignments, not initializations
            m_value1 = 1;
            m_value2 = 2.2;
            m_value3 = 'c';
        }
    };
    
    Now let’s write the same code using an initialization list:

    --->>> Look for 'class Something' above main().
    */
    Something something;
    something.print(); //print Something(1, 2.2, c)

    /*
    The member initializer list is inserted after the constructor parameters. It begins with a colon (:), and then lists 
    each variable to initialize along with the value for that variable separated by a comma.

    Note that we no longer need to do the assignments in the constructor body, since the initializer list replaces that 
    functionality. Also note that the initializer list does not end in a semicolon.

    Of course, constructors are more useful when we allow the caller to pass in the initialization values:
    */
    Something something2 {1, 7.7};

    something2.print(); //print Something(1, 7.7, c)

    /*
    Note that you can use default parameters to provide a default value in case the user didn’t pass one in.

    Here’s an example of a class that has a const member variable:

    class Something
    {
    private:
        const int m_value;

    public:
        Something(): m_value{ 5 } // directly initialize our const member variable
        {
        }
    };

    This works because we’re allowed to initialize const variables (but not assign to them!).

    Rule

    Use member initializer lists to initialize your class member variables instead of assignment.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing array members with member initializer lists" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Consider a class with an array member:

    --->>> 'class Bible'
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Initializing member variables that are classes" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A member initialization list can also be used to initialize members that are classes.
    */
    B b{ 5 };

    /*
    When variable b is constructed, the B(int) constructor is called with value 5. Before the body of the constructor 
    executes, m_a is initialized, calling the A(int) constructor with value 4. This prints “A 4”. Then control returns 
    back to the B constructor, and the body of the B constructor executes, printing “B 5”.
    */


    return 0;
}