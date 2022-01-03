#include <iostream>
#include <cmath> // for std::sqrt
#include <string> // for std::string
#include <string_view>

class Point2d
{
private:
    double m_x;
    double m_y;

public:
    Point2d(double x = 0.0, double y = 0.0)
        : m_x{ x }, m_y{ y }
    {

    }

    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ')' << '\n'; 
    }

    double distanceTo(const Point2d& distance) const
    {
        return std::sqrt((m_x - distance.m_x) * (m_x - distance.m_x) + (m_y - distance.m_y) * (m_y - distance.m_y));
    }

    friend double distanceFrom(const Point2d& first, const Point2d& second);
};

double distanceFrom(const Point2d& first, const Point2d& second)
{
    return std::sqrt((first.m_x - second.m_x) * (first.m_x - second.m_x) + 
                    (first.m_y - second.m_y) * (first.m_y - second.m_y));
}

class HelloWorld
{
private:
	char* m_data{};

public:
	HelloWorld()
	{
		m_data = new char[14];
		const char* init{ "Hello, World!" };
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}

	~HelloWorld()
	{
        // replace this comment with your destructor implementation
        delete[] m_data;
	}

	void print() const
	{
		std::cout << m_data << '\n';
	}

};

class Monster
{
public:
    enum class Type
    {
        dragon = 1,
        goblin = 2,
        ogre = 3,
        orc = 4,
        skeleton = 5,
        troll = 6,
        vampire = 7,
        zombie = 8,

        max_monster_types = 9
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hp{};

public:
    Monster(Type type, std::string name, std::string roar, int hp)
        : m_type{ type }, m_name{ name }, m_roar{ roar }, m_hp{ hp }
    {
    }

    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case Type::dragon: return " the dragon ";
        case Type::goblin: return " the goblin ";
        case Type::ogre: return " the ogre ";
        case Type::orc: return " the orc ";
        case Type::skeleton: return " the skeleton ";
        case Type::troll: return " the troll ";
        case Type::vampire: return " the vampire ";
        case Type::zombie: return " the zombie ";
        default: return "???";
        }
    }

    void print()
    {
        std::cout << m_name << getTypeString() << "has " << m_hp << " hit points and says " << m_roar << '\n';
    }

};

int main()
{
    /*
    In this chapter, we explored the meat of C++ -- object-oriented programming! This is the most important chapter in the 
    tutorial series.
    */

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quick Summary" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Classes allow you to create your own data types that bundle both data and functions that work on that data. Data and 
    functions inside the class are called members. Members of the class are selected by using the . operator (or -> if you’re 
    accessing the member through a pointer).

    Access specifiers allow you to specify who can access the members of a class. Public members can be accessed directly by 
    anybody. Private members can only be accessed by other members of the class. We’ll cover protected members later, when we 
    get to inheritance. By default, all members of a class are private and all members of a struct are public.

    Encapsulation is the process of making all of your member data private, so it can not be accessed directly. This helps 
    protect your class from misuse.

    Constructors are a special type of member function that allow you to initialize objects of your class. A constructor that 
    takes no parameters (or has all default parameters) is called a default constructor. The default constructor is used if no 
    initialization values are provided by the user. You should always provide at least one constructor for your classes.

    Member initializer lists allows you to initialize your member variables from within a constructor (rather than assigning 
    the member variables values).

    Non-static member initialization allows you to directly specify default values for member variables when they are declared.

    Constructors are allowed to call other constructors (called delegating constructors, or constructor chaining).

    Destructors are another type of special member function that allow your class to clean up after itself. Any kind of 
    deallocation or shutdown routines should be executed from here.

    All member functions have a hidden *this pointer that points at the class object being modified. Most of the time you will 
    not need to access this pointer directly. But you can if you need to.

    It is good programming style to put your class definitions in a header file of the same name as the class, and define your 
    class functions in a .cpp file of the same name as the class. This also helps avoid circular dependencies.

    Member functions can (and should) be made const if they do not modify the state of the class. Const class objects can only 
    call const member functions.

    Static member variables are shared among all objects of the class. Although they can be accessed from a class object, they 
    can also be accessed directly via the scope resolution operator.

    Similarly, static member functions are member functions that have no *this pointer. They can only access static member 
    variables.

    Friend functions are functions that are treated like member functions of the class (and thus can access a class’s private 
    data directly). Friend classes are classes where all members of the class are considered friend functions.

    It’s possible to create anonymous class objects for the purpose of evaluation in an expression, or passing or returning a 
    value.

    You can also nest types within a class. This is often used with enums related to the class, but can be done with other 
    types (including other classes) if desired.
    */
    

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time Question #1" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*

    a) Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, 
    both defaulted to 0.0. Provide a constructor and a print function.

    The following program should run:

    #include <iostream>

    int main()
    {
        Point2d first{};
        Point2d second{ 3.0, 4.0 };
        first.print();
        second.print();

        return 0;
    }

    This should print:

    Point2d(0, 0)
    Point2d(3, 4)
    */

    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    /*
    b) Now add a member function named distanceTo that takes another Point2d as a parameter, and calculates the distance 
    between them. Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as 
    std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)). The std::sqrt function lives in header cmath.

    The following program should run:
    */
    Point2d first2{};
    Point2d second2{ 3.0, 4.0 };
    first2.print();
    second2.print();
    std::cout << "Distance between two points: " << first2.distanceTo(second2) << '\n';

    /*
    c) Change function distanceTo from a member function to a non-member friend function that takes two 
    Points as parameters. Also rename it “distanceFrom”.

    The following program should run:
    */
    Point2d first3{};
    Point2d second3{ 3.0, 4.0 };
    first3.print();
    second3.print();
    std::cout << "Distance between two points: " << distanceFrom(first3, second3) << '\n';


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time Question #2" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Write a destructor for this class:

    #include <iostream>

    class HelloWorld
    {
    private:
        char* m_data{};

    public:
        HelloWorld()
        {
            m_data = new char[14];
            const char* init{ "Hello, World!" };
            for (int i = 0; i < 14; ++i)
                m_data[i] = init[i];
        }

        ~HelloWorld()
        {
            // replace this comment with your destructor implementation
        }

        void print() const
        {
            std::cout << m_data << '\n';
        }

    };

    int main()
    {
        HelloWorld hello{};
        hello.print();

        return 0;
    }
    */
    HelloWorld hello{};
	hello.print();


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Quiz time Question #3" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Let’s create a random monster generator. This one should be fun.

    a) First, let’s create an enumeration of monster types named MonsterType. Include the following monster types: Dragon, 
    Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. Add an additional max_monster_types enum so we can count 
    how many enumerators there are.
    */

    /*
    c) enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration. 
    When the enum is inside the class the “Monster” in “MonsterType” is redundant, it can be removed.
    */
    Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };

    /*
    e) Now we want to be able to print our monster so we can validate it’s correct. To do that, we’re going to need to 
    write a function that converts a Monster::Type into a string. Write that function (called getTypeString()), as well 
    as a print() member function.
    */
    Monster troll{ Monster::Type::troll, "Trolek", "*bla bla bla bla*", 133 };
    troll.print();



    return 0;
}