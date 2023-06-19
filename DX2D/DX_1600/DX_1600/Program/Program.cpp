#include "framework.h"
#include "Program.h"
#include "../Scence/BagicScene/TutorialScene.h"
#include "../Scence/BagicScene/SolarSystem.h"
#include "../Scence/BagicScene/DungreedScene.h"
#include "../Scence/BagicScene/ColliderScene.h"
#include "../Scence/BagicScene/SpriteScene.h"
#include "../Scence/BagicScene/ActionScene.h"
#include "../Scence/BagicScene/CupHeadScene.h"
#include "../Scence/BagicScene/EffectScene.h"

Program::Program()
{
	srand((unsigned int)time(nullptr));

	_curScene = make_shared<CupHeadScene>();

	Timer::GetInstance()->SetLockFPS(60.0);
}

Program::~Program()
{
}

void Program::Update()
{
	InputManager::GetInstance()->Update();
	Timer::GetInstance()->Update();
	Sound::GetInstance()->Update();
	CAMERA->Update();

	_curScene->Collider_Update();
	_curScene->Update();

	EffectManager::GetInstance()->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	CAMERA->SetCameraBuffer();
	CAMERA->SetProjectionBuffer();

	ALPHA->SetState();

	_curScene->Render();
	EffectManager::GetInstance()->Render();

	ImGui::Text("FPS : %d", Timer::GetInstance()->GetFPS());

	CAMERA->PostRender();
	_curScene->PostRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
