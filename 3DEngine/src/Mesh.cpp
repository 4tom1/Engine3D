#include "Mesh.h"

void E3D::Mesh::Rotate(float x, float y, float z)
{
	for (Tri& tri : triangles)
	{
		for (int i = 0; i < 3; i++)
		{
			RotatePoint(tri.p[i], x, y, z);
		}
	}
}

void E3D::Mesh::RotatePoint(vec3f& point, float x, float y, float z)
{
	float rad = 0;

	rad = x;
	point.y = cosf(rad) * point.y - sinf(rad) * point.z;
	point.z = sinf(rad) * point.y + cosf(rad) * point.z;

	rad = y;
	point.x = cosf(rad) * point.x + sinf(rad) * point.z;
	point.z = -sinf(rad) * point.x + cosf(rad) * point.z;

	rad = z;
	point.x = cosf(rad) * point.x - sinf(rad) * point.y;
	point.y = sinf(rad) * point.x + cosf(rad) * point.y;
}