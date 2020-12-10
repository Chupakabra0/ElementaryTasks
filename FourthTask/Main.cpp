#include "Application/Application.hpp"

int main(int argc, char **argv) {
  return task::fourth::Application::GetInstance(argc, argv)();
}