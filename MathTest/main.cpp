#include <iostream>
#include "cmath.h"

int main() {
	MathTest* taskBank = nullptr;

	std::cout << "Welcome to the Mathematical Olympiad!\n";
	transfer setup = user_input();
	taskBank = user_choice(setup);
	delete taskBank;
}
