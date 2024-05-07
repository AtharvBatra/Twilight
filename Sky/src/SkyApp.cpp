#include "twipch.h"
#include <Twilight.h>

class ExampleLayer : public Twilight::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		TWI_INFO("ExampleLayer::Update");
	}

	void OnEvent(Twilight::Event& event) override
	{
		TWI_TRACE("{0}", event);
	}
};

class Sky : public Twilight::Application {
public:
	Sky()
	{
		PushLayer(new ExampleLayer());
	};
	~Sky() {};
};

Twilight::Application* Twilight::CreateApplication()
{
	return new Sky();
}