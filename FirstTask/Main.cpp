#include "Application/Application.hpp"

int main(const int argc, const char** argv) {
 return task::first::Application::GetInstance(argc, argv)();
}