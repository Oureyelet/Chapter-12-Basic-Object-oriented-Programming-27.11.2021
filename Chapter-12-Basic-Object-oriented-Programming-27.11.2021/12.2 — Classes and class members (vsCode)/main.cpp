#include <iostream>
#include <string>
#include <vector>
#include <array>

struct DateStruct
{
    int year{};
    int month{};
    int day{};
};

class DateClass
{
public:
    int m_year{};
    int m_month{};
    int m_day{};

    void print()// defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

class Emplayee
{
public:
    std::string m_name{};
    int m_id{};
    double m_wage{};

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name <<
                    " Id: " << m_id <<
                    " Wage: $" << m_wage << '\n';
    }

};

void print(const DateStruct &date)
{
    std::cout << date.year << '/' << date.month << '/' << date.day << '\n';
}

class Calculator
{
public:
    using number_type = int;// this is a nested type alias
    using double_type = double; // just for fun... ;P

    std::vector<number_type> m_resultHistory{};

    number_type add(number_type a, number_type b)
    {
        auto result{ a + b };

        m_resultHistory.push_back(result);

        return result;
    }
};

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Classes and class members" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    While C++ provides a number of fundamental data types (e.g. char, int, long, float, double, etc…) 
    that are often sufficient for solving relatively simple problems, it can be difficult to solve complex problems 
    using just these types. One of C++’s more useful features is the ability to define your own data types that better 
    correspond to the problem being solved. You have already seen how enumerated types and structs can be used to create 
    your own custom data types.

    Here is an example of a struct used to hold a date:
    */

    DateStruct today{ 2021, 11, 29 };// use uniform initialization

    today.day = 30; // use member selection operator to select a member of the struct
    print(today);

    
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Classes" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the world of object-oriented programming, we often want our types to not only hold data, but provide functions that 
    work with the data as well. In C++, this is typically done via the class keyword. The class keyword defines a new 
    user-defined type called a class.

    In C++, classes and structs are essentially the same. In fact, the following struct and class are effectively identical:
    */

    // LOOK ABOVE MAIN() --->> class 'DataClass'

    /*
    Note that the only significant difference is the public: keyword in the class. We will discuss the function of this 
    keyword in the next lesson.

    Just like a struct declaration, a class declaration does not allocate any memory. It only defines what the class looks like.
    */

    /*
    Class (and struct) definitions are like a blueprint -- they describe what the resulting object will look like, but 
    they do not actually create the object. To actually create an object of the class, a variable of that class type must 
    be defined:
    */

    DateClass yesturday{ 2021, 11, 29 }; // declare a variable of class DateClass

    /*
    A reminder:

    Initialize the member variables of a class at the point of declaration.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Member Functions" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In addition to holding data, classes (and structs) can also contain functions! Functions defined inside of a 
    class are called member functions (or sometimes methods). Member functions can be defined inside or outside of the 
    class definition. We’ll define them inside the class for now (for simplicity), and show how to define them outside 
    the class later.

    Here is our Date class with a member function (or sometimes methods) to print the date:
    */

    // LOOK ABOVE MAIN() --->> class 'DataClass' and new function inside 'print()'

    /*
    Just like members of a struct, members (variables and functions) of a class are accessed using the 
    member selector operator (.):
    */

    yesturday.m_day = 30;// use member selection operator to select a member variable of the class

    yesturday.print();// use member selection operator to call a member function of the class

    /*
    Note how similar this program is to the struct version we wrote above.

    However, there are a few differences. In the DateStruct version of print() from the example above, we needed to pass 
    the struct itself to the print() function as the first parameter. Otherwise, print() wouldn’t know what DateStruct we 
    wanted to use. We then had to reference this parameter inside the function explicitly.

    Member functions work slightly differently: All member function calls must be associated with an object of the class. 
    When we call “today.print()”, we’re telling the compiler to call the print() member function, associated with 
    the today object.

    Now let’s take a look at the definition of the print member function again:

        void print() // defines a member function named print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }

    What do m_year, m_month, and m_day actually refer to? They refer to the associated object (as determined by the caller).

    So when we call “today.print()”, the compiler interprets m_day as today.m_day, m_month as today.m_month, and 
    m_year as today.m_year. If we called “tomorrow.print()”, m_day would refer to tomorrow.m_day instead.

    In this way, the associated object is essentially implicitly passed to the member function. For this reason, it is 
    often called the implicit object.

    We’ll talk more about how the implicit object passing works in detail in a later lesson in this chapter.

    The key point is that with non-member functions, we have to pass data to the function to work with. With member functions, 
    we can assume we always have an implicit object of the class to work with!

    Using the “m_” prefix for member variables helps distinguish member variables from function parameters or local variables 
    inside member functions. This is useful for several reasons. First, when we see an assignment to a variable with the “m_” 
    prefix, we know that we are changing the state of the class instance. Second, unlike function parameters or local variables, 
    which are declared within the function, member variables are declared in the class definition. Consequently, if we want to 
    know how a variable with the “m_” prefix is declared, we know that we should look in the class definition instead of within 
    the function.

    By convention, class names should begin with an upper-case letter.

    Best practice:

    Name your classes starting with a capital letter.

    Here’s another example of a class:
    */

    // LOOK ABOVE MAIN() --->> class 'Employee' and new function inside 'print()'

    // Declare two employees
    Emplayee Ania{ "Ania", 1, 25.00 };
    Emplayee Mateusz{ "Mateusz", 2, 22.55 };

    // Print out the employee information
    Ania.print();
    Mateusz.print();

    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Member types" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In addition to member variables and member functions, classes can have member types or nested types 
    (including type aliases). In the following example, we’re creating a calculator where we can swiftly change the type 
    of number it’s using if we ever need to.
    */

    Calculator calculator;

    std::cout << calculator.add(3, 4) << '\n'; // 7
    std::cout << calculator.add(99, 24) << '\n'; // 123

    for(Calculator::number_type& result : calculator.m_resultHistory)
    {
        std::cout << result << '\n';
    }

    /*
    In such a context, the class name effectively acts like a namespace for the nested type. From inside the class, we only 
    need reference number_type. From outside the class, we can access the type via Calculator::number_type.

    When we decide that an int no longer fulfills our needs and we want to use a double, we only need to update the type alias, 
    rather than having to replace every occurrence of int with double.

    Type alias members make code easier to maintain and can reduce typing. Template classes, which we’ll cover later, often 
    make use of type alias members. You’ve already seen this as std::vector::size_type, where size_type is an alias for an 
    unsigned integer.

    Up to now, we used a “_t” suffix for type aliases. For member type aliases, a “_type” or no suffix at all is more common.

    Nested types cannot be forward declared. Generally, nested types should only be used when the nested type is used 
    exclusively within that class. Note that since classes are types, it’s possible to nest classes inside other classes -- 
    this is uncommon and is typically only done by advanced programmers.
    */

    
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "A note about structs in C++" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In C, structs can only hold data, and do not have associated member functions. In C++, after designing classes 
    (using the class keyword), Bjarne Stroustrup spent some amount of time considering whether structs 
    (which were inherited from C) should be granted the ability to have member functions. Upon consideration, he determined 
    that they should, in part to have a unified ruleset for both. So although we wrote the above programs using the class 
    keyword, we could have used the struct keyword instead.

    Many developers (including myself) feel this was the incorrect decision to be made, as it can lead to dangerous assumptions. 
    For example, it’s fair to assume a class will clean up after itself (e.g. a class that allocates memory will 
    deallocate it before being destroyed), but it’s not safe to assume a struct will. Consequently, we recommend using the 
    struct keyword for data-only structures, and the class keyword for defining objects that require both data and functions 
    to be bundled together.

    Best practice

    Use the struct keyword for data-only structures. Use the class keyword for objects that have both data and functions.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "You have already been using classes without knowing it" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    It turns out that the C++ standard library is full of classes that have been created for your benefit. std::string, 
    std::vector, and std::array are all class types! So when you create an object of any of these types, you’re instantiating 
    a class object. And when you call a function using these objects, you’re calling a member function.
    */

    std::string s{ "Hello, world!" };
    std::array<Calculator::number_type, 3> a { 1, 2, 3 };
    std::vector<Calculator::double_type> v { 1.1, 2.2, 3.3 };

    std::cout << "lenght: " << s.length() << '\n';

    
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Conclusion" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The class keyword lets us create a custom type in C++ that can contain both member variables and member functions. 
    Classes form the basis for Object-oriented programming, and we’ll spend the rest of this chapter and many of the future 
    chapters exploring all they have to offer!
    */
    
    
    
    return 0;
}