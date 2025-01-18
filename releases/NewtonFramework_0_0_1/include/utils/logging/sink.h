//
// Created by nate on 1/12/25.
//

#pragma once
#include "logdata.h"

namespace NewtonFramework {
    class LogSink {
    public:
        virtual ~LogSink() = default;
        virtual void write (const LogData& logData) = 0;
    };
}

