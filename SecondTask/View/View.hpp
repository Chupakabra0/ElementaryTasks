//
// Created by Александр Сафиюлин on 30.11.2020.
//

#ifndef SECONDTASK_VIEW_HPP
#define SECONDTASK_VIEW_HPP

#include "../ViewModels/ViewModel.hpp"

namespace task::second {
    class View {
    public:
        View()            = delete;
        View(const View&) = default;
        View(View&&)      = default;

        explicit View(const ViewModel& vm) : vm_(vm) {}

        void Out() const {
            if (CanPutIn(this->vm_.GetFirstEnvelope(), this->vm_.GetSecondEnvelope())) {
                std::cout << "First envelope can be put in second envelope" << std::endl;
            }
            else {
                std::cout << "First envelope can NOT be put in second envelope" << std::endl;
            }

            if (CanPutIn(this->vm_.GetSecondEnvelope(), this->vm_.GetFirstEnvelope())) {
                std::cout << "Second envelope can be put in first envelope" << std::endl;
            }
            else {
                std::cout << "Second envelope can NOT be put in first envelope" << std::endl;
            }
        }

        ~View() = default;

    private:
        ViewModel vm_;
    };
}

#endif //SECONDTASK_VIEW_HPP
