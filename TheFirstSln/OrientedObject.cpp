#include <iostream>
using namespace std;

class Box {
public:
    double get_length() { return length; }
private:
    double length;
    double width;
    double height;
} box1, box2;

int main(void) {
    cout << box1.get_length << endl;
}
