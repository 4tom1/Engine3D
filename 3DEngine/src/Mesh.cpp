#include "Mesh.h"

void E3D::Mesh::Rotate(float x, float y, float z)
{
	for (Tri& tri : triangles)
	{
		for (int i = 0; i < 3; i++)
		{
			tri.p[i].x += position.x;
			tri.p[i].y += position.y;
			tri.p[i].z += position.z;

			RotatePoint(tri.p[i], x, y, z);

			tri.p[i].x -= position.x;
			tri.p[i].y -= position.y;
			tri.p[i].z -= position.z;
		}
	}
}

inline void E3D::Mesh::RotatePoint(vec3f& point, float x, float y, float z)
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