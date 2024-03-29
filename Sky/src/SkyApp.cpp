#include <Twilight.h>

class Sky : public Twilight::Application {
public:
	Sky() {};
	~Sky() {};
};

Twilight::Application* Twilight::CreateApplication()
{
	return new Sky();
}