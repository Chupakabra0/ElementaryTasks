//
// Created by Александр Сафиюлин on 05.12.2020.
//

#ifndef FOURTHTASK_VIEW_HPP
#define FOURTHTASK_VIEW_HPP

#include "../Models/Prescription.hpp"

namespace task::fifth
{
	class View
	{
	public:
		View() = delete;

		View(const View&) = delete;

		View(View&&) = delete;

		explicit View(const long long number)
		: number_(number), numberString_(Prescription::ToSmallPrescription
		(this->number_)) {}

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