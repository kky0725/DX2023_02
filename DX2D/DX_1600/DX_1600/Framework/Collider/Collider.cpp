#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
    return false;
}
