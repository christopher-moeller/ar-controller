#pragma once

#include "Event.h"

namespace Harmony {

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
        
        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "WindowResize"; }
        int GetCategoryFlags() const override { return static_cast<int>(EventCategory::EventCategoryApplication); }
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }
        
        static EventType GetStaticType() {
            return EventType::WindowResize;
        }
        
    private:
        unsigned int m_Width, m_Height;
        
    };


    class WindowCloseEvent : public Event {
        
    public:
        WindowCloseEvent() = default;
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "WindowClose"; }
        int GetCategoryFlags() const override { return static_cast<int>(EventCategory::EventCategoryApplication); }
        
        static EventType GetStaticType() {
            return EventType::WindowClose;
        }
    };

    class AppTickEvent : public Event {
        
    public:
        AppTickEvent() = default;
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "AppTick"; }
        int GetCategoryFlags() const override { return static_cast<int>(EventCategory::EventCategoryApplication); }
        
        static EventType GetStaticType() {
            return EventType::AppTick;
        }
    };

    class AppUpdateEvent : public Event {
        
    public:
        AppUpdateEvent() = default;
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "AppUpdate"; }
        int GetCategoryFlags() const override { return static_cast<int>(EventCategory::EventCategoryApplication); }
        
        static EventType GetStaticType() {
            return EventType::AppUdate;
        }
    };

    class AppRenderEvent : public Event {
        
    public:
        AppRenderEvent() = default;
        
        EventType GetEventType() const override { return GetStaticType(); }
        const char* GetName() const override { return "AppRenderEvent"; }
        int GetCategoryFlags() const override { return static_cast<int>(EventCategory::EventCategoryApplication); }
        
        static EventType GetStaticType() {
            return EventType::AppUdate;
        }
    };

}
