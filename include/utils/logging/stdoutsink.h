//
// Created by nate on 1/12/25.
//

#pragma once
#include "sink.h"

namespace NewtonFramework {
    class StdoutSink final : public LogSink {
        void write(const LogData &logData) override;
    };
}

