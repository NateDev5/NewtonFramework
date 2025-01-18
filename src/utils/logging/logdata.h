//
// Created by nate on 1/12/25.
//

#pragma once

#define LEVEL_STRING(level) \
((level) == NewtonFramework::LogLevel::INFO ? "INFO" : \
(level) == NewtonFramework::LogLevel::WARN ? "WARNING" : \
(level) == NewtonFramework::LogLevel::ERR ? "ERROR" : \
(level) == NewtonFramework::LogLevel::DBG ? "DEBUG" : "UNKNOWN")
#include <string>

namespace NewtonFramework {
    enum LogLevel {
        INFO,
        WARN,
        ERR,
        DBG
    };

    struct LogData {
        LogLevel level;
        std::string message;
        std::string scope;
        time_t timestamp;
        std::string timestampStr;
    };
}

