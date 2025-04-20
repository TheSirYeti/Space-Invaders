#pragma once
#include "Bullet.h"

struct BulletPool
{
    int Amount;
    Bullet* bullets;

    BulletPool();
    BulletPool(int amount);

    void UpdateBullets();

    void ActivateBullet(V2 Position, V2 Direction, Color color);

    void Pool(int id);
};
