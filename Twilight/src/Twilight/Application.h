#pragma once

#include "Core.h"

namespace Twilight {

	class TWI_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// Definition expected in client
	Application* CreateApplication();

}