#pragma once
#include "Objects/Ball.hpp"
#include "Objects/Paddle.hpp"
#include "Objects/Brick.hpp"
#include "Objects/Bonus.hpp"
#include "States/Play_state.hpp"

void paddle_ball_collision(const Paddle &paddle, Ball &ball);

void brick_ball_collision(Brick &brick, Ball &ball);

void paddle_bonusball_collision(const Paddle &paddle, Bonushealth &bonus, Ball &ball);

void paddle_bonushealth_collision(const Paddle &paddle, Bonushealth &bonus, Ball &ball);

void paddle_bonus_collision(const Paddle &paddle, Bonus &bonus, Ball &ball);