#include "Enemy.h"

#include "../Game.h"
#include "../Components/SpriteComponent.h"
#include "../Components/NavComponent.h"
#include "Grid.h"
#include "Tile.h"
#include "../Components/CircleCollisionComponent.h"

#include <algorithm>

Enemy::Enemy(class Game* game)
	:Actor(game),
	mCircle(nullptr),
	mSprite(nullptr)
{
	// Add to enemy vector
	game->GetEnemies().emplace_back(this);

	SpriteComponent* spriteComp = new SpriteComponent(this);
	spriteComp->SetTexture(game->GetTexture("Assets/Airplane.png"));
	// Set position at start tile
	SetPosition(GetGame()->GetGrid()->GetStartTile()->GetPosition());
	// Setup a nav component at the start tile
	NavComponent* navComp = new NavComponent(this);
	navComp->SetForwardSpeed(150.0f);
	navComp->StartPath(GetGame()->GetGrid()->GetStartTile());
	// Setup a circle for collision
	mCircle = new CircleCollisionComponent(this);
	mCircle->SetRadius(25.0f);
}

Enemy::~Enemy()
{
	// Remove from enemy vector
	auto iter = std::find(GetGame()->GetEnemies().begin(),
		GetGame()->GetEnemies().end(),
		this);
	// GetGame()->RemoveSprite(this->mSprite);
	// GetGame()->RemoveActor(this);
	GetGame()->GetEnemies().erase(iter);

}

void Enemy::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	// Am I near the end tile?
	Vector2 diff = GetPosition() - GetGame()->GetGrid()->GetEndTile()->GetPosition();
	if (Math::NearZero(diff.Length(), 10.0f))
	{
		SetState(EDead);
	}
}
