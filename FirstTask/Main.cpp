#include "Application/Application.hpp"

int main(int argc, char** argv)
{
	return task::first::Application::GetInstance(argc, argv)();
}