#pragma once

#include "Animation.h"
#include "Vec2.h"

class Character {

private:
	enum class Sequence {
		WalkingLeft,
		WalkingRight, 
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};

public:
	Character(const Vec2& pos);
	void Draw(Graphics& gfx) const;
	void SetDirection(const Vec2& dir);
	void Update(float dt);
private:
	Surface sprite;
	Vec2 pos;
	Vec2 velocity;
	std::vector<Animation> animations;
	Sequence iCurSequence = Sequence::StandingDown;
	float speed = 140.0f;
};