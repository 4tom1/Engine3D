#pragma once

#include "Window.h"
#include "Renderer.h"
#include "Mesh.h"

namespace E3D {

	class Engine3D
	{
		public:

			Engine3D() : renderer(window) {}

			virtual void Update(float deltaTime) = 0;

			void Run();

		public:
			Renderer renderer;
			Window window;

		private:

	};
}