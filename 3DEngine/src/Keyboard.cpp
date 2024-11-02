#include "Keyboard.h"

E3D::Keyboard& E3D::Keyboard::GetInstance()
{
	static Keyboard keyboard;
	return keyboard;
}

bool& E3D::Keyboard::GetKeyRef(E3D::Key key)
{
	return keyboard_map[key];
}