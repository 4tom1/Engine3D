#include <iostream>

#include "Engine3D.h"
#include "Mesh.h"

constexpr float DIS = 0.5f;

class Demo : public E3D::Engine3D
{
	public:

		Demo() 
		{
			cube.triangles = { 
				
				// SOUTH
				{DIS,DIS,DIS, DIS,DIS * -1.0f,DIS,DIS * -1.0f,DIS * -1.0f,DIS},
				{DIS,DIS,DIS, DIS * -1.0f,DIS * -1.0f,DIS, DIS * -1.0f,DIS,DIS},

				// EAST
				{DIS * -1.0f,DIS,DIS, DIS * -1.0f,DIS * -1.0f,DIS, DIS * -1.0f,DIS * -1.0f,DIS * -1.0f},
				{DIS * -1.0f,DIS,DIS, DIS * -1.0f,DIS * -1.0f,DIS * -1.0f, DIS * -1.0f,DIS,DIS * -1.0f},

				// NORTH
				{DIS * -1.0f,DIS,DIS * -1.0f, DIS * -1.0f,DIS * -1.0f,DIS * -1.0f, DIS,DIS * -1.0f,DIS * -1.0f},
				{DIS * -1.0f,DIS,DIS * -1.0f, DIS,DIS * -1.0f,DIS * -1.0f, DIS * -1.0f,DIS,DIS * -1.0f},

				// WEST
				{DIS,DIS,DIS * -1.0f, DIS,DIS * -1.0f,DIS * -1.0f, DIS,DIS * -1.0f,DIS},
				{DIS,DIS,DIS * -1.0f, DIS,DIS * -1.0f,DIS, DIS,DIS,DIS},

				// TOP
				{DIS,DIS * -1.0f,DIS, DIS,DIS * -1.0f,DIS * -1.0f, DIS * -1.0f,DIS * -1.0f,DIS * -1.0f},
				{DIS,DIS * -1.0f,DIS, DIS * -1.0f,DIS * -1.0f,DIS * -1.0f, DIS * -1.0f,DIS * -1.0f,DIS},

				// BOTTOM
				{DIS * -1.0f,DIS,DIS * -1.0f, DIS,DIS,DIS * -1.0f, DIS,DIS,DIS},
				{DIS * -1.0f,DIS,DIS * -1.0f, DIS,DIS,DIS, DIS * -1.0f,DIS,DIS},
			};

			cube.position.x = 0.5f;
			cube.position.y = 0.5f;
			cube.position.z = 3.0f;
		}

		void Update(float deltaTime) override 
		{		
			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Up))
			{
				cube.Rotate(rot_speed * deltaTime);
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Down))
			{
				cube.Rotate(-rot_speed * deltaTime);
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Left))
			{
				cube.Rotate(0.0f, rot_speed * deltaTime);
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::Right))
			{
				cube.Rotate(0.0f, -rot_speed * deltaTime);
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::W))
			{
				cube.position.z += speed * deltaTime;
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::S))
			{
				cube.position.z -= speed * deltaTime;
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::A))
			{
				cube.position.x += speed * deltaTime;
			}

			if (E3D::Keyboard::GetInstance().GetKeyRef(E3D::D))
			{
				cube.position.x -= speed * deltaTime;
			}
			
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