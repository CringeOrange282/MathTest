#include "cmath.h"
#include <cstdlib>
#include <random>
std::mt19937 Task::gen(std::random_device{}());

Task::Task(){
	std::uniform_real_distribution<double> distrib;
	this->num1 =distrib(gen);
	this->num2 =distrib(gen);
	

	random_operator();
	random_answer();
}
Task::Task(int min, int max, char user_operation) : operation(user_operation) {
	std::uniform_real_distribution<double> distrib(min, max);
	this->num1 = distrib(gen);
	this->num2 = distrib(gen);
	

	if (this->operation == '\0') {
		random_operator();
	}
	random_answer();
	
}
void Task::random_operator() {
	std::uniform_int_distribution<int> distrib(1, 4);
	int rand = distrib(gen);
	switch (rand) {
	case 1: this->operation = '+'; break;
	case 2: this->operation = '-'; break;
	case 3: this->operation = '*'; break;
	case 4: this->operation = '/'; break;
	}
}
void Task::random_answer() {
	
	switch (this->operation) {
	case '+': this->answer = num1 + num2; break;
	case '-': this->answer = num1 - num2; break;
	case '*': this->answer = num1 * num2; break;
	case '/':
		if (this->num2 != 0.0) {
			this->answer = num1 / num2;
		}
		else {
			this->answer = 0.0; 
		}
		break;
	}
}

MathTest::MathTest(int count_tests) {
	tasks = new Task[count_tests];
	count = count_tests;
	user_answers = new int[count_tests];
	correct_count = 0;
}
MathTest::MathTest(int count_tests, int min, int max) {
	tasks = new Task[count_tests];
	for (int i = 0; i < count_tests; i++) {
		tasks[i] = Task(min, max);
	}
	count = count_tests;
	user_answers = new int[count_tests];
	correct_count = 0;
}
MathTest::MathTest(int count_tests, int min, int max, char operation) {
	tasks = new Task[count_tests];
	for (int i = 0; i < count_tests; i++) {
		tasks[i] = Task(min, max, operation);
	}
	count = count_tests;
	user_answers = new int[count_tests];
	correct_count = 0;
}
MathTest::~MathTest() {
	delete[] tasks;
	delete[] user_answers;
}

const Task& MathTest::getTask(int index) const{
	return tasks[index];
}