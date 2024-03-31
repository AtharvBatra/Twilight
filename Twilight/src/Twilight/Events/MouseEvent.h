#pragma once

#include "Event.h"

namespace Twilight {

	class TWI_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float mouse_x, float mouse_y)
			: m_mouse_x(mouse_x), m_mouse_y(mouse_y) {}

		inline float GetX() const { return m_mouse_x; }
		inline float GetY() const { return m_mouse_y; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: Mouse-X(" << GetX() << "), Mouse-Y(" << GetY() << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_mouse_x, m_mouse_y;
	};

	class TWI_API MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float x_offset, float y_offset)
			: m_x_offset(x_offset), m_y_offset(y_offset) {}

		inline float GetX() const { return m_x_offset; }
		inline float GetY() const { return m_y_offset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: X-Offset(" << GetX() << "), Y-Offset(" << GetY() << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)

	private:
		float m_x_offset, m_y_offset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString()
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString()
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}