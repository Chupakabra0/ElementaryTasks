//
// Created by Александр Сафиюлин on 05.12.2020.
//

#pragma once

#ifndef FOURTHTASK_MAIN_HPP
#define FOURTHTASK_MAIN_HPP

namespace task::fifth {
class Application {
 public:
  Application() = delete;

  Application(const Application &) = delete;

  Application(Application &&) = delete;

  Application &operator=(const Application &) = delete;

  Application &operator=(Application &&) = delete;

  static Application &GetInstance(unsigned argc, char **argv);

  int operator()() const;

  ~Application() = default;
 private:
  explicit Application(const unsigned argc, char ** argv) : argc_(argc), argv_(argv) {}

  unsigned argc_;
  char **argv_;
};
}

#endif //FOURTHTASK_MAIN_HPP
