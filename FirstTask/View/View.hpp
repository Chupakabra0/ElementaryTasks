//
// Created by Александр Сафиюлин on 27.11.2020.
//

#pragma once

#ifndef FIRSTTASK_VIEW_HPP
#define FIRSTTASK_VIEW_HPP

#include "../ViewModels/ViewModel.hpp"

namespace task::first
{
	template<class ViewModelType>
	class View
	{
	public:
		View() = delete;

		View(const View&) = delete;

		View(View&&) noexcept = delete;

		View& operator=(const View&) = delete;

		View& operator=(View&&) = delete;

		explicit View(const ViewModel<ViewModelType>& vm) : vm_(vm)
		{}

		void Out() const
		{
			std::cout << this->vm_.GetChessBoard() << std::endl;
		}

		~View() = default;

	private:
		// TIP: maybe unique_ptr...
		ViewModel<ViewModelType> vm_;
	};
}

#endif //FIRSTTASK_VIEW_HPP
