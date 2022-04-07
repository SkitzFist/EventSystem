#pragma once
#include "EventHandler.h"
#include "OnTest.h"
#include "Log.h"

class TestHandlerDos :
    public EventHandler<OnTest>{
public:
    TestHandlerDos();
    ~TestHandlerDos();
    void onEvent(const OnTest& event) override;
};

TestHandlerDos::TestHandlerDos(){}
TestHandlerDos::~TestHandlerDos(){}

void TestHandlerDos::onEvent(const OnTest& event){
    Log::info("Dos recieved event: " + event.getMessage());
}
