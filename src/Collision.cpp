#include "Collision.hpp"

// AABB algorithm
template <typename T1, typename T2>
bool intersection(const T1 &a, const T2 &b) noexcept
{
        return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

void paddle_ball_collision(const Paddle &paddle, Ball &ball)
{
        if (!intersection(paddle, ball))
                return;

        ball.set_velocity_y(-Ball::m_Velocity);
        ball.set_velocity_x(ball.x() < paddle.x() ? -Ball::m_Velocity : Ball::m_Velocity);
}

void brick_ball_collision(Brick &brick, Ball &ball)
{
        if (!intersection(brick, ball))
                return;

        brick.dmg();

        if (brick.get_health() <= 0)
        {
                brick.set_destroy_flag(true);
        }

        float left_overlap = ball.right() - brick.left();
        float right_overlap = brick.right() - ball.left();
        float top_overlap = ball.bottom() - brick.top();
        float bottom_overlap = brick.bottom() - ball.top();

        bool ball_from_left(std::abs(left_overlap) < std::abs(right_overlap));
        bool ball_from_top(std::abs(top_overlap) < std::abs(bottom_overlap));

        float xoverlap = ball_from_left ? left_overlap : right_overlap;
        float yoverlap = ball_from_top ? top_overlap : bottom_overlap;

        if (std::abs(xoverlap) < std::abs(yoverlap))
                ball.set_velocity_x(ball_from_left ? -Ball::m_Velocity : Ball::m_Velocity);
        else
                ball.set_velocity_y(ball_from_top ? -Ball::m_Velocity : Ball::m_Velocity);
}


void paddle_bonusball_collision(const Paddle &paddle, Bonushealth &bonus, Ball &ball)
{
        if (!intersection(paddle, bonus))
                return;

        ExtraBall extr_ball(ball.x(), ball.y());
        bonus.set_destroy_flag(true);

}

void paddle_bonushealth_collision(const Paddle &paddle, Bonushealth &bonus, Ball &ball)
{
        if (!intersection(paddle, bonus))
                return;        
        bonus.set_destroy_flag(true);

}

void paddle_bonus_collision(const Paddle &paddle, Bonus &bonus, Ball &ball)
{
        if (!intersection(paddle, bonus))
                return;        
        bonus.set_destroy_flag(true);

}
