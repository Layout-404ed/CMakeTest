// player
#include "Player.hpp"
#include "raylib.h"

Player::Player(){
    key = {
        .up = KEY_W,
        .down = KEY_S,
        .left = KEY_A,
        .right = KEY_D
    };

    rect = {
        .x = GetScreenWidth() / 2.0f - 50.0f,
        .y = GetScreenHeight() / 2.0f + 50.0f,
        .width = 100.0f,
        .height = 100.0f
    };
}
Player::Player(Texture2D texture){
    this->texture = texture;
    key = {
        .up = KEY_W,
        .down = KEY_S,
        .left = KEY_A,
        .right = KEY_D
    };

    rect = {
        .x = GetScreenWidth() / 2.0f - 50.0f,
        .y = GetScreenHeight() / 2.0f + 50.0f,
        .width = 100.0f,
        .height = 100.0f
    };
}
Player::~Player() = default;

void Player::move(float speed){
    if(IsKeyDown(key.up)) rect.y -= speed * GetFrameTime();
    if(IsKeyDown(key.down)) rect.y += speed * GetFrameTime();
    if(IsKeyDown(key.left)) rect.x -= speed * GetFrameTime();
    if(IsKeyDown(key.right)) rect.x += speed * GetFrameTime();
};