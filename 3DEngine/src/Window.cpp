#include "Window.h"

void E3D::Window::Pixel(float x, float y)
{
	m_points.emplace_back(x, y);
}

void E3D::Window::Display()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	for (auto& point : m_points)
	{
		SDL_RenderDrawPoint(m_renderer, point.x, point.y);
	}

	SDL_RenderPresent(m_renderer);

	m_points.clear();
}

void E3D::Window::Input()
{
	while (SDL_PollEvent(&m_event))
	{
		if (m_event.type == SDL_QUIT)
		{
			SDL_Quit();
			exit(0);
		}
	}
}