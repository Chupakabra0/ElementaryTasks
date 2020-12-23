#pragma once

#ifndef SIXTHTASK_FILEINPUTVALIDATOR_HPP
#define SIXTHTASK_FILEINPUTVALIDATOR_HPP

#include <fstream>
#include <filesystem>

namespace task::helpers {
// Class, that reads data from file line by line
class FileInputReader {
 public:
//------------------------------ CTOR ------------------------------------------

  FileInputReader() = delete;

  FileInputReader(const FileInputReader &) = delete;

  FileInputReader(FileInputReader &&) noexcept = default;

  FileInputReader& operator=(const FileInputReader&) = delete;

  FileInputReader& operator=(FileInputReader&&) noexcept = default;

  explicit FileInputReader(const std::filesystem::path &path)
	  : path_(path), fileStream_(this->path_, std::ios_base::in) {}

//-------------------------- GETTERS/SETTERS -----------------------------------

  [[nodiscard]] std::filesystem::path GetPath() const {
	return this->path_;
  }

  void SetPath(const std::filesystem::path &path) {
	if (path == this->path_) {
	  return;
	}
	this->path_ = path;
  }

//----------------------- BOOLEAN CHECKS ---------------------------------------

  [[nodiscard]] bool IsFileValid() const {
	return this->fileStream_.is_open();
  }

//--------------------------- VALIDATE -----------------------------------------

  std::unique_ptr<std::string> ValidLine(bool predicate(const char[]) =
  	nullptr) {
	std::string result;

	if (!getline(this->fileStream_, result) ||
		(nullptr != predicate && !predicate(result.c_str()))) {
	  return nullptr;
	}

	return std::make_unique<std::string>(result);
  }

//-------------------------------- DTOR ----------------------------------------

  ~FileInputReader() = default;

 private:
//------------------------------ PRIVATE FIELDS --------------------------------

  std::filesystem::path path_;
  std::fstream fileStream_;
};
}

#endif //SIXTHTASK_FILEINPUTVALIDATOR_HPP
