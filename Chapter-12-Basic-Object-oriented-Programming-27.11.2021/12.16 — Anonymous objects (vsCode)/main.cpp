#include <iostream>

int add(int x, int y)
{
    int sum{ x + y };

    return sum;
}

int add_anonymous(int x, int y)
{
    return x + y;// an anonymous object is created to hold and return the result of x + y
}

void printValue(int value)
{
    std::cout << value << '\n';
}

int main()
{
    std::cout << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Anonymous objects" << '\n';
    std::cout << "//////////////////////////////////////////////////////////////////////////////////////////" << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In certain cases, we need a variable only temporarily. For example, consider the following situation:
    */
    std::cout << add(234, 234) << '\n';

    /*
    In the add() function, note that the sum variable is really only used as a temporary placeholder variable. It doesn’t 
    contribute much -- rather, its only function is to transfer the result of the expression to the return value.

    There is actually an easier way to write the add() function using an anonymous object. An anonymous object is essentially a 
    value that has no name. Because they have no name, there’s no way to refer to them beyond the point where they are created. 
    Consequently, they have “expression scope”, meaning they are created, evaluated, and destroyed all within a single expression.

    Here is the add() function rewritten using an anonymous object:
    */
    std::cout << add_anonymous(123, 321) << '\n';

    /*
    When the expression x + y is evaluated, the result is placed in an anonymous object. A copy of the anonymous object is then 
    returned to the caller by value, and the anonymous object is destroyed.

    This works not only with return values, but also with function parameters. For example, instead of this:
    */
    int sum{ 4 + 7 };
    printValue(sum);



    return 0;
}