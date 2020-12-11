#include "Application/Application.hpp"

int main(int argc, char* argv[])
{
  return task::fifth::Application::GetInstance(argc, argv)();
}