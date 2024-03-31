#include "Music_player.hpp"
#include <iostream>

Music_player::Music_player(Resource_manager& resource_manager)
          :m_resource_manager{resource_manager},
           m_current_music{0U}
{

}

void Music_player::play() noexcept
{
          m_resource_manager.m_music[m_current_music]->play();
}

void Music_player::restart() noexcept
{
          m_resource_manager.m_music[m_current_music]->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
}

bool Music_player::finished() noexcept
{
        return m_resource_manager.m_music[m_current_music]->getStatus() != sf::Music::Playing;
}

void Music_player::stop() noexcept
{
          m_resource_manager.m_music[m_current_music]->stop();
}

void Music_player::force_next()
{
        force_next_mutex.lock();
        m_force_next = true;
        force_next_mutex.unlock();
}

void Music_player::try_force_switch()
{
        force_next_mutex.lock();
        if (m_force_next) {
                this->next();
                m_force_next = false;
        }
        force_next_mutex.unlock();
}

void Music_player::next() noexcept
{
        std::cout << "next music()" << std::endl;
        m_resource_manager.m_music[m_current_music]->stop();
        m_resource_manager.m_music[m_current_music]->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
        m_current_music = (m_current_music + 1) % m_resource_manager.m_music.size();
        m_resource_manager.m_music[m_current_music]->play();
}

void Music_player::previous() noexcept
{
          m_resource_manager.m_music[m_current_music]->stop();
          m_resource_manager.m_music[m_current_music]->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
          --m_current_music;
          m_resource_manager.m_music[m_current_music]->play();
}

void Music_player::shuffle_play() noexcept
{
        std::size_t i; 
        while((i = util::randomize(0,m_resource_manager.m_music.size() - 1)) == m_current_music);

        m_resource_manager.m_music[m_current_music]->stop();
        m_resource_manager.m_music[m_current_music]->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
        m_current_music = i;
        m_resource_manager.m_music[m_current_music]->play();
}

Music_player::~Music_player()
{
        m_resource_manager.m_music[m_current_music]->stop();
}
