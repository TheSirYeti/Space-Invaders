#pragma once
#include "Ships/AlienShip.h"
#include "Bullets/BulletPool.h"
#include "Ships/Player.h"

class AlienManager
{
public:
    AlienShip* aliens;
    BulletPool* bulletPool;
    int Amount;
    float MaxPerLine;

    AlienManager();
    AlienManager(int amount, int max);
    ~AlienManager();

    void UpdateAliens();
    void InitializeAliens();
    void CheckForAlienCollisions(BulletPool* playerBulletPool);
    void CheckForPlayerCollisions(Player* player);
};
