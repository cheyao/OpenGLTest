//
// Created by Ray on 04/07/2023.
//
#include <iostream>

#include "Game/Sprite.h"
#include "Game/MainGame.h"

MainGame::MainGame() {
    _screen_width = 1024; _screen_height = 768;
    _game_state = GAME_STATE::PLAY;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "ERROR! Could not initialize SDL!";
        SDL_Quit();
        exit(1);
    }

    _window = SDL_CreateWindow("Game or something",
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               _screen_width, _screen_height,
                               SDL_WINDOW_OPENGL);
    if (_window == nullptr) {
        std::cerr << "ERROR! Window could not be created!";
        SDL_Quit();
        exit(1);
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == nullptr) {
        std::cerr << "ERROR! GL Context could not be created!";
        SDL_Quit();
        exit(1);
    }

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "ERROR! GLEW could not be created!";
        SDL_Quit();
        exit(1);
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.f, 1.f, 1.f, 1.f);

    _sprite.init(-1.f, -1.f, 1.f, 1.f);
}

MainGame::~MainGame() {
    SDL_Quit();
}

void MainGame::run() {
    gameLoop();
}

void MainGame::gameLoop() {
    while (_game_state != GAME_STATE::EXIT) {
        processInput();
        drawGame();
    }
}

void MainGame::processInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _game_state = GAME_STATE::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout << "X:" << event.motion.x << "Y:" << event.motion.y << "\n";
        }
    }
}

void MainGame::drawGame() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _sprite.draw();

    SDL_GL_SwapWindow(_window);
}
