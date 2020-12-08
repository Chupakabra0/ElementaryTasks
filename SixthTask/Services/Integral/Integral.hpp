//
// Created by Александр Сафиюлин on 08.12.2020.
//

#ifndef SIXTHTASK_INTEGRAL_HPP
#define SIXTHTASK_INTEGRAL_HPP

namespace task::helpers {
	class Integral {
	public:
		Integral() = delete;

		Integral(const Integral&) = delete;

		Integral(Integral&&) = delete;

		template<class Function>
		static double TrapezoidCount(
				Function function, const double a,
				const double b, const unsigned n)
		{
			auto result = 0.0;
			const auto h = (b - a) / n;

			for (auto i = a; i < b; i += h)
			{
				auto temp = function(i) + function(i + h);
				if (temp != temp) {
					temp = std::numeric_limits<double>::epsilon();
				}
				result += temp;
			}

			return h / 2.0 * result;
		}

		template<class Function>
		static double SimpsonCount(Function function, const double a,
							 const double b, const unsigned n) {
			const auto h = (b - a) / n;
			auto temp = h * (function(a) + function(b)) / 6.0;

			if (temp != temp) {
				temp = std::numeric_limits<double>::epsilon();
			}
			auto result = temp;

			for (auto i = 1u; i <= n; ++i) {
				auto temp = (4.0 / 6.0) * h * function(a + h * i - h / 2.0);
				if (temp != temp) {
					temp = std::numeric_limits<double>::epsilon();
				}
				result += temp;
			}

			for (auto i = 1u; i <= n - 1; ++i) {
				auto temp = (2.0 / 6.0) * h * function(a + h * i);
				if (temp != temp) {
					temp = std::numeric_limits<double>::epsilon();
				}
				result += temp;
			}

			return result;
		}

		~Integral() = delete;
	private:

	};
}

#endif //SIXTHTASK_INTEGRAL_HPP
