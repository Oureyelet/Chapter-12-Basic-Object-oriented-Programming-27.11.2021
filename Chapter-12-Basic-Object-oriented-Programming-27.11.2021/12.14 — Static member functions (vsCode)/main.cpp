#include <iostream>
#include <vector>

class Something
{
private:
    static int s_value;

public:
    static int getValue()// static member function
    {
        return s_value;
    }

};

class ID_Generator
{
private:
    static int s_nextID;// Here's the declaration for a static member

public:
    static int getNextID();// Here's the declaration for a static function
};

int Something::s_value{ 7 };// initializer, this is okay even though s_value is private since it's a definition

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int ID_Generator::s_nextID{ 1 };

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int ID_Generator::getNextID()
{
    return s_nextID++;
}

class MyClass
{
public:
    static std::vector<char> s_mychars;

    //for instance with lambda
    static std::vector<char> s_mychars_L;

};

std::vector<char> MyClass::s_mychars{ 'a', 'e', 'i', 'o', 'u' };// initialize static variable at point of definition

//same like above but with lambda

std::vector<char> MyClass::s_mychars_L{
    []{
        std::vector<char> v{};

        for(char ch{'a'}; ch <= 'z'; ++ch)
        {
            v.push_back(ch);
        }

        return v;
    }()
};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Static member functions" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the previous lesson on 12.13 -- Static member variables, you learned that static member variables are member 
    variables that belong to the class rather than objects of the class. If the static member variables are public, 
    we can access them directly using the class name and the scope resolution operator. But what if the static member 
    variables are private? Consider the following example:
    */

    //see our Something class...
    // how do we access Something::s_value since it is private?

    /*
    In this case, we can’t access Something::s_value directly from main(), because it is private. Normally we access 
    private members through public member functions. While we could create a normal public member function to access 
    s_value, we’d then need to instantiate an object of the class type to use the function! We can do better. It turns 
    out that we can also make functions static.

    Like static member variables, static member functions are not attached to any particular object. Here is the above 
    example with a static member function accessor:
    */
    std::cout << Something::getValue() << '\n'; 

    /*
    Because static member functions are not attached to a particular object, they can be called directly by using the class 
    name and the scope resolution operator. Like static member variables, they can also be called through objects of the 
    class type, though this is not recommended.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Static member functions have no *this pointer" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Static member functions have two interesting quirks worth noting. First, because static member functions are not attached 
    to an object, they have no this pointer! This makes sense when you think about it -- the this pointer always points to 
    the object that the member function is working on. Static member functions do not work on an object, so the this pointer 
    is not needed.

    Second, static member functions can directly access other static members (variables or functions), but not non-static 
    members. This is because non-static members must belong to a class object, and static member functions have no class 
    object to work with!
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Another example" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Static member functions can also be defined outside of the class declaration. This works the same way as for normal 
    member functions.

    Here’s an example:
    */
    for(int i{ 0 }; i < 5; ++i)
    {
        std::cout << "The next ID is: " << ID_Generator::getNextID() << '\n';
    }

    /*
    Note that because all the data and functions in this class are static, we don’t need to instantiate an object of the 
    class to make use of its functionality! This class utilizes a static member variable to hold the value of the next ID 
    to be assigned, and provides a static member function to return that ID and increment it.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "A word of warning about classes with all static members" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Be careful when writing classes with all static members. Although such “pure static classes” (also called “monostates”) 
    can be useful, they also come with some potential downsides.

    First, because all static members are instantiated only once, there is no way to have multiple copies of a pure static 
    class (without cloning the class and renaming it). For example, if you needed two independent IDGenerator objects, this 
    would not be possible with a single pure static class.

    Second, in the lesson on global variables, you learned that global variables are dangerous because any piece of code 
    can change the value of the global variable and end up breaking another piece of seemingly unrelated code. The same 
    holds true for pure static classes. Because all of the members belong to the class (instead of object of the class), 
    and class declarations usually have global scope, a pure static class is essentially the equivalent of declaring 
    functions and global variables in a globally accessible namespace, with all the requisite downsides that global 
    variables have.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "C++ does not support static constructors" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    If you can initialize normal member variables via a constructor, then by extension it makes sense that you should be able 
    to initialize static member variables via a static constructor. And while some modern languages do support static 
    constructors for precisely this purpose, C++ is unfortunately not one of them.

    If your static variable can be directly initialized, no constructor is needed: you can initialize the static member 
    variable at the point of definition (even if it is private). We do this in the IDGenerator example above. Here’s another 
    example:
    */
    for(auto& elemet : MyClass::s_mychars)
    {
        std::cout << elemet << '\n';
    }

    /*
    If initializing your static member variable requires executing code (e.g. a loop), there are many different, 
    somewhat obtuse ways of doing this. One way that works with all variables, static or not, is to use a lambda 
    and call it immediately.
    */
    for(auto& element : MyClass::s_mychars_L)
    {
        std::cout << element << ' ';
    }

    /*
    The following code presents a method that behaves more like a regular constructor. However, it is a little tricky, 
    and you’ll probably never need it, so feel free to skip the remainder of this section if you desire.
    */
    // see more: https://www.learncpp.com/cpp-tutorial/static-member-functions/


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Summary" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Static member functions can be used to work with static member variables in the class. An object of the class is not 
    required to call them.

    Classes can be created with all static member variables and static functions. However, such classes are essentially the 
    equivalent of declaring functions and global variables in a globally accessible namespace, and should generally be 
    avoided unless you have a particularly good reason to use them.
    */
    



    return 0;
}