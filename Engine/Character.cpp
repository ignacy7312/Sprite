#include "Character.h"

Character::Character(const Vec2& pos)
	:
	sprite("link90x90.bmp"),
	pos(pos)
{
	for (int i = 0; i < (int)Sequence::StandingLeft; i++) {
		animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, sprite, 0.16f));
	}
	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++) {
		animations.emplace_back(Animation(0, 90 * (i- (int)Sequence::StandingLeft), 90, 90, 4, sprite, 0.16f));
	}
}

void Character::Draw(Graphics& gfx) const
{
	animations[(int)iCurSequence].Draw((Vei2)pos, gfx);
}

void Character::SetDirection(const Vec2& dir)
{
	if (dir.x > 0.0f) {
		iCurSequence = Sequence::WalkingRight;
	} else if (dir.x < 0.0f) {
		iCurSequence = Sequence::WalkingLeft;
	} else if (dir.y < 0.0f) {
		iCurSequence = Sequence::WalkingUp;
	}else if (dir.y > 0.0f) {
		iCurSequence = Sequence::WalkingDown;
	} else {
		
		if (velocity.x > 0.0f) {
			iCurSequence = Sequence::StandingRight;
		} else if (velocity.x < 0.0f) {
			iCurSequence = Sequence::StandingLeft;
		} else if (velocity.y < 0.0f) {
			iCurSequence = Sequence::StandingUp;
		} else if (velocity.y > 0.0f) {
			iCurSequence = Sequence::StandingDown;
		}
	}
	velocity = dir * speed;
}

void Character::Update(float dt)
{
	pos += velocity * dt;
	animations[(int)iCurSequence].Update(dt);

}

