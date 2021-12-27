#ifndef TEST_H
#define TEST_H

class Test
{
private:
    static const int s_test_1{ 33 }; // a static const int can be declared and initialized directly

public:
    Test()
    {
        s_test = s_test_1;
    }

    static int s_test;
    static constexpr double s_value{ 2.2 }; //ok
    static constexpr std::array<int, 3> s_array{1, 2, 3}; // this even works for classes that support constexpr initialization

    int print()
    {
        return s_test_1;
    }
};

#endif // end TEST_H
