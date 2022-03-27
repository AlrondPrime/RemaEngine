#include <Rema.h>

class NovelGame : public remaEngine::Engine
{
public:
	NovelGame()
	{
		REMA_INFO("Application has been startred");
	}

	~NovelGame()
	{
		REMA_INFO("Game has been shutdown");
	}
};

remaEngine::Engine* remaEngine::CreateApplication()
{
	return new NovelGame();
}