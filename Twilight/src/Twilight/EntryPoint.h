#pragma once

#ifdef TWI_PLATFORM_WINDOWS

extern Twilight::Application* Twilight::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Twilight::CreateApplication();
	app->Run();
	delete app;
}

#endif