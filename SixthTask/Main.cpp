#include "Application/Application.hpp"

int main(const int argc, const char **argv) {
  return task::sixth::Application::GetInstance(argc, argv)();
}
