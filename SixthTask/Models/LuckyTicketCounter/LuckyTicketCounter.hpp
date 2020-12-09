//
// Created by Александр Сафиюлин on 08.12.2020.
//

#ifndef SIXTHTASK_LUCKYTICKET_HPP
#define SIXTHTASK_LUCKYTICKET_HPP

#include <cmath>
#include <numbers>

#include "../../Services/Integral/Integral.hpp"
#include "../LuckyTicketType/LuckyTicketType.hpp"

namespace task::sixth {
	class LuckyTicketCounter {
	public:
		LuckyTicketCounter(const LuckyTicketCounter&) = default;

		LuckyTicketCounter(LuckyTicketCounter&&) = default;

		explicit LuckyTicketCounter(const unsigned countNumbers = 3u) :
		countNumbers_(countNumbers), rank_(10u) {}

//		[[nodiscard]] unsigned long long GetLuckyTicketsForceCount() const {
//			std::vector<unsigned long long> sums((this->rank_ - 1) *
//			this->countNumbers_ + 1);
//			auto limit = std::pow(10ull, this->countNumbers_);
//			auto result = 0ull;
//
//			for (auto i = 0ull; i < limit; ++i) {
//				++sums[this->getSumOfAllDigits(i)];
//			}
//
//			for (const auto& i : sums) {
//				result += i * i;
//			}
//
//			return result;
//		}

		[[nodiscard]] unsigned long long GetLuckyTicketsCount
			(const LuckyTicketType luckyTicketType) const {
			switch (luckyTicketType)
			{
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

		~LuckyTicketCounter() = default;

	private:
		[[nodiscard]] double functionToCount(double x) const {
			return std::pow(std::sin(this->rank_ * x) / sin(x),
				   2.0 * this->countNumbers_) / std::numbers::pi;
		}

		[[nodiscard]] unsigned long long getSumOfAllDigits(unsigned long long num)
		const {
			if (0ull == num) {
				return num;
			}

			return num % this->rank_ + getSumOfAllDigits(num / this->rank_);
		}

		[[nodiscard]] unsigned long long getSumOfEvenDigits(unsigned long
			long num) const {
			if (0ull == num) {
				return num;
			}

			return num % this->rank_ + getSumOfEvenDigits(num / std::pow
			(this->rank_, 2u));
		}

		[[nodiscard]] unsigned long long getSumOfOddDigits(unsigned long
			long num) const {
			if (0ull == num) {
				return num;
			}

			return (num % (this->rank_ * this->rank_) / this->rank_) +
			getSumOfOddDigits(num / (this->rank_ * this->rank_));
		}

		[[nodiscard]] unsigned long long getLuckyTicketsMoscowCount() const {
			auto temp = [this](double x) -> double {
				return this->functionToCount(x);
			};

			return static_cast<unsigned long long>
			(task::helpers::Integral::SimpsonCount(temp,
												   std::numeric_limits<double>::epsilon(),
												   std::numbers::pi,1000u));
		}

		[[nodiscard]] unsigned long long getLuckyTicketPiterCount() const {
			auto result = 0u;
			auto limit = std::pow(this->rank_, this->countNumbers_ * 2u);

			for (auto i = 0u; i < limit; ++i) {
				if (this->getSumOfEvenDigits(i) == this->getSumOfOddDigits(i)) {
					++result;
				}
			}

			return result;
		}

		unsigned countNumbers_;
		unsigned rank_;
	};
}

#endif //SIXTHTASK_LUCKYTICKET_HPP
