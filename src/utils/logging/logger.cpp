//
// Created by nate on 1/12/25.
//

#include "logger.h"

#include <chrono>
#include <format>

NewtonFramework::Logger &NewtonFramework::Logger::instance() {
    static Logger instance_;
    return instance_;
}

void NewtonFramework::Logger::popSink() {
    logSinks.pop_back();
}

void NewtonFramework::Logger::log(const LogLevel &level, const std::string &message, const std::string &scope) {
    // get the timestamp of this log
    std::time_t timestamp = std::time(nullptr);
    std::string timestampStr = std::format("{:%H:%M}", std::chrono::system_clock::from_time_t(timestamp));
    for (const std::shared_ptr<LogSink>& sink : logSinks)
        if (sink != nullptr)
            sink->write({level, message, scope, timestamp, timestampStr});
}

void NewtonFramework::Logger::addSink(const std::shared_ptr<LogSink>& sink) {
    logSinks.push_back(sink);
}





