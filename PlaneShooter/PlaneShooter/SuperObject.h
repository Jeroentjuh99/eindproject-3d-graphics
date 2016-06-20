#pragma once
#include "ModelLoader.h"
#include <string>
#include <array>

class SuperObject : public ModelLoader
{
public:
	SuperObject(std::string);
	~SuperObject();
	void SetLocation(float, float, float);
	void SetRotation(float, float, float);
	Vec3f* GetLocation(void) const;
	std::array <float, 3> GetLocationFloat() const;
	Vec3f* GetRotation(void) const;
	std::array <float, 3> GetRotationFloat() const;
	void SetColor(const float, const float, const float);
	void Draw(void);
	void SetZLocation(float) const;
	float GetZLocation();

protected:
	Vec3f *location, *rotation;
	float color[3] = { 1.0f, 1.0f, 1.0f };
};