//
// Created by nate on 1/12/25.
//

#pragma once
#include <sstream>
#include <string>

namespace NewtonFramework {
    struct Version {
        unsigned int major;
        unsigned int minor;
        unsigned int patch;

        [[nodiscard]] std::string toString () const {
            std::ostringstream oss;
            oss << major << "." << minor << "." << patch;
            return oss.str();
        }
    };
}
