//
// Created by Александр Сафиюлин on 18.12.2020.
//

#include <gtest/gtest.h>
#include <StringSpliter/StringSpliter.hpp>

// ---------------------------- HELPER TEST CLASSES ---------------------------

struct StringSpliterFixture : testing::Test {

	explicit StringSpliterFixture()
		: symbolToSplit('\n'),
		stringDelimiter(new(std::nothrow) task::helpers::StringSpliter(this->symbolToSplit))
	{}

	~StringSpliterFixture() override = default;

	char symbolToSplit;

	std::unique_ptr<task::helpers::StringSpliter> stringDelimiter;
};

// ----------------------------- CTOR TESTS -----------------------------------

TEST(SplitStringTest, Tes1) {
	const auto symbolToDelimit = '\n';

	const std::unique_ptr<task::helpers::StringSpliter> stringSplitter
	(new(std::nothrow) task::helpers::StringSpliter(symbolToDelimit));

	ASSERT_NE(nullptr, stringSplitter);
	ASSERT_EQ(stringSplitter->GetDelimiter(), symbolToDelimit);
}

//---------------------------- GETTERS TESTS ----------------------------------

TEST_F(StringSpliterFixture, SymbolGetterTest) {
	ASSERT_EQ(this->symbolToSplit, this->stringDelimiter->GetDelimiter());
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(StringSpliterFixture, SymbolSetterTest) {
	const char valuesToSet[]{
		std::numeric_limits<char>::min(),
		std::numeric_limits<char>::max(),
		std::numeric_limits<char>::epsilon(),
	};

	for (const auto& i : valuesToSet) {
		const auto temp = *this->stringDelimiter;
		this->stringDelimiter->SetDelimiter(i);

		ASSERT_EQ(i, this->stringDelimiter->GetDelimiter());
		ASSERT_NE(temp.GetDelimiter(), this->stringDelimiter->GetDelimiter());
	}
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(StringSpliterFixture, AssignmentTest) {
	this->stringDelimiter->SetDelimiter(' ');

	const auto copy = *this->stringDelimiter;

	ASSERT_EQ(this->stringDelimiter->GetDelimiter(), copy.GetDelimiter());

	this->stringDelimiter->SetDelimiter('!');

	ASSERT_NE(copy.GetDelimiter(), this->stringDelimiter->GetDelimiter());
}

//----------------------------- CLEAN TESTS ---------------------------------

TEST_F(StringSpliterFixture, CleanTest1) {
	this->stringDelimiter->SetDelimiter(' ');
	const auto vector = this->stringDelimiter->Split(std::string("A B C D"));
	ASSERT_EQ(vector.size(), 4u);
	ASSERT_STREQ(vector.at(0u).c_str(), "A");
	ASSERT_STREQ(vector.at(1u).c_str(), "B");
	ASSERT_STREQ(vector.at(2u).c_str(), "C");
	ASSERT_STREQ(vector.at(3u).c_str(), "D");
}

TEST_F(StringSpliterFixture, CleanTest2) {
	this->stringDelimiter->SetDelimiter('!');
	const auto vector = this->stringDelimiter->Split(std::string("A B!C D"));
	ASSERT_EQ(vector.size(), 2u);
	ASSERT_STREQ(vector.at(0u).c_str(), "A B");
	ASSERT_STREQ(vector.at(1u).c_str(), "C D");
}

TEST_F(StringSpliterFixture, CleanTest3) {
	this->stringDelimiter->SetDelimiter('\n');
	const auto vector = this->stringDelimiter->Split(std::string("1\n2\n3\n"));
	ASSERT_EQ(vector.size(), 3u);
	ASSERT_STREQ(vector.at(0u).c_str(), "1");
	ASSERT_STREQ(vector.at(1u).c_str(), "2");
	ASSERT_STREQ(vector.at(2u).c_str(), "3");
}

TEST_F(StringSpliterFixture, CleanTest4) {
	this->stringDelimiter->SetDelimiter('S');
	const auto vector = this->stringDelimiter->Split(std::string(100u, 'S'));
	ASSERT_TRUE(vector.empty());
}

TEST_F(StringSpliterFixture, CleanTest5) {
	this->stringDelimiter->SetDelimiter('\t');
	const auto vector = this->stringDelimiter->Split(std::string(100u, '1'));
	ASSERT_EQ(vector.size(), 1u);
	ASSERT_STREQ(vector.at(0u).c_str(), std::string(100u, '1').c_str());
}

TEST_F(StringSpliterFixture, CleanTest6) {
	this->stringDelimiter->SetDelimiter('0');
	const auto vector = this->stringDelimiter->Split(std::string("011110"));
	ASSERT_EQ(vector.size(), 1u);
	ASSERT_STREQ(vector[0].c_str(), "1111");
}

TEST_F(StringSpliterFixture, CleanTest7) {
	this->stringDelimiter->SetDelimiter('A');
	const auto vector = this->stringDelimiter->Split(std::string("Abbba"));
	ASSERT_EQ(vector.size(), 1u);
	ASSERT_STREQ(vector[0].c_str(), "bbba");
}

TEST_F(StringSpliterFixture, CleanTest8) {
	this->stringDelimiter->SetDelimiter('B');
	const auto vector = this->stringDelimiter->Split(std::string("bAbAB"));
	ASSERT_EQ(vector.size(), 1u);
	ASSERT_STREQ(vector[0].c_str(), "bAbA");
}

TEST_F(StringSpliterFixture, CleanTest9) {
	this->stringDelimiter->SetDelimiter('\0');
	const auto vector = this->stringDelimiter->Split(std::string(""));
	ASSERT_TRUE(vector.empty());
}