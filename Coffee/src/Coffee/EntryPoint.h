#pragma once

#ifdef CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv) {
	Coffee::Log::Init();
	CF_CORE_WARN("Initialized Logging!");
	CF_CORE_INFO("hello!");

	auto app = Coffee::CreateApplication();
	app->run();
	delete app;
}

#endif // CF_PLATFORM_WINDOWS
