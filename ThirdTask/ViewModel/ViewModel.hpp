//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_VIEWMODEL_HPP
#define THIRDTASK_VIEWMODEL_HPP

#include <set>

#include "../Models/Triangle/Triangle.hpp"

namespace task::third {
class ViewModel {
 public:
  ViewModel() = delete;

  ViewModel(const ViewModel &) = default;

  ViewModel(ViewModel &&) = default;

  ViewModel &operator=(const ViewModel &) = default;

  ViewModel &operator=(ViewModel &&) = default;

  explicit ViewModel(const std::multiset<task::third::Triangle,
										 std::greater<>> &triangleMultiset);

  [[nodiscard]] std::multiset<task::third::Triangle, std::greater<>> GetMultiset() const;

  void SetMultiset(const std::multiset<task::third::Triangle,
									   std::greater<>> multiset);

  void AddToMultiset(const task::third::Triangle &triangle);

  ~ViewModel() = default;

 private:
  std::multiset<task::third::Triangle, std::greater<>> triangleMultiset_;
};
}

#endif //THIRDTASK_VIEWMODEL_HPP
