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

void E3D::Renderer::DrawMesh(Mesh& mesh)
{
	for (auto& t : mesh.tringles)
	{
		DrawLine(t.p1.x + mesh.position.x, t.p1.y + mesh.position.y, t.p2.x + mesh.position.x, t.p2.y + mesh.position.y);
		DrawLine(t.p1.x + mesh.position.x, t.p1.y + mesh.position.y, t.p3.x + mesh.position.x, t.p3.y + mesh.position.y);
		DrawLine(t.p2.x + mesh.position.x, t.p2.y + mesh.position.y, t.p3.x + mesh.position.x, t.p3.y + mesh.position.y);
	}
}