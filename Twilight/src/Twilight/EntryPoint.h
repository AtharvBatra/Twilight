#pragma once

#ifdef TWI_PLATFORM_WINDOWS

extern Twilight::Application* Twilight::CreateApplication();

int main(int argc, char** argv)
{
	Twilight::Log::Init();

	TWI_CORE_WARN("Initialised Twilight's internal logger!");
	TWI_INFO("Client logger setup!");

	auto app = Twilight::CreateApplication();
	app->Run();
	delete app;
}

#endif