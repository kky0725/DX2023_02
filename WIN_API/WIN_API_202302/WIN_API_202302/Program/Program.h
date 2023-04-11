#pragma once
class Program
{
public:
	Program();
	~Program();

	// 게임은 Update 와 Render가 두 부분으로 갈린다.
	void Update();
	void Render(HDC hdc);

	static HDC _backBuffer;

private:
	shared_ptr<Scene> _curScene;

	HBITMAP _hBit;
};

