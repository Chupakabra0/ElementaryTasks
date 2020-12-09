//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef FIRSTTASK_APPLICATION_HPP
#define FIRSTTASK_APPLICATION_HPP

#include <iostream>
#include <regex>

#include "../Models/Board/BoardCreator.hpp"
#include "../ViewModels/ViewModel.hpp"
#include "../View/View.hpp"
#include "../Services/ConsoleArgsValidator/ConsoleArgsValidator.hpp"

namespace task::first
{
	class Application
	{
	public:
		Application() = delete;

		Application(const Application&) = delete;

		Application(Application&&) noexcept = delete;

		Application& operator=(const Application&) = delete;

		Application& operator=(Application&&) = delete;

		static Application& GetInstance(const unsigned argc, char** argv);

		int operator()();

		~Application() = default;

	private:

		explicit Application(const unsigned argc, char** argv);

		unsigned argc_;
		char** argv_;
	};
}

#endif //FIRSTTASK_APPLICATION_HPP
