#pragma once
#include <string>

#include "Event.h"

class OnTest : 
    public Event{
public:
    OnTest(std::string message);
    const std::string& getMessage() const;
private:
    std::string m_message;
};

OnTest::OnTest(std::string message){
    m_message = message;
}

const std::string& OnTest::getMessage() const{
    return m_message;
}