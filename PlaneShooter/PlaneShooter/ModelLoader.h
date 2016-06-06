#pragma once

#include <vector>
#include "Model.h"
#include <string>

class ModelLoader
{
public:
	ModelLoader(void);
	~ModelLoader(void);
	void LoadModel(std::string, Model);
	std::vector<Model> GetModels(void);

private:
	std::vector<Model> models;
};
