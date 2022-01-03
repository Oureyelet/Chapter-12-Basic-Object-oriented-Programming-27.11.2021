#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::rand();

    for(int count{ 1 }; count <= 100; ++count)
    {
        std::cout << getRandomNumber(1, 6) << '\t';

        if(count % 5 == 0)
            std::cout << '\n';
    }


    return 0;
}