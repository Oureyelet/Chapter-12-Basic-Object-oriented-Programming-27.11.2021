#include <iostream>
#include <string>

class Foo
{
public:
    Foo()
    {
        std::cout << "Hello 1" << '\n';
    }

    Foo(int value) : Foo{}
    {
        std::cout << "Hello " << value << ' ' << '\n';
        // code to do A
        // code to do B
    }
};

class Emplyee
{
private:
    int m_id{};
    std::string m_name{};

public:
    Emplyee(int id = 0, const std::string &name="") : m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Emplyee(const std::string& name) : Emplyee{ 0, name }
    {

    }
};

class Goo
{
private:
    int m_a{ 1 };
    int m_b{ 2 };

public:
    Goo()
    {
    }

    Goo(int a, int b) : m_a{ a }, m_b{ b }
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void print()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset()
    {
        *this = Goo();
    }
};

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Constructors with overlapping functionality" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    When you instantiate a new object, the object’s constructor is called implicitly. It’s not uncommon to have a class with 
    multiple constructors that have overlapping functionality. Consider the following class:

    ->> Go to see 'class Foo'
    
    This class has two constructors: a default constructor, and a constructor that takes an integer. Because the “code to 
    do A” portion of the constructor is required by both constructors, the code is duplicated in each constructor.

    As you’ve (hopefully) learned by now, having duplicate code is something to be avoided as much as possible, so let’s 
    take a look at some ways to address this.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The obvious solution doesn't work" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    The obvious solution would be to have the Foo(int) constructor call the Foo() constructor to do the A portion.
    
    However, if you try to have one constructor call another constructor in this way, it will compile and maybe cause a 
    warning, but it will not work as you expect, and you will likely spend a long time trying to figure out why, even with 
    a debugger. What’s happening is that Foo(); instantiates a new Foo object, which is immediately discarded, because it’s 
    not stored in a variable.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Delegating constructors" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Constructors are allowed to call other constructors from the same class. This process is called delegating constructors 
    (or constructor chaining).

    To have one constructor call another, simply call the constructor in the member initializer list. This is one case where 
    calling another constructor directly is acceptable. Applied to our example above:
    
    Foo(int value): Foo{} // use Foo() default constructor to do A
    {
        // code to do B
    }
    */
    Foo foo{123};

    /*
    This works exactly as you’d expect. Make sure you’re calling the constructor from the member initializer list, 
    not in the body of the constructor.

    Here’s another example of using delegating constructors to reduce redundant code:
    */
    Emplyee ziomek{"Ziomek"};


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Using a normal member function for setup" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Because a constructor can only initialize or delegate, this leads to a challenge if our default constructor does some 
    common initialization. Consider the following class:

    class Foo
    {
    private:
        const int m_value { 0 };

    public:
        Foo()
        {
            // code to do some common setup tasks (e.g. open a file or database)
        }

        Foo(int value) : m_value { value } // we must initialize m_value since it's const
        {
            // how do we get to the common initialization code in Foo()?
        }

    };

    Our Foo(int) constructor can either initialize m_value, or delegate to Foo() to access the setup code, but not both. 
    But what if we need to do both? A bad solution would be to copy the setup code from our default constructor to each of 
    our other constructors. But this will result in duplicate code, and a potential maintenance headache.

    Constructor are allowed to call non-constructor member functions (and non-member functions), so a better solution is to 
    use a normal (non-constructor) member function to handle the common setup tasks, like this:

    #include <iostream>

    class Foo
    {
    private:
        const int m_value { 0 };

        void setup() // setup is private so it can only be used by our constructors
        {
            // code to do some common setup tasks (e.g. open a file or database)
            std::cout << "Setting things up...\n";
        }

    public:
        Foo()
        {
            setup();
        }

        Foo(int value) : m_value { value } // we must initialize m_value since it's const
        {
            setup();
        }

    };

    int main()
    {
        Foo a;
        Foo b{ 5 };

        return 0;
    }

    In this case, we’ve created a setup() member function to handle various setup tasks that we need, and both of our 
    constructors call setup(). We’ve made this function private so we can ensure that only members of our class can call it.

    Of course, setup() isn’t a constructor, so it can’t initialize members. By the time the constructor calls setup(), 
    the members have already been created (and initialized if an initialization value was provided). The setup() function 
    can only assign values to members or do other types of setup tasks that can be done through normal statements (e.g. 
    open files or databases). The setup() function can’t do things like bind a member reference or set a const value 
    (both of which must be done on initialization), or assign values to members that don’t support assignment.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Resetting a class" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    Relatedly, you may find yourself in the situation where you want to write a member function (e.g. named reset()) to 
    reset a class back to the default state.

    Because you probably already have a default constructor that initializes your members to the appropriate default values, 
    you may be tempted to try to call the default constructor directly from reset(). However, trying to call a constructor 
    directly will generally result in unexpected behavior as we have shown above, so that won’t work.

    A mediocre implementation of a reset() function might look like this:
    
    class Foo
    {
    private:
        int m_a{ 1 };
        int m_b{ 2 };

    public:
        Foo()
        {
        }

        Foo(int a, int b)
            : m_a{ a }, m_b{ b }
        {
        }

        void print()
        {
            std::cout << m_a << ' ' << m_b << '\n';
        }

        void reset()
        {
            m_a = 1;
            m_b = 2;
        }
    };

    int main()
    {
        Foo a{ 3, 4 };
        a.reset();

        a.print();

        return 0;
    }

    While this works, it violates the DRY principle, as we have our “default” values in two places: once in the non-static 
    member initializers, and again in the body of reset(). There is no way for the reset() function to get the default values 
    from the non-static initializer.

    However, if the class is assignable (meaning it has an accessible assignment operator), we can create a new class object, 
    and then use assignment to overwrite the values in the object we want to reset:
    */
    Goo goo{ 3, 7 };

    goo.reset();

    goo.print();

    /*
    In the above reset() function, we create a default Foo object (which will have default values), then use assignment to 
    overwrite the members of our class with members from the default object. In this case, because our class doesn’t have an 
    explicit assignment operator, the compiler will create an implicit assignment operator for us to do the copy.
    */


   
   return 0;
}