#include "SuperObject.h"

SuperObject::SuperObject(std::string path, bool needsDrawOverTexture) : ModelLoader(path)
{
	color[0] = 0.0f;
	color[1] = 0.0f;
	color[2] = 0.0f;
	this->needsDrawOverTexture = needsDrawOverTexture;
}

SuperObject::~SuperObject()
{
}

void SuperObject::SetLocation(float x, float y, float z)
{
	location[0] = x;
	location[1] = y;
	location[2] = z;
}

void SuperObject::SetRotation(float rx, float ry, float rz)
{
	rotation[0] = rx;
	rotation[1] = ry;
	rotation[2] = rz;
}

std::array<float, 3> SuperObject::GetLocation()
{
	std::array <float, 3> temp = std::array<float, 3>();
	temp[0] = location[0];
	temp[1] = location[1];
	temp[2] = location[2];
	return temp;
}

std::array<float, 3> SuperObject::GetRotation()
{
	std::array <float, 3> temp = std::array<float, 3>();
	temp[0] = rotation[0];
	temp[1] = rotation[1];
	temp[2] = rotation[2];
	return temp;
}

void SuperObject::SetColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

std::array<float, 3> SuperObject::GetColor()
{
	std::array <float, 3> temp = std::array<float, 3>();
	temp[0] = color[0];
	temp[1] = color[1];
	temp[2] = color[2];
	return temp;
}

void SuperObject::Draw()
{
	if (needsDrawOverTexture) {
		glEnable(GL_COLOR_MATERIAL);
		glColor3f(color[0], color[1], color[2]);
		__super::draw();
		glDisable(GL_COLOR_MATERIAL);
	} else
	{
		__super::draw();
	}
}
