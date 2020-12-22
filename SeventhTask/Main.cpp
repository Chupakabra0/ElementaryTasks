#include "Application/Application.hpp"

int main(int argc, const char **argv) {
  return task::seventh::Application::GetInstance(argc, argv)();
}