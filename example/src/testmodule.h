//
// Created by nate on 1/18/25.
//

#pragma once
#include "core/module.h"

class TestModule final : public NewtonFramework::Module {
private:
    int value;
public:
    TestModule();
    void onAttach() override;
    void onUpdateStart() override;
    void onUpdate() override;
    void onUpdateEnd() override;
    void onDestroy() override;

    [[nodiscard]] int getValue () const;
private:
    void add();
    void sub();
};