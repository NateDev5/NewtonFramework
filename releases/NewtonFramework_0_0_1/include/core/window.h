//
// Created by nate on 1/12/25.
//

#pragma once

namespace NewtonFramework {
    struct WinSize {
        int width;
        int height;
    };

    class Window {
    public:
        virtual ~Window() = default;
        [[nodiscard]] virtual bool running () const = 0;
        virtual void handleInput () = 0;
        virtual void handleResize () = 0;
        virtual WinSize getSize () = 0;
        virtual void onUpdateStart() = 0;
        virtual void onUpdateEnd () = 0;
        virtual void onDestroy () = 0;
        virtual void* getWindowPtr () = 0;
    };
}

