//
// Created by Александр Сафиюлин on 05.12.2020.
//

#pragma once

#include <fstream>

#ifndef FOURTHTASK_FILEPARSERLINEBYLINE_HPP
#define FOURTHTASK_FILEPARSERLINEBYLINE_HPP

namespace task::fourth {
class FileReader {
 public:
  FileReader() = delete;

  FileReader(const FileReader &) = delete;

  FileReader(FileReader &&) = delete;

  FileReader &operator=(const FileReader &) = delete;

  FileReader &operator=(FileReader &&) = delete;

  explicit FileReader(const std::filesystem::path &path)
	  : path_(path), fileStream_(this->path_, std::ios_base::in) {
  }

  bool Open() {
	this->fileStream_.open(this->path_, std::fstream::in);

	return this->fileStream_.is_open();
  }

  bool Close() {
	this->fileStream_.close();

	return !this->fileStream_.is_open();
  }

  std::vector<std::string> GetFileStrings() {
	std::vector<std::string> result;

	if (!this->fileStream_.is_open()) {
	  return result;
	}

	std::string buffer;

	while (getline(this->fileStream_, buffer)) {
	  result.push_back(buffer);
	}

	return result;
  }

  ~FileReader() = default;

 private:
  std::filesystem::path path_;
  std::fstream fileStream_;
};
}

#endif //FOURTHTASK_FILEPARSERLINEBYLINE_HPP
