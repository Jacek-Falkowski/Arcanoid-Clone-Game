#include "States/Play_state.hpp"
#include "States/Menu_state.hpp"
#include "States/Game_over.hpp"
#include "Game.hpp"
#include "Collision.hpp"
#include <iostream>

Play_state::Play_state(Game *game, int map)
    : State{game},
      ball{m_game->get_window_width() / 2.f, static_cast<float>(m_game->get_window_height() - 121)},
      win_label{"You win! Enter space to continue.", m_resource_manager.get_font("Arial.ttf"), 45},
      lost_label{"You lost! Enter space to continue.", m_resource_manager.get_font("Arial.ttf"), 45},
      paddle{static_cast<float>(m_game->get_window_width() / 2), static_cast<float>(m_game->get_window_height() - 100), m_game->get_resource_manager()},
      curr_state{State_of_game::play},
      press_space{
          "Press the spacebar to bounce the ball!!! ",
          m_resource_manager.get_font("Arial.ttf"),
          45,
      },
      Ball_on_paddle{false},
      health{3},
      score{0},
      health_label{std::string("Health: ") + std::to_string(health), m_resource_manager.get_font("Arial.ttf"), 25},
      score_label{std::string("Score: ") + std::to_string(score), m_resource_manager.get_font("Arial.ttf"), 25},
      test{1200, 700, m_game->get_resource_manager()},
      test2{700, 700, m_game->get_resource_manager()}

{
    win_label.setStyle(sf::Text::Bold);
    lost_label.setStyle(sf::Text::Bold);
    health_label.setPosition(20, 2);
    score_label.setPosition(game->get_window_width() / 2, 2);
    press_space.setStyle(sf::Text::Bold);

    m_background.setTexture(m_resource_manager.get_texture("background.png"));
    m_background.setScale(game->get_window_width() / m_background.getLocalBounds().width,
                          game->get_window_height() / m_background.getLocalBounds().height);

    win_label.setOrigin(win_label.getLocalBounds().width / 2.f, win_label.getLocalBounds().height / 2.f);
    lost_label.setOrigin(lost_label.getLocalBounds().width / 2.f, lost_label.getLocalBounds().height / 2.f);
    press_space.setOrigin(press_space.getLocalBounds().width / 2.f, press_space.getLocalBounds().height / 2.f);

    win_label.setPosition(m_game->get_window_width() / 2.f, m_game->get_window_height() / 2.f);
    lost_label.setPosition(m_game->get_window_width() / 2.f, m_game->get_window_height() / 2.f);
    press_space.setPosition(m_game->get_window_width() / 2.f, m_game->get_window_height() / 2.f);
    constexpr int brick_start_column = 0, brick_start_row = 2;
    constexpr float brick_spacing = 3.f;
    constexpr float brick_xoffset = (Brick::m_width / 2);
    int next = 0;
    std::vector<int> block_to_place = m_resource_manager.get_game_maps(map);
    for (int j = 0; j < 9; ++j)
    {
        for (int i = 0; i < 13; ++i)
        {
            float x = (i + brick_start_column) * (Brick::m_width + brick_spacing);
            float y = (j + brick_start_row) * (Brick::m_height + brick_spacing);

            int blockType = block_to_place[next];

            switch (blockType)
            {
            case 0:
            {
                Brick brick(brick_xoffset + x, y, m_game->get_resource_manager());
                bricks.emplace_back(brick);
                break;
            }
            case 1:
            {
                BronzeBrick bbrick(brick_xoffset + x, y, m_game->get_resource_manager());
                bricks.emplace_back(bbrick);
                break;
            }
            case 2:
            {
                SilverBrick sbrick(brick_xoffset + x, y, m_game->get_resource_manager());
                bricks.emplace_back(sbrick);
                break;
            }
            case 3:
            {
                GoldBrick gbrick(brick_xoffset + x, y, m_game->get_resource_manager());
                bricks.emplace_back(gbrick);
                break;
            }
            case 4:
            {
                SpecialBrickball sbrick1(brick_xoffset + x, y, m_game->get_resource_manager());
                bricks.emplace_back(sbrick1);
                break;
            }
            case 5:
            {
                SpecialBrickhealth sbrick2(brick_xoffset + x, y, m_game->get_resource_manager());
                bricks.emplace_back(sbrick2);
                break;
            }
            default:
            {
                break;
            }
            }

            next = next + 1;
        }
    }
}

void Play_state::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_game->change_state(new Menu_state(m_game));

    if (!Ball_on_paddle && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        Ball_on_paddle = true;

    if (curr_state != State_of_game::play)
        switch (curr_state)
        {
        case State_of_game::lost:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                m_game->change_state(new Game_over(m_game, score));
        }
}
void Play_state::update()
{
    if (!Ball_on_paddle)
        return;

    switch (curr_state)
    {
    case State_of_game::lost:
        break;
    case State_of_game::play:
        if (ball.bottom() >= m_game->get_window_height())
        {
            health--;

            if (health <= 0)
            {
                curr_state = State_of_game::lost;
            }

            if (health > 0)
            {
                ball.get_shape().setPosition(m_game->get_window_width() / 2.f, static_cast<float>(m_game->get_window_height() - 121));
                ball.set_velocity_x(-ball.get_velocity());
                ball.set_velocity_x(-ball.get_velocity());
                paddle.get_shape().setPosition(static_cast<float>(m_game->get_window_width() / 2), static_cast<float>(m_game->get_window_height() - 100));
                Ball_on_paddle = false;
            }
        }
        health_label.setString(std::string("Health: ") + std::to_string(health));
        score_label.setString(std::string("Score: ") + std::to_string(score));
        paddle.update(m_game->get_window_width());
        paddle_ball_collision(paddle, ball);

        ball.update(m_game->get_window_width(), m_game->get_window_height());
        ball.solve_bound_collisions(m_game->get_window_width(), m_game->get_window_height());

        if (bricks.size() == 0)
            curr_state = State_of_game::win;

        for (auto &brick : bricks)
        {
            brick.update();
            brick_ball_collision(brick, ball);
        }

        for (auto &bonus : bonuses)
        {
            bonus.update(m_game->get_window_width(), m_game->get_window_height());
            paddle_bonus_collision(paddle, bonus, ball);
        }
        for (auto &ball : bonusballs)
        {
            ball.update(m_game->get_window_width(), m_game->get_window_height());
            ball.solve_bound_collisions(m_game->get_window_width(), m_game->get_window_height());
            paddle_ball_collision(paddle, ball);
            for (auto &brick : bricks)
            {
                brick_ball_collision(brick, ball);
            }
        }

        bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
                                    [&](const auto &brick)
                                    {
                                        if (brick.is_destroyed())
                                        {
                                            if (brick.is_special1())
                                            {
                                                bonuses.emplace_back(BonusBall(brick.x(), brick.y(), m_game->get_resource_manager()));
                                            }
                                            if (brick.is_special2())
                                            {
                                                bonuses.emplace_back(Bonushealth(brick.x(), brick.y(), m_game->get_resource_manager()));
                                            }
                                            score += brick.get_score_value();
                                            return true;
                                        }
                                        return false;
                                    }),
                     std::end(bricks));

        bonuses.erase(std::remove_if(std::begin(bonuses), std::end(bonuses),
                                     [this](const auto &bonus)
                                     {
                                         if (bonus.is_destroyed())
                                         {
                                             if (bonus.is_special1())
                                             {
                                                 bonusballs.emplace_back(ExtraBall(ball.x(), ball.y()));
                                             }
                                             if (bonus.is_special2())
                                             {
                                                 health++;
                                             }
                                             return true;
                                         }
                                         return false;
                                         return bonus.is_destroyed();
                                     }),
                      std::end(bonuses));
    }
    bonusballs.erase(std::remove_if(std::begin(bonusballs), std::end(bonusballs),
                                    [](const auto &ball)
                                    {
                                        return ball.is_destroyed();
                                    }),
                     std::end(bonusballs));
}

void Play_state::draw()
{
    m_game->get_render_window().draw(m_background);
    if (!Ball_on_paddle)
    {
        m_game->get_render_window().draw(press_space);
    }

    paddle.draw(m_game->get_render_window());
    ball.draw(m_game->get_render_window());

    for (auto &brick : bricks)
        brick.draw(m_game->get_render_window());

    for (auto &bonus : bonuses)
        bonus.draw(m_game->get_render_window());
    for (auto &ball : bonusballs)
        ball.draw(m_game->get_render_window());
    m_game->get_render_window().draw(health_label);
    m_game->get_render_window().draw(score_label);

    switch (curr_state)
    {
    case State_of_game::win:
        m_game->get_render_window().draw(win_label);

        break;
    case State_of_game::lost:
        m_game->get_render_window().draw(lost_label);
        break;
    }
}
