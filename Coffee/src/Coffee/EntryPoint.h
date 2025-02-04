#pragma once

#ifdef CF_PLATFORM_WINDOWS

extern Coffee::Application* Coffee::CreateApplication();

int main(int argc, char** argv) {
	printf("Welcome to Coffee Engine");
	auto app = Coffee::CreateApplication();
	app->run();
	delete app;
}

#endif // CF_PLATFORM_WINDOWS
