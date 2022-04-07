#include "TestHandler.h"
#include "TestHandlerDos.h"
#include "EventManager.h"
#include "Log.h"

int main(){
    EventManager eventManager;
    OnTest testEvent("This is a test event");
    TestHandler handler;

    eventManager.regHandler<OnTest>(&handler);

    TestHandlerDos dos;
    eventManager.regHandler<OnTest>(&dos);

    eventManager.FireEvent(testEvent);

    OnTest onTest("This eventsystem seems to be working");
    eventManager.FireEvent(onTest);

    system("pause");
    return 0;
}