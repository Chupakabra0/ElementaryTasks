//
// Created by Александр Сафиюлин on 25.11.2020.
//

#include <algorithm>

#include "Envelope.hpp"

namespace task {

    bool CanPutIn(const Envelope &put, const Envelope &in) {
        return std::max(put.GetHeight(), put.GetWidth()) <= std::max(in.GetHeight(), in.GetWidth())
               &&
               std::min(put.GetWidth(), put.GetWidth()) <= std::min(in.GetHeight(), in.GetWidth());
    }

}