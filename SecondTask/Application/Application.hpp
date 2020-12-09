//
// Created by Александр Сафиюлин on 03.12.2020.
//

#pragma once

#ifndef SECONDTASK_MAIN_HPP
#define SECONDTASK_MAIN_HPP

namespace task::second {
class Application {
 public:

  Application(const Application &) = default;

  Application(Application &&) = default;

  Application &operator=(const Application &) = default;

  Application &operator=(Application &&) noexcept = default;

  static Application& GetInstance();

  int operator()() const;

  ~Application() = default;

 private:
  Application() = default;
};
}

#endif //SECONDTASK_MAIN_HPP