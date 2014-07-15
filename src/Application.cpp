#include "Application.hpp"
#include <core/Log.hpp>

Application *Application::m_app = nullptr;

Application::Application()
{
	// Constructor
}

Application &Application::getSingleton()
{
	if (m_app == nullptr)
		m_app = new Application();
	return *m_app;
}

Core &Application::getCore()
{
	return *m_core;
}

int Application::run(int argc, char **argv)
{
	gt::Log::Debug("Starting up core library...\n");
	m_core = new Core();

	gt::Log::Debug("Starting up GUI layer...\n");
	m_gui = gui_ptr(new GuiGtk(argc, argv));

	while (m_core->isRunning()) {
		m_core->update();
		m_gui->update();
	}

	return 0;
}