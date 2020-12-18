//
// Created by Александр Сафиюлин on 25.11.2020.
//

#pragma once
// TODO FRIEND <=>
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

  void SetHeight(double height);

  [[nodiscard]] double GetWidth() const;

  void SetWidth(double width);

  auto operator<=>(const Envelope&) const = default;

  ~Envelope() = default;

 private:
  double height_;
  double width_;
};

}
#endif //SECONDTASK_ENVELOPE_HPP