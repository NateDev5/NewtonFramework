//
// Created by nate on 1/12/25.
//

#include "stdoutsink.h"

#include <iostream>
#include <sstream>

void NewtonFramework::StdoutSink::write(const LogData &logData) {
    std::cout << '[' << logData.timestampStr << "] ["
              << LEVEL_STRING(logData.level) << "] ";

    if (!logData.scope.empty())
        std::cout << '[' << logData.scope << "] ";

    std::cout << logData.message << std::endl;
}
