//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef THIRDTASK_STRINGSPLITTER_HPP
#define THIRDTASK_STRINGSPLITTER_HPP

#include <string>
#include <sstream>
#include <vector>

namespace task::helpers
{
	class StringSplitter
	{
	public:
		StringSplitter() = delete;

		StringSplitter(const StringSplitter&) = default;

		StringSplitter(StringSplitter&&) = default;

		explicit StringSplitter(char delimiter) : delimiter_(delimiter)
		{}

		[[nodiscard]] std::vector<std::string>
		Split(const std::string& string) const
		{
			std::vector<std::string> result;
			std::string token;
			std::stringstream ss(string);
			while (getline(ss, token, this->delimiter_))
			{
				result.push_back(token);
			}
			return result;
		}

	private:
		char delimiter_;
	};
}

#endif //THIRDTASK_STRINGSPLITTER_HPP
