#include "ModelLoader.h"

ModelLoader::ModelLoader(void)
{
	Model m = Model(background, "grass.jpg");
	models.push_back(m);
}

ModelLoader::~ModelLoader(void)
{
	models.clear();
}

void ModelLoader::LoadModel(std::string path, Model model)
{

}

std::vector<Model> ModelLoader::GetModels(void)
{
	return models;
}
