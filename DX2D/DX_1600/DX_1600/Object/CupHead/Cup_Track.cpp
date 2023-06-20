#include "framework.h"
#include "Cup_Track.h"

Cup_Track::Cup_Track()
{
	_track = make_shared<Quad>(L"Resource/CupHead/track.png");
	_transform = make_shared<Transform>();
	_trackSize = _track->GetQuadHalfSize();
	_collider = make_shared<RectCollider>(_trackSize * 2.0f);

	_transform->SetParent(_collider->GetTransform());
	_transform->SetPosition(Vector2(0, 75));

	_collider->GetTransform()->SetPosition(Vector2(0.0f, CENTER.y * -1.0f));
	_transform->Update();
}

Cup_Track::Cup_Track(Vector2 value)
{
	_track = make_shared<Quad>(L"Resource/CupHead/track.png");
	_transform = make_shared<Transform>();
	_trackSize = _track->GetQuadHalfSize();
	_collider = make_shared<RectCollider>(_trackSize * 2.0f);

	_transform->SetParent(_collider->GetTransform());
	_transform->SetPosition(Vector2(0, 75));

	_collider->GetTransform()->SetPosition(value);
	_transform->Update();
}

Cup_Track::~Cup_Track()
{
}

void Cup_Track::Update()
{
	_collider->Update();
}

void Cup_Track::Render()
{
	_transform->SetBuffer(0);
	_track->Render();
	_collider->Render();
}

void Cup_Track::PostRender()
{
}
