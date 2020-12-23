#include "Application/Application.hpp"

int main(int argc, const char **argv) {
  return task::eighth::Application::GetInstance(argc, argv)();
}