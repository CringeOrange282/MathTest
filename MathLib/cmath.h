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

class MathTest {
	Task* tasks;
	int count;
	int* user_answers;
	int correct_count;
public:
	MathTest(int count_tests);
	MathTest(int count_tests, int min, int max);
	MathTest(int count_tests, int min, int max, char operation);
	~MathTest();
	void run();

	const Task& getTask(int index) const;
};

struct transfer {
	int count_tests = 0;
	int min = 0;
	int max = 0;
	char operation =  '/';
	int choice = 0;
};

transfer user_input();
MathTest* user_choice(transfer setup);