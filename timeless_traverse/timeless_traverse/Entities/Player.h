#pragma once

#include "Character.h"

class Player : public Character
{
public:
    static Player& GetInstance()
    {
        static Player instance;
        return instance;
    }

private:
    Player();
    ~Player();

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
};
