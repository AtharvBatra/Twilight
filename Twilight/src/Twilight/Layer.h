#pragma once

#include "Twilight/Core.h"
#include "Twilight/Events/Event.h"

namespace Twilight {

	class TWI_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_debug_name; }

	protected:
		const std::string& m_debug_name;
	};

}