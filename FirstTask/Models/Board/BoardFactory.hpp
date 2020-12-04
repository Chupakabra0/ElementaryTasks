//
// Created by Александр Сафиюлин on 26.11.2020.
//

#ifndef FIRSTTASK_BOARDFACTORY_HPP
#define FIRSTTASK_BOARDFACTORY_HPP

#include "Board.hpp"
#include "../../Services/Errors/ErrorHandler.hpp"

namespace task::first
{
	class BoardFactory
	{
		using value_type = char;
	public:
		BoardFactory() = delete;

		BoardFactory(const BoardFactory&) = default;

		BoardFactory(BoardFactory&&) = default;

		BoardFactory(value_type blackSymbol, value_type whiteSymbol)
				: blackSymbol_(blackSymbol), whiteSymbol_(whiteSymbol)
		{}

		std::unique_ptr<task::first::Board> CreateBoard
				(unsigned short rowsCount, unsigned short columnsCount)
		{
			if (rowsCount == 0 || columnsCount == 0)
			{
				return nullptr;
			}

			std::unique_ptr<task::first::Board> result
					(new(std::nothrow)
							 Board(rowsCount, columnsCount, this->blackSymbol_,
								   this->whiteSymbol_));
			if (nullptr == result)
			{
				return nullptr;
			}

			for (auto i = static_cast<unsigned short>(0); i < rowsCount; ++i)
			{
				for (auto j = static_cast<unsigned short>(0); j <
															  columnsCount; ++j)
				{
					value_type symbol;
					if (i % 2 == 0)
					{
						symbol = this->outStarOrBlink(j % 2, 0u,
													  std::equal_to<>());
					}
					else
					{
						symbol = this->outStarOrBlink(j % 2, 0u,
													  std::not_equal_to<>());
					}
					result->Insert(std::map<std::string, value_type>::value_type
										   (getKey(std::string(1u, 'A' + i),
												   std::string(1u,
															   j + 1 + '0')),
											symbol));
				}
			}

			return result;
		}

		~BoardFactory() = default;

	protected:
		static inline std::string getKey
				(const std::string& letter, const std::string& number)
		{
			return letter + number;
		}

		template<class Predicate>
		value_type outStarOrBlink(
				unsigned short first, unsigned short second,
				Predicate predicate)
		{
			if (predicate(first, second))
			{
				return this->blackSymbol_;
			}
			return this->whiteSymbol_;
		};

		value_type whiteSymbol_;
		value_type blackSymbol_;
	};
}

#endif //FIRSTTASK_BOARDFACTORY_HPP