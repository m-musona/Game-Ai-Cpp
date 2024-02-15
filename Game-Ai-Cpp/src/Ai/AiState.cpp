#include "AiState.h"

#include "../Components/AiComponent.h"

#include "SDL/SDL_log.h"

void AiPatrol::Update(float deltaTime)
{
	SDL_Log("Updating %s state", GetName());

	bool dead = true;/* Figure ot if I'm dead */

	if (dead)
	{
		// Tell the ai component to change states

		mOwner->ChangeState("Death");
	}
}
void AiPatrol::OnEnter()
{
	SDL_Log("Entering %s state", GetName());
}

void AiPatrol::OnExit()
{
	SDL_Log("Exiting %s state", GetName());
}

void AiDeath::Update(float deltaTime)
{
	SDL_Log("Updating %s state", GetName());
}

void AiDeath::OnEnter()
{
	SDL_Log("Entering %s state", GetName());
}

void AiDeath::OnExit()
{
	SDL_Log("Exiting %s state", GetName());
}

void AiAttack::Update(float deltaTime)
{
	SDL_Log("Updating %s state", GetName());
}

void AiAttack::OnEnter()
{
	SDL_Log("Entering %s state", GetName());
}

void AiAttack::OnExit()
{
	SDL_Log("Exiting %s state", GetName());
}
