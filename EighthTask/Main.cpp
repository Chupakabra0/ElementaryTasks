#include "Application/Application.hpp"

int main(int argc, char **argv) {
  return task::eighth::Application::GetInstance(argc, argv)();
}