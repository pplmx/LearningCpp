#include <iostream>
using namespace std;

class Box {
  double length;
  double width;
  double height;

 public:
  double get_length() { return length; }
} box1, box2;

int main(void) { cout << box1.get_length << endl; }
