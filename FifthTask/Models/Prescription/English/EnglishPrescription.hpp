//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef FIFTHTASK_MODELS_PRESCRIPTION_ENGLISH_ENGLISHPRESCRIPTION_HPP_
#define FIFTHTASK_MODELS_PRESCRIPTION_ENGLISH_ENGLISHPRESCRIPTION_HPP_

#include <map>

#include "../Base/Prescription.hpp"

namespace task::fifth {
class EnglishPrescription : public Prescription {
 public:
  EnglishPrescription() = default;

  EnglishPrescription(const EnglishPrescription &) = default;

  EnglishPrescription(EnglishPrescription &&) = default;

  EnglishPrescription &operator=(const EnglishPrescription &) = default;

  EnglishPrescription &operator=(EnglishPrescription &&) = default;

  std::string ToSmallPrescription(long long number) override;

  ~EnglishPrescription() override = default;
 protected:
  std::string toSmallPrescriptionWithoutZero(long long number) override;

  void bigNumbersPrescription(long long number,
							  long long singularLimit,
							  long long multipleLimit,
							  std::string &result) override;

  std::map<long long, std::string> singleNumbers_{
	  std::map<long long, std::string>::value_type(0ll, "zero"),
	  std::map<long long, std::string>::value_type(1ll, "one"),
	  std::map<long long, std::string>::value_type(2ll, "two"),
	  std::map<long long, std::string>::value_type(3ll, "three"),
	  std::map<long long, std::string>::value_type(4ll, "four"),
	  std::map<long long, std::string>::value_type(5ll, "five"),
	  std::map<long long, std::string>::value_type(6ll, "six"),
	  std::map<long long, std::string>::value_type(7ll, "seven"),
	  std::map<long long, std::string>::value_type(8ll, "eight"),
	  std::map<long long, std::string>::value_type(9ll, "nine"),
	  std::map<long long, std::string>::value_type(10ll, "ten"),
	  std::map<long long, std::string>::value_type(11ll, "eleven"),
	  std::map<long long, std::string>::value_type(12ll, "twelve"),
	  std::map<long long, std::string>::value_type(13ll, "thirteen"),
	  std::map<long long, std::string>::value_type(14ll, "fourteen"),
	  std::map<long long, std::string>::value_type(15ll, "fifteen"),
	  std::map<long long, std::string>::value_type(16l, "sixteen"),
	  std::map<long long, std::string>::value_type(17ll, "seventeen"),
	  std::map<long long, std::string>::value_type(18ll, "eighteen"),
	  std::map<long long, std::string>::value_type(19ll, "nineteen"),
	  std::map<long long, std::string>::value_type(20ll, "twenty"),
	  std::map<long long, std::string>::value_type(30ll, "thirty"),
	  std::map<long long, std::string>::value_type(40ll, "forty"),
	  std::map<long long, std::string>::value_type(50ll, "fifty"),
	  std::map<long long, std::string>::value_type(60ll, "sixty"),
	  std::map<long long, std::string>::value_type(70ll, "seventy"),
	  std::map<long long, std::string>::value_type(80ll, "eighty"),
	  std::map<long long, std::string>::value_type(90ll, "ninety"),
	  std::map<long long, std::string>::value_type(100ll, "hundred"),
	  std::map<long long, std::string>::value_type(1000ll, "thousand"),
	  std::map<long long, std::string>::value_type(1000000ll, "million"),
	  std::map<long long, std::string>::value_type(1000000000ll, "billion"),
	  std::map<long long, std::string>::value_type(1000000000000ll, "billiard"),
	  std::map<long long, std::string>::value_type(1000000000000000ll,
												"trillion"),
	  std::map<long long, std::string>::value_type(1000000000000000000ll,
												"trilliard"),
  };

  std::map<long long, std::string> multipleNumbers_{
	  std::map<long long, std::string>::value_type(100ll, "hundreds"),
	  std::map<long long, std::string>::value_type(1000ll, "thousands"),
	  std::map<long long, std::string>::value_type(1000000ll, "millions"),
	  std::map<long long, std::string>::value_type(1000000000ll, "billions"),
	  std::map<long long, std::string>::value_type(1000000000000ll,
												"billiards"),
	  std::map<long long, std::string>::value_type(1000000000000000ll,
												   "trillions"),
	  std::map<long long, std::string>::value_type(1000000000000000000ll,
												   "trilliards"),
  };

  std::string minus_{"minus"};
};
}

#endif //FIFTHTASK_MODELS_PRESCRIPTION_ENGLISH_ENGLISHPRESCRIPTION_HPP_
