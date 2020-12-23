#pragma once

#ifndef SIXTHTASK_LUCKYTICKETTYPE_HPP
#define SIXTHTASK_LUCKYTICKETTYPE_HPP

#include <string>

namespace task::sixth {
// Type of lucky ticket
enum class LuckyTicketType : unsigned short {
  NONE, MOSCOW, PITER
};

// Convert to string type of lucky ticket
inline std::string ToString(const LuckyTicketType luckyTicketType) {
  switch (luckyTicketType) {
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

// Convert from string type of lucky ticket
inline LuckyTicketType FromString(const std::string &string) {
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