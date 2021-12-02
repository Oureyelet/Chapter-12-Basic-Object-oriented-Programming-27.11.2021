#include <iostream>
#include <array>
#include <vector>

struct DateStruct// members are public by default
{
    int day{};// public by default, can be accessed by anyone
    int month{};// public by default, can be accessed by anyone
    int year{};// public by default, can be accessed by anyone
};

class DateClass// members are private by default
{
    int m_month {}; // private by default, can only be accessed by other members
    int m_day {}; // private by default, can only be accessed by other members
    int m_year {}; // private by default, can only be accessed by other members
};

class Rota
{
    double m_monday{};
    double m_tuesday{};
    double m_wednesday{};
    double m_thursday{};
    double m_friday{};

public:

    void setTime(double m, double tu, double w, double t, double f)
    {
        m_monday = m;
        m_tuesday = tu;
        m_wednesday = w;
        m_thursday = t;
        m_friday = f;
    }

    void print()
    {
        std::cout << "Your rota for this week: " << '\n';
        std::cout << "Monday: " << m_monday << '\n';
        std::cout << "Tuesday: " << m_tuesday << '\n';
        std::cout << "Wednesday: " << m_wednesday << '\n';
        std::cout << "Thursday: " << m_thursday << '\n';
        std::cout << "Friday: " << m_friday << '\n';
    }
};

class Point3d
{
private:
    int m_x{};
    int m_y{};
    int m_z{};
public:

    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << '\n'; 
    }

    bool isEqual(const Point3d& pt)
    {
       return (pt.m_x == m_x && pt.m_y == m_y && pt.m_z == m_z); 
    }
};

class Stack
{
private:

    std::vector<int> stack{};
    int size_of_the_stack{10};

public:

    void reset()
    {
        stack.clear();
    }

    bool push(int x)
    {

        if(stack.size() < size_of_the_stack)
        {
            stack.push_back(x);

            return 0;
        }
        else
            return 1;
    }
    
    pop()
    {
        stack.pop_back()
    }

};

int main()
{
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Public and private members" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Consider the following struct above our main function call 'DateStruct'
    */
    DateStruct date;
    date.day = 1;
    date.month = 12;
    date.year = 2021;

    /*
    In the main() function of the example above, we declare a DateStruct and then we directly access its members in 
    order to assign values to them. This works because all members of a struct are public members by default. Public 
    members are members of a struct or class that can be accessed directly by anyone, including from code that exists outside 
    the struct or class. In this case, function main() exists outside of the struct, but it can directly access members month, 
    day, and year, because they are public members.

    The code outside of a struct or class is sometimes called the public: the public is only allowed to access the public 
    members of a struct or class, which makes sense.

    Now consider the following almost-identical class (look above main() on our 'DateClass') :
    */
    DateClass date_class;
    /*
    date.m_month = 10; // error
    date.m_day = 14; // error
    date.m_year = 2020; // error
    
    If you were to compile this program, you would receive errors. This is because by default, all members of a class 
    are private. Private members are members of a class that can only be accessed by other members of the class 
    (not by the public). Because main() is not a member of DateClass, it does not have access to date’s private members.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Access specifiers" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Although class members are private by default, we can make them public by using the public keyword:
    
    class DateClass
    {
    public: // note use of public keyword here, and the colon
        int m_month {}; // public, can be accessed by anyone
        int m_day {}; // public, can be accessed by anyone
        int m_year {}; // public, can be accessed by anyone
    };

    Because DateClass’s members are now public, they can be accessed directly by main().

    The public keyword, along with the following colon, is called an access specifier. Access specifiers determine who has 
    access to the members that follow the specifier. Each of the members “acquires” the access level of the previous access 
    specifier (or, if none is provided, the default access specifier).

    C++ provides 3 different access specifier keywords: public, private, and protected. Public and private are used to make 
    the members that follow them public members or private members respectively. The third access specifier, protected, works 
    much like private does. We will discuss the difference between the private and protected access specifier when we cover 
    inheritance.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Mixing access specifiers" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    A class can (and almost always does) use multiple access specifiers to set the access levels of each of its members. 
    There is no limit to the number of access specifiers you can use in a class.

    In general, member variables are usually made private, and member functions are usually made public. We’ll take a 
    closer look at why in the next lesson.

    Rule:
    Make member variables private, and member functions public, unless you have a good reason not to.

    Let’s take a look at an example of a class that uses both private and public access:
    */
    Rota rota;
    rota.setTime(6.45, 6.45, 6.45, 6.00, 6.45);
    rota.print();
    std::cout << '\n';

    /*
    Note that although we can’t access date’s members variables m_month, m_day, and m_year directly from main 
    (because they are private), we are able to access them indirectly through public member functions setDate() and print()!

    The group of public members of a class are often referred to as a public interface. Because only public members 
    can be accessed from outside of the class, the public interface defines how programs using the class will interact 
    with the class. Note that main() is restricted to setting the date and printing the date. The class protects the member 
    variables from being accessed or edited directly.

    Some programmers prefer to list private members first, because the public members typically use the private ones, so it 
    makes sense to define the private ones first. However, a good counterargument is that users of the class don’t care about 
    the private members, so the public ones should come first. Either way is fine.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Access controls work on a per-class basis" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    https://www.learncpp.com/cpp-tutorial/public-vs-private-access-specifiers/
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Structs vs classes revisited" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Now that we’ve talked about access specifiers, we can talk about the actual differences between a class and a struct 
    in C++. A class defaults its members to private. A struct defaults its members to public.

    That’s it!

    (Okay, to be pedantic, there’s one more minor difference -- structs inherit from other classes publicly and classes 
    inherit privately. We’ll cover what this means in a future chapter, but this particular point is practically irrelevant 
    since you should never rely on the defaults anyway).
    */

    
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz Time" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    a) What is a public member?

    Show Solution

    b) What is a private member?

    Show Solution

    c) What is an access specifier?

    Show Solution

    d) How many access specifiers are there, and what are they?

    Show Solution
    */

    /*
    a) Write a simple class named Point3d. The class should contain:

    Three private member variables of type int named m_x, m_y, and m_z;
    A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
    A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>

    Make sure the following program executes correctly:

    int main()
    {
        Point3d point;
        point.setValues(1, 2, 3);

        point.print();
        std::cout << '\n';

        return 0;
    }

    This should print:

    <1, 2, 3>
    */
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    /*
    b) Add a function named isEqual() to your Point3d class. The following code should run correctly:
    */
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if(point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }


    /*
    Question #3

    Now let’s try something a little more complex. Let’s write a class that implements a simple stack from scratch. 
    Review lesson 11.8 -- The stack and the heap if you need a refresher on what a stack is.

    The class should be named Stack, and should contain:

        A private fixed array of integers of length 10.
        A private integer to keep track of the size of the stack.
        A public member function named reset() that sets the size to 0.
        A public member function named push() that pushes a value on the stack. push() should return false if the array is 
        already full, and true otherwise.
        A public member function named pop() that pops a value off the stack and returns it. If there are no values on the 
        stack, the code should exit via an assert.
        A public member function named print() that prints all the values in the stack.

    Make sure the following program executes correctly:

    int main()
    {
        Stack stack;
        stack.reset();

        stack.print();

        stack.push(5);
        stack.push(3);
        stack.push(8);
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();
        stack.pop();

        stack.print();

        return 0;
    }

    This should print:

    ( )
    ( 5 3 8 )
    ( 5 3 )
    ( )
    */


    return 0;
}