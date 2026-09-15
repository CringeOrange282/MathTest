#include <iostream>
#include "cmath.h"

int main() {
	MathTest* taskBank = nullptr; int choice;
	while (1) {
		std::cout << "Welcome to the Mathematical Olympiad!\n";
		std::cout << "1 Starting Test\n2 Statistic\n3 Exit\n";
		std::cin >> choice;
		if (choice == 1) {
			transfer setup = user_input();
			taskBank = user_choice(setup);
			taskBank->run();
		}
		else if (choice == 2) {
			if (taskBank != nullptr) {
				taskBank->show_statistics();
			}
			else {
				std::cout << "No statistic now\n";
			}
		}
		else if(choice == 3) {
			delete taskBank;
			break;
		}
		else {
			std::cout << "Enter correct: ";
		}
	}
	return 0;
}
