#include "Application/Application.hpp"

int main(int argc, char *argv[]) {
  return task::sixth::Application::GetInstance(argc, argv)();
}
