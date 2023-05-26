#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector2 size)
	: _size(size), Collider(ColliderType::RECT)
{
    CreateVertices();
    Collider::CreateData();
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
    Collider::Update();
}

void RectCollider::Render()
{
    Collider::Render();
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

RectCollider::AABBRectInfo RectCollider::GetAABBInfo()
{
    AABBRectInfo result;
    result.left     = _transform->GetWorldPosition().x - GetWorldSize().x * 0.5f;
    result.right    = _transform->GetWorldPosition().x + GetWorldSize().x * 0.5f;
    result.top      = _transform->GetWorldPosition().y + GetWorldSize().y * 0.5f;
    result.bottom   = _transform->GetWorldPosition().y - GetWorldSize().y * 0.5f;

    return result;
}

RectCollider::OBBRectInfo RectCollider::GetOBBInfo()
{
    OBBRectInfo info;

    info.worldPos = _transform->GetWorldPosition();

    XMFLOAT4X4 matrix;
    XMStoreFloat4x4(&matrix, _transform->GetMartix());
    info.direction[0] = {matrix._11, matrix._12};
    info.direction[1] = {matrix._21, matrix._22};

    info.lenght[0] = GetWorldSize().x * 0.5f;
    info.lenght[1] = GetWorldSize().y * 0.5f;

    return info;
}

bool RectCollider::IsCollision(const Vector2& pos)
{
    AABBRectInfo info = GetAABBInfo();

    if (pos.x < info.left || pos.x > info.right)
        return false;
    else if (pos.y > info.top || pos.y < info.bottom)
        return false;
    return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
    AABBRectInfo info = GetAABBInfo();

    Vector2 leftTop     = Vector2(info.left, info.top);
    Vector2 rightTop    = Vector2(info.right, info.top);
    Vector2 leftBottom  = Vector2(info.left, info.bottom);
    Vector2 rightBottom = Vector2(info.right, info.bottom);
    if (other->IsCollision(leftTop) || other->IsCollision(rightTop) || other->IsCollision(leftBottom) || other->IsCollision(rightBottom))
        return true;

    if (info.right > other->GetTransform()->GetWorldPosition().x && info.left < other->GetTransform()->GetWorldPosition().x)
    {
        if (info.top + other->GetWorldRadius() > other->GetTransform()->GetWorldPosition().y
            && info.bottom - other->GetWorldRadius() < other->GetTransform()->GetWorldPosition().y)
            return true;
    }
    if (info.bottom < other->GetTransform()->GetWorldPosition().y && info.top > other->GetTransform()->GetWorldPosition().y)
    {
        if (info.left - other->GetWorldRadius() < other->GetTransform()->GetWorldPosition().x
            && info.right + other->GetWorldRadius() > other->GetTransform()->GetWorldPosition().x)
            return true;
    }
    return false;
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

bool RectCollider::Block(shared_ptr<RectCollider> moveable)
{
    if (!IsCollision(moveable))
        return false;

    Vector2 moveableCenter = moveable->GetTransform()->GetWorldPosition();
    Vector2 blockCenter = GetTransform()->GetWorldPosition();
    Vector2 sum = (this->GetWorldSize() + moveable->GetWorldSize()) * 0.5f;
    Vector2 dir = moveableCenter - blockCenter;
    Vector2 overlap = Vector2(sum.x - abs(dir.x) , sum.y - abs(dir.y));

    Vector2 fixedPos = moveable->GetTransform()->GetPos();

    if (overlap.x < overlap.y )
    {
        float scalar = overlap.x;
        if (dir.x < 0)
            scalar *= -1;

        fixedPos.x += scalar;

        moveable->GetTransform()->AddVector2(Vector2(scalar, 0.0f));
    }
    else
    {
        float scalar = overlap.y;
        if (dir.y < 0)
            scalar *= -1;
        fixedPos.y += scalar;

        moveable->GetTransform()->AddVector2(Vector2(0.0f, scalar));
    }
    //moveable->SetPosition(fixedPos);

    return true;
}

bool RectCollider::Block(shared_ptr<CircleCollider> moveable)
{
    if (!IsCollision(moveable))
        return false;

    Vector2 moveableCenter = moveable->GetTransform()->GetWorldPosition();
    Vector2 blockCenter = GetTransform()->GetWorldPosition();
    Vector2 virtuaHalfSize = Vector2(moveable->GetWorldRadius(), moveable->GetWorldRadius());
    Vector2 sum = this->GetWorldSize() * 0.5f + virtuaHalfSize;
    Vector2 dir = moveableCenter - blockCenter;
    Vector2 overlap = Vector2(sum.x - abs(dir.x), sum.y - abs(dir.y));

    Vector2 fixedPos = moveable->GetTransform()->GetPos();

    if (overlap.x < overlap.y)
    {
        float scalar = overlap.x;
        if (dir.x < 0)
            scalar *= -1;

        fixedPos.x += scalar;

       // moveable->GetTransform()->AddVector2(Vector2(scalar, 0.0f));
    }
    else
    {
        float scalar = overlap.y;
        if (dir.y < 0)
            scalar *= -1;
        fixedPos.y += scalar;

       // moveable->GetTransform()->AddVector2(Vector2(0.0f, scalar));
    }
    moveable->SetPosition(fixedPos);

    return true;
}
