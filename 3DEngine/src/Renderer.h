#pragma once

#include "Window.h"
#include "Mesh.h"

namespace E3D {

	class Renderer
	{
		public:
			
			Renderer(Window& window) : p_window(&window) {}

			void DrawMesh(const Mesh& mesh);

		public:
			float fov = 90.0f;
			float far = 1000.0f;
			float near = 0.1f;

		private:
			inline void Projection3D(vec3f& point) const;
			inline void DrawTriangle(const Tri& tri);
			inline void DrawLine(float x1, float y1, float x2, float y2);

		private:
			Window* p_window;
	};
}



