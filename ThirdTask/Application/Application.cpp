//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include <regex>
#include <set>

#include "../Services/ConsoleInputValidator/ConsoleInputValidator.hpp"
#include "../Services/StringCleaner/StringCleaner.hpp"
#include "../Services/StringSpliter/StringSplitter.hpp"
#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

#include "../Models/Triangle/Triangle.hpp"
#include "../View/View.hpp"

#include "Application.hpp"

task::third::Application &task::third::Application::GetInstance() {
  static Application instance;
  return instance;
}

int task::third::Application::operator()() {
  std::string flag;
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<task::third::View<std::ostream>>
	  view(new(std::nothrow) task::third::View(std::cout, errorHandler));
  if (nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::helpers::ConsoleInputValidator>
	  consoleInputValidator(new(std::nothrow)
								task::helpers::ConsoleInputValidator());
  if (nullptr == consoleInputValidator) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::helpers::StringCleaner> stringCleaner(new
																  (std::nothrow) task::helpers::StringCleaner(
	  ' '));
  if (nullptr == stringCleaner) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::helpers::StringSplitter> stringSplitter(new
																	(std::nothrow) task::helpers::StringSplitter(
	  ','));
  if (nullptr == stringSplitter) {
	view->OutMemoryError();

	return EXIT_FAILURE;
  }

  do {

	view->OutInstructions();

	std::unique_ptr<std::string> triangleString =
		consoleInputValidator->LoopInput<std::string>();
	if (nullptr == triangleString) {
	  view->OutMemoryError();

	  return EXIT_FAILURE;
	}

	const auto triangleParams =
		stringSplitter->Split(stringCleaner->Clean(*triangleString));

	if (triangleParams.size() < 4) {
	  view->OutParseError();
	} else {
	  auto isPositiveDouble = [](const char string[]) -> bool {
		const std::regex number(R"((^\d+?(\.\d+?$|$)))");
		return std::regex_match(string, number)
			&& std::string(string).find('-') == std::string::npos;
	  };

	  std::unique_ptr<std::string> triangleName =
	  	task::helpers::Converter<std::string>::ConvertString(triangleParams[0]);
	  std::unique_ptr<double> firstSide =
		  task::helpers::Converter<double>::ConvertString(triangleParams[1], isPositiveDouble);
	  std::unique_ptr<double> secondSide =
		  task::helpers::Converter<double>::ConvertString(triangleParams[2], isPositiveDouble);
	  std::unique_ptr<double> thirdSide =
		  task::helpers::Converter<double>::ConvertString(triangleParams[3], isPositiveDouble);

	  if (nullptr == triangleName || nullptr == firstSide ||
		  nullptr == secondSide || nullptr == thirdSide) {
		view->OutParseError();
	  } else {
		std::unique_ptr<task::third::Triangle> triangle
			(task::third::Triangle::CreateUniquePtrTriangle
				 (*triangleName, *firstSide, *secondSide, *thirdSide));

		if (nullptr == triangle) {
		  view->OutValidError();
		} else {
		  view->AddToMultiset(*triangle);
		}

		view->OutTriangles();
	  }

	  std::cout << std::endl << "Continue? [y/Yes]:";
	  std::cin >> flag;
	  std::cin.ignore();
	  std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
	}
  } while ("Y" == flag || "YES" == flag);

  return EXIT_SUCCESS;
}

