//
// Created by ��������� �������� on 17.12.2020.
//

#include <gtest/gtest.h>
#include <Converter/Converter.hpp>

// ---------------------- TO INT TEST ---------------------------------

TEST(ConvertToIntTest, Test1) {
	ASSERT_EQ(10, *task::helpers::Converter<int>::ConvertString("10"));
}

TEST(ConvertToIntTest, Test2) {
	ASSERT_EQ(-10, *task::helpers::Converter<int>::ConvertString("-10"));
}

TEST(ConvertToIntTest, Test3) {
	ASSERT_EQ(nullptr, task::helpers::Converter<int>::ConvertString("TEST"));
}

TEST(ConvertToIntTest, Test4) {
	ASSERT_EQ(nullptr, task::helpers::Converter<int>::ConvertString("1.0"));
}

TEST(ConvertToIntTest, Test5) {
	ASSERT_EQ(nullptr, task::helpers::Converter<int>::ConvertString("trash1trash"));
}

TEST(ConvertToIntTest, Test6) {
	ASSERT_EQ(nullptr, task::helpers::Converter<int>::ConvertString("trash1"));
}

TEST(ConvertToIntTest, Test7) {
	ASSERT_EQ(nullptr, task::helpers::Converter<int>::ConvertString("1trash"));
}

TEST(ConvertToIntTest, Test8) {
	const auto str = std::to_string(std::numeric_limits<int>::max());
	ASSERT_EQ(std::numeric_limits<int>::max(), *task::helpers::Converter<int>::ConvertString(str));
}

TEST(ConvertToIntTest, Test9) {
	const auto str = std::to_string(-std::numeric_limits<int>::max());
	ASSERT_EQ(-std::numeric_limits<int>::max(), *task::helpers::Converter<int>::ConvertString(str));
}

TEST(ConvertToIntTest, Test10) {
	ASSERT_EQ(nullptr, task::helpers::Converter<int>::ConvertString(""));
}

// ---------------------- TO DOUBLE TEST ---------------------------------

TEST(ConvertToDoubleTest, Test1) {
	ASSERT_DOUBLE_EQ(10.0, *task::helpers::Converter<double>::ConvertString("10"));
}

TEST(ConvertToDoubleTest, Test2) {
	ASSERT_DOUBLE_EQ(-10.0, *task::helpers::Converter<double>::ConvertString("-10"));
}

TEST(ConvertToDoubleTest, Test3) {
	ASSERT_EQ(nullptr, task::helpers::Converter<double>::ConvertString("TEST"));
}

TEST(ConvertToDoubleTest, Test4) {
	ASSERT_DOUBLE_EQ(1.1, *task::helpers::Converter<double>::ConvertString("1.1"));
}

TEST(ConvertToDoubleTest, Test5) {
	ASSERT_EQ(nullptr, task::helpers::Converter<double>::ConvertString("trash1trash"));
}

TEST(ConvertToDoubleTest, Test6) {
	ASSERT_EQ(nullptr, task::helpers::Converter<double>::ConvertString("trash1"));
}

TEST(ConvertToDoubleTest, Test7) {
	ASSERT_EQ(nullptr, task::helpers::Converter<double>::ConvertString("1trash"));
}

TEST(ConvertToDoubleTest, Test8) {
	ASSERT_EQ(nullptr, task::helpers::Converter<double>::ConvertString(""));
}

TEST(ConvertToDoubleTest, Test9) {
	ASSERT_DOUBLE_EQ(1.0, *task::helpers::Converter<double>::ConvertString("1.0"));
}

TEST(ConvertToDoubleTest, Test10) {
	ASSERT_DOUBLE_EQ(-1.0, *task::helpers::Converter<double>::ConvertString("-1.0"));
}

TEST(ConvertToDoubleTest, Test11) {
	ASSERT_DOUBLE_EQ(-1.123, *task::helpers::Converter<double>::ConvertString("-1.123"));
}

TEST(ConvertToDoubleTest, Test12) {
	ASSERT_DOUBLE_EQ(-0.123, *task::helpers::Converter<double>::ConvertString("-0.123"));
}

TEST(ConvertToDoubleTest, Test13) {
	ASSERT_DOUBLE_EQ(.0, *task::helpers::Converter<double>::ConvertString(".0"));
}

TEST(ConvertToDoubleTest, Test14) {
	ASSERT_DOUBLE_EQ(0., *task::helpers::Converter<double>::ConvertString("0."));
}

// ---------------------- TO FLOAT TEST ---------------------------------

TEST(ConvertToFloatTest, Test1) {
	ASSERT_FLOAT_EQ(10.f, *task::helpers::Converter<float>::ConvertString("10"));
}

TEST(ConvertToFloatTest, Test2) {
	ASSERT_FLOAT_EQ(-10.f, *task::helpers::Converter<float>::ConvertString("-10"));
}

TEST(ConvertToFloatTest, Test3) {
	ASSERT_EQ(nullptr, task::helpers::Converter<float>::ConvertString("TEST"));
}

TEST(ConvertToFloatTest, Test4) {
	ASSERT_FLOAT_EQ(1.1f, *task::helpers::Converter<float>::ConvertString("1.1"));
}

TEST(ConvertToFloatTest, Test5) {
	ASSERT_EQ(nullptr, task::helpers::Converter<float>::ConvertString("trash1trash"));
}

TEST(ConvertToFloatTest, Test6) {
	ASSERT_EQ(nullptr, task::helpers::Converter<float>::ConvertString("trash1"));
}

TEST(ConvertToFloatTest, Test7) {
	ASSERT_EQ(nullptr, task::helpers::Converter<float>::ConvertString("1trash"));
}

TEST(ConvertToFloatTest, Test8) {
	ASSERT_EQ(nullptr, task::helpers::Converter<float>::ConvertString(""));
}

TEST(ConvertToFloatTest, Test9) {
	ASSERT_FLOAT_EQ(1.0f, *task::helpers::Converter<float>::ConvertString("1.0"));
}

TEST(ConvertToFloatTest, Test10) {
	ASSERT_FLOAT_EQ(-1.0f, *task::helpers::Converter<float>::ConvertString("-1.0"));
}

TEST(ConvertToFloatTest, Test11) {
	ASSERT_FLOAT_EQ(-1.123f, *task::helpers::Converter<float>::ConvertString("-1.123"));
}

TEST(ConvertToFloatTest, Test12) {
	ASSERT_FLOAT_EQ(-1.123f, *task::helpers::Converter<float>::ConvertString("-1.123f"));
}

TEST(ConvertToFloatTest, Test14) {
	ASSERT_FLOAT_EQ(-0.123f, *task::helpers::Converter<float>::ConvertString("-0.123"));
}

TEST(ConvertToFloatTest, Test15) {
	ASSERT_FLOAT_EQ(0.f, *task::helpers::Converter<float>::ConvertString("0.f"));
}

TEST(ConvertToFloatTest, Test16) {
	ASSERT_FLOAT_EQ(.0f, *task::helpers::Converter<float>::ConvertString(".0f"));
}

// ---------------------- TO UNSIGNED TEST ---------------------------------

TEST(ConvertToUnsignedTest, Test1) {
	ASSERT_EQ(10u, *task::helpers::Converter<unsigned>::ConvertString("10"));
}

TEST(ConvertToUnsignedTest, Test2) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString("-10"));
}

TEST(ConvertToUnsignedTest, Test3) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString("TEST"));
}

TEST(ConvertToUnsignedTest, Test4) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString("1.1"));
}

TEST(ConvertToUnsignedTest, Test5) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString("trash1trash"));
}

TEST(ConvertToUnsignedTest, Test6) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString("trash1"));
}

TEST(ConvertToUnsignedTest, Test7) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString("1trash"));
}

TEST(ConvertToUnsignedTest, Test8) {
	ASSERT_EQ(nullptr, task::helpers::Converter<unsigned>::ConvertString(""));
}

TEST(ConvertToUnsignedTest, Test9) {
	ASSERT_EQ(11u, *task::helpers::Converter<unsigned>::ConvertString("11"));
}