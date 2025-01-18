//
// Created by nate on 1/12/25.
//

#pragma once

namespace NewtonFramework {
    class Module {
    public:
        virtual ~Module() = default;
        virtual void onAttach () = 0;
        virtual void onUpdateStart () = 0;
        virtual void onUpdate () = 0;
        virtual void onUpdateEnd () = 0;
        virtual void onDestroy () = 0;
    };
}

