#pragma once

class AiState
{
public:
	AiState(class AiComponent* owner)
		: mOwner(owner)
	{ }

	// State-Specific behaviour
	virtual void Update(float deltatime) = 0;
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	// Getter for string name of state
	virtual const char* GetName() const = 0;
protected:
	class AiComponent* mOwner;
};

class AiPatrol : public AiState
{
public:
	AiPatrol(class AiComponent* owner)
		:AiState(owner)
	{ }

	// Override with behaviors for this state
	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	const char* GetName() const override
	{
		return "Patrol";
	}
};

class AiDeath : public AiState
{
public:
	AiDeath(class AiComponent* owner)
		:AiState(owner)
	{ }

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	const char* GetName() const override
	{
		return "Death";
	}
};

class AiAttack : public AiState
{
public:
	AiAttack(class AiComponent* owner)
		:AiState(owner)
	{ }

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	const char* GetName() const override
	{
		return "Attack";
	}
};
