#include "cmath.h"
#include <cstdlib>
#include <random>
#include <iomanip>
#include <string>
std::mt19937 Task::gen(std::random_device{}());

Task::Task() {
	std::uniform_int_distribution<int> distrib(1, 50);
	this->num1 = distrib(gen);
	this->num2 = distrib(gen);

	random_operator();
	random_answer();
}
Task::Task(int min, int max, char user_operation) : operation(user_operation) {
	std::uniform_int_distribution<int> distrib(min, max);
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
		this->answer = this->num1;
		this->num1 = this->answer * this->num2;
		if (this->num2 == 0){
			this->num2 = 1;
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

const Task& MathTest::getTask(int index) const {
	return tasks[index];
}

transfer user_input() {
	transfer setup;
	std::cout << "1 random questions\n2 random questions in the range\n3 questions in a range with a choice of operations\n";
	std::cin >> setup.choice;
	while (setup.choice > 3 || setup.choice < 1) {
		std::cout << "Please, enter correct:";
		std::cin >> setup.choice;
	}
	if (setup.choice == 1) {
		std::cout << "select the number of questions\n";
		std::cin >> setup.count_tests;
		return setup;
	}
	else if (setup.choice == 2) {
		std::cout << "select the number of questions, min number, max number\n";
		std::cin >> setup.count_tests >> setup.min >> setup.max;
		return setup;
	}
	else if (setup.choice == 3) {
		std::cout << "select the number of questions, min number, max number and operation\n";
		std::cin >> setup.count_tests >> setup.min >> setup.max >> setup.operation;
		return setup;
	}
}

MathTest* user_choice(transfer setup) {
	if (setup.choice == 1) {
		return new MathTest(setup.count_tests);
	}
	else if (setup.choice == 2) {
		return new MathTest(setup.count_tests, setup.min, setup.max);
	}
	else if (setup.choice == 3) {
		return new MathTest(setup.count_tests, setup.min, setup.max, setup.operation);
	}
	else return nullptr;
}

void MathTest::run() {
	int answer;
	for (int i = 0; i < this->count; i++) {
		std::cout << this->getTask(i).num1 << this->getTask(i).operation << this->getTask(i).num2 << "\n";
		std::cout << "Your answer: ";
		std::cin >> answer;
		check_answer(answer, i);
	}
}
void MathTest::check_answer(int answer, int index) {
	if (answer == this->getTask(index).answer) {
		this->correct_count++;
	}
	this->user_answers[index] = answer;

}
void MathTest::show_statistics() {
	std::cout << "|    No     |";
	for (int i = 0; i < this->count; i++) {
		std::cout << " " << std::setw(6) << (i + 1) << " |";
	}
	std::cout << "\n";

	std::cout << "+-----------+";
	for (int i = 0; i < count; ++i) {
		std::cout << "--------+";
	}
	std::cout << "\n";

	std::cout << "| Question  |";
	for (int i = 0; i < count; ++i) {
		std::string expr = std::to_string(this->getTask(i).num1) + " " +
			std::string(1, this->getTask(i).operation) + " " +
			std::to_string(this->getTask(i).num2);
		std::cout << " " << std::setw(6) << expr << " |";
	}
	std::cout << "\n";

	std::cout << "| True Ans  |";
	for (int i = 0; i < count; ++i) {
		std::cout << " " << std::setw(6) << this->getTask(i).answer << " |";
	}
	std::cout << "\n";

	std::cout << "| Your Ans  |";
	for (int i = 0; i < count; ++i) {
		std::cout << " " << std::setw(6) << user_answers[i] << " |";
	}
	std::cout << "\n";

	std::cout << "|  Result   |";
	for (int i = 0; i < count; ++i) {
		char sign = (user_answers[i] == this->getTask(i).answer) ? '+' : '-';
		std::cout << " " << std::setw(6) << sign << " |";
	}
	std::cout << "\n\n";

	std::cout << "Total Result: " << correct_count << " / " << count << "\n";
}