#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Twilight {

	class TWI_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
		
	private:
		bool m_running = true;
	};

	// Definition expected in client
	Application* CreateApplication();

}