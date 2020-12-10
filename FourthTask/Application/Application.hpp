//
// Created by Александр Сафиюлин on 09.12.2020.
//

#pragma once

#ifndef FOURTHTASK_APPLICATION_APPLICATION_HPP_
#define FOURTHTASK_APPLICATION_APPLICATION_HPP_

namespace task::fourth {
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
  explicit Application(unsigned argc, char **argv);

  unsigned argc_;
  char **argv_;
};
}

#endif //FOURTHTASK_APPLICATION_APPLICATION_HPP_
