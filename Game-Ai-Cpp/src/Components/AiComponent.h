#pragma once
#include "../Component.h"

#include <unordered_map>
#include <string>


class AiComponent : public Component
{
public:
	AiComponent(class Actor* owner);

	void Update(float deltatime) override;
	void ChangeState(const std::string& name);

	// Add a new state to the map
	void RegisterState(class AiState* state);

private:
	// Maps name of state to AiState instance
	std::unordered_map<std::string, class AiState*> mStateMap;

	// Current state we are in
	class AiState* mCurrentState;
};