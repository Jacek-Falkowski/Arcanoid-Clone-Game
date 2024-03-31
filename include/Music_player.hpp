#pragma once
#include <mutex>
#include <SFML/Audio.hpp>
#include "Resource_manager.hpp"
#include "Utility.hpp"

class Music_player
{
public:
    explicit Music_player(Resource_manager &resource_manager);

    void play() noexcept;

    void restart() noexcept;

    void stop() noexcept;

    bool finished() noexcept;

    void next() noexcept;

    void force_next();

    void try_force_switch();

    void previous() noexcept;

    void shuffle_play() noexcept;

    ~Music_player();

private:
    Resource_manager &m_resource_manager;
    std::size_t m_current_music;

    bool m_force_next;
    std::mutex force_next_mutex;
};
