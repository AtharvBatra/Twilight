#pragma once

#include "Core.h"

#include "Window.h"
#include "Twilight/LayerStack.h"
#include "Twilight/Events/Event.h"
#include "Twilight/Events/ApplicationEvent.h"

namespace Twilight {

	class TWI_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_running = true;
		LayerStack m_layer_stack;
	};

	// Definition expected in client
	Application* CreateApplication();

}