#pragma once

#include "Window.h"
#include "Mesh.h"

namespace E3D {

	class Renderer
	{
		public:
			
			Renderer(Window& window) : p_window(&window) {}

			void DrawMesh(Mesh& mesh);
			void DrawLine(float x1, float y1, float x2, float y2);

		private:

			Window* p_window;
	};
}



