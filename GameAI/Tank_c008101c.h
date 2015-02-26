#pragma once
#ifndef TANK_C008101C_H
#define TANK_C008101C_H

#include "BaseTank.h"
#include <SDL.h>
#include "Commons.h"


enum Deceleration
{ 
	sonic = 1,
	human = 2,
	snail = 3
};

class Tank_c008101c :
	protected BaseTank
{
	//---------------------------------------------------------------
public:
	Tank_c008101c(SDL_Renderer* renderer, TankSetupDetails details);
	~Tank_c008101c();
	void CheckInput(SDL_Event e);

	void ChangeState(BASE_TANK_STATE newState);

	void Update(float deltaTime, SDL_Event e);

	//---------------------------------------------------------------
protected:
	double mMaxSeeAhead = 10;
	double mMaxAvoidForce = 100;
	Vector2D mTargetPosition;
	Vector2D mAhead;
	Vector2D mAhead2;
	Deceleration mDeceleration = sonic;
	STEERING_BEHAVIOUR mBehaviour = STEERING_SEEK;

	void MoveInHeadingDirection(float deltaTime);
	Vector2D Seek(Vector2D targetPosition);
	Vector2D Flee(Vector2D targetPosition);
	Vector2D Arrive(Vector2D targetPosition, Deceleration deceleration);
	Vector2D ObstacleAvoidance();
	GameObject* MostThreateningObstacle();
};

//---------------------------------------------------------------

#endif //TANK_C008101C_H

