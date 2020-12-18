//
// Created by Александр Сафиюлин on 18.12.2020.
//

#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>
#include <ConsoleInputValidator/ConsoleInputValidator.hpp>

// ---------------------- HELPER TEST CLASSES ---------------------------------
struct ConsoleInputValidatorFixtures : public testing::Test {
public:
	explicit ConsoleInputValidatorFixtures(const std::filesystem::path& path)
		: path(path), fs(this->path),
		civ(new(std::nothrow) task::helpers::ConsoleInputValidator<std::fstream>(this->fs))
		{}

	~ConsoleInputValidatorFixtures() override = default;
	
	std::filesystem::path path;
	std::fstream fs;
	
	std::unique_ptr<task::helpers::ConsoleInputValidator<std::fstream>> civ;
};

//---------------------------- CTOR TESTS -------------------------------------

TEST(ConsoleInputValidatorTests, CtorTest) {
	const std::filesystem::path path("temp.tmp");
	std::fstream fileStream(path);

	const std::unique_ptr<task::helpers::ConsoleInputValidator<std::fstream>> civ
	(new(std::nothrow) task::helpers::ConsoleInputValidator<std::fstream>
		(fileStream));

	ASSERT_NE(nullptr, civ);

	fileStream.close();
	std::filesystem::remove(path);
}