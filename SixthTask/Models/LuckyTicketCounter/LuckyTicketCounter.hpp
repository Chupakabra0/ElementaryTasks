//
// Created by Александр Сафиюлин on 08.12.2020.
//

#ifndef SIXTHTASK_LUCKYTICKET_HPP
#define SIXTHTASK_LUCKYTICKET_HPP

#include <cmath>
#include <numbers>

#include <Integral/Integral.hpp>
#include <LuckyTicketType/LuckyTicketType.hpp>

namespace task::sixth {
// Class, that count amount of lucky ticket of special chosen type
class LuckyTicketCounter {
 public:
//------------------------- CTORS ----------------------------------------------

  LuckyTicketCounter(const LuckyTicketCounter &) = delete;

  LuckyTicketCounter(LuckyTicketCounter &&) noexcept = delete;

  LuckyTicketCounter& operator=(const LuckyTicketCounter&) = delete;

  LuckyTicketCounter& operator=(LuckyTicketCounter&&) noexcept = delete;

  explicit LuckyTicketCounter(const unsigned countNumbers = 3u) :
	  countNumbers_(countNumbers), rank_(RANK), integral_(IntegralN) {}

//---------------------- PUBLIC METHODS ----------------------------------------

  [[nodiscard]] unsigned long long GetLuckyTicketsCount
	  (const LuckyTicketType luckyTicketType) const {
    // Choose lucky type
	switch (luckyTicketType) {
	  case LuckyTicketType::MOSCOW: {
		return this->getLuckyTicketsMoscowCount();
	  }
	  case LuckyTicketType::PITER: {
		return this->getLuckyTicketPiterCount();
	  }
	  default: {
		return 0ull;
	  }
	}
  }

//-------------------------- GETTERS/SETTERS -----------------------------------

  [[nodiscard]] unsigned GetCountNumbers() const {
	return this->countNumbers_;
  }

  void SetCountNumbers(const unsigned counterNumber) {
	if (counterNumber == this->countNumbers_) {
	  return;
	}
	this->countNumbers_ = counterNumber;
  }

//----------------------------- DTOR -------------------------------------------

  ~LuckyTicketCounter() = default;

 private:
//-------------------------- PRIVATE METHODS -----------------------------------

  [[nodiscard]] double functionToCount(const double x) const {
	return std::pow(std::sin(this->rank_ * x) / sin(x),
					2.0 * this->countNumbers_) / std::numbers::pi;
  }

  [[nodiscard]] unsigned long long getSumOfAllDigits(const unsigned long long num)
  const {
	if (0ull == num) {
	  return num;
	}

	return num % this->rank_ + getSumOfAllDigits(num / this->rank_);
  }

//------------------------- GET MOSCOW COUNT -----------------------------------

  [[nodiscard]] unsigned long long getLuckyTicketsMoscowCount() const {
	auto temp = [this](const double x) -> double {
	  return this->functionToCount(x);
	};

	return static_cast<unsigned long long>
		(std::round(this->integral_.SimpsonCount
		(temp, std::numeric_limits<double>::epsilon(), std::numbers::pi)));
  }

//----------------------- GET PITER COUNT --------------------------------------

  [[nodiscard]] unsigned long long getLuckyTicketPiterCount() const {
	std::vector<unsigned long long> sums((this->rank_ - 1) *
		this->countNumbers_ + 1);
	auto limit = std::pow(this->rank_, this->countNumbers_);
	auto result = 0ull;

	for (auto i = 0ull; i < limit; ++i) {
	  ++sums[this->getSumOfAllDigits(i)];
	}

	for (const auto &i : sums) {
	  result += i * i;
	}

	return result;
  }

//----------------------- PRIVATE FIELDS ---------------------------------------

  unsigned countNumbers_;
  unsigned rank_;
  helpers::Integral integral_;

//---------------------- STATIC FIELDS -----------------------------------------

  static const unsigned RANK      = 10u;
  static const unsigned IntegralN = 2905u;
};
}

#endif //SIXTHTASK_LUCKYTICKET_HPP
