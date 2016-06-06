#pragma once
#include "Model.h"
#include <string>

class plane: public Model {
	plane(std::string, int, Vec3f);
};