// player, child of enitity
#pragma once
#include <raylib.h>
#include "Entity.hpp"
#include "Key.hpp"

class Player : public Entity{
    public:
        Key key;

        Player();
        Player(Texture2D Texture);
        ~Player();
        
        void move(float speed);
};