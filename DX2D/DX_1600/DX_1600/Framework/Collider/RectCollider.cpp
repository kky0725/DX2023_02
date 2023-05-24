#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 size)
	: _size(size)
{
    CreateData();
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
    _transform->Update();
}

void RectCollider::Render()
{
    _vertexBuffer->Set(0);

    _transform->SetBuffer(0);

    _colorBuffer->SetPsBuffer(0);


    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set();
    _ps->Set();

    DC->Draw(_vertices.size(), 0);
}

void RectCollider::CreateData()
{
    CreateVertices();

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());

    _vs = make_shared<VertexShader>(L"Shader/ColliderVS.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColliderPS.hlsl");

    _transform = make_shared<Transform>();
    _colorBuffer = make_shared<ColorBuffer>();
    SetGreen();
}

void RectCollider::CreateVertices()
{
    Vertex temp;
    Vector2 halfSize;
    halfSize.x = _size.x * 0.5f;
    halfSize.y = _size.y * 0.5f;

    temp.pos = { XMFLOAT3(-halfSize.x, halfSize.y, 0.0f) };
    _vertices.push_back(temp);

    temp.pos = { XMFLOAT3(halfSize.x, halfSize.y, 0.0f) };

    _vertices.push_back(temp);

    temp.pos = { XMFLOAT3(halfSize.x, -halfSize.y, 0.0f) };
    _vertices.push_back(temp);

    temp.pos = { XMFLOAT3(-halfSize.x, -halfSize.y, 0.0f) };
    _vertices.push_back(temp);

    temp.pos = { XMFLOAT3(-halfSize.x, halfSize.y, 0.0f) };
    _vertices.push_back(temp);
}

bool RectCollider::IsCollision(Vector2 pos)
{
    if (pos.x < Left() || pos.x > Right())
        return false;
    else if (pos.y < Top() || pos.y > Bottom())
        return false;
    return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
    Vector2 rectCenter = _transform->GetWorldPosition();
    Vector2 circleCenter = other->GetTransform()->GetWorldPosition();
    Vector2 distance = this->GetWorldSize() * 0.5f + Vector2(other->GetRadius(), other->GetRadius());

    Vector2 leftTop     = Vector2(Left(), Top());
    Vector2 rightTop    = Vector2(Right(), Top());
    Vector2 leftBottom  = Vector2(Left(), Bottom());
    Vector2 rightBottom = Vector2(Right(), Bottom());
    if (other->IsCollision(leftTop) || other->IsCollision(rightTop) || other->IsCollision(leftBottom) || other->IsCollision(rightBottom))
        return true;

    if (abs(rectCenter.x - circleCenter.x) > distance.x)
        return false;
    else if (abs(rectCenter.y - circleCenter.y) > distance.y)
        return false;
    else
        return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
    Vector2 center1 = _transform->GetWorldPosition();
    Vector2 center2 = other->GetTransform()->GetWorldPosition();
    Vector2 distance = (this->GetWorldSize() + other->GetWorldSize())* 0.5f;
    if (abs(center1.x - center2.x) > distance.x)
        return false;
    else if (abs(center1.y - center2.y) > distance.y)
        return false;
    else
        return true;
}