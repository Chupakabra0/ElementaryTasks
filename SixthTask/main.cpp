#include <iostream>
#include <filesystem>

#include "Models/LuckyTicketCounter.hpp"

int main()
{
	const auto* ltc = new(std::nothrow)
			task::sixth::LuckyTicketCounter(9);
	std::cout << ltc->GetLuckyTicketsIntegralCount() << std::endl;
	std::cout << ltc->GetLuckyTicketsForceCount() << std::endl;
	delete ltc;

	return EXIT_SUCCESS;
}
