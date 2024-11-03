#include "Renderer.h"

void E3D::Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float length = sqrtf(dx * dx + dy * dy);
	float atg = atan2f(dy, dx);

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
	for (auto tri : mesh.triangles)
	{	
		for (int i = 0; i < 3; i++)
		{
			tri.p[i].x += mesh.position.x;
			tri.p[i].y += mesh.position.y;
			tri.p[i].z += mesh.position.z;
			
			Projection3D(tri.p[i]);

			tri.p[i].x += 1.0f;
			tri.p[i].y += 1.0f;
			tri.p[i].x *= 0.25f * p_window->GetWidth();
			tri.p[i].y *= 0.25f * p_window->GetHight();
		}

		DrawTriangle(tri);
	}
}

#include <iostream>

void E3D::Renderer::Projection3D(vec3f& point) const
{
	float tg = tanf(fov * 0.5f);
	point.z = point.z * (far / (far - near)) - ((far * near) / (far - near));
	
	if (point.z != 0)
	{
		point.x = (aspectRatio * point.x) / (tg * point.z);
		point.y = (aspectRatio * point.y) / (tg * point.z);
	}
}