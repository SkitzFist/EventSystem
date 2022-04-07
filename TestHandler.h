#pragma once
#include "EventHandler.h"
#include "OnTest.h"
#include "Log.h"

class TestHandler : 
    public EventHandler<OnTest>{
public:
    TestHandler();
    ~TestHandler();
    void onEvent(const OnTest& event) override;
private:

};

TestHandler::TestHandler(){
}

TestHandler::~TestHandler(){

}

void TestHandler::onEvent(const OnTest& event){
    Log::info("Test recieved event: " + event.getMessage());
}