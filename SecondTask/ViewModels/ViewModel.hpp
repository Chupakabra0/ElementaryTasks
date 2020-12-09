//
// Created by Александр Сафиюлин on 25.11.2020.
//

#pragma once

#ifndef SECONDTASK_VIEWMODEL_HPP
#define SECONDTASK_VIEWMODEL_HPP

#include <iostream>

#include "../Models/Envelope/Envelope.hpp"

namespace task::second {
class ViewModel {
 public:
  ViewModel() = delete;

  ViewModel(const ViewModel &) = default;

  ViewModel(ViewModel &&) = default;

  ViewModel &operator=(const ViewModel &) = default;

  ViewModel &operator=(ViewModel &) = default;

  explicit ViewModel(const Envelope &firstEnvelope, const Envelope &
  secondEnvelope);

  [[nodiscard]] Envelope GetFirstEnvelope() const;

  void SetFirstEnvelope(const Envelope &envelope);

  [[nodiscard]] Envelope GetSecondEnvelope() const;

  void SetSecondEnvelope(const Envelope &envelope);

  ~ViewModel() = default;

 private:
  Envelope firstEnvelope_;
  Envelope secondEnvelope_;
};
}

#endif //SECONDTASK_VIEWMODEL_HPP
