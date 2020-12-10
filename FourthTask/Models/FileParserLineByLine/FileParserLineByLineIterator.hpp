//
// Created by Александр Сафиюлин on 05.12.2020.
//

#pragma once

#ifndef FOURTHTASK_FILEPARSERLINEBYLINEITERATOR_HPP
#define FOURTHTASK_FILEPARSERLINEBYLINEITERATOR_HPP

#include <fstream>

namespace task::fourth {
template<class Type>
concept IsSymbolType = std::is_same_v<Type, char> ||
	std::is_same_v<Type, wchar_t> ||
	std::is_same_v<Type, char8_t> ||
	std::is_same_v<Type, char16_t> ||
	std::is_same_v<Type, char32_t> ||
	std::is_same_v<Type, signed char> ||
	std::is_same_v<Type, unsigned char>;

template<IsSymbolType Type>
class FileParserLineByLineIterator {
 public:
  using value_type = char;
  using pointer = value_type *;
  using const_pointer = const pointer;
  using reference = value_type &;
  using const_reference = const reference;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::random_access_iterator_tag;

  explicit FileParserLineByLineIterator(std::fstream *pointer = nullptr)
	  : fileStream_(pointer) {
	this->read();
  }

  FileParserLineByLineIterator(
	  const FileParserLineByLineIterator &copy) {
	this->fileStream_ = copy.fileStream_;
	this->stringBuffer_ = copy.stringBuffer_;
  }

  FileParserLineByLineIterator(FileParserLineByLineIterator &&move)
  noexcept {
	this->fileStream_ = move.fileStream_;
	this->stringBuffer_ = move.stringBuffer_;
	move.fileStream_ = nullptr;
  }

  FileParserLineByLineIterator &operator=(const
										  FileParserLineByLineIterator &copy) {
	if (*this == copy) {
	  return *this;
	}
	this->fileStream_ = copy.fileStream_;
	this->stringBuffer_ = copy.stringBuffer_;

	return *this;
  }

  FileParserLineByLineIterator &operator=(FileParserLineByLineIterator &&
  move) noexcept {
	if (*this == move) {
	  return *this;
	}
	this->fileStream_ = move.fileStream_;
	this->stringBuffer_ = move.stringBuffer_;
	move.fileStream_ = nullptr;

	return *this;
  }

  auto &operator++() {
	this->read();
	return *this;
  }

  auto operator++(int) {
	auto temp = *this;
	this->read();
	return temp;
  }

  friend bool operator==(
	  const FileParserLineByLineIterator &first,
	  const FileParserLineByLineIterator &second) {
	return first.fileStream_ == second.fileStream_;
  }

  friend bool operator!=(
	  const FileParserLineByLineIterator &first,
	  const FileParserLineByLineIterator &second) {
	return !(first == second);
  }

  std::string &operator*() {
	return this->stringBuffer_;
  }

  std::string *operator->() {
	return &this->stringBuffer_;
  }

  ~FileParserLineByLineIterator() = default;

 private:

  void read() {
	if (nullptr == this->fileStream_) {
	  return;
	}

	if (!getline(*this->fileStream_, this->stringBuffer_)) {
	  // TODO: maybe seekg or another stuff to move it to the begin
	  this->fileStream_ = nullptr;
	}
  }

  std::fstream *fileStream_;
  std::string stringBuffer_;
};
}

#endif //FOURTHTASK_FILEPARSERLINEBYLINEITERATOR_HPP
