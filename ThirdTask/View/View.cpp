//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "View.hpp"

task::third::View::View(const task::third::ViewModel &vm) : vm_(vm) {}

void task::third::View::SetVM(const task::third::ViewModel &vm) {
  this->vm_ = vm;
}

void task::third::View::Out() const {
  for (const auto &i : this->vm_.GetMultiset()) {
	std::cout << i << std::endl;
  }
}