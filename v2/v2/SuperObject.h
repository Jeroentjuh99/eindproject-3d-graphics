#pragma once
#include "ModelLoader.h"
#include <string>
#include <array>

class SuperObject : public ModelLoader
{
public:
	SuperObject(std::string, bool);
	~SuperObject();
	void SetLocation(float, float, float);
	void SetRotation(float, float, float);
	std::array<float, 3> GetLocation();
	std::array <float, 3> GetRotation();
	void SetColor(float, float, float);
	std::array<float, 3> GetColor();
	void Draw();

protected:
	float location[3], rotation[3], color[3];
	bool needsDrawOverTexture = false;
};