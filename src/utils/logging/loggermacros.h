//
// Created by nate on 1/16/25.
//

#pragma once

#include "utils/logging/logger.h"

#define NWT_LOGGER NewtonFramework::Logger::instance()

#define NWT_LOG(level, message, ...) \
NewtonFramework::Logger::instance().log(level, message, ##__VA_ARGS__);
#define NWT_INFO(message, ...)    NWT_LOG(NewtonFramework::LogLevel::INFO, message, ##__VA_ARGS__)
#define NWT_WARN(message, ...)    NWT_LOG(NewtonFramework::LogLevel::WARN, message, ##__VA_ARGS__)
#define NWT_ERR(message, ...)     NWT_LOG(NewtonFramework::LogLevel::ERR, message, ##__VA_ARGS__)
#define NWT_DBG(message, ...)     NWT_LOG(NewtonFramework::LogLevel::DBG, message, ##__VA_ARGS__)
