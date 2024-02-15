#include "Bullet.h"

#include "../Components/SpriteComponent.h"
#include "../Components/MoveComponent.h"
#include "../Components/CircleCollisionComponent.h"
#include "../Game.h"
#include "Enemy.h"

Bullet::Bullet(class Game* game)
	:Actor(game),
	mCircle(nullptr),
	mSprite(nullptr)
{
	SpriteComponent* spriteComp = new SpriteComponent(this);
	spriteComp->SetTexture(game->GetTexture("Assets/Projectile.png"));

	MoveComponent* moveComp = new MoveComponent(this);
	moveComp->SetForwardSpeed(400.0f);

	mCircle = new CircleCollisionComponent(this);
	mCircle->SetRadius(5.0f);

	mLiveTime = 1.0f;
}

Bullet::~Bullet()
{
	GetGame()->RemoveSprite(this->mSprite);
	GetGame()->RemoveActor(this);
}

void Bullet::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	// Check for collision vs enemies
	for (Enemy* e : GetGame()->GetEnemies())
	{
		if (Intersect(*mCircle, *(e->GetCircle())))
		{
			// We both die on collision
			e->SetState(EDead);
			SetState(EDead);
			break;
		}
	}

	mLiveTime -= deltaTime;
	if (mLiveTime <= 0.0f)
	{
		// Time limit hit, die
		SetState(EDead);
	}
}
