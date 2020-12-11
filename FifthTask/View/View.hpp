//
// Created by Александр Сафиюлин on 05.12.2020.
//

#ifndef FOURTHTASK_VIEW_HPP
#define FOURTHTASK_VIEW_HPP

#include "../Models/Prescription/Base/Prescription.hpp"

namespace task::fifth
{
	class View
	{
	public:
		View() = delete;

		View(const View&) = delete;

		View(View&&) = delete;

		explicit View(const long long number, const std::string& numberString)
		: number_(number), numberString_(numberString) {}

		void Out() const {
			std::cout << "Digit: " << this->number_ << std::endl
			<< "Letter: " << this->numberString_ << std::endl;
		}

		~View() = default;

	private:
		long long number_;
		std::string numberString_;
	};
}

#endif //FOURTHTASK_VIEW_HPP