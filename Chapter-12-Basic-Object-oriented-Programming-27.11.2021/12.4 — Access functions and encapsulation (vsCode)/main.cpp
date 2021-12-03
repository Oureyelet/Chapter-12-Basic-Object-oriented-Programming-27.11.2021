#include <iostream>

int main()
{
    std::cout << "Hello World\n";

    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Why make member variables private?" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    In the previous lesson, we mentioned that class member variables are typically made private. Developers who are 
    learning about object-oriented programming often have a hard time understanding why you’d want to do this. To answer 
    that question, let’s start with an analogy.

    In modern life, we have access to many electronic devices. Your TV has a remote control that you can use to turn the 
    TV on/off. You drive a car (or scooter) to work. You take a picture on your smartphone. All three of these things use 
    a common pattern: They provide a simple interface for you to use (a button, a steering wheel, etc…) to perform an action. 
    However, how these devices actually operate is hidden away from you. When you press the button on your remote control, you 
    don’t need to know what it’s doing to communicate with your TV. When you press the gas pedal on your car, you don’t need to 
    know how the combustion engine makes the wheels turn. When you take a picture, you don’t need to know how the sensors gather 
    light into a pixellated image. This separation of interface and implementation is extremely useful because it allows us to 
    use objects without understanding how they work. This vastly reduces the complexity of using these objects, and increases 
    the number of objects we’re capable of interacting with.

    For similar reasons, the separation of implementation and interface is useful in programming.
    */


    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    std::cout << "Encapsulation" << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////" << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*
    */


    return 0;
}