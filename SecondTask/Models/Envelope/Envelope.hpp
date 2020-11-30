//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef SECONDTASK_ENVELOPE_HPP
#define SECONDTASK_ENVELOPE_HPP

namespace task::second {
    class Envelope {
    public:
        Envelope() = delete;
        Envelope(const Envelope &) = default;
        Envelope(Envelope &&)      = default;

        Envelope(double heightAndWidth) : Envelope(heightAndWidth, heightAndWidth) {}
        Envelope(double height, double width) : height_(height), width_(width) {}

        [[nodiscard]] double GetHeight() const {
            return this->height_;
        }
        void SetHeight(unsigned height) {
            if (std::abs(this->height_ - height) < std::numeric_limits<double>::epsilon()) {
                return;
            }
            this->height_ = height;
        }

        [[nodiscard]] double GetWidth() const {
            return this->width_;
        }
        void SetWidth(unsigned width) {
            if (std::abs(this->width_ - width) < std::numeric_limits<double>::epsilon()) {
                return;
            }
            this->width_ = width;
        }

        Envelope& operator=(const Envelope&) = default;

        ~Envelope() = default;

    private:
        double height_;
        double width_;
    };

    // TODO: functional object for this
    inline bool CanPutIn(const Envelope &put, const Envelope &in) {
        return std::max(put.GetHeight(), put.GetWidth()) <= std::max(in.GetHeight(), in.GetWidth())
               &&
               std::min(put.GetWidth(), put.GetWidth()) <= std::min(in.GetHeight(), in.GetWidth());
    }

}
#endif //SECONDTASK_ENVELOPE_HPP