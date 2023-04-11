#pragma once
class Program
{
public:
	Program();
	~Program();

	// ������ Update �� Render�� �� �κ����� ������.
	void Update();
	void Render(HDC hdc);

	static HDC _backBuffer;

private:
	shared_ptr<Scene> _curScene;

	HBITMAP _hBit;
};

