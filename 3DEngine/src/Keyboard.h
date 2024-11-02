#pragma once

namespace E3D {

	enum Key {
		Up,
		Down,
		Left,
		Right,
		W,
		S,
		D,
		A,
	};

	class Keyboard
	{
		public:
			static Keyboard& GetInstance();
			bool& GetKeyRef(Key key);
			
		private:
			bool keyboard_map[8];
	};
}