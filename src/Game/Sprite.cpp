//
// Created by Ray on 04/07/2023.
//

#include "Game/Sprite.h"

Sprite::Sprite() {

};

Sprite::~Sprite() {
    if (_vboID != 0) {
        glDeleteBuffers(1, &_vboID);
    }
}

void Sprite::init(float x, float y, float width, float height) {
    _x = x; _y = y;
    _width = width; _height = height;

    glGenBuffers(1, &_vboID);

    float vertexData[6 * 2] = {x + width,
                               y + height,

                               x,
                               y + height,

                               x,
                               y,

                               x + width,
                               y + height,

                               x + width,
                               y,

                               x,
                               y};

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw() {
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
