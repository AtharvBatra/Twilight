#pragma once

#include "Event.h"

namespace Twilight {

	class TWI_API KeyEvent : public Event
	{
	public:
		inline unsigned int GetKeyCode() const { return m_keycode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		KeyEvent(unsigned int keycode)
			: m_keycode(keycode) {}

		unsigned int m_keycode;
	};

	class TWI_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(unsigned int keycode, int repeat_count)
			: KeyEvent(keycode), m_repeat_count(repeat_count) {}

		inline int GetRepeatCount() const { return m_repeat_count; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeat_count << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeat_count;
	};

	class TWI_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(unsigned int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}