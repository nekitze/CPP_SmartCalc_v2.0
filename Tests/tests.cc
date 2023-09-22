#include <gtest/gtest.h>

#include "../Model/calculator.h"
#include "../Model/financecalculator.h"

TEST(DefaultTest, Zero) {
  s21::Calculator calculator;
  calculator.InputData("2*0");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 0);
}

TEST(DefaultTest, FloatingPoint) {
  s21::Calculator calculator;
  calculator.InputData("2.2+2.2");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 4.4);
}

TEST(DefaultTest, Logical) {
  s21::Calculator calculator;
  calculator.InputData("(2+2)*2");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 8);
}

TEST(DefaultTest, Sin) {
  s21::Calculator calculator;
  calculator.InputData("sin(0)*5");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 0);
}

TEST(DefaultTest, Cos) {
  s21::Calculator calculator;
  calculator.InputData("cos(0)*5");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 5);
}

TEST(DefaultTest, Complex) {
  s21::Calculator calculator;
  calculator.InputData("(cos(0)*5)^2");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 25);
}

TEST(DefaultTest, DoubleAndInt) {
  s21::Calculator calculator;
  calculator.InputData("(-0.6)^2");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), 0.36);
}

TEST(DefaultTest, CreditStyle) {
  s21::Calculator calculator;
  calculator.InputData("2000*((0.04*(1+0.04)^48)/((1+0.04)^(48-1)))");
  EXPECT_NEAR(calculator.Calculate(), 83.2, 0.0000001);
}

TEST(DefaultTest, UnaryOp) {
  s21::Calculator calculator;
  calculator.InputData("(-2.2) + (-2.2)");
  EXPECT_DOUBLE_EQ(calculator.Calculate(), -4.4);
}

TEST(DefaultTest, UnaryAll) {
  s21::Calculator calculator;
  calculator.InputData("-((-2.2) + (-2.2))");
  EXPECT_NEAR(calculator.Calculate(), 4.4, 0.000001);
}

TEST(Full, Long) {
  s21::Calculator calculator;
  calculator.InputData(
      "+(-sqrt(4)*acos(0)-ln(2^3)+tan(2)mod(1)-asin(0.4)/atan(2)*log(1))/"
      "0.877111");
  EXPECT_NEAR(calculator.Calculate(), 1, 0.000001);
}

TEST(Full, E) {
  s21::Calculator calculator;
  calculator.InputData("1e-3 * 2");
  EXPECT_NEAR(calculator.Calculate(), 0.002, 0.000001);
}

TEST(Fincalc, Annuity) {
  s21::FinanceCalculator fcalculator;
  std::string result =
      fcalculator.CalculatePayments("300000", "7.5", "36", 1).substr(17, 11);
  EXPECT_EQ(result, "9331.865448");
}

TEST(Fincalc, Differ) {
  s21::FinanceCalculator fcalculator;
  std::string result =
      fcalculator.CalculatePayments("300000", "7.5", "36", 0).substr(17, 12);
  EXPECT_EQ(result, "10139.497717");
}
