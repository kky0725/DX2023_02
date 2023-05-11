#include "framework.h"
#include "Program.h"
#include "../Scence/TutorialScene.h"

Program::Program()
{
	_curScene = make_shared<TutorialScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	_curScene->Update();
}

void Program::Render()
{
	_curScene->Render();
}
