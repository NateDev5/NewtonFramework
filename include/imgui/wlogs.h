//
// Created by nate on 1/12/25.
//

#pragma once

#include "imguiwindow.h"
#include <deque>
#include <imgui.h>

#include "utils/logging/logdata.h"

namespace NewtonFramework {
    class WLogs final : public ImGuiWindow {
    private:
        unsigned int maxLogs;
        std::deque<NewtonFramework::LogData> logs;
        ImVec4 getColor(NewtonFramework::LogLevel level) const;
    public:
        WLogs();
        void setMaxLogs (unsigned int maxLogs_);
        void addLogEntry (const NewtonFramework::LogData &logData);
    protected:
        void render() override;
    };
}

