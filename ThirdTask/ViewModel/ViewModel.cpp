//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "ViewModel.hpp"

task::third::ViewModel::ViewModel(const std::multiset<task::third::Triangle,
													  std::greater<>> &triangleMultiset)
	: triangleMultiset_(triangleMultiset) {}

std::multiset<task::third::Triangle, std::greater<>> task::third::ViewModel::GetMultiset() const {
  return this->triangleMultiset_;
}

void task::third::ViewModel::SetMultiset(const std::multiset<task::third::Triangle,
															 std::greater<>> multiset) {
  if (this->triangleMultiset_ == multiset) {
	return;
  }
  this->triangleMultiset_ = multiset;
}

void task::third::ViewModel::AddToMultiset(const task::third::Triangle &triangle) {
  this->triangleMultiset_.insert(triangle);
}