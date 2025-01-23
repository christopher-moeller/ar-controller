#pragma once

#include "Event.h"


namespace Harmony {

    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_Keycode; }
        
        int GetCategoryFlags() const override { return static_cast<int>(EventCategory::EventCategoryKeyboard) | static_cast<int>(EventCategory::EventCategoryInput); }
        
    protected:
        KeyEvent(int keycode) : m_Keycode(keycode) {}
        
        int m_Keycode;
    };

    class KeyPressedEvent : public KeyEvent {
        
    public:
        KeyPressedEvent(int keyCode, bool isRepeat = false) : KeyEvent(keyCode), m_IsRepeat(isRepeat) {}
        
        bool IsRepeat() const { return m_IsRepeat; }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "KeyPressed"; }
        
        static EventType GetStaticType() {
            return EventType::KeyPressed;
        }
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_Keycode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }
        
    private:
        bool m_IsRepeat;
        
    };

    class KeyReleasedEvent : public KeyEvent {
        
        KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_Keycode;
            return ss.str();
        }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "KeyReleased"; }
        
        static EventType GetStaticType() {
            return EventType::KeyReleased;
        }
        
    };

}
