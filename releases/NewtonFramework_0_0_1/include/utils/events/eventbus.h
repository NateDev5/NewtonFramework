//
// Created by nate on 1/13/25.
//

#pragma once
#include <functional>
#include <string>
#include <unordered_map>

#include "event.h"

#define NWT_EVENTS NewtonFramework::EventBus::instance()

template<typename T>
concept isEventType = std::derived_from<T, NewtonFramework::Event>;

namespace NewtonFramework {
    class EventBus {
    private:
        std::unordered_map<std::string, std::vector<std::function<void((void *))> > > subscribers;

    public:
        static EventBus &instance() {
            static EventBus instance;
            return instance;
        }

        template<typename t_event> requires isEventType<t_event>
        void subscribe(std::function<void(t_event)> callback) {
            subscribers[typeid(t_event).name()].emplace_back([callback](void *event) {
                callback(*static_cast<t_event *>(event));
            });
        }

        template<typename t_event> requires isEventType<t_event>
        void invoke(const t_event &event) {
            if (subscribers.empty()) return;
            std::vector<std::function<void(void*)>> sub = subscribers.at(typeid(t_event).name());
            for (const auto& subscriber : sub)
                subscriber((void*)&event);
        }
    };
}
