#pragma once
class Program
{
public:
	Program();
	~Program();

	// ������ Update �� Render�� �� �κ����� ������.
	void Update();
	void Render(HDC hdc);

private:
	shared_ptr<Scene> _curScene;
};

