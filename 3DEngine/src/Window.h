#pragma once

#include <SDL.h>
#include <vector>

#include "Keyboard.h"

namespace E3D {
	
	struct Pointf2 {
		float x, y;
	};

	class Window
	{
		public:

			Window()
			{
				SDL_Init(SDL_INIT_VIDEO);
				SDL_CreateWindowAndRenderer(1000, 1000, 0, &m_window, &m_renderer);
				SDL_RenderSetScale(m_renderer, 2, 2);
				aspectRatio = 1000 / 1000;
			}

			void Pixel(float x, float y);
			void Display();
			void Input();
			
			int GetHight();
			int GetWidth();

		public:
			float aspectRatio;

		private:
			void SetKeyState(bool state);

		private:
			SDL_Event m_event;
			SDL_Window* m_window;
			SDL_Renderer* m_renderer;
			std::vector<Pointf2> m_points;
	};
}