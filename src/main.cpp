// Test
//TODO: make the yaml so that github makes the builds for both mac (.app) and windows (.exe)

// libs
#include "Player.hpp"
#include <iostream>
#include <raylib.h>
#include <string>

int main(void)  
{
    // init
    InitWindow(0.0f, 0.0f, "test");
    SetTargetFPS(60.0f);
    InitAudioDevice();
    ChangeDirectory(GetApplicationDirectory());

    Player player;
    Music chiptune;
    Font font;
    Camera2D camera;
    
    try {
        player.texture = LoadTexture("assets/sprites/spritesheet.png");
        chiptune = LoadMusicStream("assets/sounds/[C H I P T U N E V I B E] - Context Sensitive.mp3");
        font = LoadFont("assets/fonts/Minecraft.ttf");
        
        if(!IsTextureValid(player.texture))
            throw "Texture not found or is invalid...";
        if(!IsMusicValid(chiptune))
            throw "Music not found or is invalid...";
        if(!IsFontValid(font))
            throw "Font not found or is invalid...";
    } catch (std::string error) {
        std::cerr << "Something went wrong: " << error << '\n';
    }catch(...){
        std::cerr << "Something went wrong: dont know\n";
    }camera = Camera2D{
        .offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f},
        .target = {player.rect.x + player.rect.width * .5f, player.rect.y + player.rect.height * .5f},
        .rotation = 0.0f,
        .zoom = 1.0f
    };
    
    SetMusicVolume(chiptune, 1.0f);
    PlayMusicStream(chiptune);

    // run
    while(!WindowShouldClose())
    {
        // update
        UpdateMusicStream(chiptune);
        if(!IsMusicStreamPlaying(chiptune))
            PlayMusicStream(chiptune);

        // draw
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode2D(camera);
        
        DrawTexturePro(player.texture, {0.0f, 0.0f, 16.0f, 16.0f}, player.rect, {0.0f, 0.0f}, 0.0f, WHITE);
        player.move(500.0f);

        camera.target.x += ((player.rect.x + player.rect.width * .5f) - camera.target.x) * .1f;
        camera.target.y += ((player.rect.y + player.rect.height * .5f) - camera.target.y) * .1f;

        std::string txt = std::string("Hello!\n")
                        + "Ty for testing ts lol\n"
                        + "Loaded Successfully:\n";
        if(IsTextureValid(player.texture))
            txt += "\tTexture\n";
        if(IsMusicValid(chiptune))
            txt += "\tMusic\n";
        if(IsFontValid(font))
            txt += "\tFont\n";
        txt += "Failed Load:\n";
        if(!IsTextureValid(player.texture))
            txt += "\tTexture\n";
        if(!IsMusicValid(chiptune))
            txt += "\tMusic\n";
        if(!IsFontValid(font))
            txt += "\tFont\n";
        DrawText(txt.c_str(), GetScreenWidth() / 2.0f - 50.0f, GetScreenHeight() / 2.0f + 50.0f, 20.0f, WHITE);
        
        EndMode2D();
        EndDrawing();
    }

    //unload
    UnloadMusicStream(chiptune);
    UnloadTexture(player.texture);
    UnloadFont(font);
    
    // close
    CloseAudioDevice();
    CloseWindow();
    
    return 0; // destructors should be called automatically
}