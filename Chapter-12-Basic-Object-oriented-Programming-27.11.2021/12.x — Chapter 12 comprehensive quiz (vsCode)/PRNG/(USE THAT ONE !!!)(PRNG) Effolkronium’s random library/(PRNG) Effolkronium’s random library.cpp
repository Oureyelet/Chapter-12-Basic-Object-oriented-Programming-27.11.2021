#include <iostream>
#include "random.hpp"

// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;

int main()
{
    std::cout << Random::get(11, 23) << '\n';
    std::cout << Random::get(1, 40) << '\n';
    std::cout << Random::get(113, 433) << '\n';

    int x{ Random::get(123, 456) };

    std::cout << x << '\n';
    
    return 0;
}