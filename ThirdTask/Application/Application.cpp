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
#include "../ViewModel/ViewModel.hpp"
#include "../View/View.hpp"

#include "Application.hpp"

task::third::Application &task::third::Application::GetInstance() {
  static Application instance;
  return instance;
}

int task::third::Application::operator()() {
  std::string flag;
  task::helpers::ErrorHandler errorHandler(task::helpers::ErrorCode::NO_ERROR);

  std::unique_ptr<task::third::ViewModel> vm(new(std::nothrow)
												 task::third::ViewModel(std::multiset<
	  task::third::Triangle,
	  std::greater<>>()));
  if (nullptr == vm) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  std::unique_ptr<task::third::View>
	  view(new(std::nothrow) task::third::View(*vm));
  if (nullptr == view) {
	errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	errorHandler.OutError(std::string("\n"));

	return EXIT_FAILURE;
  }

  do {
	std::unique_ptr<task::helpers::ConsoleInputValidator>
		consoleInputValidator(new(std::nothrow)
								  task::helpers::ConsoleInputValidator());
	if (nullptr == consoleInputValidator) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError(std::string("\n"));

	  return EXIT_FAILURE;
	}

	std::unique_ptr<task::helpers::StringCleaner> stringCleaner(new
	(std::nothrow) task::helpers::StringCleaner(' '));
	if (nullptr == stringCleaner) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError(std::string("\n"));

	  return EXIT_FAILURE;
	}

	std::unique_ptr<task::helpers::StringSplitter> stringSplitter(new
																	  (std::nothrow) task::helpers::StringSplitter(
		','));
	if (nullptr == stringSplitter) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError(std::string("\n"));

	  return EXIT_FAILURE;
	}

	std::cout << "Enter a new triangle in format:" << std::endl
			  << "Name, FirstSide, SecondSide, ThirdSide" << std::endl;

	std::unique_ptr<std::string> triangleString = std::move
		(consoleInputValidator->LoopInput<std::string>());
	if (nullptr == triangleString) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::MEMORY_OUT);
	  errorHandler.OutError(std::string("\n"));

	  return EXIT_FAILURE;
	}

	*triangleString = stringCleaner->Clean(*triangleString);
	const auto triangleParams = stringSplitter->Split(*triangleString);

	if (triangleParams.size() < 4) {
	  errorHandler.SetErrorCode(task::helpers::ErrorCode::PARSE_FAILED);
	  errorHandler.OutError(std::string("\n"));
	} else {
	  auto isPositiveDouble = [](const char string[]) -> bool {
		const std::regex number(R"((^\d+?(\.\d+?$|$)))");
		return std::regex_match(string, number)
			&& std::string(string).find('-') == std::string::npos;
	  };

	  std::unique_ptr<std::string> triangleName =
		  std::move(task::helpers::Converter<std::string>::
					ConvertString(triangleParams[0]));
	  std::unique_ptr<double> firstSide =
		  std::move(task::helpers::Converter<double>::ConvertString
						(triangleParams[1], isPositiveDouble));
	  std::unique_ptr<double> secondSide =
		  std::move(task::helpers::Converter<double>::ConvertString
						(triangleParams[2], isPositiveDouble));
	  std::unique_ptr<double> thirdSide =
		  std::move(task::helpers::Converter<double>::ConvertString
						(triangleParams[3], isPositiveDouble));

	  if (nullptr == triangleName || nullptr == firstSide ||
		  nullptr == secondSide || nullptr == thirdSide) {
		errorHandler.SetErrorCode(task::helpers::ErrorCode::PARSE_FAILED);
		errorHandler.OutError(std::string("\n"));
	  } else {
		std::unique_ptr<task::third::Triangle> triangle
			(task::third::Triangle::CreateUniquePtrTriangle
				 (*triangleName, *firstSide, *secondSide, *thirdSide));

		if (nullptr == triangle) {
		  errorHandler.SetErrorCode(task::helpers::ErrorCode::VALIDATION_FAILED);
		  errorHandler.OutError(std::string("\n"));
		} else {
		  vm->AddToMultiset(*triangle);
		}

		view->SetVM(*vm);
		view->Out();
	  }

	  std::cout << std::endl << "Continue? [y/Yes]:";
	  std::cin >> flag;
	  std::cin.ignore();
	  std::transform(flag.begin(), flag.end(), flag.begin(), toupper);
	}
  } while ("Y" == flag || "YES" == flag);

  return EXIT_SUCCESS;
}

