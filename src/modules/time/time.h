//
// Created by nate on 1/18/25.
//

#pragma once
#include "core/module.h"

#define NWT_TIME NewtonFramework::MTime::instance

namespace NewtonFramework {
    class MTime final : public Module {
    private:
        float lastTime_ = 0;
        float deltaTime_ = 0;
    public:
        static MTime* instance;
        MTime();
        void onAttach() override;
        void onUpdate() override;
        void onUpdateStart() override;
        void onUpdateEnd() override;
        void onDestroy() override;
        [[nodiscard]] float deltaTime () const;
    };
}
