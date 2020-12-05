//
// Created by Александр Сафиюлин on 05.12.2020.
//

#ifndef FOURTHTASK_FILEPARSERLINEBYLINEITERATOR_HPP
#define FOURTHTASK_FILEPARSERLINEBYLINEITERATOR_HPP

#include <fstream>
#include <type_traits>

namespace task::fourth
{
//	template<class Type>
//	concept IsSymbol = std::is_same_v<Type, char> ||
//					   std::is_same_v<Type, wchar_t> ||
//					   std::is_same_v<Type, char8_t>
//					   || std::is_same_v<Type, char16_t> ||
//					   std::is_same_v<Type, char32_t>;
//
//	template<IsSymbol Type>
	class FileParserLineByLineIterator
	{
	public:
		using value_type = char;
		using pointer = value_type*;
		using const_pointer = const pointer;
		using reference = value_type&;
		using const_reference = const reference;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::random_access_iterator_tag;

		FileParserLineByLineIterator(
				const FileParserLineByLineIterator& copy)
		{
			this->fileStream_ = copy.fileStream_;
			this->stringBuffer_ = copy.stringBuffer_;
		}

		FileParserLineByLineIterator(FileParserLineByLineIterator&& move)
		noexcept
		{
			this->fileStream_ = move.fileStream_;
			this->stringBuffer_ = move.stringBuffer_;
			move.fileStream_ = nullptr;
		}

		explicit FileParserLineByLineIterator(
				std::fstream* pointer = nullptr) : fileStream_(pointer)
		{
			this->read();
		}

		auto operator++()
		{
			this->read();
			return *this;
		}

		auto operator++(int)
		{
			auto temp = *this;
			this->read();
			return temp;
		}

		friend bool operator==(
				const FileParserLineByLineIterator& first,
				const FileParserLineByLineIterator& second)
		{
			return first.fileStream_ == second.fileStream_;
		}

		friend bool operator!=(
				const FileParserLineByLineIterator& first,
				const FileParserLineByLineIterator& second)
		{
			return !(first == second);
		}

		std::string& operator*()
		{
			return this->stringBuffer_;
		}

		std::string* operator->()
		{
			return &this->stringBuffer_;
		}

		~FileParserLineByLineIterator() = default;

	private:

		void read()
		{
			if (nullptr == this->fileStream_)
			{
				return;
			}

			if (!getline(*this->fileStream_, this->stringBuffer_))
			{
				this->fileStream_ = nullptr;
			}
		}

		std::fstream* fileStream_;
		std::string stringBuffer_;
	};
}

#endif //FOURTHTASK_FILEPARSERLINEBYLINEITERATOR_HPP
