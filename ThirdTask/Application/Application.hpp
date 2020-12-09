//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_APPLICATION_HPP
#define THIRDTASK_APPLICATION_HPP

namespace task::third {
class Application {
 public:
  Application(const Application &) = delete;

  Application(Application &&) = delete;

  Application& operator=(const Application&) = delete;

  Application& operator=(Application&&) = delete;

  static Application& GetInstance();

  int operator()();

  ~Application() = default;
 private:
  Application() = default;
};
}

#endif //THIRDTASK_APPLICATION_HPP
