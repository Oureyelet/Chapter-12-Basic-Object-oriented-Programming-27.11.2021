#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id) : m_id{ id }
    {
    }

    void setID(int id)
    {
        m_id = id;
    }

    int getID()
    {
        return m_id;
    }
};

int main()
{
    std::cout << "Our Lord Jezus Christ is real God." << '\n';

    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The hidden “this” pointer" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    One of the questions about classes that new object-oriented programmers often ask is, “When a member function is called, 
    how does C++ keep track of which object it was called on?”. The answer is that C++ utilizes a hidden pointer named “this”! 
    Let’s take a look at “this” in more detail.

    The following is a simple class that holds an integer and provides a constructor and access functions. Note that no 
    destructor is needed because C++ can clean up integer member variables for us.
    
    Here’s a sample program that uses this class:
    */
    Simple simple{ 5 };
    simple.setID(3);
    std::cout << simple.getID() << '\n';

    /*
    Somehow, when we call simple.setID(2);, C++ knows that function setID() should operate on object simple, and 
    that m_id actually refers to simple.m_id. Let’s examine the mechanics behind how this works.
    */


    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "The hidden *this pointer" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    
    */


    return 0;
}