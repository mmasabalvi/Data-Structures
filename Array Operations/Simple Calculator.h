#include<iostream>
using namespace std;

template<typename T>
class Calculator
{
	T a;
	T b;

public:

	Calculator(T a, T b)
	{
		this->a = a;
		this->b = b;
	}

	void show(T a, T b)
	{
		cout << "Numbers given were: " << a << " " << b << endl;
	}

	
	T Addition()
	{
		show(a, b);
		return (a + b);
	}

	T Subtraction()
	{
		show(a, b);
		return (a - b);
	}

	T Multiplication()
	{
		show(a, b);
		return (a * b);
	}

	T Division()
	{
		show(a, b);
		return (a / b);
	}

};
//--------------------------------------//
//  Calculator 
//---------------------------------
/*
TEST(CalculatorTest, PerformCalculations) {
    Calculator<int> intCalculator(5, 2);

    EXPECT_EQ(intCalculator.Addition(), 7);
    EXPECT_EQ(intCalculator.Subtraction(), 3);
    EXPECT_EQ(intCalculator.Multiplication(), 10);
    EXPECT_EQ(intCalculator.Division(), 2);
}*/
