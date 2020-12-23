#include <gtest/gtest.h>
#include <ConsoleArgsValidator/ConsoleArgsValidator.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------

struct ConsoleArgsValidatorFixture : public testing::Test {
public:
	ConsoleArgsValidatorFixture() : argc(1) {
		this->argv = new const char*("121897654");
		this->number = atoi(this->argv[0]);
		this->cav  = std::make_unique<task::helpers::ConsoleArgsValidator>(this->argc, this->argv);
	}

	~ConsoleArgsValidatorFixture() override {
		delete argv;
	}
	
	const unsigned argc;
	const char** argv;
	unsigned number;

	std::unique_ptr<task::helpers::ConsoleArgsValidator> cav;
};

//---------------------------- CTOR TESTS ------------------------------------

TEST(ConsoleArgsValidatorCtorTest, CtorTest) {
	const auto argc = 1u;
	auto** argv = new const char*("TRASH");

	const std::unique_ptr<task::helpers::ConsoleArgsValidator> cav
		(new(std::nothrow) task::helpers::ConsoleArgsValidator(argc, argv));

	ASSERT_NE(nullptr, cav);
	ASSERT_EQ(argc, cav->GetArgc());
	ASSERT_EQ(argv[0], cav->GetArgv()[0]);

	delete argv;
}

//-------------------------- GETTERS TESTS -----------------------------------

TEST_F(ConsoleArgsValidatorFixture, PathGetterTest) {
	ASSERT_EQ(this->argv[0], this->cav->GetPath());
}

TEST_F(ConsoleArgsValidatorFixture, ArgvGetterTest) {
	ASSERT_EQ(this->argv, this->cav->GetArgv());
}

TEST_F(ConsoleArgsValidatorFixture, ArgcGetterTest) {
	ASSERT_EQ(this->argc, this->cav->GetArgc());
}

TEST_F(ConsoleArgsValidatorFixture, CheckArgsTest1) {
	ASSERT_FALSE(this->cav->CheckEnoughArgc(12u));
}

TEST_F(ConsoleArgsValidatorFixture, CheckArgsTest2) {
	ASSERT_TRUE(this->cav->CheckEnoughArgc(1u));
}

//-------------------------- VALID TESTS -----------------------------------

TEST_F(ConsoleArgsValidatorFixture, ValidTest1) {
	ASSERT_EQ(*this->cav->ValidateByIndex<int>(0u), this->number);
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest2) {
	ASSERT_NE(this->cav->ValidateByIndex<int>(0u), nullptr);
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest3) {
	ASSERT_DOUBLE_EQ(*this->cav->ValidateByIndex<double>(0u),
		static_cast<double>(this->number));
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest4) {
	ASSERT_NE(this->cav->ValidateByIndex<double>(0u), nullptr);
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest5) {
	ASSERT_FLOAT_EQ(*this->cav->ValidateByIndex<float>(0u),
		static_cast<float>(this->number));
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest6) {
	ASSERT_NE(this->cav->ValidateByIndex<float>(0u), nullptr);
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest7) {
	ASSERT_EQ(*this->cav->ValidateByIndex<unsigned>(0u),
		static_cast<unsigned>(this->number));
}

TEST_F(ConsoleArgsValidatorFixture, ValidTest8) {
	ASSERT_NE(this->cav->ValidateByIndex<unsigned>(0u), nullptr);
}