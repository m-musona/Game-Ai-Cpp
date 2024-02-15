#pragma once

#include "../Actor.h"

class Enemy : public Actor
{
public:
	Enemy(class Game* game);
	~Enemy();
	void UpdateActor(float deltaTime) override;
	class CircleCollisionComponent* GetCircle() { return mCircle; }
private:
	class CircleCollisionComponent* mCircle;
	class SpriteComponent* mSprite;
};