#include <filesystem>
#include <gtest/gtest.h>
#include <FileParserLineByLine/FileParserLineByLine.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------
struct CharFileParserLineByLineFixture : testing::Test {
public:
	CharFileParserLineByLineFixture()
		: path("temp.tmp"), fs(this->path, std::ios_base::out | std::ios_base::trunc),
		parser(std::make_unique<task::fourth::CharFileParserLineByLine>(this->path))
		{}

	~CharFileParserLineByLineFixture() override {
		this->parser->CloseFile();
		this->fs.close();
		std::filesystem::remove(this->path);
	}
	
	std::filesystem::path path;
	std::fstream          fs;
	
	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser;
};

struct WCharFileParserLineByLineFixture : testing::Test {
public:
	WCharFileParserLineByLineFixture()
		: path("temp.tmp"), fs(this->path, std::ios_base::out | std::ios_base::trunc),
		parser(std::make_unique<task::fourth::WCharFileParserLineByLine>(this->path))
	{}

	~WCharFileParserLineByLineFixture() override {
		this->parser->CloseFile();
		this->fs.close();
		std::filesystem::remove(this->path);
	}

	std::filesystem::path path;
	std::fstream          fs;

	std::unique_ptr<task::fourth::WCharFileParserLineByLine> parser;
};

//---------------------------- CTOR TESTS ------------------------------------

TEST(CharFileParserLineByLineTests, CtorTest) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::CharFileParserLineByLine(path));

	ASSERT_NE(nullptr, parser);
	ASSERT_EQ(parser->GetPath(), path);
	ASSERT_TRUE(parser->IsFileOpen());
	
	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}


TEST(WCharFileParserLineByLineTests, CtorTest) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);

	std::unique_ptr<task::fourth::WCharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::WCharFileParserLineByLine(path));

	ASSERT_NE(nullptr, parser);
	ASSERT_EQ(parser->GetPath(), path);
	ASSERT_TRUE(parser->IsFileOpen());

	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

//-------------------------- GETTERS TESTS -----------------------------------

TEST_F(CharFileParserLineByLineFixture, GetPathTest) {
	ASSERT_EQ(this->path, this->parser->GetPath());
}

TEST_F(WCharFileParserLineByLineFixture, GetPathTest) {
	ASSERT_EQ(this->path, this->parser->GetPath());
}

//----------------------- OPEN/CLOSE TESTS ----------------------------------

TEST_F(CharFileParserLineByLineFixture, OpenCloseTest) {
	ASSERT_TRUE(this->parser->IsFileOpen());
	this->parser->CloseFile();
	ASSERT_FALSE(this->parser->IsFileOpen());
}

TEST_F(WCharFileParserLineByLineFixture, OpenCloseTest) {
	ASSERT_TRUE(this->parser->IsFileOpen());
	this->parser->CloseFile();
	ASSERT_FALSE(this->parser->IsFileOpen());
}

//-------------------------- READ TEST --------------------------------------

TEST(CharFileParserLineByLineTests, ReadTest1) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);
	fs << "Test info:" << std::endl << "These test are very important!"
		<< std::endl << "So let's do this..." << std::endl;

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::CharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto iter = parser->begin();
	ASSERT_STREQ("Test info:", iter++->c_str());
	ASSERT_STREQ("These test are very important!", iter++->c_str());
	ASSERT_STREQ("So let's do this...", iter->c_str());
	
	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(CharFileParserLineByLineTests, ReadTest2) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);
	const auto limit = 50u;
	
	for (auto i = 0u; i < limit; ++i) {
		fs << "TEST STRING" << std::endl;
	}

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::CharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto counter = 0u;
	for (const auto& i : *parser) {
		ASSERT_STREQ("TEST STRING", i.c_str());
		++counter;
	}
	
	ASSERT_EQ(limit, counter);
	
	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(CharFileParserLineByLineTests, ReadTest3) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);
	const auto limit = 50u;

	for (auto i = 0u; i < limit; ++i) {
		fs << "TEST STRING" << std::endl;
	}

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::CharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto counter1 = 0u;
	for (const auto& i : *parser) {
		ASSERT_STREQ("TEST STRING", i.c_str());
		++counter1;
	}

	ASSERT_EQ(limit, counter1);

	parser->Reset();

	auto counter2 = 0u;
	for (const auto& i : *parser) {
		ASSERT_STREQ("TEST STRING", i.c_str());
		++counter2;
	}

	ASSERT_EQ(limit, counter2);
	
	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(CharFileParserLineByLineTests, ReadTest4) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::CharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto iter = parser->begin();
	ASSERT_TRUE(iter++->empty());

	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(WCharFileParserLineByLineTests, ReadTest1) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);
	fs << "Î òåñòå:" << std::endl << "Ýòîò òåñò î÷åíü âàæåí!"
		<< std::endl << "Òàê ÷òî, äàâàéòå ñäåëàåì ýòî.." << std::endl;

	std::unique_ptr<task::fourth::WCharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::WCharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto iter = parser->begin();
	ASSERT_EQ("Î òåñòå:", *iter++);
	ASSERT_EQ("Ýòîò òåñò î÷åíü âàæåí!", *iter++);
	ASSERT_EQ("Òàê ÷òî, äàâàéòå ñäåëàåì ýòî..", *iter++);
	
	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(WCharFileParserLineByLineTests, ReadTest2) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);
	const auto limit = 50u;

	for (auto i = 0u; i < limit; ++i) {
		fs << "ÒÅÑÒÎÂÀß ÑÒÐÎÊÀ" << std::endl;
	}

	std::unique_ptr<task::fourth::CharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::CharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto counter = 0u;
	for (const auto& i : *parser) {
		ASSERT_STREQ("ÒÅÑÒÎÂÀß ÑÒÐÎÊÀ", i.c_str());
		++counter;
	}

	ASSERT_EQ(limit, counter);

	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(WCharFileParserLineByLineTests, ReadTest3) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);
	const auto limit = 50u;

	for (auto i = 0u; i < limit; ++i) {
		fs << "ÒÅÑÒÎÂÀß ÑÒÐÎÊÀ" << std::endl;
	}

	std::unique_ptr<task::fourth::WCharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::WCharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto counter1 = 0u;
	for (const auto& i : *parser) {
		ASSERT_STREQ("ÒÅÑÒÎÂÀß ÑÒÐÎÊÀ", i.c_str());
		++counter1;
	}

	ASSERT_EQ(limit, counter1);

	parser->Reset();

	auto counter2 = 0u;
	for (const auto& i : *parser) {
		ASSERT_STREQ("ÒÅÑÒÎÂÀß ÑÒÐÎÊÀ", i.c_str());
		++counter2;
	}

	ASSERT_EQ(limit, counter2);

	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}

TEST(ÖCharFileParserLineByLineTests, ReadTest4) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fs(path, std::ios_base::out | std::ios_base::trunc);

	std::unique_ptr<task::fourth::WCharFileParserLineByLine> parser
	(new(std::nothrow) task::fourth::WCharFileParserLineByLine(path));
	ASSERT_NE(nullptr, parser);
	ASSERT_TRUE(parser->IsFileOpen());

	auto iter = parser->begin();
	ASSERT_TRUE(iter++->empty());

	parser->CloseFile();
	fs.close();
	std::filesystem::remove(path);
}