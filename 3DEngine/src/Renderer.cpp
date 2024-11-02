#include "Renderer.h"

void E3D::Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float length = sqrtf(dx * dx + dy * dy);
	float atg = atan2(dy, dx);

	for (float i = 0; i < length; i++)
	{
		p_window->Pixel(
			x1 + cosf(atg) * i,
			y1 + sinf(atg) * i
		);
	}
}

void E3D::Renderer::DrawTriangle(const Tri& tri)
{
	DrawLine(tri.p[0].x, tri.p[0].y, tri.p[1].x, tri.p[1].y);
	DrawLine(tri.p[0].x, tri.p[0].y, tri.p[2].x, tri.p[2].y);
	DrawLine(tri.p[1].x, tri.p[1].y, tri.p[2].x, tri.p[2].y);
}

void E3D::Renderer::DrawMesh(const Mesh& mesh)
{
	for (auto& tri : mesh.triangles)
	{	
		Tri transformed;
		
		for (int i = 0; i < 3; i++)
		{
			Projection3D(tri.p[i], transformed.p[i]);

			transformed.p[i].x += mesh.position.x;
			transformed.p[i].y += mesh.position.y;
			transformed.p[i].z += mesh.position.z;
		}

		DrawTriangle(transformed);
	}
}

void E3D::Renderer::Projection3D(const vec3f& ipoint, vec3f& opoint)
{
	float tg = tanf(fov / 2);
	opoint.z = ipoint.z * (far / (far - near)) - ((far * near) / (far - near));
	
	opoint.x = (aspect_ratio * ipoint.x) / (tg * opoint.z);
	opoint.y = (aspect_ratio * ipoint.y) / (tg * opoint.z);
}