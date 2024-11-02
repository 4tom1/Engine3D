#pragma once

#include <vector>

namespace E3D {

	struct vec3f {
		float x, y, z;
	};

	typedef vec3f Position;

	struct Tri {
		vec3f p[3];
	};

	class Mesh {
		public:
			void Rotate(float x = 0.0f, float y = 0.0f, float z = 0.0f);

		private:
			void RotatePoint(vec3f& point, float x, float y, float z);

		public:
			std::vector<Tri> triangles;
			Position position;
	};
}