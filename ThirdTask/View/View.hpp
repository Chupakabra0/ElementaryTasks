//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_VIEW_HPP
#define THIRDTASK_VIEW_HPP

#include "../ViewModel/ViewModel.hpp"

namespace task::third {
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) = delete;

  explicit View(const ViewModel &vm);

  void SetVM(const ViewModel &vm);

  void Out() const;

 private:
  ViewModel vm_;
};
}

#endif //THIRDTASK_VIEW_HPP
