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
		switch (m_event.type)
		{
			SDL_QUIT:
				SDL_Quit();
				exit(0);
			//SDL_KEYDOWN:
			//	SetPressedKey(true);
			//SDL_KEYUP:
			//	SetPressedKey(false);
			default:
				break;
		}
	}
}

int E3D::Window::GetHight()
{
	int h;
	
	SDL_GetWindowSize(m_window, 0, &h);

	return h;
}

int E3D::Window::GetWidth()
{
	int w;

	SDL_GetWindowSize(m_window, &w, 0);

	return w;
}

void E3D::Window::SetPressedKey(bool state)
{
	switch (m_event.key.keysym.sym)
	{
		case SDLK_LEFT:
			Keyboard::GetInstance().GetKeyRef(E3D::Left) = state;
			break;
		case SDLK_RIGHT:
			Keyboard::GetInstance().GetKeyRef(E3D::Right) = state;
			break;
		case SDLK_UP:
			Keyboard::GetInstance().GetKeyRef(E3D::Up) = state;
			break;
		case SDLK_DOWN:
			Keyboard::GetInstance().GetKeyRef(E3D::Down) = state;
			break;
		case SDLK_a:
			Keyboard::GetInstance().GetKeyRef(E3D::A) = state;
			break;
		case SDLK_d:
			Keyboard::GetInstance().GetKeyRef(E3D::D) = state;
			break;
		case SDLK_s:
			Keyboard::GetInstance().GetKeyRef(E3D::S) = state;
			break;
		case SDLK_w:
			Keyboard::GetInstance().GetKeyRef(E3D::W) = state;
			break;
		default:
			break;
	}
}