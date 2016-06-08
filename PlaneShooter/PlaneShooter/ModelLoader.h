#pragma once
#include <string>
#include <vector>
#include <list>
#include <GL/freeglut.h>
#include "Texture.h"

class Vec3f {
public:
	union {
		struct {
			float x, y, z;
		};
		float v[3];
	};
	Vec3f();
	Vec3f(Vec3f &);
	Vec3f(float, float, float);
	float & operator[](int);
};

class Vec2f {
public:
	union {
		struct {
			float x, y;
		};
		float v[2];
	};
	Vec2f();
	Vec2f(Vec2f &);
	Vec2f(float, float);
	float & operator [](int);
};

class ModelLoader {
private:
	class Vertex {
	public:
		int position, normal, texcoord;
	};

	class Face {
	public:
		std::list<Vertex> vertices;
	};

	class MaterialInfo {
	public:
		MaterialInfo();
		std::string name;
		bool hasTexture;
		Texture *texture;
		GLfloat ambient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat diffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
		GLfloat specular[4] = { 0, 0, 0, 1.0f };
		GLfloat shininess[1] = { 0 };
		GLfloat emission[4] = { 0, 0, 0, 1 };
	};

	class ObjGroup {
	public:
		std::string name;
		int materialIndex;
		std::list<Face> faces;
	};

	std::vector<Vec3f> vertices, normals;
	std::vector<Vec2f> texcoords;
	std::vector<ObjGroup*> groups;
	std::vector<MaterialInfo*> materials;

	void loadMaterialFile(std::string fileName, std::string dirName);
public:
	ModelLoader(std::string filename);
	~ModelLoader(void);

	void draw();
};