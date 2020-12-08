//
// Created by Александр Сафиюлин on 08.12.2020.
//

#ifndef SIXTHTASK_LUCKYTICKET_HPP
#define SIXTHTASK_LUCKYTICKET_HPP

#include <cmath>
#include <numbers>

#include "../Services/Integral/Integral.hpp"

namespace task::sixth {
	class LuckyTicketCounter {
	public:
		LuckyTicketCounter(const LuckyTicketCounter&) = default;

		LuckyTicketCounter(LuckyTicketCounter&&) = default;

		explicit LuckyTicketCounter(const unsigned countNumbers = 3u, const
		unsigned rank = 10u) : countNumbers_(countNumbers), rank_(rank) {}

		[[nodiscard]] unsigned long long GetLuckyTicketsForceCount() const {
			std::vector<unsigned long long> sums((this->rank_ - 1) *
			this->countNumbers_ + 1);
			auto limit = std::pow(10ull, this->countNumbers_);
			auto result = 0ull;

			for (auto i = 0u; i < limit; ++i) {
				++sums[this->Recurtion(i)];
			}

			for (const auto& i : sums) {
				result += i * i;
			}

			return result;
		}

		[[nodiscard]] unsigned long long GetLuckyTicketsIntegralCount() const {
			auto temp = [this](double x) -> double {
				return this->functionToCount(x);
			};

			return static_cast<unsigned long long>
			(task::helpers::Integral::SimpsonCount(temp,
										  std::numeric_limits<double>::epsilon(),
										  std::numbers::pi,1000u));
		}

		~LuckyTicketCounter() = default;

	private:
		[[nodiscard]] double functionToCount(double x) const {
			return std::pow(std::sin(this->rank_ * x) / sin(x),
				   2.0 * this->countNumbers_) / std::numbers::pi;
		}

		[[nodiscard]] unsigned long long Recurtion(unsigned long long num) const {
			if (0 == num) return num;
			return num % 10 + Recurtion(num / 10);
		}

		unsigned countNumbers_;
		unsigned rank_;
	};
}

#endif //SIXTHTASK_LUCKYTICKET_HPP
