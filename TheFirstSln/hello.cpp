#include <iostream>
#include <time.h>

constexpr auto Pi = 3.14159265354;
const double pai = 3.1415926;

// declare int variable, and assign 4 directly
extern int aa = 4;
int cc = 123;

// declare function
int ret();
void multiplication_table(void);
void arr(void);
void pointer(void);
size_t generate_rand();
void reference(void);
void print_book(struct Books book);

struct Books {
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};

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

    enum month {
        Jan, // 0, enum is from 0, then autoincrease +1
        Feb = 2,
        March, // 3, it's up to the previous value
    };

    // define enum month variable "mon", whose value is March
    enum month mon = March;

    // define enum weekday variable "day"
    enum weekday {
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

    arr();
    pointer();
    reference();

    // struct
    Books book1;
    Books book2;

    strcpy_s(book1.title, "Machine Learning in Action");
    strcpy_s(book1.author, "Unknown");
    strcpy_s(book1.subject, "Machine Learning");
    book1.book_id = 123;

    // define a struct pointer
    Books* book_p;
    book_p = &book1;
    print_book(*book_p);
    // <=>
    print_book(book1);
    // if you wanna access struct member by struct pointer, you need use ->
    std::cout << "Title(book_p->title): " << book_p->title << std::endl;

    return 0;
}

int ret() {
    return cc;
}

void print_book(struct Books book) {
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Subject: " << book.subject << std::endl;
    std::cout << "ID: " << book.book_id << std::endl;
}

size_t generate_rand() {
    srand((unsigned)time(NULL));
    return rand();
}

void reference(void) {
    int i = 10;
    int& ref = i;
    // Personally, ref is the alias of i.
    std::cout << "The val of ref: " << ref << std::endl;
    std::cout << "The addr of ref: " << &ref << std::endl;
    std::cout << "The addr of i: " << &i << std::endl;
    std::cout << "The val of i: " << i << std::endl;
}

void pointer(void) {
    int temp = 100;
    int* ip = &temp;// int *ip; ip = &temp;
    std::cout << "The *ip is : " << *ip << std::endl; // temp value
    std::cout << "The ip is : " << ip << std::endl; // temp address
    std::cout << "The &ip is : " << &ip << std::endl; // pointer's own address
    std::cout << "The &*ip is : " << &*ip << std::endl; // temp address
    std::cout << "The temp is : " << temp << std::endl; // temp value
    std::cout << "The &temp is : " << &temp << std::endl; // temp address
    std::cout << "The *&temp is : " << *&temp << std::endl; // temp value
    // All in all
    // & is to get the memory addr of a variable(Get Addr)
    // * is to get the value by memory addr(Get Val)

    double balance[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
    // balance is the balance[0]'s address
    double* p = balance;
    // Actually, To calculate the size of a memory address
    std::cout << "The size of pointer: " << sizeof p << std::endl;
    printf("balance[0] = %.1f\t *p = %.1f\t\t p[0] = %.1f\n", balance[0], *p, p[0]);
    printf("balance[1] = %.1f\t *(p + 1) = %.1f\t\t p[1] = %.1f\n", balance[1], *(p + 1), p[1]);
    printf("balance[2] = %.1f\t *(p + 2) = %.1f\t\t p[2] = %.1f\n", balance[2], *(p + 2), p[2]);
    printf("balance[3] = %.1f\t *(p + 3) = %.1f\t p[3] = %.1f\n", balance[3], *(p + 3), p[3]);
    printf("balance[4] = %.1f\t *(p + 4) = %.1f\t p[4] = %.1f\n", balance[4], *(p + 4), p[4]);
}

void arr(void) {
    // char array must be ended with NULL
    char a1[] = { 'a','b','c' }; // initialization without NULL
    char a2[] = { 'a','b','c', '\0' }; // initialization with NULL
    char a3[] = "C++"; // automatically append NULL
    const char a4[6] = "hello"; // automatically append NULL
    char a5[15] = "0123456789";
    printf("The length of a1: %zu\n", sizeof(a1)); // 3
    printf("The length of a2: %zu\n", sizeof(a2)); // 4
    printf("The length of a3: %zu\n", sizeof(a3)); // 4
    printf("The length of a4: %zu\n", sizeof(a4)); // 6
    printf("The length of a5: %zu\n", sizeof a5); // 15
    printf("The length of a5: %zu\n", strlen(a5)); // 10
}

void multiplication_table(void) {
    for (size_t i = 1; i < 10; i++) {
        for (size_t j = 1; j < i + 1; j++) {
            printf("%zu * %zu = %zu, ", j, i, j * i);
        }
        printf("\n");
    }
}

void yang_hui_triangle(size_t floor) {
    if (floor < 1) {
        printf("The floor should no be less than 1.");
        return;
    }
    for (size_t i = 0; i < floor; i++) {
        for (size_t j = 0; j < 99; j++) {
            // TODO After learning the pointer
        }
    }
}
