//
// Created by nate on 1/12/25.
//

#pragma once
#include <memory>
#include <vector>

#include "sink.h"

namespace NewtonFramework {
    class Logger {
        std::vector<std::shared_ptr<LogSink>> logSinks;
    public:
        static Logger& instance ();
        void addSink (const std::shared_ptr<LogSink>& sink);
        void popSink ();
        void log (const LogLevel& level, const std::string& message, const std::string &scope = "");
    };
}

