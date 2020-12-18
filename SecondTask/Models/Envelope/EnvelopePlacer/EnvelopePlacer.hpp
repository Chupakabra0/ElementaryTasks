//
// Created by Александр Сафиюлин on 18.12.2020.
//
#pragma once

#ifndef SECONDTASK_ENVELOPEPLACER_HPP
#define SECONDTASK_ENVELOPEPLACER_HPP

#include <Envelope/Envelope/Envelope.hpp>

namespace task::second {
struct EnvelopePlacer {
	[[nodiscard]] static bool CanPlace(const Envelope& put, const Envelope& in) {
		return
			std::max(put.GetHeight(), put.GetWidth()) <=
			std::max(in.GetHeight(), in.GetWidth())
			&&
			std::min(put.GetHeight(), put.GetWidth()) <=
			std::min(in.GetHeight(), in.GetWidth());
	}
};
}

#endif //!SECONDTASK_ENVELOPEPLACER_HPP