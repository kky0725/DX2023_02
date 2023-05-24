#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
	: _radius(radius)
{
	CreateData();
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
    _transform->Update();
}

void CircleCollider::Render()
{
    _vertexBuffer->Set(0);

    _transform->SetBuffer(0); // vs

    _colorBuffer->SetPsBuffer(0); // ps

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set();
    _ps->Set();

    DC->Draw(_vertices.size(), 0);
}

void CircleCollider::CreateData()
{
    CreateVertices();

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());

    _vs = make_shared<VertexShader>(L"Shader/ColliderVS.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColliderPS.hlsl");

    _transform = make_shared<Transform>();

    _colorBuffer = make_shared<ColorBuffer>();
    SetGreen();
}

void CircleCollider::CreateVertices()
{
    float radian = 2.0f * PI / 36.0f;
    for (int i = 0; i < 37; i++)
    {
        Vertex temp;
        temp.pos = { XMFLOAT3(cos(radian * i) * _radius, sin(radian * i) * _radius, 0.0f) };
        _vertices.push_back(temp);
    }
}

bool CircleCollider::IsCollision(Vector2 pos)
{
    float distance = (_transform->GetWorldPosition() - pos).Length();
    return distance < GetWorldRadius();
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
    Vector2 center1 = _transform->GetWorldPosition();
    Vector2 center2 = other->_transform->GetWorldPosition();
    float distance = (center1 - center2).Length();
    return distance < GetWorldRadius() + other->GetWorldRadius();
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
    return other->IsCollision(shared_from_this());
}
