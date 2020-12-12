//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef EIGHTHTASK_APPLICATION_APPLICATION_HPP_
#define EIGHTHTASK_APPLICATION_APPLICATION_HPP_

namespace task::eighth {
class Application {
 public:
  Application() = delete;

  Application(const Application &) = delete;

  Application(Application &&) noexcept = delete;

  Application &operator=(const Application &) = delete;

  Application &operator=(Application &&) noexcept = delete;

  static Application& GetInstance(unsigned argc, char **argv);

  int operator()() const;

  ~Application() = default;
 private:
  explicit Application(const unsigned argc, char **argv)
	  : argc_(argc), argv_(argv) {}

  unsigned argc_;
  char **argv_;
};
}

#endif //EIGHTHTASK_APPLICATION_APPLICATION_HPP_