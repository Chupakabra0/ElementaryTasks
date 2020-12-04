//
// Created by Александр Сафиюлин on 27.11.2020.
//

#ifndef FIRSTTASK_VIEW_HPP
#define FIRSTTASK_VIEW_HPP

#include "../ViewModels/ViewModel.hpp"

namespace task::first
{
	class View
	{
	public:
		View() = delete;

		View(const View&) = delete;

		View(View&&) = delete;

		explicit View(const ViewModel& vm) : vm_(vm)
		{}

		void Out() const
		{
			std::cout << this->vm_.GetChessBoard() << std::endl;
		}

		~View() = default;

	private:
		// TIP: maybe unique_ptr...
		ViewModel vm_;
	};
}

#endif //FIRSTTASK_VIEW_HPP
