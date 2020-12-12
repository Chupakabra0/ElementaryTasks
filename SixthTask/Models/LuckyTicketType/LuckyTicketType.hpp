//
// Created by Александр Сафиюлин on 09.12.2020.
//

#ifndef SIXTHTASK_LUCKYTICKETTYPE_HPP
#define SIXTHTASK_LUCKYTICKETTYPE_HPP

#include <string>

namespace task::sixth {
	enum class LuckyTicketType : unsigned short  {
		NONE, MOSCOW, PITER
	};

	inline std::string ToString(const LuckyTicketType luckyTicketType) {
		switch (luckyTicketType)
		{
			case LuckyTicketType::MOSCOW: {
				return std::string("MOSCOW");
			}
			case LuckyTicketType::PITER: {
				return std::string("PITER");
			}
			default: {
				return std::string("NONE");
			}
		}
	}

	inline LuckyTicketType FromString(const std::string& string) {
		if (ToString(LuckyTicketType::MOSCOW) == string) {
			return LuckyTicketType::MOSCOW;
		}
		if (ToString(LuckyTicketType::PITER) == string) {
			return LuckyTicketType::PITER;
		}

		return LuckyTicketType::NONE;
	}
}

#endif //SIXTHTASK_LUCKYTICKETTYPE_HPP
