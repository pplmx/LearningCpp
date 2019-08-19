#include <iostream>

constexpr auto Pi = 3.14159265354;
const double pai = 3.1415926;

// declare int variable, and assign 4 directly
extern int aa = 4;
int cc = 123;

// declare function
int ret();
void multiplication_table(void);

/*
parameter is none
return is int
*/
int main(void) {
    // only define external variable on a local declaration
    // cannot initialize directly
    extern int bb;

    // print hello, world
    std::cout << "hello, world" << std::endl;

    bool is_on = false;
    char ch = 'a';
    int num = 10;
    float fl = 10.1;
    double dou = 10.2;
    std::cout << "num + fl = " << num + (int)fl << std::endl;

    // define boolean 
    typedef bool boolean;
    boolean is_Okay = false;

    enum month
    {
        Jan, // 0, enum is from 0, then autoincrease +1
        Feb = 2,
        March, // 3, it's up to the previous value
    };

    // define enum month variable "mon", whose value is March
    enum month mon = March;

    // define enum weekday variable "day"
    enum weekday
    {
        Sun, //0
        Mon, //1
        Tues, //2
        Wed, Thur, Fri, Sat
    } day;
    day = Fri;

    int cc = 20;
    // the func's cc is still global cc, so kk = 123
    int kk = ret();
    // local cc
    std::cout << cc << std::endl;
    // global cc
    std::cout << ::cc << std::endl;
    std::cout << kk << std::endl;

    multiplication_table();

    // lambda expression
    // [capture](parameters)->return-type{statement}
    auto fun1 = [](int x, int y) { return x < y; };
    auto fun2 = [](int x, int y) -> int { int z = x + y; return z + x; };


    return 0;
}

int ret() {
    return cc;
}

void multiplication_table(void) {
    for (size_t i = 1; i < 10; i++)
    {
        for (size_t j = 1; j < i + 1; j++)
        {
            printf("%zu * %zu = %zu, ", j, i, j * i);
        }
        printf("\n");
    }
}

void yang_hui_triangle(size_t floor) {
    if (floor < 1)
    {
        printf("The floor should no be less than 1.");
        return;
    }
    for (size_t i = 0; i < floor; i++)
    {
        for (size_t j = 0; j < 99; j++)
        {
            // TODO After learning the pointer
        }
    }
}
