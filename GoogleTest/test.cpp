#include "pch.h"
#include "cmath.h"

TEST(Task, TestNumRange) {
	Task first(1, 5);
	EXPECT_GE(first.num1, 1);
	EXPECT_LE(first.num1, 5);
	EXPECT_GE(first.num2, 1);
	EXPECT_LE(first.num2, 5);
}

TEST(Task, TestOperation) {
	Task first(1, 5, '+');
	EXPECT_EQ(first.operation, '+');
}

TEST(Task, TestUnique) {
	Task first;
	Task second;
	EXPECT_NE(first.num1, second.num1);
	EXPECT_NE(first.num2, second.num2);
	EXPECT_NE(first.answer, second.answer);
}
TEST(Task, TestAnswer) {
	Task first;
	switch (first.operation) {
	case '+': EXPECT_DOUBLE_EQ(first.answer, first.num1 + first.num2)<< "Ошибка при сложении"; break;
	case '-': EXPECT_DOUBLE_EQ(first.answer, first.num1 - first.num2)<< "Ошибка при вычитании"; break;
	case '*': EXPECT_DOUBLE_EQ(first.answer, first.num1 * first.num2)<< "Ошибка при умножении"; break;
	case '/': EXPECT_DOUBLE_EQ(first.answer, first.num1 / first.num2)<< "Ошибка при делении"; break;
	}
}
TEST(Task, TestDivisionByZero) {
	Task first(0.0, 0.0, '/');
	EXPECT_DOUBLE_EQ(first.answer, 0.0) << "Защита от деления на ноль";
}

TEST(MathTest, InitializationConstructor) {
	MathTest first(5, 10, 50);
	for (int i = 0; i < 5; i++) {
		EXPECT_GE(first.getTask(i).num1, 10.0);
		EXPECT_LE(first.getTask(i).num1, 50.0);
		EXPECT_GE(first.getTask(i).num2, 10.0);
		EXPECT_LE(first.getTask(i).num2, 50.0);
	}
}

TEST(MathTest, TestAnswer) {
	MathTest first(5, 10, 50, '/');
	for (int i = 0; i < 5; i++) {
		double first_num = first.getTask(i).num1;
		double second_num = first.getTask(i).num2;
		EXPECT_EQ(first.getTask(i).operation, '/');
		EXPECT_DOUBLE_EQ(first.getTask(i).answer, first_num /second_num);
	}
}

TEST(MathTest, TestDelete) {
	{
		MathTest first(10, 1, 50);
	}
	SUCCEED(); 
}