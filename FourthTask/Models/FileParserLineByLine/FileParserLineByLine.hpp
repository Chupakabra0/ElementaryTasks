//
// Created by Александр Сафиюлин on 05.12.2020.
//

#pragma once

#ifndef FOURTHTASK_FILEPARSERLINEBYLINE_HPP
#define FOURTHTASK_FILEPARSERLINEBYLINE_HPP

#include "FileParserLineByLineIterator.hpp"

namespace task::fourth {
template<IsSymbolType Type>
class FileParserLineByLine {
  using value_type = Type;
  using pointer = value_type *;
  using const_pointer = const pointer;
  using reference = value_type &;
  using const_reference = const reference;
  using difference_type = std::ptrdiff_t;
  using iterator = FileParserLineByLineIterator<value_type>;
  using const_iterator = const iterator;
 public:
  FileParserLineByLine() = delete;

  FileParserLineByLine(const FileParserLineByLine &) = delete;

  FileParserLineByLine(FileParserLineByLine &&) noexcept = default;

  FileParserLineByLine& operator=(const FileParserLineByLine&) = delete;

  FileParserLineByLine& operator=(FileParserLineByLine&&) noexcept = default;

  explicit FileParserLineByLine(const std::filesystem::path& path) {
	this->path_ = path;
	this->fileStream_.open(path);
  }

  [[nodiscard]] std::string GetPath() const {
	return this->path_;
  }

  auto begin() {
	return iterator(&this->fileStream_);
  }

  auto end() {
	return iterator();
  }

  auto cbegin() const {
	return const_iterator(&this->fileStream_);
  }

  auto cend() const {
	return const_iterator();
  }

  bool IsFileOpen() const {
	return this->fileStream_.is_open();
  }

  void CloseFile() {
	this->fileStream_.close();
  }

  void Reset() {
	this->fileStream_.clear();
	this->fileStream_.seekg(0u);
  }

  ~FileParserLineByLine() = default;

 private:
  std::fstream fileStream_;
  std::filesystem::path path_;
};

using CharFileParserLineByLine = FileParserLineByLine<char>;
using Char8tFileParserLineByLine = FileParserLineByLine<char8_t>;
using Char16tFileParserLineByLine = FileParserLineByLine<char16_t>;
using Char32tFileParserLineByLine = FileParserLineByLine<char32_t>;
using WCharFileParserLineByLine = FileParserLineByLine<wchar_t>;
using IntFileParserLineByLine = FileParserLineByLine<unsigned char>;

}

#endif //FOURTHTASK_FILEPARSERLINEBYLINE_HPP
