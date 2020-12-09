//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include <sstream>
#include <string>

#include "View.hpp"

task::second::View::View(const ViewModel &vm) : vm_(vm) {}

void task::second::View::Out() const {
  std::stringstream ss;
  ss << "First envelope " << this->vm_.GetFirstEnvelope().GetHeight()
	 << " x "
	 << this->vm_.GetFirstEnvelope().GetWidth() << " ";
  if (CanPutIn(this->vm_.GetFirstEnvelope(),
			   this->vm_.GetSecondEnvelope())) {
	ss << "can be put in second envelope";
  } else {
	ss << "can NOT be put in second envelope";
  }
  ss << " " << this->vm_.GetSecondEnvelope().GetHeight() << " x "
	 << this->vm_.GetSecondEnvelope().GetWidth() << std::endl;

  ss << "Second envelope "
	 << this->vm_.GetSecondEnvelope().GetHeight() << " x "
	 << this->vm_.GetSecondEnvelope().GetWidth() << " ";
  if (CanPutIn(this->vm_.GetSecondEnvelope(),
			   this->vm_.GetFirstEnvelope())) {
	ss << "can be put in first envelope";
  } else {
	ss << "can NOT be put in first envelope";
  }
  ss << " " << this->vm_.GetFirstEnvelope().GetHeight() << " x "
	 << " " << this->vm_.GetFirstEnvelope().GetWidth() << std::endl;

  std::cout << ss.str();
}
