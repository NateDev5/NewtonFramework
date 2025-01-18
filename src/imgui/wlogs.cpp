//
// Created by nate on 1/12/25.
//

#include "imgui/wlogs.h"
NewtonFramework::WLogs::WLogs(): maxLogs(100) {
    setWindowName("Logs");
}

ImVec4 NewtonFramework::WLogs::getColor(NewtonFramework::LogLevel level) const {
    switch (level) {
        case NewtonFramework::INFO:
            return {0.25f, 0.52f, 0.96f, 1.0f};
        case NewtonFramework::WARN:
            return {0.92f, 0.85f, 0.25f, 1.0f};
        case NewtonFramework::ERR:
            return {0.92f, 0.25f, 0.25f, 1.0f};
        case NewtonFramework::DBG:
            return {0.37f, 0.92f, 0.25f, 1.0f};
        default:
            return {1,1,1,1};
    }
}

void NewtonFramework::WLogs::render() {
    if (ImGui::Button("Clear"))
        logs.clear();

    for (const NewtonFramework::LogData& log : logs)
        ImGui::TextColored(getColor(log.level), "[%s] [%s] (%s) %s", log.timestampStr.c_str(), LEVEL_STRING(log.level), log.scope.c_str(), log.message.c_str());
}

void NewtonFramework::WLogs::setMaxLogs(unsigned int maxLogs_) {
    maxLogs = maxLogs_;
}

void NewtonFramework::WLogs::addLogEntry(const NewtonFramework::LogData& logData) {
    logs.emplace_front(logData);
    if (logs.size() > maxLogs)
        logs.pop_back();
}