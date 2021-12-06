#include <iostream>
#include <cassert>

class Foo
{
public:
    int m_x{};
    int m_y{};
};

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction()
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; } 
};

class Fractional_number
{
private:
    int m_numerator{};
    int m_denominator{};
public:
    Fractional_number()// default constructor
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fractional_number(int numerator, int denominator = 1)
    {
        assert(numerator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Date
{
private:
    int m_year{ 2021 };
    int m_month{ 12 };
    int m_day{ 6 };

    // No user-provided constructors, the compiler generates a default constructor.
};

class Date_next
{
private:
    int m_year{ 1900 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    Date_next(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    // No implicit constructor provided because we already defined our own constructor
};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Aggregate initialization" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    When all members of a class (or struct) are public, we can use aggregate initialization to initialize the class 
    (or struct) directly using list-initialization:
    */
    Foo foo { 6, 7 };// list-initialization

    /*
    However, as soon as we make any member variables private, we’re no longer able to initialize classes in this way. 
    It does make sense: if you can’t directly access a variable (because it’s private), you shouldn’t be able to directly 
    initialize it.

    So then how do we initialize a class with private member variables? The answer is through constructors.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Constructors" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A constructor is a special kind of class member function that is automatically called when an object of that class 
    is created. Constructors are typically used to initialize member variables of the class to appropriate user-provided 
    values, or to do any setup steps necessary for the class to be used (e.g. open a file or database).

    After a constructor executes, the object should be in a well-defined, usable state.

    Unlike normal member functions, constructors have specific rules for how they must be named:

        1.Constructors must have the same name as the class (with the same capitalization)
        2.Constructors have no return type (not even void)
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Default constructors and default initialization" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A constructor that takes no parameters (or has parameters that all have default values) is called a default 
    constructor. The default constructor is called if no user-provided initialization values are provided.

    Here is an example of a class that has a default constructor:
    */
    Fraction frac;// calls Fraction() default constructor
    std::cout << frac.getNumerator() << '/' << frac.getDenominator() << '=' << frac.getValue() << '\n';

    /*
    This class was designed to hold a fractional value as an integer numerator and denominator. We have defined a default 
    constructor named Fraction (the same as the class).

    When the line Fraction frac{}; executes, the compiler will see that we’re instantiating an object of type Fraction with 
    no arguments. It then performs value-initialization of frac, that is, the default constructor gets called. Although 
    technically incorrect, this is often called default initialization. In this case, the default constructor will be called 
    immediately after memory has been allocated and cleared for the object. The default constructor runs just like a normal 
    function (assigning the values 0 to m_numerator and 1 to m_denominator).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "List-initialization" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the above program, we initialized our class object using list-initialization:
    */
    Fraction frac2{};// List-initialization with empty set of braces (leads to value-initialization)

    Fraction frac3;// Default-initialization, calls default constructor

    /*
    For the most part, default- and list-initialization of a class object results in the same outcome: the default 
    constructor is called.

    Many programmers favor default-initialization over list-initialization for class objects. This is because when using 
    value-initialization, the compiler may zero-initialize the class members before calling the default constructor in 
    certain cases, which is slightly inefficient (C++ programmers don’t like paying for features they’re not using).

    However, favoring default-initialization also comes with a downside: you have to know whether a type will initialize 
    itself, ie. it is a class-type and all members have an initializer, or there is a default-constructor that initializes 
    all member variables. If you see a defined variable without an initializer, you have to think about whether that’s a 
    mistake or not (depending on what type the object it is).

    For example, the following code causes undefined behavior

    https://www.learncpp.com/cpp-tutorial/constructors/

    While you might be able to initialize all members in the classes you write, it’s not feasible to read the definitions 
    of all classes you use to make sure they do the same.

    Favoring value initialization for class objects is simple, consistent, and can help you catch errors, particularly while 
    you are learning.

    Best practice:
    Favor list-initialization over default-initialization for class objects.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Direct- and list-initialization using constructors with parameters" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    While the default constructor is great for ensuring our classes are initialized with reasonable default values, 
    often times we want instances of our class to have specific values that we provide. Fortunately, constructors can 
    also be declared with parameters. Here is an example of a constructor that takes two integer parameters that are 
    used to initialize the numerator and denominator:

    ---->>>> Look up on our 'class Fractional_number'
    
    Note that we now have two constructors: a default constructor that will be called in the default case, and a second 
    constructor that takes two parameters. These two constructors can coexist peacefully in the same class due to function 
    overloading. In fact, you can define as many constructors as you want, so long as each has a unique signature (number 
    and type of parameters).

    So how do we use this constructor with parameters? It’s simple! We can use list or direct initialization:
    */
    Fractional_number fiveThirds{ 5, 3 };// List initialization, calls Fraction(int, int)
    Fractional_number threeQuarters( 3, 4 );// Direct initialization, also calls Fraction(int, int)

    std::cout << fiveThirds.getValue() << '\n';
    std::cout << threeQuarters.getValue() << '\n';

    /*
    As always, we prefer list initialization. We’ll discover reasons (Templates and std::initializer_list) to use direct 
    initialization when calling constructors later in the tutorials. There is another special constructor that might make 
    brace initialization do something different, in that case we have to use direct initialization. We’ll talk about these 
    constructors later.

    Note that we have given the second parameter of the constructor with parameters a default value, so the following is also 
    legal:
    */
    Fractional_number six{ 7 };// calls Fraction(int, int) constructor, second parameter uses default value of 1

    std::cout << six.getValue() << '\n';

    /*
    Default values for constructors work exactly the same way as with any other functions, so in the above case where 
    we call six{ 7 }, the Fraction(int, int) function is called with the second parameter defaulted to value 1.

    Best practice:
    Favor brace initialization to initialize class objects.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Copy initialization using equals with classes" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Much like with fundamental variables, it’s also possible to initialize classes using copy initialization:
    */
    Fractional_number seven = Fractional_number{ 7 };// Copy initialize a Fraction, will call Fraction(6, 1)

    // Copy initialize a Fraction.  The compiler will try to find a way to convert 7 to a 
    //Fraction, which will invoke the Fraction(7, 1) constructor.
    Fractional_number eight = 8;

    std::cout << eight.getValue() << '\n';

    /*
    However, we recommend you avoid this form of initialization with classes, as it may be less efficient. Although 
    direct-initialization, list-initialization, and copy-initialization all work identically with fundamental types, 
    copy-initialization does not work the same with classes (though the end-result is often the same). We’ll explore 
    the differences in more detail in a future chapter.
    */

    
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Reducing your constructors" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the above two-constructor declaration of the Fraction class, the default constructor is actually somewhat redundant. 
    We could simplify this class as follows:
    
    class Fraction
    {
    private:
        int m_numerator {};
        int m_denominator {};

    public:
        // Default constructor
        Fraction(int numerator=0, int denominator=1)
        {
            assert(denominator != 0);

            m_numerator = numerator;
            m_denominator = denominator;
        }

        int getNumerator() { return m_numerator; }
        int getDenominator() { return m_denominator; }
        double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
    };

    Although this constructor is still a default constructor, it has now been defined in a way that it can accept one or 
    two user-provided values as well.

    Fraction zero; // will call Fraction(0, 1)
    Fraction zero{}; // will call Fraction(0, 1)
    Fraction six{ 6 }; // will call Fraction(6, 1)
    Fraction fiveThirds{ 5, 3 }; // will call Fraction(5, 3)

    When implementing your constructors, consider how you might keep the number of constructors down through smart defaulting 
    of values.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "A reminder about default parameters" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The rules around defining and calling functions that have default parameters (described in lesson 8.12 -- Default arguments) 
    apply to constructors too. To recap, when defining a function with default parameters, all default parameters must follow 
    any non-default parameters, i.e. there cannot be non-defaulted parameters after a defaulted parameter.

    This may produce unexpected results for classes that have multiple default parameters of different types. Consider:

    class Something
    {
    public:
        // Default constructor
        Something(int n = 0, double d = 1.2) // allows us to construct a Something(int, double), Something(int), or Something()
        {
        }
    };

    int main()
    {
        Something s1 { 1, 2.4 }; // calls Something(int, double)
        Something s2 { 1 }; // calls Something(int, double)
        Something s3 {}; // calls Something(int, double)

        Something s4 { 2.4 }; // will not compile, as there's no constructor to handle Something(double)

        return 0;
    }

    With s4, we’ve attempted to construct a Something by providing only a double. This won’t compile, as the rules for how 
    arguments match with default parameters won’t allow us to skip a non-rightmost parameter (in this case, the leftmost int 
    parameter).

    If we want to be able to construct a Something with only a double, we’ll need to add a second (non-default) constructor:

    class Something
    {
    public:
        // Default constructor
        Something(int n = 0, double d = 1.2) // allows us to construct a Something(int, double), Something(int), or Something()
        {
        }

        Something(double d)
        {
        }
    };

    int main()
    {
        Something s1 { 1, 2.4 }; // calls Something(int, double)
        Something s2 { 1 }; // calls Something(int, double)
        Something s3 {}; // calls Something(int, double)

        Something s4 { 2.4 }; // calls Something(double)

        return 0;
    }
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An implicitly generated default constructor" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    If your class has no constructors, C++ will automatically generate a public default constructor for you. 
    This is sometimes called an implicit constructor (or implicitly generated constructor).

    Consider the following class:
    */
    Date date{};

    /*
    The Date class has no constructors. Therefore, the compiler will generate a default constructor that allows us to create 
    a Date object without arguments.

    When the generated default constructor is called, members will still be initialized if they have non-static member 
    initializers.

    If your class has any other constructors, the implicitly generated constructor will not be provided. For example:
    */
    Date_next date{}; // error: Can't instantiate object because default constructor doesn't exist 
    //and the compiler won't generate one

    Date_next today{ 2020, 1, 19 }; // today is initialized to Jan 19th, 2020

    /*
    If your class has another constructor and you want to allow default construction, you can either add default 
    arguments to every parameter of a constructor with parameters, or explicitly define a default constructor.

    There’s a third option as well: you can use the default keyword to tell the compiler to create a default constructor 
    for us anyway:
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "An implicitly generated default constructor" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*


    return 0;
}
