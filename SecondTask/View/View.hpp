//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef SECONDTASK_VIEW_HPP
#define SECONDTASK_VIEW_HPP

#include <sstream>
#include <string>

#include "../ViewModels/ViewModel.hpp"

namespace task::second {
    class View {
    public:
        View()            = delete;
        View(const View&) = default;
        View(View&&)      = default;

        explicit View(const ViewModel& vm) : vm_(vm) {}

        void Out() const {
            std::stringstream ss;
            ss << "First envelope " << this->vm_.GetFirstEnvelope().GetHeight() << " x "
               << this->vm_.GetFirstEnvelope().GetWidth() << " ";
            if (CanPutIn(this->vm_.GetFirstEnvelope(), this->vm_.GetSecondEnvelope())) {
                ss << "can be put in second envelope";
            }
            else {
                ss << "can NOT be put in second envelope";
            }
            ss << " " << this->vm_.GetSecondEnvelope().GetHeight() << " x "
                  << this->vm_.GetSecondEnvelope().GetWidth() << std::endl;

            ss << "Second envelope " << this->vm_.GetSecondEnvelope().GetHeight() << " x "
               << this->vm_.GetSecondEnvelope().GetWidth() << " ";
            if (CanPutIn(this->vm_.GetSecondEnvelope(), this->vm_.GetFirstEnvelope())) {
                ss << "can be put in first envelope";
            }
            else {
                ss << "can NOT be put in first envelope";
            }
            ss << " " << this->vm_.GetFirstEnvelope().GetHeight() << " x "
               << " " << this->vm_.GetFirstEnvelope().GetWidth() << std::endl;

            std::cout << ss.str();
        }

        ~View() = default;

    private:
        ViewModel vm_;
    };
}

#endif //SECONDTASK_VIEW_HPP
