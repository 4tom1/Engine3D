#include <iostream>

#include "Engine3D.h"
#include "Mesh.h"

constexpr float DIS = 1.0f;

class Demo : public E3D::Engine3D
{
	public:

		Demo() 
		{
			cube.triangles = { 
				
				// SOUTH
				{DIS,DIS,DIS, DIS,0,DIS, 0,0,DIS},
				{DIS,DIS,DIS, 0,0,DIS, 0,DIS,DIS},

				// EAST
				{0,DIS,DIS, 0,0,DIS, 0,0,0},
				{0,DIS,DIS, 0,0,0, 0,DIS,0},

				// NORTH
				{0,DIS,0, 0,0,0, DIS,0,0},
				{0,DIS,0, DIS,0,0, 0,DIS,0},

				// WEST
				{DIS,DIS,0, DIS,0,0, DIS,0,DIS},
				{DIS,DIS,0, DIS,0,DIS, DIS,DIS,DIS},

				// TOP
				{DIS,0,DIS, DIS,0,0, 0,0,0},
				{DIS,0,DIS, 0,0,0, 0,0,DIS},

				// BOTTOM
				{0,DIS,0, DIS,DIS,0, DIS,DIS,DIS},
				{0,DIS,0, DIS,DIS,DIS, 0,DIS,DIS}
			};

			cube.position.x = 0.0f;
			cube.position.y = 0.0f;
			cube.position.z = 3.0f;
		}

		void Update(float deltaTime) override 
		{
			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Up))
				cube.Rotate(rot_speed * deltaTime);

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Down))
				cube.Rotate(-rot_speed * deltaTime);

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Left))
				cube.Rotate(0.0f, rot_speed * deltaTime);

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Right))
				cube.Rotate(0.0f, -rot_speed * deltaTime);
			
			renderer.DrawMesh(cube);
		}

	private:
		E3D::Mesh cube;
		float rot_speed = 0.5f;
		float speed = 1.0f;
};

int main(int argc, char* argv[])
{
	Demo demo;
	demo.Run();
	return 0;
}