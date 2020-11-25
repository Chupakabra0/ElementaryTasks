//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef SECONDTASK_VIEW_HPP
#define SECONDTASK_VIEW_HPP

#include <iostream>

#include "Envelope.hpp"

namespace task {
    namespace second {
        class View {
        public:
            View()  = delete;
            View(const task::second::Envelope& firstEnvelope, const task::second::Envelope& secondEnvelope)
                : firstEnvelope_(firstEnvelope), secondEnvelope_(secondEnvelope) {

            }

            void Out() const {
                if (task::second::CanPutIn(this->firstEnvelope_, this->secondEnvelope_)) {
                    std::cout << "First envelope can be put in second envelope" << std::endl;
                } else {
                    std::cout << "First envelope can NOT be put in second envelope" << std::endl;
                }

                if (task::second::CanPutIn(this->secondEnvelope_, this->firstEnvelope_)) {
                    std::cout << "Second envelope can be put in first envelope" << std::endl;
                } else {
                    std::cout << "Second envelope can NOT be put in first envelope" << std::endl;
                }
            }

            ~View() = default;
        private:
            task::second::Envelope firstEnvelope_;
            task::second::Envelope secondEnvelope_;
        };
    }
}

#endif //SECONDTASK_VIEW_HPP
