#include "Application/Application.hpp"

int main(const int argc, const char **argv) {
  return task::fourth::Application::GetInstance(argc, argv)();
}