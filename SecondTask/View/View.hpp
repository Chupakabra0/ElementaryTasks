//
// Created by Александр Сафиюлин on 30.11.2020.
//

#pragma once

#include "../ViewModels/ViewModel.hpp"

#ifndef SECONDTASK_VIEW_HPP
#define SECONDTASK_VIEW_HPP

namespace task::second {
class View {
 public:
  View() = delete;

  View(const View &) = default;

  View(View &&) noexcept = default;

  explicit View(const ViewModel &vm);

  View &operator=(const View &) = default;

  View &operator=(View &&) noexcept = default;

  void Out() const;

  ~View() = default;

 private:
  // TODO: maybe smart_ptr
  ViewModel vm_;
};
}

#endif //SECONDTASK_VIEW_HPP
