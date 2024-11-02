#pragma once

#include <vector>

namespace E3D {

	struct vecf3 {
		float x, y, z;
	};

	typedef vecf3 Position;

	struct tri {
		vecf3 p1, p2, p3;
	};

	class Mesh {
		public:
			void Rotate(float x = 0.0f, float y = 0.0f, float z = 0.0f);

		private:
			void RotatePoint(vecf3& point, float x, float y, float z);

		public:
			std::vector<tri> tringles;
			Position position;
	};
}