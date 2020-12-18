//
// Created by Александр Сафиюлин on 18.12.2020.
//

#include <gtest/gtest.h>
#include <Triangle/Triangle.hpp>

// ---------------------------- HELPER TEST CLASSES ---------------------------

struct TriangleFixture : testing::Test {

	explicit TriangleFixture()
		: name("Name"), firstSide(10.4), secondSide(7.8), thirdSide(5.1),
		triangle(task::third::Triangle::CreateUniquePtrTriangle
		(this->name, this->firstSide, this->secondSide, this->thirdSide))
		{}

	~TriangleFixture() override = default;

	std::string name;
	double firstSide;
	double secondSide;
	double thirdSide;

	std::unique_ptr<task::third::Triangle> triangle;
};

// --------------------------- CREATE TESTS ---------------------------------

TEST(TriangleTests, CreateTest1) {
	const auto testName   = std::string("Test");
	const auto firstSide  = 10.0;
	const auto secondSide = 14.0;
	const auto thirdSide  = 5.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
		(testName, firstSide, secondSide, thirdSide);
	
	ASSERT_NE(nullptr, triangle);
	ASSERT_STREQ(testName.c_str(), triangle->GetName().c_str());
	ASSERT_DOUBLE_EQ(firstSide, triangle->GetFirstSide());
	ASSERT_DOUBLE_EQ(secondSide, triangle->GetSecondSide());
	ASSERT_DOUBLE_EQ(thirdSide, triangle->GetThirdSide());
}

TEST(TriangleTests, CreateTest2) {
	const auto testName   = std::string("\n");
	const auto firstSide  = 8.9;
	const auto secondSide = 6.7;
	const auto thirdSide  = 5.2;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_STREQ(testName.c_str(), triangle->GetName().c_str());
	ASSERT_DOUBLE_EQ(firstSide, triangle->GetFirstSide());
	ASSERT_DOUBLE_EQ(secondSide, triangle->GetSecondSide());
	ASSERT_DOUBLE_EQ(thirdSide, triangle->GetThirdSide());
}

TEST(TriangleTests, CreateTest3) {
	const auto testName = std::string("A\tA");
	const auto firstSide = 10.0;
	const auto secondSide = 10.0;
	const auto thirdSide = 0.001;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_STREQ(testName.c_str(), triangle->GetName().c_str());
	ASSERT_DOUBLE_EQ(firstSide, triangle->GetFirstSide());
	ASSERT_DOUBLE_EQ(secondSide, triangle->GetSecondSide());
	ASSERT_DOUBLE_EQ(thirdSide, triangle->GetThirdSide());
}

TEST(TriangleTests, CreateTest4) {
	const auto testName = std::string("\n\t\r");
	const auto firstSide = 1.0;
	const auto secondSide = 1.0;
	const auto thirdSide = 1.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_STREQ(testName.c_str(), triangle->GetName().c_str());
	ASSERT_DOUBLE_EQ(firstSide, triangle->GetFirstSide());
	ASSERT_DOUBLE_EQ(secondSide, triangle->GetSecondSide());
	ASSERT_DOUBLE_EQ(thirdSide, triangle->GetThirdSide());
}

TEST(TriangleTests, CreateTest5) {
	const auto testName = std::string("nAmE");
	const auto firstSide = 0.8;
	const auto secondSide = 0.5;
	const auto thirdSide = 1.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_STREQ(testName.c_str(), triangle->GetName().c_str());
	ASSERT_DOUBLE_EQ(firstSide, triangle->GetFirstSide());
	ASSERT_DOUBLE_EQ(secondSide, triangle->GetSecondSide());
	ASSERT_DOUBLE_EQ(thirdSide, triangle->GetThirdSide());
}

TEST(TriangleTests, CreateTest6) {
	const auto testName = std::string("NO");
	const auto firstSide = 0.0;
	const auto secondSide = 0.5;
	const auto thirdSide = 1.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest7) {
	const auto testName = std::string("NO-NO");
	const auto firstSide = 1.0;
	const auto secondSide = 0.0;
	const auto thirdSide = 1.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest8) {
	const auto testName = std::string("NO-NO");
	const auto firstSide = 1.0;
	const auto secondSide = 100.0;
	const auto thirdSide = 0.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest9) {
	const auto testName = std::string("NotEmpty");
	const auto firstSide = 1.0;
	const auto secondSide = 100.0;
	const auto thirdSide = -1.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest10) {
	const auto testName = std::string("Negative");
	const auto firstSide = 1.0;
	const auto secondSide = -12.0;
	const auto thirdSide = 11.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest11) {
	const auto testName = std::string("123");
	const auto firstSide = -0.1;
	const auto secondSide = 0.2;
	const auto thirdSide = 0.1;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest12) {
	const auto testName = std::string("NaN");
	const auto firstSide = 1000.1;
	const auto secondSide = 0.3;
	const auto thirdSide = 0.44;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest13) {
	const auto testName = std::string("13");
	const auto firstSide = 2.1;
	const auto secondSide = 13.3;
	const auto thirdSide = 0.4;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest14) {
	const auto testName = std::string("13");
	const auto firstSide = 0.1;
	const auto secondSide = 0.3;
	const auto thirdSide = 0.4;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

TEST(TriangleTests, CreateTest15) {
	const auto testName = std::string("");
	const auto firstSide = 12.1;
	const auto secondSide = 6.1;
	const auto thirdSide = 8.1;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_EQ(nullptr, triangle);
}

//---------------------------- GETTERS TESTS ----------------------------------

TEST_F(TriangleFixture, GetFirstSideTest) {
	ASSERT_DOUBLE_EQ(this->firstSide, this->triangle->GetFirstSide());
}

TEST_F(TriangleFixture, GetSecondSideTest) {
	ASSERT_DOUBLE_EQ(this->secondSide, this->triangle->GetSecondSide());
}

TEST_F(TriangleFixture, GetThirdSideTest) {
	ASSERT_DOUBLE_EQ(this->thirdSide, this->triangle->GetThirdSide());
}

TEST_F(TriangleFixture, GetNameTest) {
	ASSERT_STREQ(this->name.c_str(), this->triangle->GetName().c_str());
}

//--------------------------- PERIMETER TESTS ---------------------------------

TEST(TriangleTests, GetPerimeterTest1) {
	const auto testName = std::string("PerimeterTest");
	const auto firstSide = 10.1;
	const auto secondSide = 13.1;
	const auto thirdSide = 5.1;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_DOUBLE_EQ(firstSide + secondSide + thirdSide, triangle->GetPerimeter());
}

TEST(TriangleTests, GetPerimeterTest2) {
	const auto testName = std::string("Triangle");
	const auto firstSide = 8.1;
	const auto secondSide = 5.1;
	const auto thirdSide = 5.1;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_DOUBLE_EQ(firstSide + secondSide + thirdSide, triangle->GetPerimeter());
}

TEST(TriangleTests, GetPerimeterTest3) {
	const auto testName = std::string("12345");
	const auto firstSide = 10.0;
	const auto secondSide = 9.7;
	const auto thirdSide = 15.0;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	ASSERT_NE(nullptr, triangle);
	ASSERT_DOUBLE_EQ(firstSide + secondSide + thirdSide, triangle->GetPerimeter());
}

//--------------------------- SQUARE TESTS ------------------------------------

TEST(TriangleTests, GetSquareTest1) {
	const auto testName = std::string("SquareTest");
	const auto firstSide = 0.7;
	const auto secondSide = 1.4;
	const auto thirdSide = 0.8;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	
	const auto halfPerimeter = 0.5 * (firstSide + secondSide + thirdSide);
	const auto square = std::sqrt(
		halfPerimeter * (halfPerimeter - firstSide) *
		(halfPerimeter - secondSide) *
		(halfPerimeter - thirdSide));
	
	ASSERT_NE(nullptr, triangle);
	ASSERT_DOUBLE_EQ(square, triangle->GetSquare());
}

TEST(TriangleTests, GetSquareTest2) {
	const auto testName = std::string("SquareTest");
	const auto firstSide = 1.4;
	const auto secondSide = 1.4;
	const auto thirdSide = 2.7999;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	const auto halfPerimeter = 0.5 * (firstSide + secondSide + thirdSide);
	const auto square = std::sqrt(
		halfPerimeter * (halfPerimeter - firstSide) *
		(halfPerimeter - secondSide) *
		(halfPerimeter - thirdSide));

	ASSERT_NE(nullptr, triangle);
	ASSERT_DOUBLE_EQ(square, triangle->GetSquare());
}

TEST(TriangleTests, GetSquareTest3) {
	const auto testName = std::string("SquareTest");
	const auto firstSide = 11.4;
	const auto secondSide = 8.4;
	const auto thirdSide = 3.9;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);

	const auto halfPerimeter = 0.5 * (firstSide + secondSide + thirdSide);
	const auto square = std::sqrt(
		halfPerimeter * (halfPerimeter - firstSide) *
		(halfPerimeter - secondSide) *
		(halfPerimeter - thirdSide));

	ASSERT_NE(nullptr, triangle);
	ASSERT_DOUBLE_EQ(square, triangle->GetSquare());
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(TriangleFixture, AssignmentTest) {
	this->triangle->SetName("Name");
	const auto copy = *this->triangle;

	ASSERT_EQ(this->triangle->GetName(), copy.GetName());

	this->triangle->SetName("NoName");
	ASSERT_NE(copy.GetName(), this->triangle->GetName());
}

//--------------------------- EQUATION TESTS ------------------------------------

TEST_F(TriangleFixture, EqualityTest1) {
	this->triangle->SetName("Name");
	const auto copy = *this->triangle;
	
	ASSERT_EQ(copy, *this->triangle);
	
	this->triangle->SetName("NewName");
	ASSERT_NE(copy, *this->triangle);
}

TEST_F(TriangleFixture, EqualityTest2) {
	this->triangle->SetName("Name");
	const auto copy = *this->triangle;

	ASSERT_EQ(copy, *this->triangle);

	this->triangle->SetName("NewName");
	ASSERT_NE(copy, *this->triangle);
}

TEST(TriangleTests, EqualityTest3) {
	const auto testName = std::string("Triangle");
	const auto firstSide = 1.0;
	const auto secondSide = 2.1;
	const auto thirdSide = 1.2;
	const auto triangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, triangle);
	
	auto copy = *triangle;
	ASSERT_EQ(copy, *triangle);

	copy.SetName("Copy");
	ASSERT_NE(copy, *triangle);
}

TEST(TriangleTests, EqualityTest4) {
	const auto testName = std::string("Triangle");
	const auto firstSide = 2.5;
	const auto secondSide = 3.3;
	const auto thirdSide = 1.1;
	const auto firstTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, firstTriangle);

	const auto secondTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, secondTriangle);

	ASSERT_EQ(*firstTriangle, *secondTriangle);

	firstTriangle->SetName("Copy");
	ASSERT_NE(*firstTriangle, *secondTriangle);
}

TEST(TriangleTests, LessEqualTest1) {
	const auto testName = std::string("B");
	const auto firstSide = 102.52;
	const auto secondSide = 300.0;
	const auto thirdSide = 200.12;
	const auto firstTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, firstTriangle);

	const auto secondTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, secondTriangle);

	ASSERT_EQ(*secondTriangle, *firstTriangle);
	ASSERT_LE(*secondTriangle, *firstTriangle);
	ASSERT_GE(*firstTriangle, *secondTriangle);

	firstTriangle->SetName("A");
	ASSERT_NE(*secondTriangle, *firstTriangle);
	ASSERT_LT(*firstTriangle, *secondTriangle);
	ASSERT_GT(*secondTriangle, *firstTriangle);
}

TEST(TriangleTests, LessEqualTest2) {
	const auto testName = std::string("B");
	const auto firstSide = 21.0;
	const auto secondSide = 30.0;
	auto thirdSide = 20.0;
	const auto firstTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, firstTriangle);

	thirdSide = 19.0;
	const auto secondTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, secondTriangle);

	ASSERT_NE(*secondTriangle, *firstTriangle);
	ASSERT_LE(*secondTriangle, *firstTriangle);
	ASSERT_GE(*firstTriangle, *secondTriangle);

	ASSERT_LT(*secondTriangle, *firstTriangle);
	ASSERT_GT(*firstTriangle, *secondTriangle);
}

TEST(TriangleTests, LessEqualTest3) {
	const auto testName = std::string("B");
	const auto firstSide = 12.0;
	auto secondSide = 30.0;
	const auto thirdSide = 20.0;
	const auto firstTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, firstTriangle);

	secondSide = 16.0;
	const auto secondTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, secondTriangle);

	ASSERT_NE(*secondTriangle, *firstTriangle);
	ASSERT_GE(*secondTriangle, *firstTriangle);
	ASSERT_LE(*firstTriangle, *secondTriangle);

	ASSERT_GT(*secondTriangle, *firstTriangle);
	ASSERT_LT(*firstTriangle, *secondTriangle);
}

TEST(TriangleTests, LessEqualTest4) {
	const auto testName = std::string("B");
	auto firstSide = 12.0;
	const auto secondSide = 30.0;
	const auto thirdSide = 20.0;
	const auto firstTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, firstTriangle);

	firstSide = 11.9;
	const auto secondTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(testName, firstSide, secondSide, thirdSide);
	ASSERT_NE(nullptr, secondTriangle);

	ASSERT_NE(*secondTriangle, *firstTriangle);
	ASSERT_LE(*secondTriangle, *firstTriangle);
	ASSERT_GE(*firstTriangle, *secondTriangle);

	ASSERT_LT(*secondTriangle, *firstTriangle);
	ASSERT_GT(*firstTriangle, *secondTriangle);
}

TEST(TriangleTests, LessEqualTest5) {
	const auto firstTestName = std::string("B");
	const auto firstFirstSide = 2.0;
	const auto firstSecondSide = 3.0;
	const auto firstThirdSide = 4.0;
	const auto firstTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(firstTestName, firstFirstSide, firstSecondSide, firstThirdSide);
	ASSERT_NE(nullptr, firstTriangle);

	const auto secondTestName = std::string("A");
	const auto secondFirstSide = 12.4;
	const auto secondSecondSide = 9.1;
	const auto secondThirdSide = 5.6;
	const auto secondTriangle = task::third::Triangle::CreateUniquePtrTriangle
	(secondTestName, secondFirstSide, secondSecondSide, secondThirdSide);
	ASSERT_NE(nullptr, secondTriangle);

	ASSERT_NE(*secondTriangle, *firstTriangle);
	ASSERT_LE(*firstTriangle, *secondTriangle);
	ASSERT_GE(*secondTriangle, *firstTriangle);

	ASSERT_GT(*secondTriangle, *firstTriangle);
	ASSERT_LT(*firstTriangle, *secondTriangle);
}