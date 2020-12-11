#include "Application/Application.hpp"

int main(int argc, char **argv) {
  return task::seventh::Application::GetInstance(argc, argv)();
}