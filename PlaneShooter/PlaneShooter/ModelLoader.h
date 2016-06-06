#pragma once

#include <vector>
#include "Model.h"
#include <string>

class ModelLoader
{
public:
	ModelLoader(void);
	~ModelLoader(void);
	std::vector<Model> GetModels(void);

private:
	std::vector<Model> models;
	void LoadModel(std::string, Model);
};
