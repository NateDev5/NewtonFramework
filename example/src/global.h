//
// Created by nate on 1/18/25.
//

#pragma once
#include <memory>
#include "testmodule.h"

inline extern std::shared_ptr<TestModule> testModule = std::make_shared<TestModule>();
