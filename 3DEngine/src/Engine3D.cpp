#include <chrono>
#include <iostream>
#include "Engine3D.h"

void E3D::Engine3D::Run()
{	
	float preDeltaTime = 0.0f;
	float deltaTime = 0.0f;
	float timer = 0.0f;

	while (true)
	{
		auto begin = std::chrono::high_resolution_clock::now();

		Update(deltaTime);

		window.Display();
		window.Input();

		auto end = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.f;

		// Debug

		if (m_fpsCounter)
		{
			timer += deltaTime;

			if (timer >= 1)
			{
				std::cout << 1.0f / deltaTime << " fps" << std::endl;
				timer = 0.0f;
			}
		}
	}
}