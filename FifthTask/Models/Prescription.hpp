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
				std::string strings[]{
						"twenty", "thirty", "forty", "fifty", "sixty",
						"seventy", "eighty", "ninety" };
				return strings[number / 10 - 2] + " " +
					   ToSmallPrescriptionWithoutZero(number % 10);
			}
			if (number <= 199ll)
			{
				return std::string("one hundred") + " " +
					   ToSmallPrescriptionWithoutZero(number % 100);
			}
			if (number <= 999ll)
			{
				return ToSmallPrescriptionWithoutZero(number / 100) + " "
					   + "hundreds" + " " +
					   ToSmallPrescriptionWithoutZero(number % 100);
			}
			if (number <= 1999ll)
			{
				return std::string("one thousand") + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000);
			}
			if (number <= 999999ll)
			{
				return ToSmallPrescriptionWithoutZero(number / 1000) + " "
					   + "thousands" + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000);
			}
			if (number <= 1999999ll)
			{
				return std::string("one million") + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000);
			}
			if (number <= 999999999ll)
			{
				return ToSmallPrescriptionWithoutZero(number / 1000) + " " +
					   std::string("millions") + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000);
			}
			if (number <= 1999999999ll)
			{
				return std::string("one billion") + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000000000);
			}
			if (number <= 999999999999ll)
			{
				return ToSmallPrescriptionWithoutZero(number / 1000000000) + " "
					   + "billions" + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000000000);
			}
			if (number <= 1999999999999ll)
			{
				return std::string("one billiard") + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000000000000);
			}
			if (number <= 999999999999999ll)
			{
				return ToSmallPrescriptionWithoutZero(number / 1000000000000) +
					   " "
					   + "billiards" + " " +
					   ToSmallPrescriptionWithoutZero(number % 1000000000000);
			}
			if (number <= 1999999999999999ll)
			{
				return std::string("one trillion") + " " +
					   ToSmallPrescriptionWithoutZero(
							   number % 1000000000000000);
			}
			if (number <= 999999999999999999ll)
			{
				return ToSmallPrescriptionWithoutZero(
						number / 1000000000000000) +
					   " "
					   + "trillions" + " " +
					   ToSmallPrescriptionWithoutZero(
							   number % 1000000000000000);
			}
			if (number <= 1999999999999999999ll)
			{
				return std::string("one trilliard") + " " +
					   ToSmallPrescriptionWithoutZero(
							   number % 1000000000000000000);
			}

			return ToSmallPrescriptionWithoutZero(
					number / 1000000000000000000) +
				   " "
				   + "trilliards" + " " +
				   ToSmallPrescriptionWithoutZero(number % 1000000000000000000);
		}
	};
}

#endif //FOURTHTASK_PRESCRIPTION_HPP
