//
// Created by Александр Сафиюлин on 05.12.2020.
//

#ifndef FOURTHTASK_FILEPARSERLINEBYLINE_HPP
#define FOURTHTASK_FILEPARSERLINEBYLINE_HPP

#include "FileParserLineByLineIterator.hpp"

namespace task::fourth
{
//	template<IsSymbol Type>
	class FileParserLineByLine
	{
		using value_type = char;
		using pointer = value_type*;
		using const_pointer = const pointer;
		using reference = value_type&;
		using const_reference = const reference;
		using difference_type = std::ptrdiff_t;
		using iterator = FileParserLineByLineIterator;
		using const_iterator = iterator;
	public:

		// TODO: make it more pretty)
		void Close() {
			this->fileStream_.close();
		}

		FileParserLineByLine() = delete;

		FileParserLineByLine(const FileParserLineByLine&) = default;

		FileParserLineByLine(FileParserLineByLine&&) noexcept = default;

		explicit FileParserLineByLine(const std::string& path)
		{
			this->path_ = path;
			this->fileStream_.open(path);
		}

		[[nodiscard]] std::string GetPath() const {
			return this->path_;
		}

		auto begin()
		{
			return iterator(&this->fileStream_);
		}

		auto end()
		{
			return iterator();
		}

		~FileParserLineByLine() = default;

	private:
		std::fstream fileStream_;
		std::string path_;
	};
//
//	using CharFileParserLineByLine = FileParserLineByLine<char>;
}

#endif //FOURTHTASK_FILEPARSERLINEBYLINE_HPP
