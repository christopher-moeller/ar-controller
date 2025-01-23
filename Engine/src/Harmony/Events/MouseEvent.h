#pragma once

#include "Event.h"

namespace Harmony {

    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
        
        inline float GetX() const { return m_MouseX; }
        inline float GetY() const { return m_MouseY; }
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "MouseMoved"; }
        int GetCategoryFlags() const override {
            return static_cast<int>(EventCategory::EventCategoryMouse) | static_cast<int>(EventCategory::EventCategoryInput);
        }
        
        static EventType GetStaticType() {
            return EventType::MouseMoved;
        }
        
    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScolledEvent : Event {
        
    public:
        MouseScolledEvent(const float xOffset, const float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}
        
        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "MouseScrolled"; }
        int GetCategoryFlags() const override {
            return static_cast<int>(EventCategory::EventCategoryMouse) | static_cast<int>(EventCategory::EventCategoryInput);
        }
        
        static EventType GetStaticType() {
            return EventType::MouseScrolled;
        }
        
    private:
        float m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event {
        
    public:
        
        int GetCategoryFlags() const override {
            return static_cast<int>(EventCategory::EventCategoryMouse) | static_cast<int>(EventCategory::EventCategoryInput) | static_cast<int>(EventCategory::EventCategoryMouseButton);
        }
        
    protected:
        MouseButtonEvent(int button) : m_Button(button) {}
        
        int m_Button;
        
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
        
    public:
        MouseButtonPressedEvent(const int button) : MouseButtonEvent(button) {}
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "MouseButtonPressed"; }
        
        static EventType GetStaticType() {
            return EventType::MouseButtonPressed;
        }
        
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
        
    public:
        MouseButtonReleasedEvent(const int button) : MouseButtonEvent(button) {}
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "MouseButtonReleased"; }
        
        static EventType GetStaticType() {
            return EventType::MouseButtonReleased;
        }
        
    };
    

}
