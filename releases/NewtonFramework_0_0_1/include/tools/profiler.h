//
// Created by nate on 1/13/25.
//

#pragma once
#include <chrono>
#include <string>
#include <unordered_map>

namespace NewtonFramework::DevTools {
    struct ProfilingData {
        std::string name;
        double elapsed;
    };

    class Profiler {
    private:
        std::unordered_map<std::string, ProfilingData> data;
    public:
        static Profiler& instance ();
        std::unordered_map<std::string, ProfilingData>& getData();
        void addProfileDataEntry (const ProfilingData& data_);
    };

    class ProfilerTimer {
    private:
        const char* name;
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    public:
        ProfilerTimer(const char* name_);
        ~ProfilerTimer();
    };
}

#ifdef PROFILER_ENABLED
#define PROFILE_FUNCTION Newton::DevTools::ProfilerTimer timer(__PRETTY_FUNCTION__);
#endif

