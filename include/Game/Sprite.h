//
// Created by Cyao on 04/07/2023.
//

#ifndef TOBENAMED_SPRITE_H
#define TOBENAMED_SPRITE_H

#include <GL/glew.h>


class Sprite {
public:
    Sprite();
    ~Sprite();

    void draw();
    void init(float x, float y, float width, float height);

private:
    float _x, _y;
    float _width, _height;
    GLuint _vboID;
};


#endif //TOBENAMED_SPRITE_H
