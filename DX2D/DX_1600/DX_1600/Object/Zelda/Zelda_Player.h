#pragma once
class Link_Ani;

class Zelda_Player
{
public:
	Zelda_Player();
	~Zelda_Player();

	void Update();
	void Render();
	void PostRender();

	void Move(Vector2 movePos) { _collider->GetTransform()->AddVector2(movePos); }
	void Input();


private:
	shared_ptr<Link_Ani> _animation;

	shared_ptr<RectCollider> _collider;
	int _hp = 200;
	float _speed = 200.0f;
};

