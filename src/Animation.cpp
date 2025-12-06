#include "Animation.h"

Animation::Animation() {}

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
<<<<<<< HEAD
    Frame = 0;                 // current frame index
    speed = Speed;             // how fast the animation plays

    for (int i = 0; i < count; i++)
        frames.push_back(IntRect(x + i*w, y, w, h));  // store each frame

    sprite.setTexture(t);      // assign texture
    sprite.setOrigin(w/2, h/2); // center the sprite
    sprite.setTextureRect(frames[0]); // start with first frame
=======
    Frame = 0;              // start on first frame
    speed = Speed;          // animation speed

    for (int i = 0; i < count; i++)
        frames.push_back(IntRect(x + i*w, y, w, h));  // store all frames

    sprite.setTexture(t);   // apply texture
    sprite.setOrigin(w/2, h/2);   // center sprite
    sprite.setTextureRect(frames[0]); // first frame
>>>>>>> b8e650bc352432e0b90b90dc99d2a50de25a052d
}

void Animation::update()
{
<<<<<<< HEAD
    Frame += speed;            // advance frame
    int n = frames.size();     // total frames

    if (Frame >= n) Frame -= n; // loop animation
=======
    Frame += speed;         // next frame
    int n = frames.size();  // total frames
    if (Frame >= n) Frame -= n;       // loop animation
>>>>>>> b8e650bc352432e0b90b90dc99d2a50de25a052d
    if (n > 0) sprite.setTextureRect(frames[int(Frame)]); // update sprite
}

bool Animation::isEnd()
{
<<<<<<< HEAD
    return Frame + speed >= frames.size(); // check if near last frame
}
=======
    return Frame + speed >= frames.size();  // check if reaching last frame
}
>>>>>>> b8e650bc352432e0b90b90dc99d2a50de25a052d
