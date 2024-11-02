#include <chrono>
#include "Engine3D.h"

void E3D::Engine3D::Run()
{
	float deltaTime = 0.0f;

	while (true)
	{
		auto begin = std::chrono::high_resolution_clock::now();

		Update(deltaTime);

		window.Display();
		window.Input();

		auto end = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000.f;
	}
}