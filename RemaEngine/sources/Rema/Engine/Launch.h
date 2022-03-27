#ifndef REMA_LAUNCH_H
#define REMA_LAUNCH_H

#ifdef REMA_PLATFORM_WINDOWS
extern remaEngine::Engine* remaEngine::CreateApplication();

int main(int argc, char** argv)
{
    remaEngine::Log::Init();
    REMA_CORE_INFO("Engine has been started");

    auto app = remaEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif // !REMA_PLATFORM_WINDOWS


#endif // !REMA_LAUNCH_H

