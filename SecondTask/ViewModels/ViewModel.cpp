//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "ViewModel.hpp"

task::second::ViewModel::ViewModel(const Envelope &firstEnvelope,
								   const Envelope &secondEnvelope)
	: firstEnvelope_(firstEnvelope), secondEnvelope_(secondEnvelope) {}

task::second::Envelope task::second::ViewModel::GetFirstEnvelope() const {
  return this->firstEnvelope_;
}

void task::second::ViewModel::SetFirstEnvelope(const task::second::Envelope &envelope) {
  this->firstEnvelope_ = envelope;
}

task::second::Envelope task::second::ViewModel::GetSecondEnvelope() const {
  return this->secondEnvelope_;
}

void task::second::ViewModel::SetSecondEnvelope(const task::second::Envelope &envelope) {
  this->secondEnvelope_ = envelope;
}
