//
// Created by Александр Сафиюлин on 18.12.2020.
//

#include <gtest/gtest.h>
#include <StringCleaner/StringCleaner.hpp>

// ---------------------------- HELPER TEST CLASSES ---------------------------

struct StringCleanerFixture : testing::Test {

	explicit StringCleanerFixture()
		: symbolToClean('\n'),
		stringCleaner(new(std::nothrow) task::helpers::StringCleaner(this->symbolToClean))
		{}

	~StringCleanerFixture() override = default;
	
	char symbolToClean;
	
	std::unique_ptr<task::helpers::StringCleaner> stringCleaner;
};

// ----------------------------- CTOR TESTS -----------------------------------

TEST(CleanStringTest, CtorTest) {
	const auto symbolToClean = '\n';

	const std::unique_ptr<task::helpers::StringCleaner> stringCleaner
	(new(std::nothrow) task::helpers::StringCleaner(symbolToClean));

	ASSERT_NE(nullptr, stringCleaner);
	ASSERT_EQ(stringCleaner->GetSymbolToClean(), symbolToClean);
}

//---------------------------- GETTERS TESTS ----------------------------------

TEST_F(StringCleanerFixture, SymbolGetterTest) {
	ASSERT_EQ(this->symbolToClean, this->stringCleaner->GetSymbolToClean());
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(StringCleanerFixture, SymbolSetterTest) {
	const char valuesToSet[]{
		std::numeric_limits<char>::min(),
		std::numeric_limits<char>::max(),
		std::numeric_limits<char>::epsilon(),
	};

	for (const auto& i : valuesToSet) {
		const auto temp = *this->stringCleaner;
		this->stringCleaner->SetSymbolToClean(i);

		ASSERT_EQ(i, this->stringCleaner->GetSymbolToClean());
		ASSERT_NE(temp.GetSymbolToClean(), this->stringCleaner->GetSymbolToClean());
	}
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(StringCleanerFixture, AssignmentTest) {
	this->stringCleaner->SetSymbolToClean(' ');

	const auto copy = *this->stringCleaner;

	ASSERT_EQ(this->stringCleaner->GetSymbolToClean(), copy.GetSymbolToClean());

	this->stringCleaner->SetSymbolToClean('!');

	ASSERT_NE(copy.GetSymbolToClean(), this->stringCleaner->GetSymbolToClean());
}

//----------------------------- CLEAN TESTS ---------------------------------

TEST_F(StringCleanerFixture, CleanTest1) {
	this->stringCleaner->SetSymbolToClean(' ');
	ASSERT_STREQ(this->stringCleaner->Clean(std::string("A B C D")).c_str(),
		std::string("ABCD").c_str());
}

TEST_F(StringCleanerFixture, CleanTest2) {
	this->stringCleaner->SetSymbolToClean('!');
	ASSERT_STREQ(this->stringCleaner->Clean(std::string("A B!C D")).c_str(),
		std::string("A BC D").c_str());
}

TEST_F(StringCleanerFixture, CleanTest3) {
	this->stringCleaner->SetSymbolToClean('\n');
	ASSERT_STREQ(this->stringCleaner->Clean(std::string("A\nB\nC\nD")).c_str(),
		std::string("ABCD").c_str());
}

TEST_F(StringCleanerFixture, CleanTest4) {
	this->stringCleaner->SetSymbolToClean('\0');
	ASSERT_TRUE(this->stringCleaner->Clean(std::string(100u, '\0')).empty());
}

TEST_F(StringCleanerFixture, CleanTest5) {
	this->stringCleaner->SetSymbolToClean('\t');
	ASSERT_STREQ(this->stringCleaner->Clean(std::string(100u, '\0')).c_str(),
		std::string(100u, '\0').c_str());
}

TEST_F(StringCleanerFixture, CleanTest6) {
	this->stringCleaner->SetSymbolToClean(' ');
	auto string = this->stringCleaner->Clean(" A/B!S\t\nW \t  WA//\\T");
	ASSERT_STREQ(string.c_str(),
		std::string("A/B!S\t\nW\tWA//\\T").c_str());

	this->stringCleaner->SetSymbolToClean('\\');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("A/B!S\t\nW\tWA//T").c_str());
	
	this->stringCleaner->SetSymbolToClean('/');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("AB!S\t\nW\tWAT").c_str());

	this->stringCleaner->SetSymbolToClean('W');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("AB!S\t\n\tAT").c_str());

	this->stringCleaner->SetSymbolToClean('A');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("B!S\t\n\tT").c_str());

	this->stringCleaner->SetSymbolToClean('\t');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("B!S\nT").c_str());

	this->stringCleaner->SetSymbolToClean('\n');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("B!ST").c_str());

	this->stringCleaner->SetSymbolToClean('!');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("BST").c_str());

	this->stringCleaner->SetSymbolToClean('B');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("ST").c_str());

	this->stringCleaner->SetSymbolToClean('S');
	string = this->stringCleaner->Clean(string);
	ASSERT_STREQ(string.c_str(),
		std::string("T").c_str());

	this->stringCleaner->SetSymbolToClean('T');
	string = this->stringCleaner->Clean(string);
	ASSERT_TRUE(string.empty());
}