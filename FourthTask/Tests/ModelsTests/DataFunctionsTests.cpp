//
// Created by Александр Сафиюлин on 21.12.2020.
//

#include <gtest/gtest.h>
#include <DataFunctions/DataFunctions.hpp>

//---------------------------- COUNT TESTS -------------------------------------

TEST(DataFunctionsTest, CountTestString) {
  const auto stringToFind = std::string("\n\tihih");
  const std::vector<std::string> vector{
	  stringToFind, "TEST", "string", "144", "Why?", stringToFind, stringToFind
  };

  ASSERT_EQ(3u, task::fourth::DataFunctions::CountEq
  	(vector.begin(), vector.end(), stringToFind));
}

TEST(DataFunctionsTest, CountTestInt) {
  const auto intToFind = -4;
  const std::vector<int> vector{
	  intToFind, 1, 43, 0, 1, -1, 3
  };

  ASSERT_EQ(1u, task::fourth::DataFunctions::CountEq
	  (vector.begin(), vector.end(), intToFind));
}

TEST(DataFunctionsTest, CountTestDouble) {
  const auto doubleToFind = 0.0;
  const std::vector<double> vector{
	  0.8, 0.1, 4.3, 1.0, -1.2, 5.9, 3.0
  };

  ASSERT_EQ(0u, task::fourth::DataFunctions::CountEq
	  (vector.begin(), vector.end(), doubleToFind));
}

//-------------------------- REPLACE TESTS -------------------------------------

TEST(DataFunctionsTest, ReplaceTestString) {
  const auto stringToReplace = std::string("12345");
  const auto constString = std::string("no");
  const auto replacingString = std::string("replace");
  std::vector<std::string> vector{
	  stringToReplace, constString, constString, constString,
	  constString, stringToReplace, stringToReplace
  };

  task::fourth::DataFunctions::ReplaceEq(vector.begin(), vector.end(),
										 stringToReplace, replacingString);

  ASSERT_STREQ(vector.at(0).c_str(), replacingString.c_str());
  ASSERT_STREQ(vector.at(1).c_str(), constString.c_str());
  ASSERT_STREQ(vector.at(2).c_str(), constString.c_str());
  ASSERT_STREQ(vector.at(3).c_str(), constString.c_str());
  ASSERT_STREQ(vector.at(4).c_str(), constString.c_str());
  ASSERT_STREQ(vector.at(5).c_str(), replacingString.c_str());
  ASSERT_STREQ(vector.at(6).c_str(), replacingString.c_str());
}

TEST(DataFunctionsTest, ReplaceTestInt) {
  const auto intToReplace = 12;
  const auto constInt = -1;
  const auto replacingInt = 0;
  std::vector<int> vector{
	  intToReplace, constInt, constInt, constInt,
	  constInt, intToReplace, intToReplace
  };

  task::fourth::DataFunctions::ReplaceEq(vector.begin(), vector.end(),
										 intToReplace, replacingInt);

  ASSERT_EQ(vector.at(0), replacingInt);
  ASSERT_EQ(vector.at(1), constInt);
  ASSERT_EQ(vector.at(2), constInt);
  ASSERT_EQ(vector.at(3), constInt);
  ASSERT_EQ(vector.at(4), constInt);
  ASSERT_EQ(vector.at(5), replacingInt);
  ASSERT_EQ(vector.at(6), replacingInt);
}

TEST(DataFunctionsTest, ReplaceTestDouble) {
  const auto doubleToReplace = 1.1;
  const auto constDouble = 1.11;
  const auto replacingDouble = 1.111;
  std::vector<double> vector{
	  doubleToReplace, constDouble, constDouble, constDouble,
	  constDouble, doubleToReplace, doubleToReplace
  };

  task::fourth::DataFunctions::ReplaceEq(vector.begin(), vector.end(),
										 doubleToReplace, replacingDouble);

  ASSERT_DOUBLE_EQ(vector.at(0), replacingDouble);
  ASSERT_DOUBLE_EQ(vector.at(1), constDouble);
  ASSERT_DOUBLE_EQ(vector.at(2), constDouble);
  ASSERT_DOUBLE_EQ(vector.at(3), constDouble);
  ASSERT_DOUBLE_EQ(vector.at(4), constDouble);
  ASSERT_DOUBLE_EQ(vector.at(5), replacingDouble);
  ASSERT_DOUBLE_EQ(vector.at(6), replacingDouble);
}