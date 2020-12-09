//
// Created by Александр Сафиюлин on 25.11.2020.
//

#pragma once

#ifndef SECONDTASK_ENVELOPE_HPP
#define SECONDTASK_ENVELOPE_HPP

namespace task::second {
class Envelope {
 public:
  Envelope() = delete;

  Envelope(const Envelope &) = default;

  Envelope(Envelope &&) = default;

  explicit Envelope(double heightAndWidth);

  explicit Envelope(double height, double width);

  Envelope &operator=(const Envelope &) = default;

  Envelope &operator=(Envelope &&) noexcept = default;

  [[nodiscard]] double GetHeight() const;

  void SetHeight(unsigned height);

  [[nodiscard]] double GetWidth() const;

  void SetWidth(unsigned width);

  ~Envelope() = default;

 private:
  double height_;
  double width_;
};

// TODO: functional object for this
inline static bool CanPutIn(const Envelope &put, const Envelope &in) {
  return std::max(put.GetHeight(), put.GetWidth()) <=
	  std::max(in.GetHeight(), in.GetWidth())
	  &&
		  std::min(put.GetWidth(), put.GetWidth()) <=
			  std::min(in.GetHeight(), in.GetWidth());
}

}
#endif //SECONDTASK_ENVELOPE_HPP