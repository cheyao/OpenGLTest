//
// Created by Ray on 04/07/2023.
//

#ifndef TOBENAMED_MAINGAME_H
#define TOBENAMED_MAINGAME_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "Game/Sprite.h"

class MainGame {
public:
    MainGame();
    ~MainGame();

    void run();

private:
    void gameLoop();
    void processInput();
    void drawGame();

    SDL_Window* _window;
    int _screen_width, _screen_height;
    enum class GAME_STATE {PLAY, EXIT} _game_state;

    Sprite _sprite;
};


#endif //TOBENAMED_MAINGAME_H
