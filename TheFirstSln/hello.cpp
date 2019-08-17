#include <iostream>

// define int variable, and assign 4 directly
extern int aa = 4;

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

	return 0;
}