#pragma once

#include "Window.h"
#include "Mesh.h"

namespace E3D {

	class Renderer
	{
		public:
			
			Renderer(Window& window) : p_window(&window) 
			{
				aspect_ratio = (float)p_window->GetHight() / (float)p_window->GetWidth();
			}

			void DrawMesh(const Mesh& mesh);

		public:
			float aspect_ratio;
			float fov = 90.0f;
			float far = 1000.0f;
			float near = 0.1f;

		private:
			void Projection3D(const vec3f& ipoint, vec3f& opoint);
			void DrawTriangle(const Tri& tri);
			void DrawLine(float x1, float y1, float x2, float y2);

		private:
			Window* p_window;
	};
}



