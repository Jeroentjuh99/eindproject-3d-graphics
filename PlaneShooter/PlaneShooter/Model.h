#pragma once
#include <string>

#define background 0
#define player 1
#define enemy 2
#define playerProjectile 3
#define enemyProjectile 4

class Vec3f
{
public:
	union
	{
		struct
		{
			float x, y, z;
		};
		float v[3];
	};
	Vec3f();
	Vec3f(Vec3f &other);
	Vec3f(float x, float y, float z);
	float& operator [](int);
};

class Vec2f
{
public:
	union
	{
		struct
		{
			float x, y;
		};
		float v[2];
	};
	Vec2f();
	Vec2f(float x, float y);
	Vec2f(Vec2f &other);
	float& operator [](int);
};


class Model {
public:
	Model(std::string, int, Vec3f);
	Model(int, std::string);
	void Draw(void);

private:
	int type;
	
};