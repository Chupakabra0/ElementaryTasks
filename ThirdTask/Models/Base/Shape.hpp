//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_SHAPE_HPP
#define THIRDTASK_SHAPE_HPP

#include <string>

namespace task::third {
class Shape {
 public:
  Shape() = delete;

  Shape(const Shape &) = default;

  Shape(Shape &&) noexcept = default;

  explicit Shape(const std::string &name);;

  Shape &operator=(const Shape &) = default;

  Shape &operator=(Shape &&) noexcept = default;

  [[nodiscard]] std::string GetName() const;

  void SetName(const std::string &string);

  virtual double GetPerimeter() const = 0;

  virtual double GetSquare() const = 0;

  virtual ~Shape() = default;

 protected:
  std::string name_;
};
}

#endif //THIRDTASK_SHAPE_HPP
