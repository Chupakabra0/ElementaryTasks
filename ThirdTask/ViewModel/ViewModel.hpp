//
// Created by Александр Сафиюлин on 04.12.2020.
//

#ifndef THIRDTASK_VIEWMODEL_HPP
#define THIRDTASK_VIEWMODEL_HPP

#include <set>

#include "../Models/Triangle/Triangle.hpp"

namespace task::third
{
	class ViewModel
	{
	public:
		ViewModel() = delete;

		ViewModel(const ViewModel&) = default;

		ViewModel(ViewModel&&) = default;

		ViewModel& operator=(const ViewModel&) = default;

		ViewModel& operator=(ViewModel&&) = default;

		explicit ViewModel
				(
						const std::multiset<task::third::Triangle,
								std::greater<>>&
						triangleMultiset) : triangleMultiset_(triangleMultiset)
		{}

		[[nodiscard]] auto GetMultiset() const
		{
			return this->triangleMultiset_;
		}

		void SetMultiset(
				const std::multiset<task::third::Triangle,
						std::greater<>> multiset)
		{
			if (this->triangleMultiset_ == multiset)
			{
				return;
			}
			this->triangleMultiset_ = multiset;
		}

		void AddToMultiset(const task::third::Triangle& triangle)
		{
			this->triangleMultiset_.insert(triangle);
		}

		~ViewModel() = default;

	private:
		std::multiset<task::third::Triangle, std::greater<>> triangleMultiset_;
	};
}

#endif //THIRDTASK_VIEWMODEL_HPP
