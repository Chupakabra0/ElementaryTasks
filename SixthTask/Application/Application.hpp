//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef SIXTHTASK_APPLICATION_APPLICATION_HPP_
#define SIXTHTASK_APPLICATION_APPLICATION_HPP_

namespace task::sixth {
class Application {
 public:
  Application() = delete;

  Application(const Application&) = delete;

  Application(Application&&) = delete;

  Application& operator=(const Application&) = delete;

  Application& operator=(Application &&) = delete;

  static Application& GetInstance(unsigned argc, char **argv);

  int operator()() const;

  ~Application() = default;
 private:
  explicit Application(const unsigned argc, char ** argv) : argc_(argc), argv_(argv) {}

  unsigned argc_;
  char **argv_;
};
}

#endif //SIXTHTASK_APPLICATION_APPLICATION_HPP_
