#include "CircleCollisionComponent.h"
#include "../Actor.h"

CircleCollisionComponent::CircleCollisionComponent(class Actor* owner)
	:Component(owner)
	, mRadius(0.0f)
{

}

const Vector2& CircleCollisionComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

float CircleCollisionComponent::GetRadius() const
{
	return mOwner->GetScale() * mRadius;
}

bool Intersect(const CircleCollisionComponent& a, const CircleCollisionComponent& b)
{
	// Calculate distance squared
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSq();

	// Calculate sum of radii squared
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}
