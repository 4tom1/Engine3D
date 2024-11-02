#include "Engine3D.h"
#include "Mesh.h"

#include <iostream>

#define DIS -50

class Demo : public E3D::Engine3D
{
	public:

		Demo() 
		{
			cube.tringles = {
				// SOUTH
				{{DIS,DIS,DIS}, {DIS,DIS * -1,DIS}, {DIS * -1,DIS * -1,DIS}},
				{{DIS,DIS,DIS}, {DIS * -1,DIS * -1,DIS}, {DIS * -1,DIS,DIS}},

				// EAST
				{{DIS * -1,DIS,DIS}, {DIS * -1,DIS * -1,DIS}, {DIS * -1,DIS * -1,DIS * -1}},
				{{DIS * -1,DIS,DIS}, {DIS * -1,DIS * -1,DIS * -1}, {DIS * -1,DIS,DIS * -1}},

				// NORTH
				{{DIS * -1,DIS,DIS * -1}, {DIS * -1,DIS * -1,DIS * -1}, {DIS,DIS * -1,DIS * -1}},
				{{DIS * -1,DIS,DIS * -1}, {DIS,DIS * -1,DIS * -1}, {DIS * -1,DIS,DIS * -1}},

				// WEST
				{{DIS,DIS,DIS * -1}, {DIS,DIS * -1,DIS * -1}, {DIS,DIS * -1,DIS}},
				{{DIS,DIS,DIS * -1}, {DIS,DIS * -1,DIS}, {DIS,DIS,DIS}},

				// TOP
				{{DIS,DIS * -1,DIS}, {DIS,DIS * -1,DIS * -1}, {DIS * -1,DIS * -1,DIS * -1}},
				{{DIS,DIS * -1,DIS}, {DIS * -1,DIS * -1,DIS * -1}, {DIS * -1,DIS * -1,DIS}},

				// BOTTOM
				{{DIS * -1,DIS,DIS * -1}, {DIS,DIS,DIS * -1}, {DIS,DIS,DIS}},
				{{DIS * -1,DIS,DIS * -1}, {DIS,DIS,DIS}, {DIS * -1,DIS,DIS}}
			};

			cube.position.x = window.GetWidth() / 4;
			cube.position.y = window.GetHight() / 4;
		}

		void Update(float deltaTime) override 
		{
			std::cout << deltaTime * 1000.f << " ms" << std::endl;
			cube.Rotate(0.5f * deltaTime, 0.7f * deltaTime, 0.3f * deltaTime);
			renderer.DrawMesh(cube);
		}

	private:
		E3D::Mesh cube;
};

int main(int argc, char* argv[])
{
	Demo demo;
	demo.Run();
	return 0;
}