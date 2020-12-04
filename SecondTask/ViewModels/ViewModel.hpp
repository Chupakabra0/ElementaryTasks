//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef SECONDTASK_VIEWMODEL_HPP
#define SECONDTASK_VIEWMODEL_HPP

#include <iostream>

#include "../Models/Envelope/Envelope.hpp"

namespace task::second
{
	class ViewModel
	{
	public:
		ViewModel() = delete;

		ViewModel(const ViewModel&) = default;

		ViewModel(ViewModel&&) = default;

		explicit ViewModel(
				const Envelope& firstEnvelope, const Envelope&
		secondEnvelope)
				: firstEnvelope_(firstEnvelope), secondEnvelope_(secondEnvelope)
		{}

		[[nodiscard]] Envelope GetFirstEnvelope() const
		{
			return this->firstEnvelope_;
		}

		void SetFirstEnvelope(const Envelope& envelope)
		{
			this->firstEnvelope_ = envelope;
		}

		[[nodiscard]] Envelope GetSecondEnvelope() const
		{
			return this->secondEnvelope_;
		}

		void SetSecondEnvelope(const Envelope& envelope)
		{
			this->secondEnvelope_ = envelope;
		}

		~ViewModel() = default;

	private:
		Envelope firstEnvelope_;
		Envelope secondEnvelope_;
	};
}

#endif //SECONDTASK_VIEWMODEL_HPP
