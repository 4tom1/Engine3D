#include "Engine3D.h"
#include "Mesh.h"

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
};

int main(int argc, char* argv[])
{
	Demo demo;
	demo.Run();
	return 0;
}