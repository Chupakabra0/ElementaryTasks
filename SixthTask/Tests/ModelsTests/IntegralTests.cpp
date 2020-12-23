#include <gtest/gtest.h>
#include <numbers>
#include <cmath>
#include <Integral/Integral.hpp>

//--------------------------- SIMPSON TESTS ------------------------------------

TEST(IntegralTests, SimpsonTests1) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return std::pow(x, 4.0) + 4.0 * std::pow(x, 3.0) - std::pow(x, 2);
  }, 0.0, 1);

  ASSERT_LE(x - 18127.8, 1.0 / integral.GetN());
}

TEST(IntegralTests, SimpsonTests2) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return x;
  }, -1, 1);

  ASSERT_LE(x - 0.0, 1.0 / integral.GetN());
}

TEST(IntegralTests, SimpsonTests3) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return cos(x) - sin(x) + 1.5;
  }, 0.0, 2.0 * std::numbers::pi);

  ASSERT_LE(x - 3.0 * std::numbers::pi, 1.0 / integral.GetN());
}

TEST(IntegralTests, SimpsonTests4) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return log(x) - sin(x) - x + 2.0;
  }, 0.0, 10.0);

  ASSERT_LE(x - (10.0 * log(10.0) + cos(10.0) - 41.0), 1.0 / integral.GetN());
}

TEST(IntegralTests, SimpsonTests5) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return exp(5.0 * x) + std::pow(x, 10.0);
  }, -2.0, 1.0);

  ASSERT_LE(x - (exp(5.0) / 5.0 + 2049.0 / 11.0 - 1.0 / (5.0 * exp(10))),
			1.0 / integral.GetN());
}

TEST(IntegralTests, SimpsonTests6) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return tan(x) - cos(x) - sin(x) + 1.0;
  }, -2.0, std::numbers::pi);

  ASSERT_LE(x - 0.59032,
			1.0 / integral.GetN());
}

TEST(IntegralTests, SimpsonTests7) {
  task::helpers::Integral integral(1000u);
  auto x = integral.SimpsonCount([](double x) {
	return exp(3.0 * x + 1.0);
  }, 0.0, 1.0);

  ASSERT_LE(x - ((exp(4.0) - exp(1.0)) / 3),
			1.0 / integral.GetN());
}