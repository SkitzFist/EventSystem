#pragma once

#include <typeinfo>
#include <vector>
#include <unordered_map>
#include <string>

#include "Obj.h"
#include "Event.h"
#include "Log.h"

class EventManager{
private: 
    class Registration{
        public:
        Registration(const std::string& eventID){ m_eventID = eventID;}
        std::string m_eventID;
        std::vector<Obj*> m_handlers;
    };

public:
    EventManager();
    ~EventManager();
    template <typename T> void regHandler(Obj* handler);
    template <typename T> void FireEvent(const T& event);

private:
    std::unordered_map<std::string, Registration*> handlerMap;
    const bool idExists(std::string id) const;
    std::vector<std::string> eventIds; 
}; 

EventManager::EventManager(){
}

EventManager::~EventManager(){
    for(int i = 0; i < eventIds.size(); ++i){
       delete handlerMap[eventIds[i]];
    }
}

template<typename T>
void EventManager::regHandler(Obj* handler){ 
    std::string id = typeid(T).name();

    Registration* reg;
    if(!idExists(id)){
        reg = new Registration(id);
        std::pair<std::string, Registration*> r = {id, reg};
        handlerMap.insert(r);
        eventIds.emplace_back(id);
        reg->m_handlers.emplace_back(handler);
        Log::info("Registered new Event + handler");
    }else{
        reg = handlerMap[id];
        reg->m_handlers.emplace_back(handler);
        Log::info("Registered handler");
    }
}

template <typename T> void 
EventManager::FireEvent(const T& event){
    Registration* reg = handlerMap[typeid(T).name()];
    for(int i = 0; i < reg->m_handlers.size(); ++i){
        Obj* obj = reg->m_handlers[i];
        EventHandler<T>* handler = dynamic_cast<EventHandler<T>*>(obj);
        handler->onEvent(event);
    }
}

const bool EventManager::idExists(std::string id) const{
    if(handlerMap.find(id) == handlerMap.end()){
        return false;
    }
    return true;
}