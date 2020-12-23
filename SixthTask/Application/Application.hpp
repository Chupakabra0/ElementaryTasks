#pragma once

#ifndef SIXTHTASK_APPLICATION_APPLICATION_HPP_
#define SIXTHTASK_APPLICATION_APPLICATION_HPP_

namespace task::sixth {
// Applications class, that refactors main
class Application {
 public:
  Application() = delete;

  Application(const Application &) = delete;

  Application(Application &&) = delete;

  Application &operator=(const Application &) = delete;

  Application &operator=(Application &&) = delete;

  static Application &GetInstance(unsigned argc, const char **argv);

  int operator()() const;

  ~Application() = default;
 private:
  explicit Application(unsigned argc, const char **argv);

  unsigned argc_;
  const char **argv_;
};
}

#endif //SIXTHTASK_APPLICATION_APPLICATION_HPP_
