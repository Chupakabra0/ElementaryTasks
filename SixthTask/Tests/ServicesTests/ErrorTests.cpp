#include <gtest/gtest.h>
#include <Errors/ErrorHandler/ErrorHandler.hpp>


// ---------------------- HELPER TEST CLASSES ---------------------------------

struct ErrorHandlerFixture : public testing::Test {
public:
	ErrorHandlerFixture()
		: errorCode(task::helpers::ErrorCode::NO_ERROR),
		errorHandler(new(std::nothrow) task::helpers::ErrorHandler(this->errorCode))
	{}

	~ErrorHandlerFixture() override = default;

	task::helpers::ErrorCode errorCode;
	
	std::unique_ptr<task::helpers::ErrorHandler> errorHandler;
};

//---------------------------- CTOR TESTS -------------------------------------

TEST(ErrorHandlerTests, CtorTest) {
	const auto errorCode = task::helpers::ErrorCode::NO_ERROR;
	
	const std::unique_ptr<task::helpers::ErrorHandler>
		errorHandler(new(std::nothrow) task::helpers::ErrorHandler(errorCode));

	ASSERT_NE(nullptr, errorHandler);
	ASSERT_EQ(errorHandler->GetErrorCode(), errorCode);
}

//---------------------------- GETTERS TESTS ----------------------------------

TEST_F(ErrorHandlerFixture, ErrorHandlerGetterTest) {
	ASSERT_EQ(this->errorHandler->GetErrorCode(), this->errorCode);
}

//-------------------------- SETTERS TESTS -----------------------------------

TEST_F(ErrorHandlerFixture, ErrorHandlerSetterTest) {
	const task::helpers::ErrorCode valuesToSet[]{
		task::helpers::ErrorCode::NOT_ENOUGH_ARGS,
		task::helpers::ErrorCode::NO_ERROR,
		task::helpers::ErrorCode::ETERNAL_SERVER_ERROR,
		task::helpers::ErrorCode::FILE_NOT_EXIST,
		task::helpers::ErrorCode::MEMORY_OUT,
		task::helpers::ErrorCode::PARSE_FAILED,
		task::helpers::ErrorCode::VALIDATION_FAILED
	};

	for (const auto& i : valuesToSet) {
		const auto temp = *this->errorHandler;
		this->errorHandler->SetErrorCode(i);

		// TODO FIX IT AT THE FIRST BRANCH
		ASSERT_EQ(i, this->errorHandler->GetErrorCode());
		ASSERT_NE(temp.GetErrorCode(), this->errorHandler->GetErrorCode());
	}
}

//------------------------- ASSIGNMENTS TESTS ------------------------------

TEST_F(ErrorHandlerFixture, AssignmentTest) {
	
	this->errorHandler->SetErrorCode(task::helpers::ErrorCode::NOT_ENOUGH_ARGS);
	
	const auto copy = *this->errorHandler;

	ASSERT_EQ(copy.GetErrorCode(), this->errorHandler->GetErrorCode());

	this->errorHandler->SetErrorCode(task::helpers::ErrorCode::NO_ERROR);

	ASSERT_NE(copy.GetErrorCode(), this->errorHandler->GetErrorCode());
}