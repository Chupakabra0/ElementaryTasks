//
// Created by Александр Сафиюлин on 10.12.2020.
//

#include "Prescription.hpp"

std::string task::fifth::Prescription::ToBigPrescription(const long long int
														 number) {
  auto temp = ToSmallPrescription(number);
  return std::string(1u, static_cast<char>(toupper(
	  static_cast<char>(temp[0]))))
	  + std::string(temp.begin() + 1, temp.end());
}