#include "twipch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Twilight {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_layer_stack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_layer_stack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));

		TWI_CORE_TRACE("{0}", e);

		for (auto it = m_layer_stack.end(); it != m_layer_stack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_handled)
				break;
		}
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(0, 0.1f, 0.2f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layer_stack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_running = false;
		return true;
	}

}