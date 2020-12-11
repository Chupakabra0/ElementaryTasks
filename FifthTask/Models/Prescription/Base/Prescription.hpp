//
// Created by Александр Сафиюлин on 05.12.2020.
//

#pragma once

#ifndef FOURTHTASK_PRESCRIPTION_HPP
#define FOURTHTASK_PRESCRIPTION_HPP

#include <iostream>
#include <sstream>
#include <string>

namespace task::fifth {
class Prescription {
 public:
  Prescription() = default;

  Prescription(const Prescription &) = default;

  Prescription(Prescription &&) noexcept = default;

  Prescription &operator=(const Prescription &) = default;

  Prescription &operator=(Prescription &&) noexcept = default;

  virtual std::string ToSmallPrescription(long long number) = 0;

  std::string ToBigPrescription(long long number);

  virtual ~Prescription() = default;

 protected:
  virtual std::string toSmallPrescriptionWithoutZero(long long number) = 0;

  virtual void bigNumbersPrescription(long long number,
							  long long singularLimit,
							  long long multipleLimit,
							  std::string &result) = 0;
};

}

#endif //FOURTHTASK_PRESCRIPTION_HPP
