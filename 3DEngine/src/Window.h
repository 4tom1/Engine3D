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
				SDL_CreateWindowAndRenderer(2 * 640, 2 * 480, 0, &m_window, &m_renderer);
				SDL_RenderSetScale(m_renderer, 2, 2);
			}

			void Pixel(float x, float y);
			void Display();
			void Input();
			
			int GetHight();
			int GetWidth();

		private:
			void SetPressedKey(bool state);

		private:
			SDL_Event m_event;
			SDL_Window* m_window;
			SDL_Renderer* m_renderer;
			std::vector<Pointf2> m_points;
	};
}