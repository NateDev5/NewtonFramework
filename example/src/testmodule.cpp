//
// Created by nate on 1/18/25.
//

#include "testmodule.h"

#include <NewtonFramework.h>

#include "events.h"

TestModule::TestModule(): value(0) {

}

void TestModule::onAttach() {
    NWT_WARN("Test module is attached!", "Test module");

    NWT_EVENTS.subscribe<TestEventAdd>(std::bind(&TestModule::add, this));

    NWT_EVENTS.subscribe<TestEventSub>(std::bind(&TestModule::sub, this));
}

void TestModule::onUpdateStart() {
}

void TestModule::onUpdate() {
    /**
    * Input
    */
    if (NWT_INPUT.isKeyDown(NWT_KEY_A))
        NWT_DBG("A down");

    if (NWT_INPUT.isKeyPressed(NWT_KEY_A))
        NWT_DBG("A pressed");

    if (NWT_INPUT.isMouseButtonDown(NWT_MOUSE_BUTTON_1))
        NWT_DBG("Mouse btn 1 down");

    if (NWT_INPUT.isMouseButtonPressed(NWT_MOUSE_BUTTON_1))
        NWT_DBG("Mouse btn 1 pressed");
}

void TestModule::onUpdateEnd() {
}

void TestModule::onDestroy() {

}

void TestModule::add() {
    value++;
}

void TestModule::sub() {
    value--;
}

int TestModule::getValue() const {
    return value;
}



