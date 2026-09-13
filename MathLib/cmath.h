#pragma once
#include <iostream>
#include<random>
struct Task {
	double num1;
	double num2;
	char operation;
	double answer;
	void random_operator();
	void random_answer();

	Task();
	Task(int min, int max, char user_operation = '\0');

private:
	static std::mt19937 gen;
};

class MathTest;