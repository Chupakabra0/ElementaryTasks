//
// Created by Александр Сафиюлин on 21.12.2020.
//

#include <gtest/gtest.h>
#include <Sequence/SequenceBuilder/SequenceBuilder.hpp>

using ullint = unsigned long long;

struct SequenceFiboBuilderFixture : public testing::Test {

  SequenceFiboBuilderFixture()
	  : low(12ull), high(100ull),
	  sb (std::make_unique<task::eighth::SequenceBuilder<ullint,
		 task::eighth::Fibo>>(this->low, this->high,
		 	task::eighth::GenRule<ullint,
		 	task::eighth::Fibo>()))
  {}

  ~SequenceFiboBuilderFixture() override = default;

  unsigned long long low;
  unsigned long long high;

  std::unique_ptr<task::eighth::SequenceBuilder<ullint,
												 task::eighth::Fibo>> sb;
};

//---------------------------- CTOR TESTS ------------------------------------

TEST(SequenceFiboBuilderTest, CtorTest) {
  auto sb = std::make_unique<task::eighth::SequenceBuilder<ullint,
	task::eighth::Fibo>>(0ull, 1ull, task::eighth::GenRule<ullint,
		task::eighth::Fibo>());

  ASSERT_NE(nullptr, sb);
  ASSERT_EQ(0ull, sb->GetBegin());
  ASSERT_EQ(1ull, sb->GetEnd());
}

//--------------------------- GETTERS TESTS ------------------------------------

TEST_F(SequenceFiboBuilderFixture, GetBeginTest) {
  ASSERT_EQ(this->sb->GetBegin(), this->low);
}

TEST_F(SequenceFiboBuilderFixture, GetEndTest) {
  ASSERT_EQ(this->sb->GetEnd(), this->high);
}

//--------------------------- SETTERS TESTS ------------------------------------

TEST_F(SequenceFiboBuilderFixture, SetBeginTest1) {
  this->sb->SetBegin(1000ull);
  ASSERT_NE(this->sb->GetBegin(), 1000ull);
  ASSERT_EQ(this->sb->GetBegin(), this->low);
}

TEST_F(SequenceFiboBuilderFixture, SetBeginTest2) {
  this->sb->SetBegin(0ull);
  ASSERT_NE(this->sb->GetBegin(), this->low);
  ASSERT_EQ(this->sb->GetBegin(), 0ull);
}

TEST_F(SequenceFiboBuilderFixture, SetEndTest1) {
  this->sb->SetEnd(0ull);
  ASSERT_NE(this->sb->GetEnd(), 0ull);
  ASSERT_EQ(this->sb->GetEnd(), this->high);
}

TEST_F(SequenceFiboBuilderFixture, SetEndTest2) {
  this->sb->SetEnd(120ull);
  ASSERT_NE(this->sb->GetEnd(), this->high);
  ASSERT_EQ(this->sb->GetEnd(), 120ull);
}

//---------------------------- BUILD TESTS -------------------------------------

TEST_F(SequenceFiboBuilderFixture, BuildTest1) {

  const auto begin = 0ull;
  const auto end = 21ll;

  this->sb->SetEnd(end);
  this->sb->SetBegin(begin);

  const unsigned long long numbers[]{
    0ull, 1ull, 1ull, 2ull, 3ull, 5ull, 8ull, 13ull, 21ull, 34ull, 55ull,
    89ull, 144ull, 233ull, 377ull, 610ull, 987ull, 1597ull, 2584ull,
	4181ull, 6765ull
  };
  auto* pointer = numbers;

  auto result = this->sb->Build();

  for (const auto& i :  result) {
    ASSERT_EQ(i, *(pointer++));
  }

  ASSERT_EQ(numbers + sizeof(numbers) / sizeof(unsigned long long), pointer);
}

TEST_F(SequenceFiboBuilderFixture, BuildTest2) {

  const auto begin = 12ull;
  const auto end = 20ull;

  this->sb->SetEnd(end);
  this->sb->SetBegin(begin);

  const unsigned long long numbers[]{
    144ull, 233ull, 377ull, 610ull, 987ull, 1597ull, 2584ull,
    4181ull
  };
  auto* pointer = numbers;

  auto result = this->sb->Build();

  for (const auto& i :  result) {
	ASSERT_EQ(i, *(pointer++));
  }

  ASSERT_EQ(numbers + sizeof(numbers) / sizeof(unsigned long long), pointer);
}

TEST_F(SequenceFiboBuilderFixture, BuildTest3) {

  const auto begin = 17ull;
  const auto end = 20ull;

  this->sb->SetEnd(end);
  this->sb->SetBegin(begin);

  const unsigned long long numbers[]{
	  1597ull, 2584ull, 4181ull
  };
  auto* pointer = numbers;

  auto result = this->sb->Build();

  for (const auto& i :  result) {
	ASSERT_EQ(i, *(pointer++));
  }

  ASSERT_EQ(numbers + sizeof(numbers) / sizeof(unsigned long long), pointer);
}

TEST_F(SequenceFiboBuilderFixture, BuildTest4) {

  const auto end = 95ull;

  this->sb->SetEnd(end);
  this->sb->SetBegin(this->sb->GetEnd());

  auto result = this->sb->Build();

  ASSERT_TRUE(result.empty());
}

TEST_F(SequenceFiboBuilderFixture, BuildTest5) {

  const auto begin = 95ull;
  const auto end   = 96ull;
  const auto wait  = 2787843521ull;

  this->sb->SetEnd(end);
  this->sb->SetBegin(begin);
  auto result = this->sb->Build();

  ASSERT_EQ(*result.begin(), wait);
}

//------------------------- BUILD TESTS RANGE ----------------------------------

TEST(SequenceFiboBuilderTest, BuildTest6) {
  const auto begin     = 0ull;
  const auto end       = 10ull;
  const auto rangeLow  = 2ull;
  const auto rangeHigh = 5ull;

  task::eighth::SequenceBuilder<unsigned long long, task::eighth::Fibo> sb
	  (begin, end, rangeLow, rangeHigh, task::eighth::GenRule<unsigned long
	      long, task::eighth::Fibo>());

  const unsigned long long numbers[]{
    2ull, 3ull, 5ull
  };
  auto* pointer = numbers;

  auto result = sb.Build();

  for (const auto& i :  result) {
	ASSERT_EQ(i, *(pointer++));
  }

  ASSERT_EQ(numbers + sizeof(numbers) / sizeof(unsigned long long), pointer);
}