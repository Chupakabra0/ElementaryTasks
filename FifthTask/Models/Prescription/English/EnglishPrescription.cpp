//
// Created by Александр Сафиюлин on 11.12.2020.
//

#include "EnglishPrescription.hpp"

std::string task::fifth::EnglishPrescription::ToSmallPrescription(const long long int number) {
  if (0ll == number) {
	return this->singleNumbers_[0ll];
  }
  return this->toSmallPrescriptionWithoutZero(number);
}

std::string task::fifth::EnglishPrescription::toSmallPrescriptionWithoutZero(
	const long long int number) {
  if (number == 0ll) {
	return std::string("");
  }
  if (number < 0ll) {
	return this->minus_ + " " +
		toSmallPrescriptionWithoutZero(std::abs(number));
  }
  if (number <= 19ll) {
	return this->singleNumbers_[number];
  }
  if (number <= 99ll) {
	const auto temp = toSmallPrescriptionWithoutZero(number % 10ll);

	return this->singleNumbers_[number / 10ll * 10ll]
		+ (temp.empty() ? "" : " " + temp);
  }
  if (number <= 199ll) {
	const auto temp = toSmallPrescriptionWithoutZero(number % 100ll);

	return this->singleNumbers_[1ll] + " " + this->singleNumbers_[100ll] +
		(temp.empty() ? "" : " " +temp);
  }
  if (number <= 999ll) {
	const auto temp = toSmallPrescriptionWithoutZero(number % 100ll);

	return toSmallPrescriptionWithoutZero(number / 100ll)
		+ " " + this->multipleNumbers_[100ll] +
		(temp.empty() ? "" : " " + temp);
  }

  std::string result;

  this->bigNumbersPrescription(number, 1999ll,999999ll,result);
  if (!result.empty()) {
	return result;
  }

  this->bigNumbersPrescription(number, 1999999ll,999999999ll,result);
  if (!result.empty()) {
	return result;
  }

  this->bigNumbersPrescription(number, 1999999999ll, 999999999999ll, result);
  if (!result.empty()) {
	return result;
  }

  this->bigNumbersPrescription(number, 1999999999999ll, 999999999999999ll,
							   result);
  if (!result.empty()) {
	return result;
  }

  this->bigNumbersPrescription(number, 1999999999999999ll,
							   999999999999999999ll, result);
  if (!result.empty()) {
	return result;
  }

  if (number <= 1999999999999999999ll) {
	const auto temp = toSmallPrescriptionWithoutZero(
		number % 1000000000000000000ll);
	return this->singleNumbers_[1ll] + " " +
		this->singleNumbers_[1000000000000000000ll] +
		(temp.empty() ? "" : " " + temp);
  }

  const auto temp = toSmallPrescriptionWithoutZero(number %
	  1000000000000000000ll);

  return toSmallPrescriptionWithoutZero(
	  number / 1000000000000000000ll) + " " + this->multipleNumbers_[1000000000000000000ll] +
	  (temp.empty() ? "" : " " + temp);
}

void task::fifth::EnglishPrescription::bigNumbersPrescription(const long long number,
															  const long long
															  singularLimit,
															  const long long
															  multipleLimit,
															  std::string &result) {
  const auto divider = (singularLimit + 1ll) / 2ll;
  const auto singularString = this->singleNumbers_[1ll] + " " +
	  this->singleNumbers_[divider];
  const auto multipleString = this->multipleNumbers_[divider];

  if (number <= singularLimit) {
	const auto temp = toSmallPrescriptionWithoutZero(number % divider);

	result = singularString + (temp.empty() ? "" : " " + temp);
  }
  else if (number <= multipleLimit) {
	const auto temp = toSmallPrescriptionWithoutZero(number % divider);

	result = toSmallPrescriptionWithoutZero(number / divider) +
		" " + multipleString + (temp.empty() ? "" : " " + temp);
  }
}
