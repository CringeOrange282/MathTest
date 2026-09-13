#include "pch.h"
#include "cmath.h"

TEST(MathTest, TestNumRange) {
	Task first(1, 5);
	EXPECT_GE(first.num1, 1);
	EXPECT_LE(first.num1, 5);
	EXPECT_GE(first.num2, 1);
	EXPECT_LE(first.num2, 5);
}

TEST(MathTest, TestOperation) {
	Task first(1, 5, '+');
	EXPECT_EQ(first.operation, '+');
}

TEST(MathTest, TestUnique) {
	Task first;
	Task second;
	EXPECT_NE(first.num1, second.num1);
	EXPECT_NE(first.num2, second.num2);
	EXPECT_NE(first.answer, second.answer);
}
TEST(MathTest, TestAnswer) {
	Task first;
	switch (first.operation) {
	case '+': EXPECT_DOUBLE_EQ(first.answer, first.num1 + first.num2)<< "Ошибка при сложении"; break;
	case '-': EXPECT_DOUBLE_EQ(first.answer, first.num1 - first.num2)<< "Ошибка при вычитании"; break;
	case '*': EXPECT_DOUBLE_EQ(first.answer, first.num1 * first.num2)<< "Ошибка при умножении"; break;
	case '/': EXPECT_DOUBLE_EQ(first.answer, first.num1 / first.num2)<< "Ошибка при делении"; break;
	}
}
TEST(MathTest, TestDivisionByZero) {
	Task first(0.0, 0.0, '/');
	EXPECT_DOUBLE_EQ(first.answer, 0.0) << "Защита от деления на ноль";
}
