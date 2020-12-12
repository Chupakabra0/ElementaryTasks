//
// Created by Александр Сафиюлин on 03.12.2020.
//

#pragma once

#ifndef SECONDTASK_MAIN_HPP
#define SECONDTASK_MAIN_HPP

namespace task::second {
class Application {
 public:
  Application(const Application &) = delete;

  Application(Application &&) = delete;

  Application &operator=(const Application &) = delete;

  Application &operator=(Application &&) noexcept = delete;

  static Application& GetInstance();

  int operator()() const;

  ~Application() = default;

 private:
  Application() = default;
};
}

#endif //SECONDTASK_MAIN_HPP