//
// Created by nate on 1/13/25.
//

#include "tools/profiler.h"

NewtonFramework::DevTools::Profiler& NewtonFramework::DevTools::Profiler::instance() {
    static Profiler instance;
    return instance;
}

std::unordered_map<std::string, NewtonFramework::DevTools::ProfilingData> &NewtonFramework::DevTools::Profiler::getData() {
    return data;
}

void NewtonFramework::DevTools::Profiler::addProfileDataEntry(const ProfilingData& data_) {
    data[data_.name] = data_;
}

NewtonFramework::DevTools::ProfilerTimer::ProfilerTimer(const char *name_): name(name_) {
    startTime = std::chrono::high_resolution_clock::now();
}

NewtonFramework::DevTools::ProfilerTimer::~ProfilerTimer() {
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    Profiler::instance().addProfileDataEntry({name, static_cast<double>(elapsed.count()/ 1000 ) });
}
