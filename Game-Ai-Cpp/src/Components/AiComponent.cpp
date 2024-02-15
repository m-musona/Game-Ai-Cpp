#include "AiComponent.h"

#include "../Actor.h"
#include "../Ai/AiState.h"

#include "SDL/SDL_log.h"

AiComponent::AiComponent(class Actor* owner)
	:Component(owner)
{
}

void AiComponent::Update(float deltatime)
{
	if (mCurrentState)
	{
		mCurrentState->Update(deltatime);
	}
}

void AiComponent::ChangeState(const std::string& name)
{
	// First exit the current state
	if (mCurrentState)
	{
		mCurrentState->OnExit();
	}

	// Try to find the new state from the map
	auto iter = mStateMap.find(name);
	if (iter != mStateMap.end())
	{
		mCurrentState = iter->second;
		// We're entering the new state
		mCurrentState->OnEnter();
	}
	else
	{
		SDL_Log("Could not find AiState %s in state map", name.c_str());
		mCurrentState = nullptr;
	}
}

void AiComponent::RegisterState(AiState* state)
{
	mStateMap.emplace(state->GetName(), state);
}
