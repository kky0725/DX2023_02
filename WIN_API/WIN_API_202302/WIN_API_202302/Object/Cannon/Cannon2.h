#pragma once
class Cannon2 : public Cannon
{
public:
	Cannon2(Vector2 pos) :Cannon(pos) {}
	virtual ~Cannon2() {}

	virtual void Move() override;
	virtual void Angle() override;
	virtual void Fire() override;


private:

};

