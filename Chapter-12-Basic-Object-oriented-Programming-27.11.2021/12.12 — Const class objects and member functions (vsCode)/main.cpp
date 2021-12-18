#include <iostream>
#include <string>
#include "rota.cpp"


class Something
{
private:

public:
    int m_number{};

    Something() : m_number{ 77 } {}

    void setValue(int number) { m_number = number; }
    int getValue() const { return m_number; }
};

class Something2
{
private:
    std::string m_name{};

public:
    Something2(const std::string& name ="I love you my Lord Jezus Christ") : m_name{ name } {}

    const std::string& getName() const { return m_name; }// getName() for const objects (returns const reference)
    std::string& getName() { return m_name; }// getName() for non-const objects (returns non-const reference)
};

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

void print(const Date& date)
{
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const class objects and member functions" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In lesson 4.15 -- Const, constexpr, and symbolic constants, you learned that fundamental data types (int, double, char, etc…) 
    can be made const via the const keyword, and that all const variables must be initialized at time of creation.

    In the case of const fundamental data types, initialization can be done through copy, direct, or uniform initialization:
    */
    const int value1 = 5; // copy initialization
    const int value2 (7); // direct initialization
    const int value3 { 9 }; // uniform initialization (C++11)


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const classes" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Similarly, instantiated class objects can also be made const by using the const keyword. Initialization is done via 
    class constructors:
    */
    const Rota rota{};
    const Rota rota2(2020, 10, 16);
    const Rota rota3{ 2020, 10, 16 };

    std::cout << rota.getMon() << ' ' << rota.getTue() << ' ' << rota.getWed() << '\n';

    /*
    Once a const class object has been initialized via constructor, any attempt to modify the member variables of the object 
    is disallowed, as it would violate the const-ness of the object. This includes both changing member variables directly 
    (if they are public), or calling member functions that set the value of member variables. Consider the following class:

    class Something
    {
    public:
        int m_value {};

        Something(): m_value{0} { }

        void setValue(int value) { m_value = value; }
        int getValue() { return m_value ; }
    };

    int main()
    {
        const Something something{}; // calls default constructor

        something.m_value = 5; // compiler error: violates const
        something.setValue(5); // compiler error: violates const

        return 0;
    }

    Both of the above lines involving variable something are illegal because they violate the constness of something by 
    either attempting to change a member variable directly, or by calling a member function that attempts to change a member 
    variable.

    Just like with normal variables, you’ll generally want to make your class objects const when you need to ensure they aren’t 
    modified after creation.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const member functions" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Now, consider the following line of code:
    */
    const Something something{}; // calls default constructor

    //something.m_number = 5; // compiler error: violates const
    //something.setValue(5); // compiler error: violates const

    std::cout << something.getValue() << '\n';

    /*
    Perhaps surprisingly, this will also cause a compile error, even though getValue() doesn’t do anything to change a member 
    variable! It turns out that const class objects can only explicitly call const member functions, and getValue() has not been 
    marked as a const member function.

    A const member function is a member function that guarantees it will not modify the object or call any non-const member 
    functions (as they may modify the object).

    To make getValue() a const member function, we simply append the const keyword to the function prototype, after the 
    parameter list, but before the function body.
    
    Now getValue() has been made a const member function, which means we can call it on any const objects.

    For member functions defined outside of the class definition, the const keyword must be used on both the function 
    prototype in the class definition and on the function definition.
    
    Futhermore, any const member function that attempts to change a member variable or call a non-const member function will cause a compiler error to occur. For example:

    class Something
    {
    public:
        int m_value {};

        void resetValue() const { m_value = 0; } // compile error, const functions can't change member variables.
    };

    In this example, resetValue() has been marked as a const member function, but it attempts to change m_value. 
    This will cause a compiler error.

    Note that constructors cannot be marked as const. This is because constructors need to be able to initialize their 
    member variables, and a const constructor would not be able to do so. Consequently, the language disallows 
    const constructors.

    Const member functions can also be called by non-const objects.

    Best practice

    Make any member function that does not modify the state of the class object const, so that it can be called by 
    const objects.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const objects via pass by const reference" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Although instantiating const class objects is one way to create const objects, a more common way to get a const object 
    is by passing an object to a function by const reference.

    In the lesson 11.3 -- Passing arguments by reference, we covered the merits of passing class arguments by const reference 
    instead of by value. To recap, passing a class argument by value causes a copy of the class to be made 
    (which is slow) -- most of the time, we don’t need a copy, a reference to the original argument works just fine, and 
    is more performant because it avoids the needless copy. We typically make the reference const in order to ensure the 
    function does not inadvertently change the argument, and to allow the function to work with R-values (e.g. literals), 
    which can be passed as const references, but not non-const references.

    Can you figure out what’s wrong with the following code?
    
    #include <iostream>

    class Date
    {
    private:
        int m_year {};
        int m_month {};
        int m_day {};

    public:
        Date(int year, int month, int day)
        {
            setDate(year, month, day);
        }

        void setDate(int year, int month, int day)
        {
            m_year = year;
            m_month = month;
            m_day = day;
        }

        int getYear() { return m_year; }
        int getMonth() { return m_month; }
        int getDay() { return m_day; }
    };

    // note: We're passing date by const reference here to avoid making a copy of date
    void printDate(const Date& date)
    {
        std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
    }

    int main()
    {
        Date date{2016, 10, 16};
        printDate(date);

        return 0;
    }
    
    The answer is that inside of the printDate function, date is treated as a const object. And with that const date, 
    we’re calling functions getYear(), getMonth(), and getDay(), which are all non-const. Since we can’t call non-const 
    member functions on const objects, this will cause a compile error.
    
    The fix is simple: make getYear(), getMonth(), and getDay() const:

    class Date
    {
    private:
        int m_year {};
        int m_month {};
        int m_day {};

    public:
        Date(int year, int month, int day)
        {
            setDate(year, month, day);
        }

        // setDate() cannot be const, modifies member variables
        void setDate(int year, int month, int day)
        {
            m_year = year;
            m_month = month;
            m_day = day;
        }

        // The following getters can all be made const
        int getYear() const { return m_year; }
        int getMonth() const { return m_month; }
        int getDay() const { return m_day; }
    };

    Now in function printDate(), const date will be able to successfully call getYear(), getMonth(), and getDay().
    */
    Date date{2021, 12, 18};
    print(date);


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Const members can not return non-const references to members" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    When a member function is const, the hidden *this pointer is also const, which means all members are treated as const 
    within that function. Therefore, a const member function can not return a non-const reference to a member, as that would 
    allow the caller to have non-const access to that const member. Const member functions can return const references to members.

    We’ll see an example of this in the next section.
    */

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Overloading const and non-const function" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Finally, although it is not done very often, it is possible to overload a function in such a way to have a const and 
    non-const version of the same function. This works because the const qualifier is considered part of the function’s 
    signature, so two functions which differ only in their const-ness are considered distinct.
    */
    Something2 something2{};
    const Something2 something3{"Read Bible every day"};

    std::cout << something2.getName() << '\n'; // calls non-const getValue();
    std::cout << something3.getName() << '\n'; // calls const getValue();

    /*
    Overloading a function with a const and non-const version is typically done when the return value needs to differ in 
    constness. In the example above, the non-const version of getValue() will only work with non-const objects, but is more 
    flexible in that we can use it to both read and write m_value (which we do by assigning the string “Hi”).

    The const version of getValue() will work with either const or non-const objects, but returns a const reference, to 
    ensure we can’t modify the const object’s data.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Summary" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Because passing objects by const reference is common, your classes should be const-friendly. That means making any member 
    function that does not modify the state of the class object const!
    */

    return 0;
}