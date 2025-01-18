//
// Created by nate on 1/12/25.
//

#pragma once

#include "core/module.h"

namespace NewtonFramework {
    class MImGui final : public Module {
    public:
        void onAttach() override;
        void onUpdate() override;
        void onDestroy() override;
        void onUpdateStart() override;
        void onUpdateEnd() override;
    };
}

