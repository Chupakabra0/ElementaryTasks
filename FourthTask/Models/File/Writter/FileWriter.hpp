//
// Created by Александр Сафиюлин on 21.12.2020.
//

#pragma once

#ifndef FOURTHTASK_MODELS_FILEPARSERLINEBYLINE_FILEWRITER_HPP_
#define FOURTHTASK_MODELS_FILEPARSERLINEBYLINE_FILEWRITER_HPP_

#include <fstream>
#include <vector>

namespace task::fourth {
class FileWriter {
 public:
  FileWriter() = delete;

  FileWriter(const FileReader &) = delete;

  FileWriter(FileReader &&) = delete;

  FileWriter &operator=(const FileReader &) = delete;

  FileWriter &operator=(FileReader &&) = delete;

  explicit FileWriter(const std::filesystem::path &path)
	  : path_(path), fileStream_(this->path_, std::ios_base::out) {
  }

  bool Open() {
	this->fileStream_.open(this->path_, std::fstream::out);

	return this->fileStream_.is_open();
  }

  bool Close() {
	this->fileStream_.close();

	return !this->fileStream_.is_open();
  }

  bool WriteStrings(const std::vector<std::string> &vector) {
	if (!this->fileStream_.is_open()) {
	  return false;
	}

	for (const auto &i : vector) {
	  this->fileStream_ << i << std::endl;
	}

	return true;
  }

  ~FileWriter() = default;

 private:
  std::filesystem::path path_;
  std::fstream fileStream_;
};
}
#endif //FOURTHTASK_MODELS_FILEPARSERLINEBYLINE_FILEWRITER_HPP_
