#include <iostream>

int generateID()
{
    static int s_id{ 0 };

    return ++s_id;
}

class Something
{
public:
    int m_value{ 1 };
};

class Something2
{
public:
    static int s_value;
};

int Something2::s_value{ 1 };

class Date
{
public:
    static double s_monday; // declares the static member variable

private:
    static int s_fofo;
};

double Date::s_monday{ 6.45 }; // defines the static member variable (we'll discuss this section below)


int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Review of static keyword uses" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the lesson on file scope and the static keyword, you learned that static variables keep their values and are not 
    destroyed even after they go out of scope. For example:
    */

    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';

    /*
    Note that s_id has kept its value across multiple function calls.

    The static keyword has another meaning when applied to global variables -- it gives them internal linkage 
    (which restricts them from being seen/used outside of the file they are defined in). Because global variables 
    are typically avoided, the static keyword is not often used in this capacity.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Static member variables" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    C++ introduces two more uses for the static keyword when applied to classes: static member variables, and static member 
    functions. Fortunately, these uses are fairly straightforward. We’ll talk about static member variables in this lesson, 
    and static member functions in the next.

    Before we go into the static keyword as applied to member variables, first consider the following class:
    */
    Something first;
    Something second;

    first.m_value = 2;

    std::cout << first.m_value << '\n';//print 2
    std::cout << second.m_value << '\n'; //print 1

    /*
    When we instantiate a class object, each object gets its own copy of all normal member variables. In this case, 
    because we have declared two Something class objects, we end up with two copies of m_value: first.m_value, and 
    second.m_value. first.m_value is distinct from second.m_value. Consequently, the program above prints: 2,1

    Member variables of a class can be made static by using the static keyword. Unlike normal member variables, static 
    member variables are shared by all objects of the class. Consider the following program, similar to the above:
    */
    Something2 first2;
    Something2 second2;

    first2.s_value = 2;

    std::cout << first2.s_value << '\n'; // print 2
    std::cout << second2.s_value << '\n'; // print 2

    /*
    This program produces the following output: 2, 2 because s_value is a static member variable, s_value is shared 
    between all objects of the class. Consequently, first.s_value is the same variable as second.s_value. The above 
    program shows that the value we set using first can be accessed using second!
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Static members are not associated with class objects" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Although you can access static members through objects of the class (as shown with first.s_value and second.s_value in 
    the example above), it turns out that static members exist even if no objects of the class have been instantiated! 
    Much like global variables, they are created when the program starts, and destroyed when the program ends.

    Consequently, it is better to think of static members as belonging to the class itself, not to the objects of the class. 
    Because s_value exists independently of any class objects, it can be accessed directly using the class name and the scope 
    resolution operator (in this case, Something::s_value):
    */

    // note: we're not instantiating any objects of type Something

    Date::s_monday = 2;
    std::cout << Date::s_monday << '\n';

    /*
    In the above snippet, s_value is referenced by class name rather than through an object. Note that we have not even 
    instantiated an object of type Something, but we are still able to access and use Something::s_value. This is the 
    preferred method for accessing static members.

    Best practice

    Access static members by class name (using the scope resolution operator) rather than through an object of the class 
    (using the member selection operator).
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Defining and initializing static member variables" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    When we declare a static member variable inside a class, we’re telling the compiler about the existence of a static member 
    variable, but not actually defining it (much like a forward declaration). Because static member variables are not part of 
    the individual class objects (they are treated similarly to global variables, and get initialized when the program starts), 
    you must explicitly define the static member outside of the class, in the global scope.

    In the example above, we do so via this line:

    int Something::s_value{ 1 }; // defines the static member variable

    This line serves two purposes: it instantiates the static member variable (just like a global variable), and optionally 
    initializes it. In this case, we’re providing the initialization value 1. If no initializer is provided, C++ initializes 
    the value to 0.

    Note that this static member definition is not subject to access controls: you can define and initialize the value even if 
    it’s declared as private (or protected) in the class.

    If the class is defined in a .h file, the static member definition is usually placed in the associated code file for the 
    class (e.g. Something.cpp). If the class is defined in a .cpp file, the static member definition is usually placed 
    directly underneath the class. Do not put the static member definition in a header file (much like a global variable, 
    if that header file gets included more than once, you’ll end up with multiple definitions, which will cause a linker error).
    */

    return 0;
}