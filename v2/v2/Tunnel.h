#pragma once
#include "SuperObject.h"

class Tunnel : public SuperObject
{
public:
	Tunnel();
	~Tunnel();
	void Draw();
	bool GetRotating();
	void SetRotating(bool);

private:
	bool isRotating = false;
	float angle = 0;
};