#pragma once
#include "Event.h"
#include "obj.h"

template <class T>
class EventHandler : public Obj{
public:
    EventHandler();
    virtual void onEvent(const T& event) = 0;
    virtual ~EventHandler();
};

template <class T>
EventHandler<T>::EventHandler(){}

template <class T>
EventHandler<T>::~EventHandler(){}