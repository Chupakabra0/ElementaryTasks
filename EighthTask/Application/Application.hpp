//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef EIGHTHTASK_APPLICATION_APPLICATION_HPP_
#define EIGHTHTASK_APPLICATION_APPLICATION_HPP_

namespace task::eighth {
// Applications class, that refactors main
class Application {
 public:
  Application() = delete;

  Application(const Application &) = delete;

  Application(Application &&) noexcept = delete;

  Application &operator=(const Application &) = delete;

  Application &operator=(Application &&) noexcept = delete;

  static Application& GetInstance(unsigned argc, const char **argv);

  int operator()() const;

  ~Application() = default;
 private:
  explicit Application(unsigned argc, const char **argv);

  unsigned argc_;
  const char **argv_;
};
}

#endif //EIGHTHTASK_APPLICATION_APPLICATION_HPP_
