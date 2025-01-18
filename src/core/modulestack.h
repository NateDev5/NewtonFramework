//
// Created by nate on 1/12/25.
//

#pragma once
#include <memory>
#include <vector>

#include "module.h"

namespace NewtonFramework {
    class ModuleStack {
    private:
        std::vector<std::shared_ptr<Module>> modules;

    public:
        void pushModule (const std::shared_ptr<Module> &module);
        void pop ();
        void updateStartAll () const;
        void updateAll () const;
        void updateEndAll () const;
        void destroyAll ();
    };
}
