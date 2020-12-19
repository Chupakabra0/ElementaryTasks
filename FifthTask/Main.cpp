#include "Application/Application.hpp"

int main(const int argc, const char** argv) {
  return task::fifth::Application::GetInstance(argc, argv)();
}