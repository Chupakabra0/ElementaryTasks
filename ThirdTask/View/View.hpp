//
// Created by Александр Сафиюлин on 04.12.2020.
//

#ifndef THIRDTASK_VIEW_HPP
#define THIRDTASK_VIEW_HPP

#include "../ViewModel/ViewModel.hpp"

namespace task::third
{
	class View
	{
	public:
		View() = delete;

		View(const View&) = delete;

		View(View&&) = delete;

		View(const ViewModel& vm) : vm_(vm)
		{}

		void SetVM(const ViewModel& vm) {
			this->vm_ = vm;
		}

		void Out() const {
			for (const auto& i : this->vm_.GetMultiset()) {
				std::cout << i << std::endl;
			}
		}

	private:
		ViewModel vm_;
	};
}

#endif //THIRDTASK_VIEW_HPP
