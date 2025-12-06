#include "Animation.h"

Animation::Animation() {}

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
    Frame = 0;                 // current frame index
    speed = Speed;             // how fast the animation plays

    for (int i = 0; i < count; i++)
        frames.push_back(IntRect(x + i*w, y, w, h));  // store each frame

    sprite.setTexture(t);      // assign texture
    sprite.setOrigin(w/2, h/2); // center the sprite
    sprite.setTextureRect(frames[0]); // start with first frame
}

void Animation::update()
{
    Frame += speed;            // advance frame
    int n = frames.size();     // total frames

    if (Frame >= n) Frame -= n; // loop animation
    if (n > 0) sprite.setTextureRect(frames[int(Frame)]); // update sprite
}

bool Animation::isEnd()
{
    return Frame + speed >= frames.size(); // check if near last frame
}
