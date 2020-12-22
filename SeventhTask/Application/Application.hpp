//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef SEVENTHTASK_APPLICATION_APPLICATION_HPP_
#define SEVENTHTASK_APPLICATION_APPLICATION_HPP_

namespace task::seventh {
class Application {
 public:
  Application() = delete;

  Application(const Application &) = delete;

  Application(Application &&) noexcept = delete;

  Application &operator=(const Application &) = delete;

  Application &operator=(Application &&) noexcept = delete;

  static Application &GetInstance(unsigned argc, const char **argv);

  int operator()() const;

  ~Application() = default;
 private:
  explicit Application(const unsigned argc, const char **argv)
	  : argc_(argc), argv_(argv) {}

  unsigned argc_;
  const char **argv_;
};
}

#endif //SEVENTHTASK_APPLICATION_APPLICATION_HPP_
