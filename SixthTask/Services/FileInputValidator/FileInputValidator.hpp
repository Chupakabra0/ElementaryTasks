//
// Created by Александр Сафиюлин on 09.12.2020.
//

#ifndef SIXTHTASK_FILEINPUTVALIDATOR_HPP
#define SIXTHTASK_FILEINPUTVALIDATOR_HPP

#include <fstream>
#include <filesystem>

namespace task::helpers {
class FileInputValidator {
 public:
  FileInputValidator() = delete;

  FileInputValidator(const FileInputValidator &) = default;

  FileInputValidator(FileInputValidator &&) = default;

  explicit FileInputValidator(const std::filesystem::path &path)
	  : path_(path), fileStream_(this->path_, std::ios_base::in) {}

  [[nodiscard]] std::filesystem::path GetPath() const {
	return this->path_;
  }

  void SetPath(const std::filesystem::path &path) {
	if (path == this->path_) {
	  return;
	}
	this->path_ = path;
  }

  [[nodiscard]] bool IsFileValid() const {
	return this->fileStream_.is_open();
  }

  std::unique_ptr<std::string> ValidLine(bool predicate(const char[]) =
  	nullptr) {
	std::string result;

	if (!getline(this->fileStream_, result) ||
		(nullptr != predicate && !predicate(result.c_str()))) {
	  return nullptr;
	}

	return std::make_unique<std::string>(result);
  }

  ~FileInputValidator() = default;

 private:
  std::filesystem::path path_;
  std::fstream fileStream_;
};
}

#endif //SIXTHTASK_FILEINPUTVALIDATOR_HPP
