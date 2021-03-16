//
// Created by romaniy on 16.03.2021.
//

#ifndef TBRPG_BULLET_HPP
#define TBRPG_BULLET_HPP


class Bullet {
    float x,y,dx,dy,w,h;
    bool isLive;
public:
    Bullet(float x, float y, bool direction) : x(x), y(y) {
        w = h = 15;
        isLive = true;
        dx = 0.5;
        if (!direction) {
            dx *= -1;
        }
    }

    void update() {
        x += dx;
        // перетин із об'єктами if (peretnuvsya) dx=0; isLive = false;
    }
};


#endif //TBRPG_BULLET_HPP
