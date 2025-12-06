#include "Animation.h"

Animation::Animation() {}

Animation::Animation(Texture &t, int x, int y, int w, int h, int count, float Speed)
{
    Frame = 0;              // start on first frame
    speed = Speed;          // animation speed

    for (int i = 0; i < count; i++)
        frames.push_back(IntRect(x + i*w, y, w, h));  // store all frames

    sprite.setTexture(t);   // apply texture
    sprite.setOrigin(w/2, h/2);   // center sprite
    sprite.setTextureRect(frames[0]); // first frame
}

void Animation::update()
{
    Frame += speed;         // next frame
    int n = frames.size();  // total frames
    if (Frame >= n) Frame -= n;       // loop animation
    if (n > 0) sprite.setTextureRect(frames[int(Frame)]); // update sprite
}

bool Animation::isEnd()
{
    return Frame + speed >= frames.size();  // check if reaching last frame
}
