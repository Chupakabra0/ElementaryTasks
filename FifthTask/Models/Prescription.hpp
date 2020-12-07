//
// Created by Александр Сафиюлин on 05.12.2020.
//

#ifndef FOURTHTASK_PRESCRIPTION_HPP
#define FOURTHTASK_PRESCRIPTION_HPP

#include <iostream>
#include <sstream>
#include <string>

namespace task::fifth
{
	class Prescription
	{
	public:
		Prescription() = delete;

		Prescription(const Prescription&) = delete;

		Prescription(Prescription&&) = delete;

		static std::string ToSmallPrescription(const long long number)
		{
			if (number == 0ll)
			{
				return std::string("zero");
			}
			return ToSmallPrescriptionWithoutZero(number);
		}

		static std::string ToBigPrescription(const long long number)
		{
			auto temp = ToSmallPrescription(number);
			return std::string(1u, static_cast<char>(toupper(
					static_cast<char>(temp[0]))))
				   + std::string(temp.begin() + 1, temp.end());
		}

		~Prescription() = delete;

	private:
		static std::string
		ToSmallPrescriptionWithoutZero(const long long number)
		{
			if (number == 0ll)
			{
				return std::string("");
			}
			if (number < 0ll)
			{
				return std::string("minus") + " " +
					   ToSmallPrescriptionWithoutZero(std::abs(number));
			}
			if (number <= 19ll)
			{
				std::string strings[19]{
						"one", "two", "three", "four", "five", "six", "seven",
						"eight", "nine", "ten", "eleven", "twelve", "thirteen",
						"fourteen", "fifteen", "sixteen", "seventeen",
						"eighteen",
						"nineteen" };
				return strings[number - 1];
			}
			if (number <= 99ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number % 10ll);
				std::string strings[]{
						"twenty", "thirty", "forty", "fifty", "sixty",
						"seventy", "eighty", "ninety" };
				return strings[number / 10 - 2] +
				(temp.empty() ? "" : " " + temp);
			}
			if (number <= 199ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						100ll);
				return std::string("one hundred") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						100ll);
				return ToSmallPrescriptionWithoutZero(number / 100ll)
					   + std::string(" hundreds") + (temp.empty() ? "" :
					   " " + temp);
			}
			if (number <= 1999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000ll);
				return std::string("one thousand")
					+ (temp.empty() ? "" : " " + temp);
			}
			if (number <= 999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000ll);
				return ToSmallPrescriptionWithoutZero(number / 1000ll) +
				std::string(" thousands") + (temp.empty() ? "" : " " + temp);
			}
			if (number <= 1999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000ll);
				return std::string("one million") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000ll);
				return ToSmallPrescriptionWithoutZero(number / 1000000ll)
					+ std::string(" millions") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 1999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000000ll);
				return std::string("one billion") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 999999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000000ll);
				return ToSmallPrescriptionWithoutZero(number / 1000000000ll) +
				std::string(" billions") + (temp.empty() ? "" : " " + temp);
			}
			if (number <= 1999999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000000000ll);
				return std::string("one billiard") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 999999999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000000000ll);
				return ToSmallPrescriptionWithoutZero(number /
				1000000000000ll) + std::string(" billiards") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 1999999999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(
						number % 1000000000000000ll);
				return std::string("one trillion") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 999999999999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(number %
						1000000000000000ll);
				return ToSmallPrescriptionWithoutZero(
						number / 1000000000000000ll) +
						std::string(" trillions") +
						(temp.empty() ? "" : " " + temp);
			}
			if (number <= 1999999999999999999ll)
			{
				const auto temp = ToSmallPrescriptionWithoutZero(
						number % 1000000000000000000ll);
				return std::string("one trilliard") +
						(temp.empty() ? "" : " " + temp);
			}

			const auto temp = ToSmallPrescriptionWithoutZero(number %
												   1000000000000000000ll);
			return ToSmallPrescriptionWithoutZero(
					number / 1000000000000000000ll) +
				   std::string(" trilliards") +
					(temp.empty() ? "" : " " + temp);
		}
	};
}

#endif //FOURTHTASK_PRESCRIPTION_HPP
